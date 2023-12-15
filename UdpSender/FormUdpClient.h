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
	void __fastcall btnSendClick(TObject *Sender);
	void __fastcall edAddressChange(TObject *Sender);
	void __fastcall edPortChange(TObject *Sender);
	void __fastcall memoChange(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfrmUdpClient(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmUdpClient *frmUdpClient;
//---------------------------------------------------------------------------
#endif
