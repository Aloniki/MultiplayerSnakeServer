//
//  PortsManager.cpp
//  GameServer
//
//  Created by Apple on 4/12/16.
//  Copyright © 2016 Aloniki's Study. All rights reserved.
//

#include "PortsManager.hpp"

std::stack<in_port_t>* PortsManager::availablePortsStack;
PortsManager* PortsManager::portsManager;

/**
 *  get the sole PortsManager entity
 *
 *  @return PortsManager
 */
PortsManager* PortsManager::getPortsManager(){
    if (NULL == portsManager) {
        portsManager = new PortsManager();
    }
    return portsManager;
}

/**
 *  pop the top available port from the available port list
 *
 *  @return the top available port
 */
in_port_t PortsManager::popAvailablePort(){
    in_port_t port = availablePortsStack->top();
    availablePortsStack->pop();
    return port;
}

/**
 *  push an available port to the port list
 *
 *  @param port an available port
 */
void PortsManager::pushAvailablePort(in_port_t port){
    availablePortsStack->push(port);
}









