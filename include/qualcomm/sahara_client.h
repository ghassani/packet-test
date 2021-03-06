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
* @file
* @package libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#pragma once

#include "definitions.h"
#include "transport/transport_interface.h"
#include "transport/packet.h"
#include "transport/packet/raw_data_packet.h"
#include "transport/packet_transporter.h"
#include "qualcomm/sahara.h"
#include "qualcomm/sahara_packets.h"
#include "qualcomm/mbn.h"

using OpenPST::Transport::RawDataPacket;

namespace OpenPST {
	namespace Qualcomm {


		struct SaharaImageRequestInfo {
			uint32_t imageId;
			uint32_t offset;
			uint32_t size;
		};

		struct SaharaHello {
			uint32_t mode;
			uint32_t version;
			uint32_t minVersion;
			uint32_t status;
		};

		struct SaharaHostInfo {			
			bool  			    requested;
			uint32_t  			serial;
			uint32_t 			sblVersion;
			uint32_t 			hwId;
			//SaharaMsmHwId		hwId;
			uint8_t 			oemPublicKeyHash[32];
		};

		struct SaharaMemoryDebugTableInfo {
			uint32_t address;
			uint32_t size;
		};

		struct SaharaState {
			bool 	 establishedSession;
			uint32_t version;
			uint32_t minVersion;
			uint32_t initialMode;
			uint32_t mode;
			SaharaImageRequestInfo lastImageRequest;
			SaharaMemoryDebugTableInfo debugTableInfo;
		};
		
		class SaharaClient {
			protected:
				TransportInterface& transport;
				PacketTransporter packetTransporter;
				PacketEndianess deviceEndianess;
				SaharaState state = {};
				SaharaHostInfo hostInfo = {};

			public:
				SaharaClient(TransportInterface& transport, PacketEndianess deviceEndianess = kPacketEndianessLittle);

				~SaharaClient();

				TransportInterface* getTransport();

				void setTransport(TransportInterface& transport);

				const SaharaState& getState();

				const SaharaState& hello();

				SaharaHello readHello();

				const SaharaState& sendHello(SaharaHello resp);

				void switchMode(uint32_t mode);

				const SaharaState& switchModeAndHello(uint32_t mode);

				const SaharaHostInfo& getHostInfo();

				std::vector<uint8_t> sendClientCommand(uint32_t command);

				void sendClientCommand(uint32_t command, uint8_t* in, size_t amount);

				SaharaImageRequestInfo sendImage(const std::string& filePath, SaharaImageRequestInfo requestInfo);

				SaharaImageRequestInfo sendImage(std::ifstream& file, uint32_t offset, size_t size);

				const SaharaImageRequestInfo& readNextImageOffset();

				bool readCommandModeReady();

				size_t readMemory(uint32_t address, size_t size, std::vector<uint8_t>& out);

				size_t readMemory(uint32_t address, size_t size, const std::string& outFilePath);

				size_t readMemory(uint32_t address, size_t size, std::ofstream& out);

				void done();

				void reset();

				//void setImageTransferCallback(std::function<void(size_t, off_t)>);

				//void setMemoryReadCallback(std::function<void(uint32_t, size_t)>);

				const std::string getRequestedImageName(uint32_t imageId);
				
				const std::string getModeName(uint32_t mode);

				const std::string getClientCommandName(uint32_t command);

		};

		class SaharaClientError : public std::exception
		{
			const SaharaClientError& operator=(SaharaClientError);
			std::string _what;
			uint8_t code;
			
			public:
				SaharaClientError(std::string message, uint8_t code = 0) : _what(message), code(code)  {}
				SaharaClientError(const SaharaClientError& second) : _what(second._what), code(second.code) {}
				virtual ~SaharaClientError() throw() {}
				virtual const char* what() const throw () {
					return _what.c_str();
				}

				uint32_t getCode()
				{
					return code;
				}

		};
	}
}