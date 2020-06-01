#pragma once
#include "ViewsExport.h"


// TestView 视图

class VIEWS_EXPORT TestView : public CView
{
	DECLARE_DYNCREATE(TestView)

protected:
	TestView();           // 动态创建所使用的受保护的构造函数
	virtual ~TestView();

public:
	virtual void OnDraw(CDC* pDC);      // 重写以绘制该视图


protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
};


