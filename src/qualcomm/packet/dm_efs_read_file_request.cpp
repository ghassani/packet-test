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
* @file dm_efs_read_file_request.cpp
* @package openpst/libopenpst
* @brief  This file was auto generated on 03/14/2017
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_efs_read_file_request.h"

using namespace OpenPST::Qualcomm;

DmEfsReadFileRequest::DmEfsReadFileRequest(PacketEndianess targetEndian) : DmEfsPacket(targetEndian)
{
	addField("fp", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("size", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("offset", kPacketFieldTypePrimitive, sizeof(uint32_t));

	setSubsysCommand(kDiagEfsRead);

	setResponseExpected(true);
}

DmEfsReadFileRequest::~DmEfsReadFileRequest()
{

}

uint32_t DmEfsReadFileRequest::getFp()
{
    return read<uint32_t>(getFieldOffset("fp"));
}
                

void DmEfsReadFileRequest::setFp(uint32_t fp)
{
    write<uint32_t>("fp", fp);
}

uint32_t DmEfsReadFileRequest::getSize()
{
    return read<uint32_t>(getFieldOffset("size"));
}
                

void DmEfsReadFileRequest::setSize(uint32_t size)
{
    write<uint32_t>("size", size);
}

uint32_t DmEfsReadFileRequest::getOffset()
{
    return read<uint32_t>(getFieldOffset("offset"));
}
                

void DmEfsReadFileRequest::setOffset(uint32_t offset)
{
    write<uint32_t>("offset", offset);
}

void DmEfsReadFileRequest::prepareResponse()
{
	if (response == nullptr) {
		DmEfsReadFileResponse* resp = new DmEfsReadFileResponse();
		response = resp;
	}
}

void DmEfsReadFileRequest::unpack(std::vector<uint8_t>& data, TransportInterface* transport)
{
	DmEfsPacket::unpack(data, transport);
	setFp(read<uint32_t>(data, getFieldOffset("fp")));
	setSize(read<uint32_t>(data, getFieldOffset("size")));
	setOffset(read<uint32_t>(data, getFieldOffset("offset")));
}
