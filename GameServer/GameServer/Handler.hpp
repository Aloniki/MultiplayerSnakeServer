//
//  Handler.hpp
//  GameServer
//
//  Created by Apple on 4/14/16.
//  Copyright © 2016 Aloniki's Study. All rights reserved.
//

#ifndef Handler_hpp
#define Handler_hpp

#include "GameHeaders.h"
#include <queue>
#include <iostream>
#include "RoomListManager.hpp"
#include "PortsManager.hpp"
#include <unistd.h>

/*
 this is class define the basic hanlder, specific handlers can inherit this class and over write
 the handle() method to cater for different needs
 */
class Handler {
protected:
    int connectfd;                      //socket connection identifier
    std::queue<DataPacket>* packetQueue; //saves the formal packet
    
    RoomListManager* RM;        //room list manager instance
    PortsManager* PM;           //ports manager instance
    
public:
    Handler(int fd, std::queue<DataPacket>* packetQueue){       //structor
        this->connectfd = fd;
        this->packetQueue = packetQueue;
        this->RM = RoomListManager::getRoomListManager();
        this->PM = PortsManager::getPortsManager();
    };
    virtual void handle(){};    //virtual handle method
    DataPacket pickFromPacketQueue();   //pick the top data packet form the queue
    
};

#endif /* Handler_hpp */
