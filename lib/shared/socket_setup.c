/**
 * File:        socket_setup.c
 * Author:      Elias Sepp
 * Created:     14.10.2024
 * Last edit:   24.08.2026
 *
 * Description: File for socket setup functions.
 */
#include "controllers.h"

/**
 * Function:       create_socket
 *
 * Description:    Creates socket and handles errors if creation failed.
 *
 * Parameters:     sockfd - int, file descriptor of socket
 *
 * Return:         Integer value of created socket file descriptor, unique.
 */
int create_socket(int sockfd)
{
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    return sockfd;
}

/**
 * Function:       timeout_declare_err
 *
 * Description:    Sets a timeout on socket file descriptor with
 *                 specific time.
 *
 * Parameters:     fam_val - address family, IPv4 in this case
 *                 addr_val - string, IP address
 *                 port_val - integer, port value
 *
 * Return:         sockaddr_in struct, contains server port, IP address.
 */
struct sockaddr_in server_setup(int fam_val, char *addr_val, int port_val)
{
    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = fam_val;
    server.sin_addr.s_addr = inet_addr(addr_val);
    server.sin_port = htons(port_val);
    return server;
}