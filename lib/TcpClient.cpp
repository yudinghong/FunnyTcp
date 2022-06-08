//
// Created by Administrator on 2022/6/8.
//

#include "TcpClient.h"

TcpLib::TcpClient::TcpClient(string ip, int port, bool async) :
    m_ip(ip),
    m_port(port),
    m_async(async)
{
    this->m_lastError = TCPLIB_NO_ERROR;
}

TcpLib::TCPLIB_ERROR TcpLib::TcpClient::getLastError() {
    return this->m_lastError;
}

void TcpLib::TcpClient::setIP(string ip) {
    this->m_ip = std::move(ip);
}

void TcpLib::TcpClient::setPort(int port) {
    this->m_port = port;
}

void TcpLib::TcpClient::setAsync(bool async) {
    this->m_async = async;
}

string TcpLib::TcpClient::getIP() {
    return this->m_ip;
}

int TcpLib::TcpClient::getPort() const {
    return this->m_port;
}

bool TcpLib::TcpClient::isAsync() const {
    return this->m_async;
}

bool TcpLib::TcpClient::start() {
    if (!this->isParamsVerified()) return false;
    SocketBase::initWSA();
    sockaddr_in addressInfo;
    socketObject = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (socketObject == INVALID_SOCKET) {
        this->setLastError(TCPLIB_INIT_FAILED);
        return false;
    }
    addressInfo.sin_family = AF_INET;
    addressInfo.sin_port = htons(this->m_port);
    addressInfo.sin_addr.S_un.S_addr = inet_addr(this->m_ip.c_str());
    // socket 连接
    if (connect(socketObject, (SOCKADDR*)&addressInfo, sizeof(addressInfo)) == SOCKET_ERROR) {
        this->setLastError(TCPLIB_CONNECT_TO_HOST_FAILED);
        SocketBase::cleanWSA();
        return false;
    }
    return true;
}

bool TcpLib::TcpClient::startWithResponse(char *response, int responseLength) {
    return false;
}

bool TcpLib::TcpClient::startWithResponse(string response) {
    return false;
}

bool TcpLib::TcpClient::isConnected() {
    SocketBase::isSocketConnected(this->socketObject);
    return false;
}

bool TcpLib::TcpClient::initClient() {
    return false;
}

void TcpLib::TcpClient::setLastError(TcpLib::TCPLIB_ERROR error) {

}

bool TcpLib::TcpClient::isParamsVerified() {
    if (this->m_ip.size() == 0) {
        this->setLastError(TCPLIB_INIT_WITHOUT_IP);
        return false;
    }
    if (this->m_port <= 0) {
        this->setLastError(TCPLIB_INIT_WITHOUT_PORT);
        return false;
    }
    return true;
}
