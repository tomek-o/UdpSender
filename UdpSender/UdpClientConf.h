//---------------------------------------------------------------------------

#ifndef UdpClientConfH
#define UdpClientConfH
//---------------------------------------------------------------------------

#include <System.hpp>
#include "SendType.h"

namespace Json
{
	class Value;
}

struct UdpClientConf
{
	AnsiString bindAddress;
	AnsiString address;
	unsigned int port;
	AnsiString dataText;

	bool autoSend;
	unsigned int sendIntervalMin;
	unsigned int sendIntervalMax;
	enum { DATAGRAMS_PER_TICK_MAX = 128 };
	unsigned int datagramsPerTickMin;
	unsigned int datagramsPerTickMax;

    enum SendType sendType;

	UdpClientConf(void);

	bool operator==(const UdpClientConf &right) const;
	bool operator!=(const UdpClientConf &right) const {
    	return !(*this == right);
	}

	void fromJson(const Json::Value &jv);
	void toJson(Json::Value &jv) const;
};

#endif
