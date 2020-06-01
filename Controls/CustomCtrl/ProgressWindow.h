#pragma once
#include "../Resource.h"
#include <thread>
#include "../ControlsExport.h"



//������Ϣ
class IProgress
{
public:
	virtual void SetCaption(const String& caption) = 0;

	/**
	���½�����Ϣ��
	@param[in] brief����Ҫ��Ϣ��
	@param[in] detail����ϸ��Ϣ��
	@parma[in] ratio�����ȣ�
	*/
	virtual void updateProgress(
		const String& brief, const String& detail, float ratio, bool show) = 0;
};

typedef std::function<void(IProgress*)> ProgressCallback;

/*  �������Ի���
	CProgressWindow xxWnd(
	[](IProgress* progress)
	{
		UpdateLoginProgress(progress); //����ִ�У������Եõ�����
	}, IDD_xxWnd_DLG
	);
	xxWnd.SetCaption(L"������...");
	xxWnd.DoModal();
*/
class CONTROLS_EXPORT CProgressWindow : public CDialogEx , public IProgress
{
public:
	/**
	����һ�����ȸ��·������÷����и����Լ�Ҫ���Ĺ��������н��ȵĿ��ơ�
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

/*  �ȴ��Ի���
	CWaitWindow xxWnd(
	[&]() {
		DoSomething...
	}, IDD_xx_DLG
	);
	xxWnd.ShowModal(L"title", L"����������..");
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