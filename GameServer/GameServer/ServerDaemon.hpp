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
#include "IWSingleRoleThread.hpp"

class ServerDaemon {
protected:
    int                 iwRole;
    in_port_t           port;
    
    int                 listenfd;
    int                 connfd;
    socklen_t           clilen;
    struct sockaddr_in  cliaddr;
    struct sockaddr_in  servaddr;
    std::vector<pthread_t>* tidList;
    
    ServerDaemon(int role){
        this->tidList = new std::vector<pthread_t>();
        switch (role) {
            case CLIENTROLE:
                this->port = IBSCPort;
                break;
            case ROOMROLE:
                this->port = IBSRPort;
                break;
            default:
                break;
        }
    }
    ~ServerDaemon(){
        delete tidList;
    }
public:
    bool initDaemon(in_port_t);
    void run();
    void* newIWSingleRoleThread(void*);
};

#endif /* ServerDaemon_hpp */
