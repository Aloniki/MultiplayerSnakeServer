//
//  Receiver.hpp
//  GameServer
//
//  Created by Apple on 4/13/16.
//  Copyright © 2016 Aloniki's Study. All rights reserved.
//

#ifndef Receiver_hpp
#define Receiver_hpp

#include "GameHeaders.h"
#include <vector>
#include <queue>
#include <pthread.h>
#include <iostream>

class Receiver {
protected:
    int connectfd;                      //socket connection identifier
    
    size_t recvCount;                   //the count of received data
    size_t packetLength;                //the length of a packet
    char recv[MAXLINE];                 //saves the data in one read
    char buf[MAXLINE];                  //saves the hole unpakcet data
    char head[DATALENGTH + 1];          //saves the packet length
    
    std::queue<DataPacket>* packetQueue; //saves the formal packet
public:
    Receiver(int fd, std::queue<DataPacket>* packetQueue){
        this->connectfd = fd;
        this->packetQueue = packetQueue;
        this->recvCount = 0;
        this->packetLength = 0;
    }
    void receive();
    void addToPacketQueue(std::string*);
};

#endif /* Receiver_hpp */
