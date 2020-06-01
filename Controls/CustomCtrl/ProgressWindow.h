#pragma once
#include "../Resource.h"
#include <thread>
#include "../ControlsExport.h"



//进度信息
class IProgress
{
public:
	virtual void SetCaption(const String& caption) = 0;

	/**
	更新进度信息。
	@param[in] brief：简要信息；
	@param[in] detail：详细信息；
	@parma[in] ratio：进度；
	*/
	virtual void updateProgress(
		const String& brief, const String& detail, float ratio, bool show) = 0;
};

typedef std::function<void(IProgress*)> ProgressCallback;

/*  进度条对话框
	CProgressWindow xxWnd(
	[](IProgress* progress)
	{
		UpdateLoginProgress(progress); //函数执行，并可以得到进度
	}, IDD_xxWnd_DLG
	);
	xxWnd.SetCaption(L"更新中...");
	xxWnd.DoModal();
*/
class CONTROLS_EXPORT CProgressWindow : public CDialogEx , public IProgress
{
public:
	/**
	接收一个进度更新方法。该方法中根据自己要做的工作，进行进度的控制。
	*/
	CProgressWindow(ProgressCallback func,UINT IDD);
	~CProgressWindow();
	/*enum { IDD = IDD_Progress_DLG };*/

public:
	virtual void SetCaption(const String& caption);
	virtual void updateProgress(
		const String& brief, const String& detail, float ratio, bool show);

protected:
	BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL OnInitDialog();
	virtual void OnCancel();
	afx_msg int  OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);

	DECLARE_MESSAGE_MAP()

private:
	CFont font_;
	String briefStr_;
	String detailStr_;
	CString m_strCaption;
	std::thread   m_thread;
	ProgressCallback m_funcCalback;
	ProgressCallback m_dataPrepareCalback;
	CRect  m_rtProgressBar;
	int    m_nPercent;
	bool   m_bShowPercent;
};

/*  等待对话框
	CWaitWindow xxWnd(
	[&]() {
		DoSomething...
	}, IDD_xx_DLG
	);
	xxWnd.ShowModal(L"title", L"加载数据中..");
*/
typedef std::function<void(void)> OperationCallBack;
class CONTROLS_EXPORT CWaitWindow : public CDialogEx
{
public:
	CWaitWindow(OperationCallBack func, UINT IDD);
	~CWaitWindow();
	/*enum { IDD = IDD_BOOWAYWaitting_DLG };*/

public:
	void ShowModal(const String& caption, const String& tipMsg);

protected:
	BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL OnInitDialog();
	afx_msg int  OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	DECLARE_MESSAGE_MAP()

private:
	CFont font_;
	CString m_strCaption;
	CString m_strTipMsg;
	CString m_OriTipMsg;
	OperationCallBack m_funcCalback;
	std::thread   m_thread;

};