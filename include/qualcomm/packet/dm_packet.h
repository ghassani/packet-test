#pragma once

#include "transport/packet.h"
#include "qualcomm/dm.h"

using namespace OpenPST::Transport;

namespace OpenPST {
    namespace Qualcomm {
    	
        class DmPacket : public Packet
        {
            public:
                /**
                * @brief Constructor
                */
                DmPacket(PacketEndianess targetEndian) : Packet(targetEndian, getMaxDataSize()) 
                {
                   addField("command", kPacketFieldTypePrimitive, sizeof(uint8_t));
                }
                
                /**
                * @brief Destructor
                */
                ~DmPacket()
                {
                    
                }

                size_t getMaxDataSize() override 
                {
                    return DIAG_MAX_PACKET_DATA_SIZE;
                }

                void setCommand(uint8_t command)
                {
                    write<uint8_t>("command", command);
                }

                uint8_t getCommand()
                {
                    return read<uint8_t>(getFieldOffset("command"));
                }
                
                void unpack(std::vector<uint8_t>& resp, TransportInterface* transport) override {
                    if (!resp.size()) {
                        throw PacketError("No data to unpack");
                    }

                    if (resp[0] != getCommand()) {
                        throw PacketError("Unexpected Response");
                    }
                }

                void prepare() override {

                }

        };
    }
}
