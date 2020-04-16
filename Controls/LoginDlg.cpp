// LoginDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Controls.h"
#include "LoginDlg.h"
#include "afxdialogex.h"
#include "LoginView.h"
#include "Resource.h"

const UINT login_viewID = WM_USER + 201;
// LoginDlg �Ի���

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


// LoginDlg ��Ϣ�������


BOOL LoginDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	CRect rect;
	GetClientRect(&rect);
	m_pFrame = new CFrameWnd(); //�Ի�������ͼ�ĸ�����
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

	///�������ڵ� classname���ܸ�ֵΪL""������creat��������  �������Ҳ���Ϊ�յ�class������ΪNULLĬ��û��ģ��
	m_pLoginView->Create(NULL, L"", WS_CHILD | WS_VISIBLE, rect, m_pFrame, login_viewID, NULL);




#if 0
	ShowWindow(SW_MAXIMIZE);//�Ի���Ĭ����󻯵���

	String strImageLineMesh = BW_STR("parametercalc.png");
	HICON mainWndIcon = CImageMgr::instance(kNullStr)->GetHicon(strImageLineMesh, 16, 16);
	SetIcon(mainWndIcon, TRUE);
#endif



	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


int LoginDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������

	return 0;
}


void LoginDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: �ڴ˴������Ϣ����������
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
	// TODO: �ڴ����ר�ô����/����û���


	CDialogEx::OnOK();
}
