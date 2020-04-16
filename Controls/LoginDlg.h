#pragma once
#include "ControlsExport.h"
#include <memory>
#include "LoginView.h"

class LoginView;
// LoginDlg 对话框

class CONTROLS_EXPORT LoginDlg : public CDialogEx
{
	DECLARE_DYNAMIC(LoginDlg)

public:
	LoginDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~LoginDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LOGIN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();

	void ShowDlg(void)
	{

		AFX_MANAGE_STATE(AfxGetStaticModuleState());

		LoginDlg dlg;

		dlg.DoModal();

	}
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual void OnOK();


private:
	CFrameWnd*					m_pFrame;
	LoginView*					m_pLoginView;
	std::shared_ptr<LoginView>  m_loginView;

};
