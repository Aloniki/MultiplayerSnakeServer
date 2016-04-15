//
//  GameHeaders.h
//  GameClient
//
//  Created by Apple on 3/3/16.
//  Copyright © 2016 Aloniki's Study. All rights reserved.
//

#ifndef GameHeaders_h
#define GameHeaders_h

#include "DataPacketProtocol.hpp"
#include "JsonManager.hpp"

#define ServIPAddr "127.0.0.1"
#define IWClientPort 9997

#define MAXLINE         9999
#define LISTENQ         10
/**
 OperationSignalTypes----------string version
 */
#define sEXIT            "EXIT"
#define sREQUIRE         "REQUIRE"
#define sCREATE          "CREATE"
#define sJOIN            "JOIN"

enum OperationSignal{
    INVALID     =  -1,
    EXIT        =   0,
    REQUIRE     =   1,
    CREATE      =   2,
    JOIN        =   3,
};

#endif /* GameHeaders_h */