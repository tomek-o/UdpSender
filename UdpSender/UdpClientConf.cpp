//---------------------------------------------------------------------------


#pragma hdrstop

#include "UdpClientConf.h"
#include <json/json.h>

//---------------------------------------------------------------------------

#pragma package(smart_init)


UdpClientConf::UdpClientConf(void):
	bindAddress(""),
	address("225.1.1.1"),
	port(4242)
{
	dataText =
		"3AE284B1C598C68ED3ACC59ED0A9D087C5A6CF9AC4A600000\n"
		"0000000000000000000000000000000000000000000000000000\n"
		"0000000000000000000000000000000000000000000000000000\n"
		"0000000000000000000000000000000000000000000000000000\n"
		"0000000000000000000000000000000000000000000000000000\n"
		"0000000000000000000000000000000000000000000000000000\n"
		"0000000000000000000000000000000000000000000000000000\n"
		"0000000000000000000000000000000000000000000000000000\n"
		"0000000000000000000000000000000000000000000000000000\n"
		"0000000000000000000000000000000000000000000000000000\n"
		"000000000000000"
	;
}

bool UdpClientConf::operator==(const UdpClientConf &right) const
{
	return (
		bindAddress == right.bindAddress &&
		address == right.address &&
		port == right.port &&
		dataText == right.dataText
	);
}

void UdpClientConf::fromJson(const Json::Value &jv)
{
	if (jv.type() != Json::objectValue)
		return;
	jv.getAString("bindAddress", bindAddress);
	jv.getAString("address", address);
	{
		int tmp = port;
		jv.getInt("port", tmp);
		if (tmp > 0 && tmp < 65536)
		{
			port = tmp;
		}
	}
	jv.getAString("dataText", dataText);
}

void UdpClientConf::toJson(Json::Value &jv) const
{
	jv = Json::Value(Json::objectValue);
	jv["bindAddress"] = bindAddress;
	jv["address"] = address;
	jv["port"] = port;
	jv["dataText"] = dataText;
}

