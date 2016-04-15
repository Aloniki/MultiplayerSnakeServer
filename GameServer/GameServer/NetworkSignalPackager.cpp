//
//  NetworkSignalPackager.cpp
//  GameServer
//
//  Created by Apple on 3/11/16.
//  Copyright © 2016 Aloniki's Study. All rights reserved.
//

#include "NetworkSignalPackager.hpp"

bool NetworkSignalPackager::Pack(std::string *rawStr, char* netSignal){
    (*rawStr) += SignalEnd;
    strcpy(netSignal, rawStr->c_str());
    
    return true;
}

bool NetworkSignalPackager::UnPack(char* netSignal, char* rawStr){
    size_t endSize = strlen(SignalEnd);
    size_t signalSize = strlen(netSignal);
    strlcpy(rawStr, netSignal, signalSize - endSize + 1);
    
    return true;
}
