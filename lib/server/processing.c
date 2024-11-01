#include "controllers.h"

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