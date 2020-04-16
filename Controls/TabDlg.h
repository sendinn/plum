#pragma once
#include "ControlsExport.h"
class TabView;
// TabDlg �Ի���

class CONTROLS_EXPORT TabDlg : public CDialogEx
{
	DECLARE_DYNAMIC(TabDlg)

public:
	TabDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~TabDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TAB };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()


protected:
	CFrameWnd*					m_pFrame;
	TabView*					m_pTabView;


public:
	virtual BOOL OnInitDialog();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};
