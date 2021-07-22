#include "net_exp.h"

int main(int argc, char **argv) {

    /* 建立服务端套接字 */
    int server_sockfd;
    if ((server_sockfd = socket(/*Placeholder*/ AF_INET,SOCK_STREAM,0)) < 0) {
        perror("socket error");
        return 1;
    }

    /* 监听端口 */
    struct sockaddr_in server_addr;
    memset(&server_addr, /*Placeholder*/ 0,sizeof(server_addr));
    server_addr.sin_family = /*Placeholder*/ AF_INET;
    server_addr.sin_addr.s_addr = /*Placeholder*/ INADDR_ANY;
    server_addr.sin_port = /*Placeholder*/ htons(TCP_SERVER_PORT);

    if (bind(/*Placeholder*/ server_sockfd,(struct sockaddr *)&server_addr,sizeof(server_addr)) == -1) {
        perror("bind error");
        return 1;
    }

    if (listen(/*Placeholder*/ server_sockfd,1) == -1) {
        perror("listen error");
        return 1;
    };

    /* 建立tcp连接 */
    int client_sockfd;
    struct sockaddr_in client_addr;
    unsigned int client_addr_len = sizeof(struct sockaddr_in);
    if ((client_sockfd = accept(/*Placeholder*/ server_sockfd,(struct sockaddr *)&client_addr,&client_addr_len)) == -1) {
        perror("accept error");
        return 1;
    }
    printf("accept client %s:%d\n", inet_ntoa(client_addr.sin_addr), client_addr.sin_port);
    char msg[1024];
	while(1){
		/* 接收数据 */
    	size_t pkt_len;
    	char recv_buf[TCP_BUF_LENGTH];
    	pkt_len = recv(/*Placeholder*/ client_sockfd,recv_buf,TCP_BUF_LENGTH,0);

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
	    printf("[TCP RECEIVER] receive msg[%d bytes]\n", (int)pkt_len);
	    printf("\t%s\n", recv_buf);
	
	    /* 发送信息 */
	    memset(msg,0,sizeof(char)*1024);
	    gets(msg);
	    
	    if (send(/*Placeholder*/ client_sockfd,recv_buf,pkt_len,0) == -1) {
	        perror("send error");
	        return 1;
	    }
	}
    

    /* 关闭套接字 */
    close(/*Placeholder*/ server_sockfd);
    close(/*Placeholder*/ client_sockfd);

    return 0;
}
