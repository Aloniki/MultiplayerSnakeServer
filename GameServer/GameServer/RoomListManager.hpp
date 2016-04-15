//
//  RoomListManager.hpp
//  GameServer
//
//  Created by Apple on 4/12/16.
//  Copyright © 2016 Aloniki's Study. All rights reserved.
//

#ifndef RoomListManager_hpp
#define RoomListManager_hpp

#define MAXROOMS 100

#include "RoomInfo.hpp"
#include <vector>

class RoomListManager{
    static std::vector<RoomInfo>* roomInfoList;
    static RoomListManager* roomListManager;
    
    /**
     *  constructor and destructor
     */
    RoomListManager(){
        roomInfoList = new std::vector<RoomInfo>();
    }
    ~RoomListManager(){
        delete roomInfoList;
        delete roomListManager;
    }
public:
    //get methods
    static RoomListManager* getRoomListManager();
    std::vector<RoomInfo>* getRoomList();
    char* getRoomListJson();
    //set methods
    void addNewRoom(RoomInfo*);
    void addNewRoomJson(char*);
    void removeRoom(const roomID_t);
    void removeRoomJson(char*);
    bool updateRoomInfo(const roomID_t, RoomInfo*);
    bool updateRoomInfoJson(char*);
};


#endif /* RoomListManager_hpp */
