
//
//  IWSingleRoleThread.cpp
//  GameServer
//
//  Created by Apple on 4/13/16.
//  Copyright © 2016 Aloniki's Study. All rights reserved.
//

#include "IWSingleRoleThread.hpp"

void* receiverThreadWrapper(void* arg){
    IWSingleRoleThread* pthis = (IWSingleRoleThread*)arg;
    pthis->newReceiver(NULL);
    pthread_exit(NULL);
}

void* handlerThreadWrapper(void* arg){
    IWSingleRoleThread* pthis = (IWSingleRoleThread*)arg;
    pthis->newHandler(NULL);
    pthread_exit(NULL);
}

void IWSingleRoleThread::run(){
    pthread_create(&tidReceiver, NULL, receiverThreadWrapper, this);
    pthread_create(&tidHandler, NULL, handlerThreadWrapper, this);
    
    pthread_join(tidReceiver, NULL);
    pthread_join(tidHandler, NULL);
}

void* IWSingleRoleThread::newReceiver(void* arg){
    this->receiver->receive();
    return (void*)0;
}

void* IWSingleRoleThread::newHandler(void* arg){
    this->handler->handle();
    pthread_exit(NULL);
}
