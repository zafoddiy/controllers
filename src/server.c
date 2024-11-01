#include "controllers.h"

int main() {
    int sockfd, i;
    struct sockaddr_in server_addr, client_addr[CONTR_NUM];
    char buffer[BUFFER_SIZE];
    socklen_t client_addr_len[CONTR_NUM];
    for (i = 0; i < CONTR_NUM; i++) {
        client_addr_len[i] = sizeof(client_addr[i]);
    }

    // Create socket
    sockfd = create_socket(sockfd);

    // Create timeout, recvfrom times out after 10 sec
    struct timeval timeout;
    timeout.tv_sec = 10;
    timeout.tv_usec = 0;
    timeout_declare_err(sockfd, timeout);

    // Server address setup
    server_addr = server_setup(AF_INET, SERVER_IP, PORT);

    // Bind the socket
    bind_check(bind(sockfd, (const struct sockaddr *)&server_addr, sizeof(server_addr)), sockfd);

    printf("...Server initialized on port %d...\n", PORT);

    // Initialise controller connection to the server
    char ping_msg[BUFFER_SIZE];
    Controller contr;
    int ping_loc = register_controller(sockfd, contr, client_addr, client_addr_len, ping_msg);
    if (ping_loc == -1)
    {
        perror("No ping controller found");
        close(sockfd);
        exit(-1);
    }

    // Check if the received message is "ping" and send "ping" to powerpack and cooling
    send_ping(ping_msg, ping_loc, sockfd, client_addr, client_addr_len);

    // Receive "pong" from listening clients
    process_pong(ping_loc, sockfd, contr, client_addr, client_addr_len);

    close(sockfd);
    return 0;
}

