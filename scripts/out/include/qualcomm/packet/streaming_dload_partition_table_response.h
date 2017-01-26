/**
* LICENSE PLACEHOLDER
*
* @file streaming_dload_partition_table_response.h
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
        
        class StreamingDloadPartitionTableResponse : public StreamingDloadPacket
        {
            public:
                /**
                * @brief Constructor
                */
                StreamingDloadPartitionTableResponse();
                
                /**
                * @brief Destructor
                */
                ~StreamingDloadPartitionTableResponse();

                /**
                * @brief Get status
                * @return uint8_t
                */
                uint8_t getStatus();
                
                /**
                * @brief Set status
                * @param uint8_t status
                * @return void
                */
                void setStatus(uint8_t status);

            void unpack(std::vector<uint8_t>& data) override;

        };
    }
}