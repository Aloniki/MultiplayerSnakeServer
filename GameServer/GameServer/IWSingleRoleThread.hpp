//
//  IWSingleRoleThread.hpp
//  GameServer
//
//  Created by Apple on 4/13/16.
//  Copyright © 2016 Aloniki's Study. All rights reserved.
//

#ifndef IWSingleRoleThread_hpp
#define IWSingleRoleThread_hpp

#include "GameHeaders.h"
#include <string>
#include <vector>
#include <queue>
#include <pthread.h>
#include "Receiver.hpp"
#include "Handler.hpp"
#include "IWClientHandler.hpp"

class IWSingleRoleThread {
protected:
    int connectfd;
    
    std::queue<DataPacket>* packetQueue;
    pthread_t tidReceiver;
    pthread_t tidHandler;
    
    Receiver* receiver;
    Handler* handler;
public:
    IWSingleRoleThread(int fd, int role){
        this->connectfd = fd;
        packetQueue = new std::queue<DataPacket>();
        receiver = new Receiver(this->connectfd, this->packetQueue);
        switch (role) {
            case CLIENTROLE:
                handler = (Handler*)new IWClientHandler(this->connectfd,this->packetQueue);
                break;
            case ROOMROLE:
                
            break;
            default:
                break;
        }
    }
    ~IWSingleRoleThread(){
        delete packetQueue;
        delete receiver;
        delete handler;
    }
    
    void run();
    void* newReceiver(void*);
    void* newHandler(void*);
};

#endif /* IWSingleRoleThread_hpp */
