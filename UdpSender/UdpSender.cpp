//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("FormMain.cpp", frmMain);
USEFORM("FormSettings.cpp", frmSettings);
USEFORM("FormAbout.cpp", frmAbout);
USEFORM("LogUnit.cpp", frmLog);
USEFORM("FormUdpClient.cpp", frmUdpClient);
//---------------------------------------------------------------------------
#pragma link "jsoncpp.lib"
#pragma link "common.lib"
#pragma link "indy.lib"

#include <stdlib.h>
#include <time.h>

WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	srand(time(NULL));

	try
	{
		Application->Initialize();
		Application->Title = "UDP sender";
		Application->CreateForm(__classid(TfrmMain), &frmMain);
		Application->CreateForm(__classid(TfrmSettings), &frmSettings);
		Application->CreateForm(__classid(TfrmAbout), &frmAbout);
		Application->CreateForm(__classid(TfrmLog), &frmLog);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
