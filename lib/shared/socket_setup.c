#include "controllers.h"

int create_socket(int sockfd)
{
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    return sockfd;
}

struct sockaddr_in server_setup(int fam_val, char *addr_val, int port_val)
{
    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = fam_val;
    server.sin_addr.s_addr = inet_addr(addr_val);
    server.sin_port = htons(port_val);
    return server;
}