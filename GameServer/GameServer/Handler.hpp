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


class Handler {
protected:
    int connectfd;                      //socket connection identifier
    std::queue<DataPacket>* packetQueue; //saves the formal packet
    
    RoomListManager* RM;
    PortsManager* PM;
    
public:
    Handler(int fd, std::queue<DataPacket>* packetQueue){
        this->connectfd = fd;
        this->packetQueue = packetQueue;
        this->RM = RoomListManager::getRoomListManager();
        this->PM = PortsManager::getPortsManager();
    };
    virtual void handle(){};
    DataPacket pickFromPacketQueue();
    
};

#endif /* Handler_hpp */
