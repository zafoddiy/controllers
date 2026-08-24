/**
 * File:        errors.c
 * Author:      Elias Sepp
 * Created:     14.10.2024
 * Last edit:   24.08.2026
 *
 * Description: File for error handling functions.
 */
#include "controllers.h"

/**
 * Function:       timeout_declare_err
 *
 * Description:    Sets a timeout on socket file descriptor with
 *                 specific time.
 *
 * Parameters:     sockfd - int, file descriptor of socket
 *                 timeout - tv struct, time in seconds and microseconds
 *
 * Return:         None
 */
void timeout_declare_err(int sockfd, struct timeval timeout)
{
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) < 0) {
        perror("Socket timeout setup failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
}

/**
 * Function:       bind_check
 *
 * Description:    Checks if socket file descriptor is bound properly.
 *
 * Parameters:     bind_check - int, return value of built-in socket bind function
 *                 sockfd - int, socket file descriptor
 *
 * Return:         None
 */
void bind_check(int bind_check, int sockfd)
{
    if (bind_check < 0) {
        perror("Socket bind failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
}

/**
 * Function:       timeout_error_check
 *
 * Description:    Checks if connection has timed out.
 *
 * Parameters:     sockfd - int, file descriptor of socket
 *
 * Return:         None
 */
void timeout_error_check(int sockfd)
{
    if (errno == EAGAIN || errno == EWOULDBLOCK) {
        perror("Connection timed out after 10s");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
}