//
// Created by Administrator on 2022/6/5.
//

#ifndef SOCKETBIND_TCPMESSAGEHANDLER_H
#define SOCKETBIND_TCPMESSAGEHANDLER_H

#include <WinSock2.h>
#include <Windows.h>
#pragma comment(lib, "ws2_32.lib")
#include <atomic>
using std::atomic;

namespace TcpBind {
    class TcpMessageHandler {
    public:
        TcpMessageHandler(SOCKET socketObject, int bufLength = 255, bool isAsync=false);
        void debugMessage();
        void setConnected(bool connected);
    private:
        SOCKET socketObject;
        int bufLength;
        bool async;
        atomic<bool> connected;
    };
}

#endif //SOCKETBIND_TCPMESSAGEHANDLER_H
