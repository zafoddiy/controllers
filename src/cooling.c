
#include "controllers.h"

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    socklen_t server_addr_len = sizeof(server_addr);
    char buffer[BUFFER_SIZE];

    // Create socket
    sockfd = create_socket(sockfd);

    // Server address setup
    server_addr = server_setup(AF_INET, SERVER_IP, PORT);

    // Register with server
    Controller contr;
    contr.id = 3;
    struct timeval curr_time;
    sendto(sockfd, &contr, sizeof(contr), 0, (const struct sockaddr *)&server_addr, sizeof(server_addr));

    // Listen for "ping" messages
    receive_ping(sockfd, buffer, server_addr, server_addr_len);

    // Get time after receiving ping
    gettimeofday(&curr_time, NULL);
    contr.timestamp = curr_time.tv_sec*1000LL + curr_time.tv_usec/1000;

    printf("Received: %s\n", buffer);

    // Send pong with timestamp, controller ID and pong message
    send_pong(contr, "pong from powerpack", sockfd, server_addr);

    close(sockfd);
    return 0;
}