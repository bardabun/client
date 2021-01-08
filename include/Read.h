#ifndef CLIENT_READ_H
#define CLIENT_READ_H

#include "../include/connectionHandler.h"
#include <thread>
class Read{
private:
    ConnectionHandler *connectionHandler;

public:
    Read(ConnectionHandler *connection );
    bool read();
};
#endif //CLIENT_READ_H
