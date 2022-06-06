#include <iostream>

#include "./lib/TcpHandler.h"

using TcpBind::TcpHandler;

int main() {
    TcpHandler *tcpClient = new TcpHandler("127.0.0.1", 11111);
    tcpClient->start();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
