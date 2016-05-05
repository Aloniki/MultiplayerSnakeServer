//
//  IWRoomHandler.hpp
//  GameServer
//
//  Created by Apple on 4/14/16.
//  Copyright © 2016 Aloniki's Study. All rights reserved.
//

#ifndef IWRoomHandler_hpp
#define IWRoomHandler_hpp

#include "Handler.hpp"

class IWRoomHandler : Handler {
    
public:
    IWRoomHandler(int fd, std::queue<DataPacket>* packetQueue) : Handler(fd, packetQueue){
    }
    void handle();
};

#endif /* IWRoomHandler_hpp */
