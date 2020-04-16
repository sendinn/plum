// TabDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Controls.h"
#include "TabDlg.h"
#include "afxdialogex.h"
#include "TabView.h"

#define TabViewID	WM_USER + 300
// TabDlg 对话框

IMPLEMENT_DYNAMIC(TabDlg, CDialogEx)

TabDlg::TabDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TAB, pParent)
{

}

TabDlg::~TabDlg()
{
}

void TabDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(TabDlg, CDialogEx)
	ON_WM_CREATE()
END_MESSAGE_MAP()


// TabDlg 消息处理程序


BOOL TabDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CRect rect;
	GetClientRect(&rect);
	m_pFrame = new CFrameWnd(); //对话框内视图的父窗口
	m_pFrame->Create(NULL, NULL, WS_CHILD | WS_VISIBLE, rect, this);
	ASSERT(m_pFrame);

	CRuntimeClass* pViewClass = RUNTIME_CLASS(TabView);
	ENSURE(pViewClass != NULL);
	ENSURE(pViewClass->IsDerivedFrom(RUNTIME_CLASS(CView)));

	CView* pView = DYNAMIC_DOWNCAST(CView, pViewClass->CreateObject());
	ASSERT_VALID(pView);

	m_pTabView = dynamic_cast<TabView*>(pView);

	m_pTabView->Create(NULL, L"", WS_CHILD | WS_VISIBLE, rect, m_pFrame, TabViewID, NULL);




	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


int TabDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码





	return 0;
}
