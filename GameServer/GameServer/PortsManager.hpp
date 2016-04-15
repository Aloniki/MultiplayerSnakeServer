//
//  PortsManager.hpp
//  GameServer
//
//  Created by Apple on 4/12/16.
//  Copyright © 2016 Aloniki's Study. All rights reserved.
//

#ifndef PortsManager_hpp
#define PortsManager_hpp

#define MINIMALPORT 5000
#define MAXIMALPORT 5999

#include <stack>
#include <arpa/inet.h>

class PortsManager {
    static std::stack<in_port_t>* availablePortsStack;
    static PortsManager* portsManager;
    
    /**
     *  constructor and destructor
     */
    PortsManager(){
        availablePortsStack = new std::stack<in_port_t>();
        for (in_port_t i = MINIMALPORT; i <= MAXIMALPORT; i++) {
            availablePortsStack->push(i);
        }
    }
    ~PortsManager(){
        delete availablePortsStack;
        delete portsManager;
    }
public:
    static PortsManager* getPortsManager();
    in_port_t popAvailablePort();
    void pushAvailablePort(in_port_t port);
};

#endif /* PortsManager_hpp */
