// TestView.cpp : ʵ���ļ�
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


// TestView ��ͼ

void TestView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO:  �ڴ���ӻ��ƴ���
	pDC->FillRect(CRect(0, 0, 300, 300), &CBrush(RGB(198, 198, 198)));
}

void dox()
{
	Sleep(2000);
}


void TestView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CView::OnLButtonDown(nFlags, point);
}


int TestView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	CWaitWindow WaitWnd([&](){
		dox();
	}, IDD_WAIT_DLG);
	WaitWnd.ShowModal(L"waiting", L"������");



	return 0;
}


void TestView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: �ڴ˴������Ϣ����������
}
