/**
* LICENSE PLACEHOLDER
*
* @file streaming_dload_get_ecc_state_request.h
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#pragma once

#include "qualcomm/packet/streaming_dload_packet.h"
#include "qualcomm/packet/streaming_dload_get_ecc_state_response.h"

using OpenPST::QC::StreamingDloadPacket;
using OpenPST::QC::StreamingDloadGetEccStateResponse;

namespace OpenPST {
    namespace QC {
        
        class StreamingDloadGetEccStateRequest : public StreamingDloadPacket
        {
            public:
                /**
                * @brief Constructor
                */
                StreamingDloadGetEccStateRequest(PacketEndianess targetEndian);
                
                /**
                * @brief Destructor
                */
                ~StreamingDloadGetEccStateRequest();

				/**
				* @overload Packet::unpack
				*/
	            void unpack(std::vector<uint8_t>& data) override;

				/**
				* @overload Packet::prepareResponse
				*/
				void prepareResponse() override;

        };
    }
}