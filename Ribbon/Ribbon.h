/* ribbon改掉原有的ribbonview，用我们的manview来替代*/
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// CRibbonApp:
// 有关此类的实现，请参阅 Ribbon.cpp
//

class CRibbonApp : public CWinAppEx
{
public:
	CRibbonApp();


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CRibbonApp theApp;
