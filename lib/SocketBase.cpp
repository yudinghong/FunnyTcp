//
// Created by Administrator on 2022/6/8.
//

#include "SocketBase.h"

bool SocketBase::initWSA() {
    WSADATA wsaData;
    WORD socketVersion = MAKEWORD(2, 2);
    if (WSAStartup(socketVersion, &wsaData) != 0) {
        return false;
    }
    return true;
}

bool SocketBase::isSocketConnected(SOCKET socket) {
    bool ret = false;
    int len;
    int retError = getsockopt(socket, IPPROTO_TCP, SO_ACCEPTCONN, (char *)(&ret), &len);
    return false;
}

void SocketBase::cleanWSA() {
    WSACleanup();
}
