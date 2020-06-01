// TestView.cpp : 实现文件
//

#include "stdafx.h"
#include "Views.h"
#include "TestView.h"
#include "Controls\CustomCtrl\ProgressWindow.h"


// TestView

IMPLEMENT_DYNCREATE(TestView, CView)

TestView::TestView()
{

}

TestView::~TestView()
{
}

BEGIN_MESSAGE_MAP(TestView, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_CREATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()


// TestView 绘图

void TestView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO:  在此添加绘制代码
	pDC->FillRect(CRect(0, 0, 300, 300), &CBrush(RGB(198, 198, 198)));
}

void dox()
{
	Sleep(2000);
}


void TestView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnLButtonDown(nFlags, point);
}


int TestView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	CWaitWindow WaitWnd([&](){
		dox();
	}, IDD_WAIT_DLG);
	WaitWnd.ShowModal(L"waiting", L"加载中");



	return 0;
}


void TestView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
}
