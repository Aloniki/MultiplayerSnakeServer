//
//  GameHeaders.h
//  GameClient
//
//  Created by Apple on 3/3/16.
//  Copyright © 2016 Aloniki's Study. All rights reserved.
//


#include "GameHeaders.h"
#include "arpa/inet.h"
#include <pthread.h>
#include "JsonManager.hpp"
#include "NetworkSignalPackager.hpp"
#include "RoomListManager.hpp"
#include "PortsManager.hpp"
#include "IWClientServerDaemon.hpp"

RoomListManager* RM;
PortsManager* PM;

ServerDaemon* iwClientServerDaemon;

pthread_t tidIWClient;
pthread_t tidIWRoom;

void init(){
    RM = RoomListManager::getRoomListManager();
    PM = PortsManager::getPortsManager();
    
    iwClientServerDaemon = new ServerDaemon();
}

void* interactWithClient(void* arg){
    iwClientServerDaemon->run();
    pthread_exit(NULL);
}

void* interactWithRoom(void* arg){
    pthread_exit(NULL);
}

int main(int argc, const char * argv[]) {
    init();
    pthread_create(&tidIWClient, NULL, interactWithClient, NULL);
    pthread_create(&tidIWRoom, NULL, interactWithRoom, NULL);
    
    pthread_join(tidIWClient, NULL);
    pthread_join(tidIWRoom, NULL);
    
    
//    //insert code here...
//    int         listenfd, connfd;
//    socklen_t   clilen;
//    static OperationSignal signal;
//    struct sockaddr_in cliaddr,servaddr;
//    
//    listenfd = socket(AF_INET, SOCK_STREAM, 0);
//    
//    bzero(&servaddr,sizeof(servaddr));
//    servaddr.sin_family         = AF_INET;
//    servaddr.sin_addr.s_addr    = htonl(INADDR_ANY);
//    servaddr.sin_port           = htons(ServRoomsPort);
//    
//    bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
//    listen(listenfd, LISTENQ);
//    
//    for (; ; ) {
//        clilen = sizeof(cliaddr);
//        connfd = accept(listenfd, (struct sockaddr*)&cliaddr, &clilen);
////        if ((childpid = fork()) == 0){
//            ssize_t n;
//            char addr[MAXLINE];
//            while (1) {
//                if ((n = read(connfd, &signal, sizeof(signal))) > 0){
//                    
//                    inet_ntop(AF_INET, &cliaddr.sin_addr, addr, sizeof(addr));
//                    printf("recv code:%d, signal comes from%s:%d",signal,addr,ntohs(cliaddr.sin_port));
//                    fflush(stdout);
//                    
//                    RoomInfo room;
//                    room.setRoomID(12345);
//                    room.setRoomAddr("114.215.136.180:9999");
//                    room.setHoster("皮尼斯鳗鱼");
//                    RM->addNewRoom(&room);
//                    auto ril = RM->getRoomList();
//                    for (auto itor = ril->begin(); itor != ril->end(); itor++) {
//                        printf("roomID:%d, roomAddr:%s, hoster:%s",itor->getRoomID(),itor->getRoomAddr().c_str(),itor->getHoster().c_str());
//                    }
//                    auto port = PM->popAvailablePort();
//                    printf("get an available port:%d",port);
//                    port = PM->popAvailablePort();
//                    printf("get an available port:%d",port);
//                    PM->pushAvailablePort(5999);
//                    port = PM->popAvailablePort();
//                    printf("get an available port:%d",port);
//                    
//                    std::string jResult;
//                    JsonManager::RoomInfoToJson(&room, jResult);
//                    printf("aa%s",jResult.c_str());
//                    fflush(stdout);
//                    char netSignal[MAXLINE];
//                    NetworkSignalPackager::Pack(&jResult, netSignal);
//                    ssize_t d;
//                    //auto c = jResult.c_str();
//                    d =write(connfd, netSignal, strlen(netSignal));
//                    printf("continue!!!!");
//                    fflush(stdout);
//                }
//            }
////        }
//    }
}
