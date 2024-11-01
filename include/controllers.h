#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <sys/time.h>
#include <arpa/inet.h> 
#include <unistd.h> 
#include <errno.h>
  
#define SERVER_IP "127.0.0.1"  
#define PORT 5000
#define BUFFER_SIZE 1024
#define CONTR_NUM 3

typedef struct controller{
    int id;
    char message[BUFFER_SIZE];
    long timestamp;
}Controller;

void timeout_declare_err(int, struct timeval);

void bind_check(int, int);

void timeout_error_check(int);

int create_socket(int);

struct sockaddr_in server_setup(int, char*, int);

int register_controller(int, Controller, struct sockaddr_in*, socklen_t*, char*);

void send_ping(char*, int, int, struct sockaddr_in*, socklen_t*);

void process_pong(int, int, Controller, struct sockaddr_in*, socklen_t*);

void receive_pongs(int, Controller, struct sockaddr_in, socklen_t, struct timeval);

void receive_ping(int, char*, struct sockaddr_in, socklen_t);

void send_pong(Controller, char*, int, struct sockaddr_in);