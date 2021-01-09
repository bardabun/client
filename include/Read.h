#ifndef CLIENT_READ_H
#define CLIENT_READ_H

#include "../include/connectionHandler.h"
#include <thread>
class Read{
private:
    ConnectionHandler *connectionHandler;
    bool terminate;

public:
    Read(ConnectionHandler *connection, bool Terminate );
    bool read();
};
#endif //CLIENT_READ_H
