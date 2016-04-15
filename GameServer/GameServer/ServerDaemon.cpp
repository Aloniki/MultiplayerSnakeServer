//
//  ServerDaemon.cpp
//  GameServer
//
//  Created by Apple on 4/12/16.
//  Copyright © 2016 Aloniki's Study. All rights reserved.
//

#include "ServerDaemon.hpp"

bool ServerDaemon::initDaemon(in_port_t port){
    //establish socket
    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (-1 == listenfd) {
        printf("socket establishment error!");
        return false;
    }
    //init server address
    bzero(&this->servaddr,sizeof(this->servaddr));
    this->servaddr.sin_family         = AF_INET;
    this->servaddr.sin_addr.s_addr    = htonl(INADDR_ANY);
    this->servaddr.sin_port           = htons(port);
    //bind server address
    auto bindResult = bind(this->listenfd, (struct sockaddr*)&(this->servaddr), sizeof(this->servaddr));
    if (-1 == bindResult) {
        printf("bind error! errno:%d",errno);
        return false;
    }
    //listen to this socket
    auto listenResult = listen(this->listenfd, LISTENQ);
    if (-1 == listenResult) {
        printf("listen error! errno:%d",errno);
        return false;
    }
    
    return true;
}
