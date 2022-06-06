cmake_minimum_required(VERSION 3.22)
project(socketbind)

set(CMAKE_CXX_STANDARD 11)

add_executable(socketbind main.cpp lib/TcpHandler.cpp lib/TcpHandler.h lib/TcpBindEnum.h lib/TcpMessageHandler.cpp lib/TcpMessageHandler.h)
