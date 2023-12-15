//---------------------------------------------------------------------------

#ifndef UdpClientConfH
#define UdpClientConfH
//---------------------------------------------------------------------------

#include <System.hpp>

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

	UdpClientConf(void);

	bool operator==(const UdpClientConf &right) const;
	bool operator!=(const UdpClientConf &right) const {
    	return !(*this == right);
	}

	void fromJson(const Json::Value &jv);
	void toJson(Json::Value &jv) const;
};

#endif
