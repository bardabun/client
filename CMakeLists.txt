cmake_minimum_required(VERSION 3.17)
project(client)

set(CMAKE_CXX_STANDARD 14)

add_executable(client main.cpp include/Write.h include/Read.h src/Read.cpp src/Write.cpp src/Client.cpp include/Client.h)