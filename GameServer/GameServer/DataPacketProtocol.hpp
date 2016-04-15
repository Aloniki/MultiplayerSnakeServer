//
//  DataPacketProtocol.hpp
//  This file defines a data packet protocol, some macros and implementation methods.
//  Use these methods, you can do easily:
//      -packet raw data to a data packet;
//      -unpacket a data packet to raw data;
//
//  Created by Apple on 3/13/16.
//  Copyright © 2016 Aloniki's Study. All rights reserved.
//

#ifndef DataPacketProtocol_hpp
#define DataPacketProtocol_hpp

#include <string>
#include <cstring>
#include <sstream>
#include <iomanip>

//define length of different parts in the packet head
#define PACKETHEADLENGTH 6
#define DATALENGTH 4
#define ROLELENGTH 1
#define TYPELENGTH 1
//define roles
#define SERVERROLE 0
#define CLIENTROLE 1
#define ROOMROLE 2
#define STRINGTYPE 1
//define the offset of the char '0' to the num 0 in standard ASCII
#define ASCIINUMOFFSET 48

/**
 *  Use to record the role, type and raw string from a data packet
 */
struct DataPacket{
    int role;
    int type;
    std::string rawStr;
};

class DataPacketProtocol{
public:
    static std::string Pack(int role, int type, std::string* rawStr);
    static DataPacket Unpack(std::string* dataPacket);
};














#endif /* DataPacketProtocol_hpp */
