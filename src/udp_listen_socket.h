#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>
#define BUFSIZE 100

class CudpListenSocket{
public:
    CudpListenSocket();
    ~CudpListenSocket();
    void Initialization(uint16_t port, const char * target_ip);
    int receive();
    int sendMessage(const char * msg);

public:
    int sock;
    sockaddr_in serveraddr, clientaddr;
    sockaddr_in peeraddr;
    int addrlen;
    char buf[BUFSIZE + 1];
};