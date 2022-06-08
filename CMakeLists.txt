cmake_minimum_required(VERSION 3.22)
project(socketbind)

set(CMAKE_CXX_STANDARD 11)

add_executable(socketbind main.cpp lib/TcpLibEnum.h lib/TcpMessageHandler.cpp lib/TcpMessageHandler.h lib/TcpClient.cpp lib/TcpClient.h lib/TcpServer.cpp lib/TcpServer.h lib/SocketBase.cpp lib/SocketBase.h)
