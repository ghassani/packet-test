/**
*
* (c) Gassan Idriss <ghassani@gmail.com>
* 
* This file is part of libopenpst.
* 
* libopenpst is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
* 
* libopenpst is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with libopenpst. If not, see <http://www.gnu.org/licenses/>.
*
* @file dm_efs_write_file_response.h
* @package openpst/libopenpst
* @brief  This file was auto generated on 03/14/2017
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#pragma once

#include "qualcomm/packet/dm_efs_packet.h"

using OpenPST::Qualcomm::DmEfsPacket;

namespace OpenPST {
    namespace Qualcomm {
        
        class DmEfsWriteFileResponse : public DmEfsPacket
        {
            public:
                /**
                * @brief Constructor
                */
                DmEfsWriteFileResponse(PacketEndianess targetEndian = kPacketEndianessLittle);
                
                /**
                * @brief Destructor
                */
                ~DmEfsWriteFileResponse();

                
                /**
                * @brief Get fp
                * @return uint32_t
                */
                uint32_t getFp();
                                

                /**
                * @brief Set fp
                * @param uint32_t fp
                * @return void
                */
                void setFp(uint32_t fp);
                                
                /**
                * @brief Get offset
                * @return uint32_t
                */
                uint32_t getOffset();
                                

                /**
                * @brief Set offset
                * @param uint32_t offset
                * @return void
                */
                void setOffset(uint32_t offset);
                                
                /**
                * @brief Get bytes_written
                * @return uint32_t
                */
                uint32_t getBytesWritten();
                                

                /**
                * @brief Set bytes_written
                * @param uint32_t bytesWritten
                * @return void
                */
                void setBytesWritten(uint32_t bytesWritten);
                                
                /**
                * @brief Get error
                * @return uint32_t
                */
                uint32_t getError();
                                

                /**
                * @brief Set error
                * @param uint32_t error
                * @return void
                */
                void setError(uint32_t error);
                				/**
				* @overload Packet::unpack
				*/
	            void unpack(std::vector<uint8_t>& data, TransportInterface* transport) override;

        };
    }
}
