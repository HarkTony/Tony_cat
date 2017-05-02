// GreenHouse.cpp : 定义应用程序的类行为。

#include "stdafx.h"
#include "GreenHouse.h"
#include "GreenHouseDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

BEGIN_MESSAGE_MAP(CGreenHouseApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()

CGreenHouseApp::CGreenHouseApp()
{
	// 支持重新启动管理器
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;
}

CGreenHouseApp theApp;

BOOL CGreenHouseApp::InitInstance()
{
	//access数据库代码三段，其二
	CoInitialize(NULL);
	if   (!AfxOleInit()) 
		{ 
			AfxMessageBox(_T("OLE 初始化失败。请确保 OLE 库是正确的版本。")); 
			return   FALSE; 
		}
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);

	// 将它设置为包括所有要在应用程序中使用的
	// 公共控件类。
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	AfxEnableControlContainer();

	// 创建 shell 管理器，以防对话框包含
	// 任何 shell 树视图控件或 shell 列表视图控件。
	CShellManager *pShellManager = new CShellManager;

	SetRegistryKey(_T("应用程序向导生成的本地应用程序"));

	CGreenHouseDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		//  “确定”来关闭对话框的代码
	}
	else if (nResponse == IDCANCEL)
	{
		//  “取消”来关闭对话框的代码
	}

	// 删除上面创建的 shell 管理器。
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

	// 由于对话框已关闭，所以将返回 FALSE 以便退出应用程序，
	//  而不是启动应用程序的消息泵。
	return FALSE;
}


