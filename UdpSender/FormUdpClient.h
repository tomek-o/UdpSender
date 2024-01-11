//---------------------------------------------------------------------------

#ifndef FormUdpClientH
#define FormUdpClientH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------

#include <vector>
#include <stdint.h>

class TfrmUdpClient : public TForm
{
__published:	// IDE-managed Components
	TPanel *pnlBottom;
	TButton *btnSend;
	TLabel *lblAddress;
	TEdit *edAddress;
	TLabel *lblPort;
	TEdit *edPort;
	TMemo *memo;
	TLabel *lblData;
	TTimer *tmrAutoSend;
	TCheckBox *chbSendAutomatically;
	TEdit *edIntervalMin;
	TLabel *lblInterval;
	TLabel *lblTo;
	TEdit *edIntervalMax;
	TLabel *lblMs;
	TLabel *lblDatagramsPerTick;
	TComboBox *cbDatagramsPerTickMin;
	TLabel *lblTo2;
	TComboBox *cbDatagramsPerTickMax;
	TLabel *lblBytes;
	TLabel *lblDataToSend;
	TComboBox *cbSendType;
	void __fastcall btnSendClick(TObject *Sender);
	void __fastcall edAddressChange(TObject *Sender);
	void __fastcall edPortChange(TObject *Sender);
	void __fastcall memoChange(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall edIntervalMinChange(TObject *Sender);
	void __fastcall edIntervalMaxChange(TObject *Sender);
	void __fastcall cbDatagramsPerTickMinChange(TObject *Sender);
	void __fastcall cbDatagramsPerTickMaxChange(TObject *Sender);
	void __fastcall chbSendAutomaticallyClick(TObject *Sender);
	void __fastcall chbSendAutomaticallyKeyPress(TObject *Sender, char &Key);
	void __fastcall chbSendAutomaticallyKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall tmrAutoSendTimer(TObject *Sender);
	void __fastcall cbSendTypeChange(TObject *Sender);
private:	// User declarations
	void ApplyConfig(void);
	int Send(void);
	std::vector<uint8_t> dataFromMemo;
	bool dataFromMemoValid;	
public:		// User declarations
	__fastcall TfrmUdpClient(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmUdpClient *frmUdpClient;
//---------------------------------------------------------------------------
#endif
