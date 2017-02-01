/**
* LICENSE PLACEHOLDER
*
* @file streaming_dload_reset_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/streaming_dload_reset_request.h"

using namespace OpenPST::QC;

StreamingDloadResetRequest::StreamingDloadResetRequest(PacketEndianess targetEndian) : StreamingDloadPacket(targetEndian)
{

	setCommand(kStreamingDloadReset);
}

StreamingDloadResetRequest::~StreamingDloadResetRequest()
{

}


void StreamingDloadResetRequest::unpack(std::vector<uint8_t>& data)
{
	StreamingDloadPacket::unpack(data);
}
void StreamingDloadResetRequest::prepareResponse()
{
	if (response == nullptr) {
		StreamingDloadResetResponse* resp = new StreamingDloadResetResponse();
		response = resp;
	}
}