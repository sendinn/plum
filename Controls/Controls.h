// Controls.h : Controls DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CControlsApp
// �йش���ʵ�ֵ���Ϣ������� Controls.cpp
//

class CControlsApp : public CWinApp
{
public:
	CControlsApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
