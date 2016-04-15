//
//  IWClientServerDaemon.cpp
//  GameServer
//
//  Created by Apple on 4/12/16.
//  Copyright © 2016 Aloniki's Study. All rights reserved.
//

#include "IWClientServerDaemon.hpp"

IWClientServerDaemon* IWClientServerDaemon::iwClientServerDaemon;

void* iwSingleRoleThreadWrapper(void* arg){
    IWClientServerDaemon* pthis = (IWClientServerDaemon*)arg;
    pthis->newIWSingleRoleThread(NULL);
    pthread_exit(NULL);
}

ServerDaemon* IWClientServerDaemon::getServerDaemon(){
    if (NULL == iwClientServerDaemon) {
        iwClientServerDaemon = new IWClientServerDaemon(CLIENTROLE);
    }
    return iwClientServerDaemon;
}

void IWClientServerDaemon::run(){
    initDaemon(IWClientPort);
    for (; ; ) {
        this->clilen = sizeof(this->cliaddr);
        this->connfd = accept(this->listenfd, (struct sockaddr*)&(this->cliaddr), &(this->clilen));
        
        char addr[MAXLINE];

        inet_ntop(AF_INET, &cliaddr.sin_addr, addr, sizeof(addr));
        printf("signal comes from%s:%d\n",addr,ntohs(cliaddr.sin_port));
        fflush(stdout);
        
        pthread_t tidSingleRole;
        pthread_create(&tidSingleRole, NULL, iwSingleRoleThreadWrapper, this);
        this->tidList->push_back(tidSingleRole);
        
        std::cout<<"new thread!!"<<std::endl;
        
//        pthread_join(tidSingleRole, NULL);
    }
}

void* IWClientServerDaemon::newIWSingleRoleThread(void* arg){
    auto iwst = new IWSingleRoleThread(this->connfd, this->iwRole);
    iwst->run();
//    pause();
    std::cout<<"after read!"<<std::endl;
    
    return (void*)0;
}
















