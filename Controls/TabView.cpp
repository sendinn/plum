#include "stdafx.h"
#include "TabView.h"
#include "LoginView.h"
#include "LoginDlg.h"
#include "Resource.h"

#define IDC_Table_Control  WM_USER + 301



IMPLEMENT_DYNCREATE(TabView, CView)

BEGIN_MESSAGE_MAP(TabView, CView)
	// ��׼��ӡ����
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
	ON_NOTIFY(TCN_SELCHANGE, IDC_Table_Control, &TabView::OnTcnSelchangeTab)
END_MESSAGE_MAP()

void TabView::DoDataExchange(CDataExchange* pDX)
{
	// TODO: �ڴ����ר�ô����/����û���

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




	m_tab.InsertItem(0, L"ҳǩ1");
	m_tab.InsertItem(1, L"ҳǩ2");
	m_tab.InsertItem(2, L"ҳǩ3");

	CDialog* pDlg[3];
	LoginDlg it;
	it.Create(IDC_Table1, &m_tab);
	//�趨��Tab����ʾ�ķ�Χ
	CRect rc;
	m_tab.GetClientRect(rc);
	rc.top += 200;
	rc.bottom = 200;
	rc.left = 500;
	rc.right = 500;
	it.MoveWindow(&rc);
	//�ѶԻ������ָ�뱣������
	pDlg[0] = &it;
	//��ʾ��ʼҳ��
	pDlg[0]->ShowWindow(SW_SHOW);
	m_CurSelTab = 0;

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


void TabView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

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
	//�ѵ�ǰ��ҳ����������
	//pDialog[m_CurSelTab]->ShowWindow(SW_HIDE);
	//�õ��µ�ҳ������
	m_CurSelTab = m_tab.GetCurSel();
	//���µ�ҳ����ʾ����
	//pDialog[m_CurSelTab]->ShowWindow(SW_SHOW);
}
