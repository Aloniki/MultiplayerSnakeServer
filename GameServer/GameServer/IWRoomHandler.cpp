//
//  IWRoomHandler.cpp
//  GameServer
//
//  Created by Apple on 4/14/16.
//  Copyright © 2016 Aloniki's Study. All rights reserved.
//

#include "IWRoomHandler.hpp"

void IWRoomHandler::handle(){
    while (true) {
        if (this->packetQueue->empty()) {
            pause();
        }
        
        auto packet = this->pickFromPacketQueue();
    }
}