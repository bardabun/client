cmake_minimum_required(VERSION 3.17)
project(client)

set(CMAKE_CXX_STANDARD 14)
link_libraries("-lboost_system")
link_libraries(-pthread)
add_executable(client include/Write.h include/Read.h src/Read.cpp src/Write.cpp src/Client.cpp include/Client.h include/connectionHandler.h src/connectionHandler.cpp)