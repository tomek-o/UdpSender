//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UdpClient.h"
#include "UdpClientConf.h"
#include "IdUdpClient.hpp"
#include "Log.h"
#include "AppStatus.h"
#include <json/json.h>
#include <algorithm>

//---------------------------------------------------------------------------

#pragma package(smart_init)

UdpClient udpClient;

UdpClient::UdpClient(void)
{
	client = new TIdUDPClient(NULL);
	client->BroadcastEnabled = true;
}

UdpClient::~UdpClient(void)
{
	delete client;
}

int UdpClient::Send(const UdpClientConf &conf, const std::vector<uint8_t> &data)
{
	SetAppStatus("");
	if (conf.bindAddress != lastBindAddress) {
		delete client;
		client = new TIdUDPClient(NULL);
		client->BroadcastEnabled = true;
		if (conf.bindAddress != "") {
			client->Binding->IP = conf.bindAddress;
			try {
				client->Binding->Bind();
			} catch (EIdSocketError &exception) {
				AnsiString msg;
				msg.sprintf("UDP client: Failed to bind to %s address", conf.bindAddress.c_str());
				SetAppStatus(msg);
				LOG("%s", msg.c_str());
				return -1;
			}
		}
		lastBindAddress = conf.bindAddress;
	}

	client->Host = conf.address;
	client->Port = conf.port;

	//client->Broadcast(data, port);
	unsigned int length = data.size();
	client->SendBuffer((void*)&data[0], length);
//	client->SendBuffer((AnsiString)"255.255.255.255", port, &val, sizeof(val));

//	count = client->ReceiveBuffer(buffer, sizeof(buffer), ipAddress, portNumber, 10);

	return 0;
}


