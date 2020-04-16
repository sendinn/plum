// TabDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Controls.h"
#include "TabDlg.h"
#include "afxdialogex.h"
#include "TabView.h"

#define TabViewID	WM_USER + 300
// TabDlg �Ի���

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


// TabDlg ��Ϣ�������


BOOL TabDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	CRect rect;
	GetClientRect(&rect);
	m_pFrame = new CFrameWnd(); //�Ի�������ͼ�ĸ�����
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
				  // �쳣: OCX ����ҳӦ���� FALSE
}


int TabDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������





	return 0;
}
