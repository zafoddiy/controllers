#include "controllers.h"

void receive_ping(int sockfd, char* buffer, struct sockaddr_in server_addr, socklen_t server_addr_len)
{
    do {
        int n = recvfrom(sockfd, buffer, BUFFER_SIZE, 0,
                         (struct sockaddr *)&server_addr, &server_addr_len);
        buffer[n] = '\0';

    } while (strcmp(buffer, "ping") != 0);
}

void send_pong(Controller contr, char *pong_msg, int sockfd, struct sockaddr_in server_addr)
{
    strncpy(contr.message, pong_msg, sizeof(contr.message) - 1);
    sendto(sockfd, &contr, sizeof(Controller) + strlen(contr.message), 0, (const struct sockaddr *)&server_addr, sizeof(server_addr));
}