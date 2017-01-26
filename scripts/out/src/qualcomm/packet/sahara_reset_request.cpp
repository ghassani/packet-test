/**
* LICENSE PLACEHOLDER
*
* @file sahara_reset_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/sahara_reset_request.h"

SaharaResetRequest::SaharaResetRequest() : SaharaPacket()
{

	setCommand(kSaharaCommandReset);
}

SaharaResetRequest::~SaharaResetRequest()
{

}


void SaharaResetRequest::unpack(std::vector<uint8_t>& data)
{
	
}