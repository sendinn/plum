// LoginDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Controls.h"
#include "LoginDlg.h"
#include "afxdialogex.h"
#include "LoginView.h"
#include "Resource.h"

const UINT login_viewID = WM_USER + 201;
// LoginDlg 对话框

IMPLEMENT_DYNAMIC(LoginDlg, CDialogEx)

LoginDlg::LoginDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_LOGIN, pParent)
	,m_loginView(std::make_shared<LoginView>())
	,m_pFrame(NULL)
{

}

LoginDlg::~LoginDlg()
{
}

void LoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(LoginDlg, CDialogEx)
	ON_WM_CREATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()


// LoginDlg 消息处理程序


BOOL LoginDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CRect rect;
	GetClientRect(&rect);
	m_pFrame = new CFrameWnd(); //对话框内视图的父窗口
	m_pFrame->Create(NULL, NULL, WS_CHILD | WS_VISIBLE, rect, this);
	ASSERT(m_pFrame);

	CRuntimeClass* pViewClass = RUNTIME_CLASS(LoginView);
	ENSURE(pViewClass != NULL);
	ENSURE(pViewClass->IsDerivedFrom(RUNTIME_CLASS(CView)));

	CView* pView = DYNAMIC_DOWNCAST(CView, pViewClass->CreateObject());
	ASSERT_VALID(pView);

	m_pLoginView = dynamic_cast<LoginView*>(pView);


	CRect rcGraphicsView;
	GetDlgItem(IDC_PIC)->GetWindowRect(&rcGraphicsView);
	ScreenToClient(&rcGraphicsView);

	m_pFrame->MoveWindow(rcGraphicsView);

	///创建窗口的 classname不能赋值为L""，否则creat方法崩溃  猜想是找不到为空的class，设置为NULL默认没有模板
	m_pLoginView->Create(NULL, L"", WS_CHILD | WS_VISIBLE, rect, m_pFrame, login_viewID, NULL);




#if 0
	ShowWindow(SW_MAXIMIZE);//对话框默认最大化弹出

	String strImageLineMesh = BW_STR("parametercalc.png");
	HICON mainWndIcon = CImageMgr::instance(kNullStr)->GetHicon(strImageLineMesh, 16, 16);
	SetIcon(mainWndIcon, TRUE);
#endif



	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


int LoginDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码

	return 0;
}


void LoginDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
	if (NULL != m_pFrame)
	{
		CRect rc;
		GetClientRect(&rc);
		m_pFrame->MoveWindow(rc);
		((CView*)m_pLoginView)->MoveWindow(rc);
	}



}


void LoginDlg::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类


	CDialogEx::OnOK();
}
