#include <iostream>
using namespace std;

// Attach a user-defined object to a framework before program execution begins.
class CWinApp;
CWinApp* g_app;

class CWinApp
{
public:
	CWinApp() { g_app = this; }
	virtual bool InitInstance() { return false; }
	virtual int  ExitInstance() { return 0; }
	virtual int  Run() { return 0; }
};
CWinApp* AfxGetApp() { return g_app; }

int main()
{
	CWinApp* pApp = AfxGetApp();

	if (pApp->InitInstance())
		pApp->Run();
	pApp->ExitInstance();
	return 0;
}
//----------------------------------------------------------
// 라이브러리 사용자 코드
class CMyApp : public CWinApp
{
public:
	virtual bool InitInstance()
	{
		cout << "app initialize" << endl;
		return false;
	}
};
CMyApp theApp;





