#include "stdafx.h"
#include "TabView.h"
#include "LoginView.h"
#include "LoginDlg.h"
#include "Resource.h"

#define IDC_Table_Control  WM_USER + 301



IMPLEMENT_DYNCREATE(TabView, CView)

BEGIN_MESSAGE_MAP(TabView, CView)
	// 标准打印命令
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
	ON_NOTIFY(TCN_SELCHANGE, IDC_Table_Control, &TabView::OnTcnSelchangeTab)
END_MESSAGE_MAP()

void TabView::DoDataExchange(CDataExchange* pDX)
{
	// TODO: 在此添加专用代码和/或调用基类

	CView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_Table_Control, m_tab);

}

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

}


void TabView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	CRect rect;
	GetClientRect(&rect);

	//m_tab.Create(WS_CHILD | WS_VISIBLE, rect, this, IDC_Table_Control);

	m_tab.Create(WS_VISIBLE | TCS_BUTTONS | TCS_FLATBUTTONS | TCS_TABS |
		TCS_FOCUSNEVER | TCS_FORCEICONLEFT | TCS_TOOLTIPS |
		TCS_RAGGEDRIGHT | TCS_MULTILINE | TCS_RIGHTJUSTIFY,
		CRect(0, 0, 200, 22),
		this,
		IDC_Table_Control);
	DWORD dwExStyle = m_tab.GetExtendedStyle();
	m_tab.SetExtendedStyle(dwExStyle | TCS_EX_FLATSEPARATORS);




	m_tab.InsertItem(0, L"页签1");
	m_tab.InsertItem(1, L"页签2");
	m_tab.InsertItem(2, L"页签3");

	CDialog* pDlg[3];
	LoginDlg it;
	it.Create(IDC_Table1, &m_tab);
	//设定在Tab内显示的范围
	CRect rc;
	m_tab.GetClientRect(rc);
	rc.top += 200;
	rc.bottom = 200;
	rc.left = 500;
	rc.right = 500;
	it.MoveWindow(&rc);
	//把对话框对象指针保存起来
	pDlg[0] = &it;
	//显示初始页面
	pDlg[0]->ShowWindow(SW_SHOW);
	m_CurSelTab = 0;

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


void TabView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnLButtonDown(nFlags, point);
}


void TabView::OnTcnSelchangeTab(NMHDR *pNMHDR, LRESULT *pResult)
{
	switch (m_tab.GetCurSel())
	{
	case 0:
		break;
	default:
		break;
	}
	//把当前的页面隐藏起来
	//pDialog[m_CurSelTab]->ShowWindow(SW_HIDE);
	//得到新的页面索引
	m_CurSelTab = m_tab.GetCurSel();
	//把新的页面显示出来
	//pDialog[m_CurSelTab]->ShowWindow(SW_SHOW);
}
