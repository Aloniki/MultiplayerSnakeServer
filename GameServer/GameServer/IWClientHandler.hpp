//
//  IWClientHandler.hpp
//  GameServer
//
//  Created by Apple on 4/14/16.
//  Copyright © 2016 Aloniki's Study. All rights reserved.
//

#ifndef IWClientHandler_hpp
#define IWClientHandler_hpp

#include "Handler.hpp"

class IWClientHandler : Handler {
    
public:
    IWClientHandler(int fd, std::queue<DataPacket>* packetQueue) : Handler(fd, packetQueue){
    }
    void handle();
};

#endif /* IWClientHandler_hpp */
