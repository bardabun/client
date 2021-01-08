#ifndef CLIENT_WRITE_H
#define CLIENT_WRITE_H


#include "../include/connectionHandler.h"
#include <thread>


class Write{
private:
    ConnectionHandler *connectionHandler;
public:
    Write(ConnectionHandler *connect );
    bool write();
};
#endif //CLIENT_WRITE_H
