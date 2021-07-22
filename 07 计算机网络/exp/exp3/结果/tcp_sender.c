#include "net_exp.h"

int main(int argc, char **argv) {

    /* 建立套接字 */
    int sockfd;
    if ((sockfd = socket(/*Placeholder*/ AF_INET,SOCK_STREAM,0)) == -1) {
        perror("socket error");
        return 1;
    }

    /* 建立tcp连接 */
    struct sockaddr_in server_addr;
    memset(&server_addr,/*Placeholder*/ 0,sizeof(server_addr));
    server_addr.sin_family = /*Placeholder*/ AF_INET;
    server_addr.sin_addr.s_addr = /*Placeholder*/ INADDR_ANY;
    server_addr.sin_port =/*Placeholder*/ htons(TCP_SERVER_PORT);

    if (connect(/*Placeholder*/ sockfd,(struct sockaddr *)&server_addr,sizeof(server_addr)) < 0) {
        perror("connect error");
        return 1;
    }
    char msg[1024];
	while(1){
		   /* 发送数据 */
		   
		   memset(msg,0,sizeof(char)*1024);
	    gets(msg);
	    send(/*Placeholder*/ sockfd,msg,strlen(msg)+1,0);

	    /* 接收数据 */
	    char recv_buf[TCP_BUF_LENGTH];
	    size_t pkt_len = 0;
	    pkt_len = recv(/*Placeholder*/ sockfd,recv_buf,TCP_BUF_LENGTH,0);

	    if (pkt_len == -1) {
	        perror("recv error");
	        return 1;
	    }

	    if (pkt_len == 0) {
	        /* 连接被远端关闭 */
	        printf("finish\n");
	        return 0;
	    }

	    /* 输出接收到的信息 */
	    recv_buf[pkt_len] = '\0';
	    printf("[TCP SENDER] receive echo msg[%d bytes]\n", (int)pkt_len);
	    printf("\t%s\n", recv_buf);
	}


    /* 关闭套接字 */
    close(/*Placeholder*/ sockfd);

    return 0;
}
