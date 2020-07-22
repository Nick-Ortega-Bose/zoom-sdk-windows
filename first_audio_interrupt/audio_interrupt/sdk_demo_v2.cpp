#include "stdafx.h"
#include "sdk_demo_app.h"

using namespace DuiLib;
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE /*hPrevInstance*/, LPSTR /*lpCmdLine*/, int nCmdShow)
{
	#ifdef DEBUG
	ofstream debuglog;
	debuglog.open("C:\\Users\\no1048340\\logs\\au_int_1.txt", ios_base::app);
	time_t now = time(NULL);
	debuglog << "Run on " << asctime(localtime(&now)) << endl;
	debuglog.close();
	#endif

	HeapSetInformation(NULL, HeapEnableTerminationOnCorruption, NULL, 0);
	CSDKDemoApp app_;
	app_.Run(hInstance);
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (WM_QUIT == msg.message)
		{
			break;
		}
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}