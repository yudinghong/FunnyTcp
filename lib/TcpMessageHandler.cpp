//
// Created by Administrator on 2022/6/5.
//

#include "TcpMessageHandler.h"
#include <iostream>
#include <string>
#include <thread>
#include <chrono>

using std::string;
using std::thread;
using std::chrono::seconds;
using std::chrono::microseconds;

TcpLib::TcpMessageHandler::TcpMessageHandler(SOCKET socketObject, int bufLength, bool isAsync) :
    socketObject(std::move(socketObject)),
    bufLength(bufLength),
    async(async),
    connected(false)
{

}

void TcpLib::TcpMessageHandler::debugMessage() {
    char *buf = new char[this->bufLength];
    while (true) {
        if (!connected) {
            break;
        }
        int receiveLen = 0;
        receiveLen = recv(this->socketObject, buf, this->bufLength, 0);
        if (receiveLen != 0) {
            std::cout << string(buf, receiveLen) << std::endl;
        }
        std::this_thread::sleep_for(microseconds(100));
    }
    delete[] buf;
}

void TcpLib::TcpMessageHandler::setConnected(bool connected) {
    this->connected = connected;
}
