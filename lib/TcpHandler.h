//
// Created by Administrator on 2022/6/4.
//

#ifndef SOCKETBIND_TCPHANDLER_H
#define SOCKETBIND_TCPHANDLER_H

#include <string>
#include <thread>
#include "TcpBindEnum.h"
#include "TcpMessageHandler.h"
#include <WinSock2.h>
#include <Windows.h>
#pragma comment(lib, "ws2_32.lib")

using std::string;
using std::thread;

namespace TcpBind {

    class TcpHandler {
    private:
    public:
        explicit TcpHandler(string ip="", int port=-1, TCPBIND_TYPE tcpType=TCPBIND_CLIENT);
        void setIP(string socketIP);
        void setPort(int socketPort);
        bool start();
        TCPBIND_ERROR getLastError();
        bool isConnected();
        bool isAsync();
        void setAsync(bool async);


    private:
        void setLastError(TCPBIND_ERROR error);
        bool initSocketClient();
        bool initSocketHost();
        bool verifyInitParams();

    private:
        TCPBIND_ERROR lastError;
        TCPBIND_TYPE tcpType;
        string ip;
        int port;
        SOCKET socketObject;
        sockaddr_in addressInfo;
        thread clientThread;
        TcpMessageHandler *clientHandler;
        bool async;
    };

} // TcpBind

#endif //SOCKETBIND_TCPHANDLER_H
