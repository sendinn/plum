#pragma once
#include "ViewsExport.h"


// TestView ��ͼ

class VIEWS_EXPORT TestView : public CView
{
	DECLARE_DYNCREATE(TestView)

protected:
	TestView();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~TestView();

public:
	virtual void OnDraw(CDC* pDC);      // ��д�Ի��Ƹ���ͼ


protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
};


