#pragma once
#include "ControlsExport.h"
class TabView;
// TabDlg 对话框

class CONTROLS_EXPORT TabDlg : public CDialogEx
{
	DECLARE_DYNAMIC(TabDlg)

public:
	TabDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~TabDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TAB };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()


protected:
	CFrameWnd*					m_pFrame;
	TabView*					m_pTabView;


public:
	virtual BOOL OnInitDialog();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};
