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

/// this class defines a handler that is used to interact with clients
class IWClientHandler : Handler {
public:
    //constructor
    IWClientHandler(int fd, std::queue<DataPacket>* packetQueue) : Handler(fd, packetQueue){
    }
    void handle();      //handle with clients
};

#endif /* IWClientHandler_hpp */
