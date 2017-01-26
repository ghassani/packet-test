/**
* LICENSE PLACEHOLDER
*
* @file streaming_dload_unlock_response.h
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#pragma once

#include "qualcomm/packet/streaming_dload_packet.h"

using OpenPST::QC::StreamingDloadPacket;

namespace OpenPST {
    namespace QC {
        
        class StreamingDloadUnlockResponse : public StreamingDloadPacket
        {
            public:
                /**
                * @brief Constructor
                */
                StreamingDloadUnlockResponse();
                
                /**
                * @brief Destructor
                */
                ~StreamingDloadUnlockResponse();


            void unpack(std::vector<uint8_t>& data) override;

        };
    }
}