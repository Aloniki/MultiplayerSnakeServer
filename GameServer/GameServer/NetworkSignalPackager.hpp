//
//  NetworkSignalPackager.hpp
//  GameServer
//
//  Created by Apple on 3/11/16.
//  Copyright © 2016 Aloniki's Study. All rights reserved.
//

#ifndef NetworkSignalPackager_hpp
#define NetworkSignalPackager_hpp

#include <string>

#define SignalEnd "$EOF$"

class NetworkSignalPackager{
public:
    static bool Pack(std::string* rawStr, char* netSignal);
    static bool UnPack(char* netSignal, char* rawStr);
};

#endif /* NetworkSignalPackager_hpp */
