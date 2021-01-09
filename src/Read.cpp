#include "../include/Read.h"

Read::Read(ConnectionHandler *connection): connectionHandler(connection) {

}

bool Read::read() {
    while(true){
        char recieved[4];
        if (!connectionHandler->getBytes(recieved, sizeof(recieved))) {
            std::cout << "Disconnected. Exiting... read \n" << std::endl;
            break;
        }
        short opcode = connectionHandler->bytesToShort(recieved,0);
        std::cout<<opcode<<std::endl;
        if (opcode == 13) {

            break;
        }
        if(opcode==12){}
    }
    return false;
}
