/**
* LICENSE PLACEHOLDER
*
* @file dm_efs_lstat_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_efs_lstat_request.h"

using namespace OpenPST::QC;

DmEfsLstatRequest::DmEfsLstatRequest(PacketEndianess targetEndian) : DmEfsPacket(targetEndian)
{
	addField("path", kPacketFieldTypeVariant, 0);

}

DmEfsLstatRequest::~DmEfsLstatRequest()
{

}

std::vector<uint8_t> DmEfsLstatRequest::getPath()
{
	return read(getFieldSize("path"), getFieldOffset("path"));
}
                
void DmEfsLstatRequest::setPath(uint8_t* data, size_t size)
{
    write("path", data, size);
}

void DmEfsLstatRequest::unpack(std::vector<uint8_t>& data)
{
	DmEfsPacket::unpack(data);
}