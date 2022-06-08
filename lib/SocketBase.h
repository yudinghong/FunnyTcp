//
// Created by Administrator on 2022/6/8.
//

#ifndef SOCKETBIND_SOCKETBASE_H
#define SOCKETBIND_SOCKETBASE_H

#include <WinSock2.h>
#include <Windows.h>
#pragma comment(lib, "ws2_32.lib")

class SocketBase {
public:
    static bool initWSA();
    static void cleanWSA();
    static bool isSocketConnected(SOCKET socket);
};


#endif //SOCKETBIND_SOCKETBASE_H
