#ifndef NETEXP_H
#define NETEXP_H

#include <sys/socket.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <time.h>
#include <pthread.h>
#include <ctype.h>


#define		TCP_SERVER_ADDRESS		"127.0.0.1"
#define 	TCP_SERVER_PORT			8000
#define		TCP_BUF_LENGTH			1000
#define 	CONN_NUM				10

#define		UDP_SERVER_ADDRESS		"127.0.0.1"
#define		UDP_RECV_PORT			8001 
#define		UDP_SEND_PORT			8002 
#define		UDP_BUF_LENGTH			1000

#define		RDT_SERVER_ADDRESS		"127.0.0.1"		//RDT��������IP
#define 	RDT_RECV_PORT			8003			//RDT���ܶ˶˿ں�
#define		RDT_SEND_PORT			8004			//RDT���Ͷ˶˿ں�
#define		RDT_BEGIN_SEQ			1				//RDT���ݰ���ʼ���кţ����������ݰ����кŲ�ѭ����		
#define		RDT_SENDWIN_LEN			10				//���Ͷ˴��ڴ�С

#define		RDT_PKT_LOSS_RATE		10			//���ɿ����ݴ����Ķ�����
#define		RDT_TIME_OUT			50000		//���ݰ���ʱʱ��
#define		RDT_HEADER_LEN			(4 + 4)		//RDTͷ�곤��
#define 	RDT_DATA_LEN			1000		//RDT�������򳤶�
#define		RDT_PKT_LEN				( RDT_DATA_LEN + RDT_HEADER_LEN )

//RDT������
#define		RDT_CTRL_BEGN			0 //��ʼ��
#define		RDT_CTRL_DATA			1 //���ݰ�
#define 	RDT_CTRL_ACK			2 //ACK��
#define		RDT_CTRL_END			3 //������

//�������������ݰ���״̬
#define		RDT_PKT_ST_INIT			0	//δ����
#define		RDT_PKT_ST_SENT			1	//�ѷ��ͣ�δȷ��
#define		RDT_PKT_ST_ACKED		2	//��ȷ��
#define		RDT_PKT_ST_TMOUT		3	//��ʱ

/*
	�������������ݰ��Ľṹ��
*/
typedef struct _STATE_PKT
{
	struct timeval send_time;
	int pkt_seq;
	int pkt_len;
	int state; //��ʶ���ݰ���״̬
	char rdt_pkt[RDT_PKT_LEN];
}STATE_PKT;

/*
	�������ڵĽṹ��
*/
typedef struct _SLD_WIN
{
	int win_len;							//�������ڳ���
	int send_left;							//�������ڵ����
	int send_right;							//�������ڵ��Ҷ�
	pthread_mutex_t lock; 					//�������ڻ���������ֻ֤��һ���߳��ڷ��ʷ��ʹ����е�����
	STATE_PKT rdt_pkts[RDT_SENDWIN_LEN]; 	//�����е����ݰ�
}SLD_WIN;


/*
	RDT packet format: |CTRL|SEQ|...DATA...|
	�����ݷ�װ��RDT���ݰ���ͷ��ֻ��������������к������п�����������ʶRDT���ݰ�����,���к����Ǵ����ݰ������кš�
	����RDT���ݰ�����
*/
int pack_rdt_pkt( char *data_buf, char *rdt_pkt, int data_len, int seq_num, int flag );



/*
	RDT packet format: |CTRL|SEQ|...DATA...|
	
	�����ݰ����װ��
	����RDT���е����ݳ���
*/
int unpack_rdt_pkt( char *data_buf, char *rdt_pkt, int pkt_len, int *seq_num, int *flag );



/*
	ģ�ⲻ�ɿ����ݴ��䣬��һ���ĸ��ʣ�RDT_PKT_LOSS_RATE���������ݰ�
*/
void udt_sendto( int sock_fd, char *pkt, int pkt_len, int flags, struct sockaddr *recv_addr, int addr_len );



/*
	��� (time_1 - time_2) �Ƿ񳬹��趨ʱ��(RDT_TIME_OUT)��
	�����ʱ����1�����򷵻�0��
*/
int time_out( struct timeval time_1, struct timeval time_2 );

#endif

