//---------------------------------------------------------------------------

#ifndef UdpClientH
#define UdpClientH
//---------------------------------------------------------------------------

#include <vector>
#include <stdint.h>

namespace Idudpclient {
	class TIdUDPClient;
}

struct UdpClientConf;

class UdpClient
{
private:
	Idudpclient::TIdUDPClient *client;
	AnsiString lastBindAddress;
public:
	UdpClient(void);
	~UdpClient(void);
	int Send(const UdpClientConf &conf, const std::vector<uint8_t> &data);
};

extern UdpClient udpClient;


#endif
