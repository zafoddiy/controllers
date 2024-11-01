#include "controllers.h"

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    socklen_t server_addr_len = sizeof(server_addr);
    char buffer[BUFFER_SIZE];

    // Create socket
    sockfd = create_socket(sockfd);

    // Create timeout, recvfrom times out after 10 sec
    struct timeval timeout;
    timeout.tv_sec = 10;
    timeout.tv_usec = 0;
    timeout_declare_err(sockfd, timeout);

    // Server address setup
    server_addr = server_setup(AF_INET, SERVER_IP, PORT);

    // Send "ping" message to server
    Controller contr;
    contr.id = 1;
    strncpy(contr.message, "ping", sizeof(contr.message) - 1);
    struct timeval curr_time;
    gettimeofday(&curr_time, NULL);
    sendto(sockfd, &contr, sizeof(contr), 0, (const struct sockaddr *)&server_addr, sizeof(server_addr));

    // Receive struct data from other controllers
    Controller incoming_contr;
    receive_pongs(sockfd, incoming_contr, server_addr, server_addr_len, curr_time);

    close(sockfd);
    return 0;
}