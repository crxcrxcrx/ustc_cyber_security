#include "net_exp.h"

SLD_WIN sending_window; //�����������ݽṹ��
int total_send_byte = 0; //��¼�ۼƷ��͵��ֽ���	

void usage( char **argv )
{
	printf( "wrong argument!\n" );
	printf( "usage: %s send_file_name. \n",  argv[0] );
}


/*
	������ն˷��ص�ACK���������û������������ݰ���״̬
*/
void slide_window_ack( int ack_num )
{	
	pthread_mutex_lock( &sending_window.lock );//������������
	
	printf( "\t[child thread] recv ack# %-8d\n",  ack_num );
	if( ack_num >= sending_window.send_left && ack_num < sending_window.send_right )
	{
		int succ_pkt_seq;
		for( succ_pkt_seq = sending_window.send_left; succ_pkt_seq <= ack_num; succ_pkt_seq++ )
			if( sending_window.rdt_pkts[succ_pkt_seq % sending_window.win_len].state == 1 )
			{
				sending_window.rdt_pkts[succ_pkt_seq % sending_window.win_len].state = 2; //set pkt state to acked
				total_send_byte += (sending_window.rdt_pkts[succ_pkt_seq % sending_window.win_len].pkt_len - RDT_HEADER_LEN);
			}
	}
	else
	{
		if( ack_num < sending_window.send_left )
			printf( "\t[child thread] already acked #pkt %-8d\n", ack_num );
		else
		{
			printf( "\t[child thread] recv wrong acked, #ack[%d] > sending_window.send_right[%d].\n", ack_num, sending_window.send_right );
			sleep(10); //wrong ack, do something?
		}
	}
	
	pthread_mutex_unlock( &sending_window.lock ); //������������
}

/*
	���ڼ����˿ڲ�����ACK�����̺߳���
*/
void *recv_acks_thread( void *arg )
{
	int *sock_fd = ( int *) arg;
	char rdt_pkt[RDT_PKT_LEN];
	int pkt_len;
	
	struct sockaddr_in reply_addr;
	int reply_addr_len;
	int reply_ack_seq;
	int reply_ack_flag;
	memset( &reply_addr, 0, sizeof(reply_addr) );
	reply_addr_len = sizeof( reply_addr );
	
	printf( "\t[child thread] waiting acks..\n" );
	while(1)
	{		
		/*����Ƿ������ݰ�����*/
		pkt_len = recvfrom( *sock_fd, rdt_pkt, RDT_PKT_LEN, MSG_PEEK, 
			(struct sockaddr *)&reply_addr, &reply_addr_len );
			
		if( pkt_len > 0 ) //�����ݰ�����
		{
			pkt_len = recvfrom( *sock_fd, rdt_pkt, RDT_PKT_LEN, 0, 
				(struct sockaddr *)&reply_addr, &reply_addr_len   );	
			
			unpack_rdt_pkt( NULL, rdt_pkt, pkt_len, &reply_ack_seq, &reply_ack_flag );
			if( reply_ack_flag == RDT_CTRL_ACK ) //��ACK������
				slide_window_ack( reply_ack_seq ); //�������û�������״̬
		}
	}
}



/*
	��黬���������Ƿ������ݰ���Ҫ���ͣ����ش����ڴ����͵����ݰ�����
*/
int pre_sending_rdt_pkt( FILE *fp )
{
	int pkt_to_send = 0;
	
	char read_buf[RDT_DATA_LEN];
	int send_base_acked;
	
	pthread_mutex_lock( &sending_window.lock );
	
	STATE_PKT *ptr_pkt_left = &sending_window.rdt_pkts[ sending_window.send_left % sending_window.win_len];
	send_base_acked = (ptr_pkt_left->state == RDT_PKT_ST_ACKED) ? 1 : 0;
	
	
	/*
		���������������˵İ��Ѿ��յ�ACK���򽫻������ڻ�������һ��û�յ�ACK�İ���λ�ã�
		ͬʱ�������ݰ�װ�뻬�������Ҷ˿�ȱλ�á�
	*/
	if( send_base_acked == 1 ) 
	{
		int new_pkt_seq;
		int max_acked;
		max_acked = sending_window.send_left;
		
		while( max_acked < sending_window.send_right &&
				(sending_window.rdt_pkts[max_acked % sending_window.win_len].state == RDT_PKT_ST_ACKED) )
			max_acked++;
		sending_window.send_left = max_acked;	

		for( 	new_pkt_seq = sending_window.send_right; 
				new_pkt_seq < (sending_window.send_left + sending_window.win_len); 
				new_pkt_seq++ )
		{
				if( feof(fp) ) //����Ƿ��ѵ��﷢���ļ���β
					break;
					
				int read_len, rdt_pkt_len;
				STATE_PKT *ptr_pkt_new = &sending_window.rdt_pkts[new_pkt_seq % sending_window.win_len];
				
				read_len = fread( read_buf, sizeof(char), RDT_DATA_LEN, fp ); //��ȡ�����ļ��е�����
				rdt_pkt_len = pack_rdt_pkt( read_buf, 
											ptr_pkt_new->rdt_pkt, 
											read_len, 
											new_pkt_seq, 
											RDT_CTRL_DATA ); //��װΪRDT���ݰ�
				
				//��ʼ����RDT���ݰ�״̬
				ptr_pkt_new->pkt_seq = new_pkt_seq;
				ptr_pkt_new->pkt_len = rdt_pkt_len;
				ptr_pkt_new->state = RDT_PKT_ST_INIT; 
				memset( &(ptr_pkt_new->send_time), 0, sizeof(struct timeval) );
				
				pkt_to_send++;
		}
		sending_window.send_right = new_pkt_seq;		
	}
	/*
		���������������˵İ���û���յ����ݰ����������Ƿ�ʱ�������ʱ�������·������л��������ڵ����ݰ�����������ȴ���
	*/
	else 
	{
		struct timeval time_now;
		gettimeofday( &time_now, NULL );
		
		/*
			����ǵ�һ�η������ݣ����������ڳ�ʼ�������������͵�����
		*/
		if( sending_window.send_left == sending_window.send_right )
		{
			int new_pkt_seq;
			for( 	new_pkt_seq = sending_window.send_right; 
					new_pkt_seq < (sending_window.send_left + sending_window.win_len); 
					new_pkt_seq++ )
			{
					int read_len, rdt_pkt_len;
					if( feof(fp) ) //����Ƿ��ѵ��﷢���ļ���β
						break;
					STATE_PKT *ptr_pkt_new = &sending_window.rdt_pkts[new_pkt_seq % sending_window.win_len];
					read_len = fread( read_buf, sizeof(char), RDT_DATA_LEN, fp );
					rdt_pkt_len = pack_rdt_pkt( read_buf, 
												ptr_pkt_new->rdt_pkt, 
												read_len, 
												new_pkt_seq, 
												RDT_CTRL_DATA );
					ptr_pkt_new->pkt_seq = new_pkt_seq;
					ptr_pkt_new->pkt_len = rdt_pkt_len;
					ptr_pkt_new->state = RDT_PKT_ST_INIT; //set pkt state to init state
					memset( &(ptr_pkt_new->send_time), 0, sizeof(struct timeval) );
					pkt_to_send++;
			}
			sending_window.send_right = new_pkt_seq;
			printf( "[main thread] begin sending, slide window[%d,%d).\n", 
							sending_window.send_left, sending_window.send_right );
		}		
		else if( time_out( time_now, ptr_pkt_left->send_time ) ) //��һ�����ݰ���ʱ
		{
			int i; 
			//���·��ʹ������������ݰ�
			for( i = sending_window.send_left; i < sending_window.send_right; i++ )
			{
				STATE_PKT *ptr_pkt = &sending_window.rdt_pkts[i % sending_window.win_len];
				memset( &(ptr_pkt->send_time), 0, sizeof(struct timeval) ); 
				ptr_pkt->state = RDT_PKT_ST_TMOUT;
				pkt_to_send++;
			}
			printf( "[main thread] slide window[%d,%d), first pkt time out.\n", 
						sending_window.send_left, sending_window.send_right );
		}
		else
		{				
			pkt_to_send = 0; //û�г�ʱ�������ȴ�ACK
		}
	}
		
	pthread_mutex_unlock( &sending_window.lock );
	
	return pkt_to_send;
}


/*
	Go-Back-N Э�鷢�Ͷ˺���
	���������
		send_file_name: �����͵��ļ���
		sock_fd���������ݵ�socket (ͬʱ�Ӹ�socket�������ݰ��ͽ������ݰ�ACK)
		recv_addr_ptr: ���ն˵ĵ�ַ
	˵����
		����һ�����߳����ڽ��ռ����˿ڲ�����ACK
		�����߳�����ά���������ڲ��������ݰ�
*/

int deliver_file( char *send_file_name, int sock_fd,  struct sockaddr_in *recv_addr_ptr )
{
	char recv_pkt_buf[RDT_PKT_LEN];
	int seq_num = RDT_BEGIN_SEQ;
	
	struct sockaddr_in reply_addr;
	int reply_addr_len;
	int reply_ack_seq;
	int reply_ack_flag;
	pthread_t worker_thread;
	int reply_thread;
	
	FILE *fp;
	int i, j, read_len, pkt_len;
	int counter = 1;
	STATE_PKT *ptr_pkt;

	if( (fp = fopen( send_file_name, "r" )) == NULL )
	{
		printf( "open file : %s failed.\n",  send_file_name );
		return 1;
	}
	
	memset( &reply_addr, 0, sizeof(reply_addr) );
	
	//��ʼ��������
	pthread_mutex_init( &sending_window.lock, NULL );
	
	//��ʼ����������
	sending_window.win_len = RDT_SENDWIN_LEN;
	sending_window.send_left = RDT_BEGIN_SEQ;
	sending_window.send_right = RDT_BEGIN_SEQ;	//[slide window]= [RDT_BEGIN_SEQ, RDT_BEGIN_SEQ)
	ptr_pkt = &sending_window.rdt_pkts[sending_window.send_left % sending_window.win_len];
	ptr_pkt->pkt_seq = RDT_BEGIN_SEQ;	
	ptr_pkt->state = 0;

	//�������߳����ڽ���ACK
	reply_thread = pthread_create( &worker_thread, NULL, recv_acks_thread, (void *)&sock_fd );
	if( reply_thread != 0 )
	{
		perror( "pthread_create failed.\n" );
		exit( 1 );
	}
	
	while(1)
	{
		int pkt_to_send;
		
		/*��黬���������Ƿ������ݰ���Ҫ����*/
		pkt_to_send = pre_sending_rdt_pkt( fp );
		
		if( pkt_to_send > 0 )
		{
			printf( "[main thread] #%d pkts to send.\n", pkt_to_send );
			for( i = sending_window.send_left; i < sending_window.send_right; i++ )
			{
				STATE_PKT *ptr_pkt;
				ptr_pkt = &sending_window.rdt_pkts[ i % sending_window.win_len];
				if( ptr_pkt->state == RDT_PKT_ST_INIT ||  ptr_pkt->state == RDT_PKT_ST_TMOUT )
				{
				
					ptr_pkt->state = RDT_PKT_ST_SENT;
					udt_sendto( sock_fd, ptr_pkt->rdt_pkt, ptr_pkt->pkt_len, 0,
							(struct sockaddr *)recv_addr_ptr, sizeof(*recv_addr_ptr) );
					
					gettimeofday( &ptr_pkt->send_time, NULL );
					printf( "[main thread] send count #%-8d rdt_pkt #%-8d %-10d bytes.\n", counter++, ptr_pkt->pkt_seq, ptr_pkt->pkt_len );
				}
			}
			printf( "[main thread] slide window: [%d,%d).\n", sending_window.send_left, sending_window.send_right );
		}
		else
		{
			//����ļ��Ƿ�����
			if( sending_window.send_left == sending_window.send_right && feof(fp) ) //data transfer finished
			{
				printf( "[main thread] finished sending! slide window: [%d,%d).\n", sending_window.send_left, sending_window.send_right );
				reply_thread = pthread_cancel( worker_thread ); /*ɾ�����߳�*/
				if( reply_thread != 0 )
				{
					printf( "[main thread] pthread_cancel failed.\n" );
					exit(1);
				}
				break;			
			}
		}
	}
	
	//ɾ��������
	pthread_mutex_destroy( &sending_window.lock );
	
	//�������͹��̣������ܶ˷��ͽ������ݰ�(������ΪRDT_CTRL_END)
	if( feof(fp) )
	{
		char rdt_pkt[RDT_PKT_LEN];
		int rdt_pkt_len;
		int new_pkt_seq = sending_window.send_left;
		rdt_pkt_len = pack_rdt_pkt( NULL, 
							rdt_pkt, 
							0, 
							new_pkt_seq, 
							RDT_CTRL_END );
		sendto( sock_fd, rdt_pkt, rdt_pkt_len, 0, (struct sockaddr *)recv_addr_ptr, sizeof(*recv_addr_ptr) );
	}
	printf( "\n\nsend file %s finished\ntotal send %d bytes.\n", send_file_name, total_send_byte );
	fclose( fp );
	return 0;
}

int main( int argc, char **argv )
{
	struct sockaddr_in recv_addr, send_addr;
	int sock_fd;
	
	if( argc != 2 )
	{
		usage( argv );
		exit(0);
	}
	
	srand ( time(NULL) );
	
	if( ( sock_fd = socket( AF_INET, SOCK_DGRAM, 0 ) ) == -1 )
	{
		printf( "error! information: %s\n", strerror(errno) );
		exit(1);	
	}
	memset( &send_addr, 0, sizeof(send_addr) );
	send_addr.sin_family = AF_INET;
	send_addr.sin_addr.s_addr = htonl( INADDR_ANY );
	send_addr.sin_port = htons( RDT_SEND_PORT );
	
	if( ( sock_fd = socket( AF_INET, SOCK_DGRAM, 0 ) ) == -1 )
	{
		printf( "error! information: %s\n", strerror(errno) );
		exit(1);	
	}
	
	//��socket�󶨵����ص�ĳ���˿ڣ�ͬʱ�Ӹ�socket�������ݰ��ͽ���ACK
	if( bind( sock_fd, (struct sockaddr *)&send_addr, sizeof(send_addr) ) == -1 )
	{
		close( sock_fd );
		printf( "error! information: %s\n", strerror(errno) );
		exit(1);	
	}
			
	//���ý��ն˵�ַ		
	memset( &recv_addr, 0, sizeof(recv_addr) );
	recv_addr.sin_family = AF_INET;
	recv_addr.sin_addr.s_addr = inet_addr( RDT_SERVER_ADDRESS );
	recv_addr.sin_port = htons( RDT_RECV_PORT );

	
	//���ô����ļ��ĺ���
	if( deliver_file( argv[1], sock_fd, &recv_addr ) != 0 )
	{
		printf( "deliver file %s failed.\n", argv[1] );
		close( sock_fd );
		exit(1);
	}
	
	close( sock_fd );
	return 0;
}


