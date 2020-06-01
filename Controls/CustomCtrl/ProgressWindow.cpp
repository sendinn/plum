#include "stdafx.h"
#include "ProgressWindow.h"
static const unsigned short treeCtrlID = __COUNTER__;

static const int kHeadBarHeight = 0;
static const int kButtonWidth = 75;
static const int kButtonHeight = 25;
static const int kBottomBarHeight = 45;
static const int kButtonDistance = 10;
static const int kButtonMarginHorizontally = 20;

//---------------------------------------------------------------
CProgressWindow::CProgressWindow(ProgressCallback func, UINT IDD) : CDialogEx(IDD, NULL)
{
	m_funcCalback = func;
	m_nPercent = 0;
	m_bShowPercent = false;
}

CProgressWindow::~CProgressWindow()
{
	font_.DeleteObject();
}

BEGIN_MESSAGE_MAP(CProgressWindow, CDialogEx)
	ON_WM_CREATE()
	ON_WM_PAINT()
	ON_WM_SIZE()
	ON_WM_ERASEBKGND()
	ON_WM_GETMINMAXINFO()
END_MESSAGE_MAP()

int CProgressWindow::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
	{
		return -1;
	}
	font_.CreatePointFont(-100, _T("黑体"));
	return 0;
}

BOOL CProgressWindow::OnInitDialog()
{
	if (!CDialogEx::OnInitDialog())
	{
		return FALSE;
	}

	SetWindowText(m_strCaption);
	MoveWindow(CRect(0, 0, 640, 150));
	CenterWindow();


	m_thread =
		std::thread(
			[this](IProgress* pProgress)
	{

		if (m_funcCalback)
		{
			m_funcCalback(pProgress);
		}

		SendMessage(WM_CLOSE, NULL, NULL);
	},
			this);

	m_thread.detach();

	return TRUE;
}

void CProgressWindow::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);
	CRect rect;
	GetClientRect(rect);

	m_rtProgressBar.left = 5;
	m_rtProgressBar.right = rect.Width() - 10;
	m_rtProgressBar.top = rect.bottom - 50;
	m_rtProgressBar.bottom = rect.bottom - 20;
}

BOOL CProgressWindow::PreTranslateMessage(MSG* pMsg)
{
	if (pMsg->message == WM_KEYDOWN)
	{
		return TRUE;
	}
	else if (pMsg->message == WM_SYSKEYDOWN && pMsg->wParam == VK_F4)
	{
		return TRUE;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}

BOOL CProgressWindow::OnEraseBkgnd(CDC* pDC)
{
	return TRUE;
}

void CProgressWindow::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	CRect rect;
	GetClientRect(&rect);
	dc.FillSolidRect(rect, RGB(255, 255, 255));

	dc.SetBkMode(TRANSPARENT);
	CGdiObject* pObj = dc.SelectObject(&font_);

	int nTextHeight = 15;

	CRect rectText1, rectText2;
	rectText1.left = 5;
	rectText1.right = rect.right - 5;
	rectText1.top = 5;
	rectText1.bottom = rectText1.top + nTextHeight;

	rectText2.left = 5;
	rectText2.right = rect.right - 5;
	rectText2.top = m_rtProgressBar.top - nTextHeight * 2 - 1;
	rectText2.bottom = m_rtProgressBar.top - 1;

	CString strText1 = briefStr_.c_str();
	CString strText2 = detailStr_.c_str();

	dc.DrawText(strText1, strText1.GetLength(), rectText1, DT_LEFT | DT_WORDBREAK);
	dc.DrawText(strText2, strText2.GetLength(), rectText2, DT_LEFT | DT_WORDBREAK);

	COLORREF clr;
	if (m_nPercent < 1000)
	{
		clr = RGB(66, 198, 105);
	}
	else//清除报表数据，生成报表数据，传参为2.0 3.0
	{
		clr = RGB(66, 198, 105);
	}

	CPen pen;
	pen.CreatePen(PS_SOLID, 1, RGB(245, 245, 245));
	CPen* pOldPen = dc.SelectObject(&pen);

	dc.MoveTo(m_rtProgressBar.left, m_rtProgressBar.top);
	dc.LineTo(m_rtProgressBar.right, m_rtProgressBar.top);
	dc.LineTo(m_rtProgressBar.right, m_rtProgressBar.bottom);
	dc.LineTo(m_rtProgressBar.left, m_rtProgressBar.bottom);
	dc.LineTo(m_rtProgressBar.left, m_rtProgressBar.top);

	CRect rectBar = m_rtProgressBar;
	rectBar.right = m_rtProgressBar.left + m_rtProgressBar.Width()*m_nPercent / 1000;

	dc.FillSolidRect(rectBar, clr);

	if (m_bShowPercent)
	{
		CString strText3 /*= StringConversion::ConvertIntToString(m_nPercent / 10).c_str()*/;
		strText3 += L"%";
		dc.DrawText(strText3, strText3.GetLength(), m_rtProgressBar, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	}

	dc.SelectObject(pObj);
	dc.SelectObject(pOldPen);

	pen.DeleteObject();
}

void CProgressWindow::SetCaption(const String& caption)
{
	m_strCaption = caption.c_str();
}

void CProgressWindow::updateProgress(const String& brief, const String& detail, float ratio, bool show)
{
	detailStr_ = briefStr_ = _T("预留大小，防止多线程赋值时候可能引起的崩溃！预留大小，防止多线程赋值时候可能引起的崩溃！\
		预留大小，防止多线程赋值时候可能引起的崩溃！预留大小，防止多线程赋值时候可能引起的崩溃！\
		预留大小，防止多线程赋值时候可能引起的崩溃！预留大小，防止多线程赋值时候可能引起的崩溃！");
	briefStr_ = brief;
	detailStr_ = detail;

	m_bShowPercent = show;
	m_nPercent = int(1000 * ratio);
	if (m_nPercent > 1000)
		m_nPercent = 1000;

	Invalidate();
}

void CProgressWindow::OnCancel()
{
	CDialog::OnCancel();
}

//---------------------------------------------------------------
//CWaitWindow
//---------------------------------------------------------------
CWaitWindow::CWaitWindow(OperationCallBack func, UINT IDD)
	: CDialogEx(IDD, NULL)
{
	m_funcCalback = func;
}

CWaitWindow::~CWaitWindow()
{
	font_.DeleteObject();
}

BEGIN_MESSAGE_MAP(CWaitWindow, CDialogEx)
	ON_WM_CREATE()
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	ON_WM_GETMINMAXINFO()
	ON_WM_TIMER()
END_MESSAGE_MAP()

int CWaitWindow::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
	{
		return -1;
	}
	font_.CreatePointFont(-100, _T("黑体"));
	ModifyStyle(WS_SIZEBOX, 0);
	return 0;
}

BOOL CWaitWindow::OnInitDialog()
{
	if (!CDialogEx::OnInitDialog())
	{
		return FALSE;
	}
	SetWindowText(m_strCaption);

	MoveWindow(CRect(0, 0, 300, 150));
	CenterWindow();

	m_thread =
		std::thread(
			[this]()
	{
		if (m_funcCalback)
		{
			m_funcCalback();
		}

		SendMessage(WM_CLOSE, NULL, NULL);
	});

	m_thread.detach();

	SetTimer(1, 500, 0);

	return TRUE;
}

BOOL CWaitWindow::PreTranslateMessage(MSG* pMsg)
{
	if (pMsg->message == WM_KEYDOWN)
	{
		return TRUE;
	}
	else if (pMsg->message == WM_SYSKEYDOWN && pMsg->wParam == VK_F4)
	{
		return TRUE;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}

BOOL CWaitWindow::OnEraseBkgnd(CDC* pDC)
{
	return TRUE;
}



void CWaitWindow::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	CRect rect;
	GetClientRect(&rect);
	dc.FillSolidRect(rect, RGB(255, 255, 255));

	dc.SetBkMode(TRANSPARENT);
	CGdiObject* pObj = dc.SelectObject(&font_);

	rect.InflateRect(0, -45);
	dc.DrawText(m_strTipMsg, m_strTipMsg.GetLength(), rect, DT_CENTER);
	dc.SelectObject(pObj);
}

void CWaitWindow::ShowModal(const String& caption, const String& tipMsg)
{
	m_strCaption = caption.c_str();
	m_OriTipMsg = m_strTipMsg = tipMsg.c_str();
	this->DoModal();
}
//---------------------------------------------------------------

void CWaitWindow::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	static int times = 0;
	if (++times % 4 == 0)
	{
		m_strTipMsg = m_OriTipMsg;
		times = 0;
	}
	else
	{
		m_strTipMsg += L".";
	}


	Invalidate();

	CDialogEx::OnTimer(nIDEvent);
}
