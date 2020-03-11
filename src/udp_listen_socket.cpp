#include "udp_listen_socket.h"

CudpListenSocket::CudpListenSocket() {
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    bzero(&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;

    clientaddr.sin_family = AF_INET;
    clientaddr.sin_addr.s_addr = htonl(INADDR_ANY);

}

CudpListenSocket::~CudpListenSocket() {
    close(sock);
}

void CudpListenSocket::Initialization(uint16_t port, const char * target_ip) {
    serveraddr.sin_port = htons(port);
    serveraddr.sin_addr.s_addr = inet_addr(target_ip);

    clientaddr.sin_port = htons(port);
    clientaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    bind(sock, (struct sockaddr *)&clientaddr, sizeof(clientaddr));
}

int CudpListenSocket::receive() {
    int retval;
    retval = recvfrom(sock, buf, BUFSIZE, 0, (sockaddr *)&peeraddr, (socklen_t *)addrlen);
    return retval;
}