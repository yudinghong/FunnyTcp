#include <iostream>

#include "lib/TcpClient.h"

using namespace TcpLib;

int main() {
    TcpClient *tcpClient = new TcpClient("127.0.0.1", 11111);
    tcpClient->start();
    tcpClient->isConnected();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
