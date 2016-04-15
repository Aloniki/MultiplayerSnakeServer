//
//  RoomListManager.cpp
//  GameServer
//
//  Created by Apple on 4/12/16.
//  Copyright © 2016 Aloniki's Study. All rights reserved.
//

#include "RoomListManager.hpp"

std::vector<RoomInfo>* RoomListManager::roomInfoList;
RoomListManager* RoomListManager::roomListManager;

/**
 *  get sole RoomListManager entity
 *
 *  @return roomListManager
 */
 RoomListManager* RoomListManager::getRoomListManager(){
     if (NULL == roomListManager) {
         roomListManager = new RoomListManager();
     }
    return roomListManager;
}

/**
 *  get all the rooms info
 *
 *  @return roomInfoList
 */
std::vector<RoomInfo>* RoomListManager::getRoomList(){
    return roomInfoList;
}

/**
 *  add new room info into the roomInfoList
 *
 *  @param roomInfo the new room info
 */
void RoomListManager::addNewRoom(RoomInfo* roomInfo){
    roomInfoList->push_back(*roomInfo);
}
//in a json way
void RoomListManager::addNewRoomJson(char* roomInfoJson){
    
}

/**
 *  remove the room that is indicated by the room id
 *
 *  @param id the room id of the room you want to remove
 */
void RoomListManager::removeRoom(const roomID_t id){
    for (auto itor = roomInfoList->begin(); itor != roomInfoList->end(); itor++) {
        if (id == itor->getRoomID()) {
            roomInfoList->erase(itor);
            break;
        }
    }
}
//in a json way
void RoomListManager::removeRoomJson(char * roomInfoJson){
    
}

/**
 *  update the certain room info
 *
 *  @param id       the room id of the room you want to update info
 *  @param roomInfo the new room info
 *
 *  @return if can find the certain room
 */
bool RoomListManager::updateRoomInfo(const roomID_t id, RoomInfo* roomInfo){
    for (auto itor = roomInfoList->begin(); itor != roomInfoList->end(); itor++) {
        if (id == itor->getRoomID()) {
            itor->updateRoomInfo(roomInfo);
            return true;
        }
    }
    return false;
}
//in a json way
bool RoomListManager::updateRoomInfoJson(char * roomInfoJson){
    return false;
}








