/* ribbon�ĵ�ԭ�е�ribbonview�������ǵ�manview�����*/
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CRibbonApp:
// �йش����ʵ�֣������ Ribbon.cpp
//

class CRibbonApp : public CWinAppEx
{
public:
	CRibbonApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CRibbonApp theApp;
