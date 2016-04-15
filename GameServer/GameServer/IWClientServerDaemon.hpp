//
//  IWClientServerDaemon.hpp
//  GameServer
//
//  Created by Apple on 4/12/16.
//  Copyright © 2016 Aloniki's Study. All rights reserved.
//

#ifndef IWClientServerDaemon_hpp
#define IWClientServerDaemon_hpp

#include "ServerDaemon.hpp"
#include "IWSingleRoleThread.hpp"


class IWClientServerDaemon :  ServerDaemon{
    static IWClientServerDaemon* iwClientServerDaemon;
    IWClientServerDaemon(int iwRole){ this->iwRole = iwRole; }
public:
    void run();
    static ServerDaemon* getServerDaemon();
    void* newIWSingleRoleThread(void*);
};

#endif /* IWClientServerDaemon_hpp */
