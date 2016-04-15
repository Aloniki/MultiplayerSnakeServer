//
//  DataPacketProtocol.cpp
//  charstr
//
//  Created by Apple on 3/13/16.
//  Copyright © 2016 Aloniki's Study. All rights reserved.
//

#include "DataPacketProtocol.hpp"
using namespace std;

string DataPacketProtocol::Pack(int role, int type, std::string *rawStr){
    size_t length = rawStr->length() + PACKETHEADLENGTH;

    stringstream ss;
    //add the formal DATALENGTH part
    ss<<setw(DATALENGTH)<<setfill('0')<<length;
    //add the formal ROLE, TYPE part and raw string
    ss<<role<<type<<*rawStr;
    
    return ss.str();
}

DataPacket DataPacketProtocol::Unpack(std::string *dataPacket){
    //get the raw string
    DataPacket packet;
    packet.role = dataPacket->at(DATALENGTH) - ASCIINUMOFFSET;
    packet.type = dataPacket->at(DATALENGTH + ROLELENGTH) -ASCIINUMOFFSET;
    packet.rawStr = dataPacket->substr(PACKETHEADLENGTH);
    
    return packet;
}