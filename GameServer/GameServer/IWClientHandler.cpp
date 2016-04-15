//
//  IWClientHandler.cpp
//  GameServer
//
//  Created by Apple on 4/14/16.
//  Copyright © 2016 Aloniki's Study. All rights reserved.
//

#include "IWClientHandler.hpp"

void IWClientHandler::handle(){
    while (true) {
        if (this->packetQueue->empty()) {
            continue;
        }
        
        auto packet = this->pickFromPacketQueue();
        switch (packet.type) {
            case REQUIRE:{
                auto roomList = this->RM->getRoomList();
                for (int i = 0; i < 5; i++) {
                    auto ri = new RoomInfo(i, "192.168.0.100:9997", "皮尼斯鳗鱼");
                    roomList->push_back(*ri);
                }
                std::string roomlistJson;
                JsonManager::RoomListToJson(roomList, roomlistJson);
                std::cout<<roomlistJson<<std::endl;
                break;
            }
            default:
                break;
        }
    }
}