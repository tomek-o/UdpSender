//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormUdpClient.h"
#include "UdpClient.h"
#include "bin2str.h"
#include "AppStatus.h"
#include "Settings.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmUdpClient *frmUdpClient;
//---------------------------------------------------------------------------
__fastcall TfrmUdpClient::TfrmUdpClient(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TfrmUdpClient::btnSendClick(TObject *Sender)
{
	SetAppStatus("");
	AnsiString text = memo->Text.Trim().LowerCase();
	AnsiString text2 = StringReplace(text, "0x", "", TReplaceFlags() << rfReplaceAll);
	text2 = StringReplace(text2, "\n", "", TReplaceFlags() << rfReplaceAll);
	text2 = StringReplace(text2, "\r", "", TReplaceFlags() << rfReplaceAll);
	const char* allowed = "0123456789abcdef";

	text = "";
	for (int i=1; i<=text2.Length(); i++)
	{
		char c = text2[i];
		if (strchr(allowed, c))
		{
        	text += c;
		}
	}

	if (text.Length() % 2)
	{
		ShowMessage("Number of hex characters in data is uneven!");
		return;
	}
	std::string str = HexStringToBuf(text.c_str());
	std::vector<uint8_t> data(str.begin(), str.end());
	int status = udpClient.Send("", edAddress->Text, static_cast<unsigned short>(StrToInt(edPort->Text)), data);
	if (status == 0)
	{
		AnsiString str;
		str.sprintf("Sent %u byte(s)", data.size());
		SetAppStatus(str);
	}
}
//---------------------------------------------------------------------------

