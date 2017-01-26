/**
* LICENSE PLACEHOLDER
*
* @file streaming_dload_hello_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/streaming_dload_hello_request.h"

StreamingDloadHelloRequest::StreamingDloadHelloRequest() : StreamingDloadPacket()
{
	addField("magic", kPacketFieldTypePrimitive, sizeof(uint8_t[]));
	addField("version", kPacketFieldTypePrimitive, sizeof(uint8_t));
	addField("compatible_version", kPacketFieldTypePrimitive, sizeof(uint8_t));
	addField("feature_bits", kPacketFieldTypePrimitive, sizeof(uint8_t));

	setCommand(kStreamingDloadHello);
}

StreamingDloadHelloRequest::~StreamingDloadHelloRequest()
{

}

std::vector<uint8_t> StreamingDloadHelloRequest::getMagic()
{
	return read(getFieldSize("magic"), getFieldOffset("magic"));
}
                
void StreamingDloadHelloRequest::setMagic(uint8_t* data, size_t size);
{
    write("magic", data, size);
}
uint8_t StreamingDloadHelloRequest::getVersion()
{
    return read<uint8_t>(getFieldOffset("version"));
}
                
void StreamingDloadHelloRequest::setVersion(uint8_t version)
{
    write<uint8_t>("version", version);
}
uint8_t StreamingDloadHelloRequest::getCompatibleVersion()
{
    return read<uint8_t>(getFieldOffset("compatible_version"));
}
                
void StreamingDloadHelloRequest::setCompatibleVersion(uint8_t compatibleVersion)
{
    write<uint8_t>("compatible_version", compatibleVersion);
}
uint8_t StreamingDloadHelloRequest::getFeatureBits()
{
    return read<uint8_t>(getFieldOffset("feature_bits"));
}
                
void StreamingDloadHelloRequest::setFeatureBits(uint8_t featureBits)
{
    write<uint8_t>("feature_bits", featureBits);
}

void StreamingDloadHelloRequest::unpack(std::vector<uint8_t>& data)
{
	
}