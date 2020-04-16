#include "stdafx.h"
#include "TabView.h"
#include "LoginView.h"
#include "LoginDlg.h"

#define IDC_Table_Control  WM_USER + 301
#define IDC_Table1  WM_USER + 302


IMPLEMENT_DYNCREATE(TabView, CView)

BEGIN_MESSAGE_MAP(TabView, CView)
	// 标准打印命令

	ON_WM_CREATE()
END_MESSAGE_MAP()

TabView::TabView()
{
}


TabView::~TabView()
{
}

void TabView::OnDraw(CDC* pDC)
{

}

int TabView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	CRect rect;
	GetClientRect(rect);
	m_tab.Create(WS_CHILD | WS_VISIBLE, rect, this, IDC_Table_Control);
	m_tab.InsertItem(0, L"页签1");
	m_tab.InsertItem(1, L"页签2");
	m_tab.InsertItem(2, L"页签3");

// 	LoginView* loginView = new LoginView();
// 
// 	auto it = new LoginDlg();
// 	it->Create(IDC_Table1, &m_tab);
// 
// 	CRect tabRect;
// 	m_tab.GetClientRect(&tabRect);    // 获取标签控件客户区Rect   
// 									  // 调整tabRect，使其覆盖范围适合放置标签页   
// 	tabRect.left += 1;
// 	tabRect.right -= 1;
// 	tabRect.top += 25;
// 	tabRect.bottom -= 1;
// 
// 	it->MoveWindow(tabRect);
// 	it->ShowWindow(SW_SHOW);
}


void TabView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类
// 	LoginView* loginView = new LoginView();
// 	
// 	LoginDlg it;
// 	it.Create(IDC_Table1, &m_tab);
// 
// 	CRect tabRect;
// 	m_tab.GetClientRect(&tabRect);    // 获取标签控件客户区Rect   
// 									  // 调整tabRect，使其覆盖范围适合放置标签页   
// 	tabRect.left += 1;
// 	tabRect.right -= 1;
// 	tabRect.top += 25;
// 	tabRect.bottom -= 1;
// 
// 	it.MoveWindow(tabRect);
// 	it.ShowWindow(SW_SHOW);
	// 根据调整好的tabRect放置m_jzmDlg子对话框，并设置为显示   
	//it.SetWindowPos(this, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_SHOWWINDOW);


}
