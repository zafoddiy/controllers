/**
 * File:        pong.c
 * Author:      Elias Sepp
 * Created:     14.10.2024
 * Last edit:   24.08.2026
 *
 * Description: File relating to functions handled in the pong controllers.
 */
#include "controllers.h"

/**
 * Function:       receive_ping
 *
 * Description:    Listens in an infinite loop until correct ping message
 *                 is received.
 *
 * Parameters:     sockfd - int, file descriptor of socket
 *                 buffer - string, buffer meant for the message to be received
 *                 server_addr - sockaddr_in, address of incoming server
 *                 server_addr_len - socklen_t, size of incoming server's address
 *
 * Return:         None
 */
void receive_ping(int sockfd, char* buffer, struct sockaddr_in server_addr, socklen_t server_addr_len)
{
    do {
        int n = recvfrom(sockfd, buffer, BUFFER_SIZE, 0,
                         (struct sockaddr *)&server_addr, &server_addr_len);
        buffer[n] = '\0';

    } while (strcmp(buffer, "ping") != 0);
}

/**
 * Function:       send_pong
 *
 * Description:    Sends pong message datagram to server.
 *
 * Parameters:     contr - Controller struct, data received from controller
 *                 pong_msg - string, message to be sent to server
 *                 sockfd - int, file descriptor of socket
 *                 server_addr - sockaddr_in, address of incoming server
 *
 * Return:         None
 */
void send_pong(Controller contr, char *pong_msg, int sockfd, struct sockaddr_in server_addr)
{
    strncpy(contr.message, pong_msg, sizeof(contr.message) - 1);
    sendto(sockfd, &contr, sizeof(Controller) + strlen(contr.message), 0, (const struct sockaddr *)&server_addr, sizeof(server_addr));
}