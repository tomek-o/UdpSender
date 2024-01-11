//---------------------------------------------------------------------------


#pragma hdrstop

#include "UdpClientConf.h"
#include <json/json.h>

//---------------------------------------------------------------------------

#pragma package(smart_init)


UdpClientConf::UdpClientConf(void):
	bindAddress(""),
	address("225.1.1.1"),
	port(4242),
	autoSend(false),
	sendIntervalMin(1000),
	sendIntervalMax(1000),
	datagramsPerTickMin(1),
	datagramsPerTickMax(1),
	sendType(SEND_WHOLE_BUFFER)
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
		dataText == right.dataText &&
		autoSend == right.autoSend &&
		sendIntervalMin == right.sendIntervalMin &&
		sendIntervalMax == right.sendIntervalMax &&
		datagramsPerTickMin == right.datagramsPerTickMin &&
		datagramsPerTickMax == right.datagramsPerTickMax &&
		sendType == right.sendType
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

	jv.getBool("autoSend", autoSend);
	jv.getUInt("sendIntervalMin", sendIntervalMin);
	jv.getUInt("sendIntervalMax", sendIntervalMax);
	if (sendIntervalMax < sendIntervalMin)
		sendIntervalMax = sendIntervalMin;
	jv.getUInt("datagramsPerTickMin", datagramsPerTickMin);
	if (datagramsPerTickMin > DATAGRAMS_PER_TICK_MAX)
		datagramsPerTickMin = DATAGRAMS_PER_TICK_MAX;
	jv.getUInt("datagramsPerTickMax", datagramsPerTickMax);
	if (datagramsPerTickMax > DATAGRAMS_PER_TICK_MAX)
		datagramsPerTickMax = DATAGRAMS_PER_TICK_MAX;
	if (datagramsPerTickMax < datagramsPerTickMin)
		datagramsPerTickMax = datagramsPerTickMin;

	{
		int tmp = sendType;
		jv.getInt("sendType", tmp);
		if (tmp >= 0 && tmp < SEND_TYPE__LIMITER)
		{
        	sendType = static_cast<SendType>(tmp);
		}
	}
}

void UdpClientConf::toJson(Json::Value &jv) const
{
	jv = Json::Value(Json::objectValue);
	jv["bindAddress"] = bindAddress;
	jv["address"] = address;
	jv["port"] = port;
	jv["dataText"] = dataText;

	jv["autoSend"] = autoSend;
	jv["sendIntervalMin"] = sendIntervalMin;
	jv["sendIntervalMax"] = sendIntervalMax;
	jv["datagramsPerTickMin"] = datagramsPerTickMin;
	jv["datagramsPerTickMax"] = datagramsPerTickMax;

	jv["sendType"] = sendType;
}

