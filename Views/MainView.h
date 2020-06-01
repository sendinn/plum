#pragma once
#include "ViewsExport.h"


// MainView 视图

class VIEWS_EXPORT MainView : public CView
{
	DECLARE_DYNCREATE(MainView)

protected:
	MainView();           // 动态创建所使用的受保护的构造函数
	virtual ~MainView();

public:
	virtual void OnDraw(CDC* pDC);      // 重写以绘制该视图

protected:
	DECLARE_MESSAGE_MAP()



public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};


