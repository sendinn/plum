#include "stdafx.h"
#include "TabView.h"
#include "LoginView.h"
#include "LoginDlg.h"

#define IDC_Table_Control  WM_USER + 301
#define IDC_Table1  WM_USER + 302


IMPLEMENT_DYNCREATE(TabView, CView)

BEGIN_MESSAGE_MAP(TabView, CView)
	// ��׼��ӡ����

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
	m_tab.InsertItem(0, L"ҳǩ1");
	m_tab.InsertItem(1, L"ҳǩ2");
	m_tab.InsertItem(2, L"ҳǩ3");

// 	LoginView* loginView = new LoginView();
// 
// 	auto it = new LoginDlg();
// 	it->Create(IDC_Table1, &m_tab);
// 
// 	CRect tabRect;
// 	m_tab.GetClientRect(&tabRect);    // ��ȡ��ǩ�ؼ��ͻ���Rect   
// 									  // ����tabRect��ʹ�串�Ƿ�Χ�ʺϷ��ñ�ǩҳ   
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

	// TODO: �ڴ����ר�ô����/����û���
// 	LoginView* loginView = new LoginView();
// 	
// 	LoginDlg it;
// 	it.Create(IDC_Table1, &m_tab);
// 
// 	CRect tabRect;
// 	m_tab.GetClientRect(&tabRect);    // ��ȡ��ǩ�ؼ��ͻ���Rect   
// 									  // ����tabRect��ʹ�串�Ƿ�Χ�ʺϷ��ñ�ǩҳ   
// 	tabRect.left += 1;
// 	tabRect.right -= 1;
// 	tabRect.top += 25;
// 	tabRect.bottom -= 1;
// 
// 	it.MoveWindow(tabRect);
// 	it.ShowWindow(SW_SHOW);
	// ���ݵ����õ�tabRect����m_jzmDlg�ӶԻ��򣬲�����Ϊ��ʾ   
	//it.SetWindowPos(this, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_SHOWWINDOW);


}
