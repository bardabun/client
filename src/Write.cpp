
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
        short opcode;
        bool sent;
        if (line == "LOGOUT") {
            opcode = 4;
            isThereMoreMessage = false;
            message = line;
        }
        if (line == "MYCOURSES") {
            opcode = 11;
            isThereMoreMessage = false;
            message = line;
        }

        if (!isThereMoreMessage) { // then must be 4 | 11
            sent = connectionHandler->sendFrame(opcode);
        } else {

            // more message
            while (line[indexMessage] != ' ') {
                message += line[indexMessage];
                indexMessage++;
            }
            std::string restOfTheMessage = line.substr(indexMessage + 1);
            //1,2,3,8 same func
            if (message == "ADMINREG") {
                //rest of message is "username pass"
                sent = connectionHandler->sendFrame(restOfTheMessage, 1);
            } else if (message == "STUDENTREG") {
                //rest of message is "username pass"
                sent = connectionHandler->sendFrame(restOfTheMessage, 2);
            } else if (message == "LOGIN") {
                //rest of message is "username pass"
                sent = connectionHandler->sendFrame(restOfTheMessage, 3);
            } else if (message == "STUDENTSTAT") {
                sent = connectionHandler->sendFrame(restOfTheMessage, 8);
            } else
                //5 ,6 ,7, 9 ,10 same func getting op and course num .
            if (message == "COURSEREG") {
                //rest of message is coursenum
                std::stringstream courseNum(restOfTheMessage);
                short cNum = 0;
                courseNum >> cNum;  // converting string to short
                sent = connectionHandler->sendFrameShort(cNum, 5);
            } else if (message == "KDAMCHECK") {
                std::stringstream courseNum(restOfTheMessage);
                short cNum = 0;
                courseNum >> cNum;  // converting string to short
                sent = connectionHandler->sendFrameShort(cNum, 6);
            } else if (message == "COURSESTAT") {
                std::stringstream courseNum(restOfTheMessage);
                short cNum = 0;
                courseNum >> cNum;  // converting string to short
                sent = connectionHandler->sendFrameShort(cNum, 7);
            } else if (message == "ISREGISTERED") {
                std::stringstream courseNum(restOfTheMessage);
                short cNum = 0;
                courseNum >> cNum;  // converting string to short
                sent = connectionHandler->sendFrameShort(cNum, 9);
            } else if (message == "UNREGISTER") {
                std::stringstream courseNum(restOfTheMessage);
                short cNum = 0;
                courseNum >> cNum;  // converting string to short
                sent = connectionHandler->sendFrameShort(cNum, 10);
            }


        }
        if (!sent) {
            std::cout << "Disconnected. Exiting... write \n" << std::endl;
            break;
        }

    }
    return false;
}


