
#include "../include/Write.h"

Write::Write(ConnectionHandler *connect) {

}

bool Write::write() {
    while (true) {
        const short bufsize = 1024;
        char buf[bufsize];
        std::cin.getline(buf, bufsize);
        std::string line(buf);

        //need a function that makes this string to a bytes array
        //then send it by using - connectionhandler.sendbytes - sends to the server
        std::string message;
        bool isThereMoreMessage = true;
        int indexMessage = 0;
        if (line == "LOGOUT" || line == "MYCOURSES") {
            isThereMoreMessage = false;
            message = line;
        }
        if (isThereMoreMessage) {
            while (line[indexMessage] != ' '){
               message+= line[indexMessage];
                indexMessage++;
        }
            std::string restOfTheMessage;
            if(message== "ADMINREG"){
                restOfTheMessage= line.substr(indexMessage+1);
               // connectionHandler.sendFrame(restOfTheMessage,1);
                //a func we need to make - gets string and short opcode
                //
            }

//        bool sent;
//        std::string sub = "";
//        if (command=="ADMINREG") {
//



        }
        return false;
    }
}


