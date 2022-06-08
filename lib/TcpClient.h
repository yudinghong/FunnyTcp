//
// Created by Administrator on 2022/6/8.
//

#ifndef SOCKETBIND_TCPCLIENT_H
#define SOCKETBIND_TCPCLIENT_H

#include <string>
#include <chrono>
#include "TcpLibEnum.h"
#include "SocketBase.h"

using std::string;

namespace TcpLib {
    class TcpClient {
    public:
        explicit TcpClient(string ip, int port=-1, bool async=false);
        TCPLIB_ERROR getLastError();
        // set params
        void setIP(string ip);
        void setPort(int port);
        void setAsync(bool async);
        // get params
        string getIP();
        int getPort() const;
        bool isAsync() const;
        // start client
        bool start();
        bool startWithResponse(char *response, int responseLength);
        bool startWithResponse(string response);
        // check states
        bool isConnected();

    private:
        bool initClient();
        void setLastError(TCPLIB_ERROR error);
        bool isParamsVerified();

    private:
        string m_ip;
        int m_port;
        bool m_async;
        TCPLIB_ERROR m_lastError;
        SOCKET socketObject;
    };
}



#endif //SOCKETBIND_TCPCLIENT_H
