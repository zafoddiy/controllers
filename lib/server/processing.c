/**
 * File:        processing.c
 * Author:      Elias Sepp
 * Created:     16.10.2024
 * Last edit:   24.08.2026
 *
 * Description: Server functions for processing datagrams to and from
 *              controllers.
 */
#include "controllers.h"

/**
 * Function:       create_socket
 *
 * Description:    Receives datagram from controller, processes if it
 *                 is a ping-sending controller or not. Error checking
 *                 to ensure only 1 controller is sending pings.
 *
 * Parameters:     sockfd - int, file descriptor of socket
 *                 contr - Controller struct, data received from controller
 *                 client_addr - sockaddr_in, address of incoming client
 *                 client_addr_len - socklen_t, size of incoming client's address
 *                 ping_msg - string, message to be sent to receiving controllers
 *
 * Return:         Integer, index of the ping-sending controller.
 */
int register_controller(int sockfd, Controller contr, struct sockaddr_in *client_addr, socklen_t *client_addr_len, char *ping_msg)
{
    int ping_loc = -1;
    int ping_loc_count = 0;
    for (int i = 0; i < CONTR_NUM; i++){
        int n = recvfrom(sockfd, &contr, sizeof(contr), 0,
                        (struct sockaddr *)&client_addr[i], &client_addr_len[i]);
        timeout_error_check(sockfd);
        printf("Registered controller: %d\n", contr.id);
        if (contr.id == 1)
        {
            contr.message[strlen(contr.message) + 1] = '\0';
            strncpy(ping_msg, contr.message, BUFFER_SIZE);
            ping_loc = i;
            ping_loc_count++;

            printf("Received: %s\n", ping_msg);
        }
    }
    if (ping_loc_count > 1) {
        perror("Too many ping drives");
        close(sockfd);
        exit(-1);
    }
    return ping_loc;
}

/**
 * Function:       send_ping
 *
 * Description:    Checks if datagram is a ping and sends to the receiving controllers.
 *
 * Parameters:     ping_msg - string, ping message
 *                 ping_loc - int, index of ping-sending controller
 *                 sockfd - int, socket file descriptor
 *                 client_addr - sockaddr_in, client IP address struct
 *                 client_addr_len - socklen_t, client IP address struct size
 *
 * Return:         None
 */
void send_ping(char* ping_msg, int ping_loc, int sockfd, struct sockaddr_in *client_addr, socklen_t *client_addr_len)
{
    if (strcmp(ping_msg, "ping") == 0) {
        printf("Received 'ping' from drive\n");
        for (int i = 0; i < CONTR_NUM; i++) {
            if (i == ping_loc) {continue;};
            sendto(sockfd, ping_msg, strlen(ping_msg), 0,
                        (struct sockaddr *)&client_addr[i], client_addr_len[i]);
            printf("Sent 'ping' to other clients\n");
        }
    }
}

/**
 * Function:       process_pong
 *
 * Description:    Receives pong message from controllers and sends
 *                 to ping-sending controller.
 *
 * Parameters:     ping_loc - int, index of ping-sending controller
 *                 sockfd - int, socket file descriptor
 *                 contr - Controller struct, data received from controller
 *                 client_addr - sockaddr_in, client IP address struct
 *                 client_addr_len - socklen_t, client IP address struct size
 *
 * Return:         None
 */
void process_pong(int ping_loc, int sockfd, Controller contr, struct sockaddr_in *client_addr, socklen_t *client_addr_len)
{
    for (int i = 0; i < CONTR_NUM; i++){
        if (i == ping_loc) {continue;};
        int n = recvfrom(sockfd, &contr, sizeof(Controller) + BUFFER_SIZE, 0,
                        (struct sockaddr *)&client_addr[i], &client_addr_len[i]);
        contr.message[strlen(contr.message) + 1] = '\0';
        printf("Received %s\n", contr.message);
        sendto(sockfd, &contr, sizeof(Controller) + strlen(contr.message), 0,
                        (struct sockaddr *)&client_addr[ping_loc], client_addr_len[ping_loc]);
        printf("Sent %s\n", contr.message);
    }
}