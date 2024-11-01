#include "controllers.h"

void receive_pongs(int sockfd, Controller contr, struct sockaddr_in server_addr, socklen_t server_addr_len, struct timeval curr_time)
{
    long long curr_time_msec = curr_time.tv_sec*1000LL + curr_time.tv_usec/1000;
    for (int i = 0; i < 2; i++) {
        int n = recvfrom(sockfd, &contr, sizeof(Controller) + BUFFER_SIZE, 0,
             (struct sockaddr *)&server_addr, &server_addr_len);
        if (n < 0 && (errno == EAGAIN || errno == EWOULDBLOCK)) {
            perror("Connection timed out after 10s");
            close(sockfd);
            exit(EXIT_FAILURE);
        }
        contr.message[strlen(contr.message) + 1] = '\0';
        printf("Received: %s with controller id: %d\n", contr.message, contr.id);
        printf("Ping time: %lld ms\n", contr.timestamp - curr_time_msec);
    }
}