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
#include "ServerDaemon.hpp"

#define SELFROLE SERVERROLE     //self role

RoomListManager* RM;    //room list manager instance
PortsManager* PM;       //ports manager instance

ServerDaemon* iwClientServerDaemon;     //a server dameon that is interacting with client
ServerDaemon* iwRoomServerDaemon;       //a server dameon that is interacting with room

//interaction thread IDs
pthread_t tidIWClient;
pthread_t tidIWRoom;

/**
 Initialize RoomListManager, PortsManager and server daemons
 
 - returns: void
 */
void init(){
    RM = RoomListManager::getRoomListManager();
    PM = PortsManager::getPortsManager();
    iwClientServerDaemon = new ServerDaemon(CLIENTROLE);
    iwRoomServerDaemon = new ServerDaemon(ROOMROLE);
}

/**
 *  run a new server daemon to interact with client
 *
 *  @param arg void
 *
 *  @return void
 */
void* interactWithClient(void* arg){
    iwClientServerDaemon->run();
    pthread_exit(NULL);
}

/**
 *  run a new server daemon to interact with room
 *
 *  @param arg void
 *
 *  @return void
 */
void* interactWithRoom(void* arg){
    pthread_exit(NULL);
}


/**
 *  main logic method
 *
 *  @param argc the number of startup args
 *  @param argv startup args
 *
 *  @return 0
 */
int main(int argc, const char * argv[]) {
    //initialize
    init();
    //create new threads to run server daemons
    pthread_create(&tidIWClient, NULL, interactWithClient, NULL);
    pthread_create(&tidIWRoom, NULL, interactWithRoom, NULL);
    //waiting for these threads
    pthread_join(tidIWClient, NULL);
    pthread_join(tidIWRoom, NULL);
    //end this program
    exit(0);
}
