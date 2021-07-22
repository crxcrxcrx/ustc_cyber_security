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


#define		RDT_SERVER_ADDRESS		"127.0.0.1"		//RDT��������IP
#define 	RDT_RECV_PORT			8003            //RDT���ն˶˿ں�
#define		RDT_SEND_PORT			8004            //RDT���Ͷ˶˿ں�
#define		RDT_BEGIN_SEQ			1               //RDT���ݰ���ʼ���кţ����������ݰ����кŲ�ѭ����

#define		RDT_PKT_LOSS_RATE		10				//���ɿ����ݴ����Ķ�����
#define		RDT_TIME_OUT			5000            //���ݰ���ʱʱ��
#define		RDT_HEADER_LEN			(4 + 4)         //RDTͷ�곤��
#define 	RDT_DATA_LEN			1000            //RDT�������򳤶�
#define		RDT_PKT_LEN				( RDT_DATA_LEN + RDT_HEADER_LEN )	//RDT�����ݰ�����

//RDT������
#define		RDT_CTRL_BEGN			0	//��ʼ��
#define		RDT_CTRL_DATA			1   //���ݰ�
#define 	RDT_CTRL_ACK			2   //ACK��
#define		RDT_CTRL_NACK			3   //NACK��
#define		RDT_CTRL_END			4	//������


/*
	RDT packet format: |CTRL|SEQ|...DATA...|
	�����ݷ�װ��RDT���ݰ���ͷ��ֻ��������������к������п�����������ʶRDT���ݰ�����,���к����ǰ��������ݰ������кš�
	��������RDT���ݰ�����
*/
int pack_rdt_pkt( char *data_buf, char *rdt_pkt, int data_len, int seq_num, int flag );

/*
	RDT packet format: |CTRL|SEQ|...DATA...|
	�����ݰ����װ��
	��������RDT���е����ݳ���
*/
int unpack_rdt_pkt( char *data_buf, char *rdt_pkt, int pkt_len, int *seq_num, int *flag );

/*
	ģ�ⲻ�ɿ����ݴ��䣬��һ���ĸ��ʣ�RDT_PKT_LOSS_RATE���������ݰ���������ʽ��recvfromһ��
*/
void udt_sendto( int sock_fd, char *pkt, int pkt_len, int flags, struct sockaddr *recv_addr, int addr_len );

#endif
