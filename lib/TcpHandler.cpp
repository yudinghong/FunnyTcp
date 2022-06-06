//
// Created by Administrator on 2022/6/4.
//

#include "TcpHandler.h"

using std::move;

namespace TcpBind {
    TcpHandler::TcpHandler(string ip, int port, TCPBIND_TYPE tcpType) :
        ip(move(ip)),
        port(port),
        tcpType(tcpType)
    {
        this->lastError = TCPBIND_NO_ERROR;
        this->clientHandler = nullptr;
        this->async = false;
    }

    void TcpHandler::setIP(string socketIP) {
        this->ip = move(socketIP);
    }

    void TcpHandler::setPort(int socketPort) {
        this->port = socketPort;
    }

    bool TcpHandler::start() {
        WSADATA wsaData;
        WORD socketVersion = MAKEWORD(2, 2);
        if (WSAStartup(socketVersion, &wsaData) != 0) {
            return false;
        }
        if (tcpType == TCPBIND_CLIENT) {
            return this->initSocketClient();
        }
        else {
            return this->initSocketHost();
        }
    }

    TCPBIND_ERROR TcpHandler::getLastError() {
        return this->lastError;
    }

    bool TcpHandler::initSocketClient() {
        // 校验参数
        bool verifySuccess = this->verifyInitParams();
        if (!verifySuccess) {
            return false;
        }
        // 设置socket参数
        socketObject = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if (socketObject == INVALID_SOCKET) {
            this->setLastError(TCPBIND_INIT_FAILED);
            return false;
        }
        addressInfo.sin_family = AF_INET;
        addressInfo.sin_port = htons(this->port);
        addressInfo.sin_addr.S_un.S_addr = inet_addr(this->ip.c_str());
        // socket 连接
        if (connect(socketObject, (SOCKADDR*)&addressInfo, sizeof(addressInfo)) == SOCKET_ERROR) {
            this->setLastError(TCPBIND_CONNECT_TO_HOST_FAILED);
            return false;
        }
        if (this->clientHandler == nullptr) {
            this->clientHandler = new TcpMessageHandler(this->socketObject, 255, false);
        }
        this->clientThread = thread(&TcpMessageHandler::debugMessage, this->clientHandler);
        this->clientThread.join();
        return true;
    }

    bool TcpHandler::initSocketHost() {
        return false;
    }

    void TcpHandler::setLastError(TCPBIND_ERROR error) {

    }

    bool TcpHandler::verifyInitParams() {
        if (this->ip.empty()) {
            this->setLastError(TCPBIND_INIT_WITHOUT_IP);
            return false;
        }
        if (this->port <= 0) {
            this->setLastError(TCPBIND_INIT_WITHOUT_PORT);
            return false;
        }
        return true;
    }

    bool TcpHandler::isConnected() {
//        struct tcp_info info;
//        int len=sizeof(info);
//        getsockopt(sock, IPPROTO_TCP, TCP_INFO, &info, (socklen_t *)&len);
//        if((info.tcpi_state==TCP_ESTABLISHED))  则说明未断开  else 断开
        return false;
    }

    void TcpHandler::setAsync(bool async) {
        this->async = async;
    }

    bool TcpHandler::isAsync() {
        return this->async;
    }

} // TcpBind