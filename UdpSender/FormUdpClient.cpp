//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormUdpClient.h"
#include "UdpClient.h"
#include "bin2str.h"
#include "AppStatus.h"
#include "Settings.h"
#include <stdlib.h>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmUdpClient *frmUdpClient;
//---------------------------------------------------------------------------

namespace
{

unsigned int GetRandomInRange(unsigned int minValue, unsigned int maxValue)
{
	if (minValue >= maxValue)
		return minValue;
	unsigned int delta = maxValue - minValue;
	return minValue + (rand() % (delta + 1));
}

}

__fastcall TfrmUdpClient::TfrmUdpClient(TComponent* Owner)
	: TForm(Owner),
	dataFromMemoValid(false)
{
	for (int i=1; i<=UdpClientConf::DATAGRAMS_PER_TICK_MAX; i++)
	{
		cbDatagramsPerTickMin->Items->Add(i);
		cbDatagramsPerTickMax->Items->Add(i);
	}
	cbDatagramsPerTickMin->ItemIndex = 0;
	cbDatagramsPerTickMax->ItemIndex = 0;

	for (int i=0; i<SEND_TYPE__LIMITER; i++)
	{
		const char* name = GetSendTypeDescription(static_cast<SendType>(i));
		cbSendType->Items->Add(name);
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmUdpClient::btnSendClick(TObject *Sender)
{
	SetAppStatus("");
	Send();
}
//---------------------------------------------------------------------------

void __fastcall TfrmUdpClient::edAddressChange(TObject *Sender)
{
	appSettings.udpClient.address = edAddress->Text;
}
//---------------------------------------------------------------------------

void __fastcall TfrmUdpClient::edPortChange(TObject *Sender)
{
	int val = StrToIntDef(edPort->Text, -1);
	if (val > 0)
	{
		appSettings.udpClient.port = val;
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmUdpClient::memoChange(TObject *Sender)
{
	appSettings.udpClient.dataText = memo->Text;

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
		SetAppStatus("Number of hex characters in data is uneven!");
		dataFromMemoValid = false;
		lblBytes->Caption = "";
		return;
	}
	else
	{
    	SetAppStatus("");
	}
	std::string str = HexStringToBuf(text.c_str());
	dataFromMemo = std::vector<uint8_t>(str.begin(), str.end());
	dataFromMemoValid = true;
	AnsiString bytesText;
	bytesText.sprintf("%u B", dataFromMemo.size());
	lblBytes->Caption = bytesText;
}
//---------------------------------------------------------------------------

void __fastcall TfrmUdpClient::FormShow(TObject *Sender)
{
	const UdpClientConf &cfg = appSettings.udpClient;

	edAddress->Text = cfg.address;
	edPort->Text = cfg.port;
	memo->Text = cfg.dataText;

	chbSendAutomatically->Checked = cfg.autoSend;
	edIntervalMin->Text = cfg.sendIntervalMin;
	edIntervalMax->Text = cfg.sendIntervalMax;
	cbDatagramsPerTickMin->ItemIndex = cfg.datagramsPerTickMin - 1;
	cbDatagramsPerTickMax->ItemIndex = cfg.datagramsPerTickMax - 1;

	cbSendType->ItemIndex = cfg.sendType;

    memoChange(NULL);

	ApplyConfig();
}
//---------------------------------------------------------------------------

void TfrmUdpClient::ApplyConfig(void)
{
	const UdpClientConf &cfg = appSettings.udpClient;
	if (cfg.autoSend)
	{
		tmrAutoSend->Enabled = false;
		tmrAutoSend->Interval = GetRandomInRange(cfg.sendIntervalMin, cfg.sendIntervalMax);
		tmrAutoSend->Enabled = true;
	}
	else
	{
		tmrAutoSend->Enabled = false;
	}
}

void __fastcall TfrmUdpClient::edIntervalMinChange(TObject *Sender)
{
	appSettings.udpClient.sendIntervalMin = StrToIntDef(edIntervalMin->Text, 1000);
	ApplyConfig();
}
//---------------------------------------------------------------------------

void __fastcall TfrmUdpClient::edIntervalMaxChange(TObject *Sender)
{
	appSettings.udpClient.sendIntervalMax = StrToIntDef(edIntervalMax->Text, 1000);
	ApplyConfig();
}
//---------------------------------------------------------------------------

void __fastcall TfrmUdpClient::cbDatagramsPerTickMinChange(TObject *Sender)
{
	appSettings.udpClient.datagramsPerTickMin = cbDatagramsPerTickMin->ItemIndex;
}
//---------------------------------------------------------------------------

void __fastcall TfrmUdpClient::cbDatagramsPerTickMaxChange(TObject *Sender)
{
	appSettings.udpClient.datagramsPerTickMax = cbDatagramsPerTickMax->ItemIndex;
}
//---------------------------------------------------------------------------

void __fastcall TfrmUdpClient::chbSendAutomaticallyClick(TObject *Sender)
{
	appSettings.udpClient.autoSend = chbSendAutomatically->Checked;
	ApplyConfig();
}
//---------------------------------------------------------------------------

void __fastcall TfrmUdpClient::chbSendAutomaticallyKeyPress(TObject *Sender,
	  char &Key)
{
	appSettings.udpClient.autoSend = chbSendAutomatically->Checked;
	ApplyConfig();
}
//---------------------------------------------------------------------------

void __fastcall TfrmUdpClient::chbSendAutomaticallyKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
	appSettings.udpClient.autoSend = chbSendAutomatically->Checked;
	ApplyConfig();
}
//---------------------------------------------------------------------------

void __fastcall TfrmUdpClient::tmrAutoSendTimer(TObject *Sender)
{
	SetAppStatus("");

	const UdpClientConf &cfg = appSettings.udpClient;
	unsigned int cnt = GetRandomInRange(cfg.datagramsPerTickMin, cfg.datagramsPerTickMax);
	for (unsigned int i=0; i<cnt; i++)
	{
		int status = Send();
		if (status)
			break;
	}
}
//---------------------------------------------------------------------------

int TfrmUdpClient::Send(void)
{
	if (dataFromMemoValid == false)
		return -1;

	const UdpClientConf &cfg = appSettings.udpClient;

	std::vector<uint8_t> data;

	if (cfg.sendType == SEND_WHOLE_BUFFER)
	{
		data = dataFromMemo;
	}
	else
	{
		unsigned int size = dataFromMemo.size();
		size = rand() % (size+1);
		data = dataFromMemo;
		data.resize(size);
	}

	int status = udpClient.Send(appSettings.udpClient, data);
	if (status == 0)
	{
		AnsiString str;
		str.sprintf("Sent %u byte(s)", data.size());
		SetAppStatus(str);
	}
	return status;
}

void __fastcall TfrmUdpClient::cbSendTypeChange(TObject *Sender)
{
	appSettings.udpClient.sendType = static_cast<SendType>(cbSendType->ItemIndex);
}
//---------------------------------------------------------------------------

