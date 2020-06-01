// MainView.cpp : 实现文件
//

#include "stdafx.h"
#include "Views.h"
#include "MainView.h"


// MainView

IMPLEMENT_DYNCREATE(MainView, CView)

MainView::MainView()
{

}

MainView::~MainView()
{
}

BEGIN_MESSAGE_MAP(MainView, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// MainView 绘图

void MainView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO:  在此添加绘制代码
	pDC->FillRect(CRect(0, 0, 200, 200), &CBrush(RGB(255, 0, 0)));
}


void MainView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnLButtonDown(nFlags, point);
}
