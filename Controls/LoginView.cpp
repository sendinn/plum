#include "stdafx.h"
#include "LoginView.h"

#define IDC_UserNameBtn   WM_USER + 100
#define IDC_PassWordBtn   WM_USER + 101
#define IDC_UserNameEdit   WM_USER + 102
#define IDC_PassWordEdit   WM_USER + 103


IMPLEMENT_DYNCREATE(LoginView, CView)

BEGIN_MESSAGE_MAP(LoginView, CView)
	// 标准打印命令

	ON_WM_SIZE()
	ON_WM_CREATE()
END_MESSAGE_MAP()



LoginView::LoginView()
{
}


LoginView::~LoginView()
{
}


void LoginView::OnDraw(CDC* pDC)
{

}

void LoginView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类

	SetWindowText(L"登录");
	ShowWindow(SW_MAXIMIZE);//对话框默认最大化弹出

// 	String strImageLineMesh = BW_STR("parametercalc.png");
// 	HICON mainWndIcon = CImageMgr::instance(kNullStr)->GetHicon(strImageLineMesh, 16, 16);
// 	SetIcon(mainWndIcon, TRUE);
}


void LoginView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
	CRect rect;
	GetClientRect(rect);

	UserName_Btn.MoveWindow(CRect(rect.left + 10, rect.top + 20, rect.left + 70, rect.top + 50));
	PassWord_Btn.MoveWindow(CRect(rect.left + 10, rect.top + 70, rect.left + 70, rect.top + 100));

	UserName_Edit.MoveWindow(CRect(rect.left + 100, rect.top + 20, rect.left + 190, rect.top + 50));
	PassWord_Edit.MoveWindow(CRect(rect.left + 100, rect.top + 70, rect.left + 190, rect.top + 100));

	Invalidate();
}


int LoginView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	CRect rect;
	rect.SetRectEmpty();
	UserName_Btn.Create(L"用户名：", WS_CHILD | WS_VISIBLE, rect, this, IDC_UserNameBtn);
	PassWord_Btn.Create(L"密码：", WS_CHILD | WS_VISIBLE, rect, this, IDC_PassWordBtn);
	UserName_Edit.Create(WS_CHILD | WS_VISIBLE | WS_BORDER , rect, this, IDC_UserNameEdit);
	PassWord_Edit.Create(WS_CHILD | WS_VISIBLE | WS_BORDER, rect, this, IDC_PassWordEdit);

	return 0;
}
