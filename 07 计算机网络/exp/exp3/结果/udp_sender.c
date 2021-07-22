#include "net_exp.h"

int main(int argc, char **argv) {

    /* 建立套接字 */
    int socket_fd;
    if ((socket_fd = socket(/*Placeholder*/ AF_INET,SOCK_DGRAM,0)) == -1) {
        perror("socket error");
        return 1;
    }

    /* 发送数据 */
    struct sockaddr_in server_addr;
    memset(&server_addr, /*Placeholder*/ 0,sizeof(server_addr));
    server_addr.sin_family = /*Placeholder*/ AF_INET;
    server_addr.sin_addr.s_addr = /*Placeholder*/ INADDR_ANY;
    server_addr.sin_port = /*Placeholder*/ htons(UDP_SERVER_PORT);

    int counter = 0;
    char send_buf[UDP_BUF_LENGTH];

    while (1) {
        memset(send_buf, sizeof(send_buf), 0);
        printf("sending data packet with #: %d\n", counter);
        sprintf(send_buf, "data packet with #: %d.", counter);
        sendto(/*Placeholder*/ socket_fd,send_buf,UDP_BUF_LENGTH+1,0,(struct sockaddr *)&server_addr,sizeof(server_addr));

        counter++;
        if (counter > 10)
            break;

        sleep(1);
    }

    /* 关闭套接字 */
    close(/*Placeholder*/ socket_fd);

    return 0;
}
