// Views.h : Views DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CViewsApp
// �йش���ʵ�ֵ���Ϣ������� Views.cpp
//

class CViewsApp : public CWinApp
{
public:
	CViewsApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
