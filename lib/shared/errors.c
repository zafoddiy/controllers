#include "controllers.h"

void timeout_declare_err(int sockfd, struct timeval timeout)
{
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) < 0) {
        perror("Socket timeout setup failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
}

void bind_check(int bind_check, int sockfd)
{
    if (bind_check < 0) {
        perror("Socket bind failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
}

void timeout_error_check(int sockfd)
{
    if (errno == EAGAIN || errno == EWOULDBLOCK) {
        perror("Connection timed out after 10s");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
}