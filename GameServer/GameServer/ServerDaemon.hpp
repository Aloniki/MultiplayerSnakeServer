//
//  ServerDaemon.hpp
//  GameServer
//
//  Created by Apple on 4/12/16.
//  Copyright © 2016 Aloniki's Study. All rights reserved.
//

#ifndef ServerDaemon_hpp
#define ServerDaemon_hpp

#include "GameHeaders.h"
#include <iostream>
#include <arpa/inet.h>
#include <pthread.h>
#include <vector>

class ServerDaemon {
protected:
    int                 iwRole;
    
    int                 listenfd;
    int                 connfd;
    socklen_t           clilen;
    struct sockaddr_in  cliaddr;
    struct sockaddr_in  servaddr;
    std::vector<pthread_t>* tidList;
    
    ServerDaemon(){
        this->tidList = new std::vector<pthread_t>();
    }
    ~ServerDaemon(){
        delete tidList;
    }
public:
    bool initDaemon(in_port_t);
    virtual void run(){};
    virtual void* newIWSingleRoleThread(void*){return (void*)0;};
};

#endif /* ServerDaemon_hpp */
