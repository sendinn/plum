// MainView.cpp : ʵ���ļ�
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


// MainView ��ͼ

void MainView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO:  �ڴ���ӻ��ƴ���
	pDC->FillRect(CRect(0, 0, 200, 200), &CBrush(RGB(255, 0, 0)));
}


void MainView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CView::OnLButtonDown(nFlags, point);
}
