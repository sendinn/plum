#pragma once
#include "ViewsExport.h"


// MainView ��ͼ

class VIEWS_EXPORT MainView : public CView
{
	DECLARE_DYNCREATE(MainView)

protected:
	MainView();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~MainView();

public:
	virtual void OnDraw(CDC* pDC);      // ��д�Ի��Ƹ���ͼ

protected:
	DECLARE_MESSAGE_MAP()



public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};


