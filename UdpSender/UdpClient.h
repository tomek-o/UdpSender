//---------------------------------------------------------------------------

#ifndef UdpClientH
#define UdpClientH
//---------------------------------------------------------------------------

#include <vector>
#include <stdint.h>

namespace Idudpclient {
	class TIdUDPClient;
}

class UdpClient
{
private:
	Idudpclient::TIdUDPClient *client;
	AnsiString lastBindAddress;
public:
	UdpClient(void);
	~UdpClient(void);
	int Send(AnsiString bindAddress, AnsiString address, unsigned short port, const std::vector<uint8_t> &data);
};

extern UdpClient udpClient;


#endif
