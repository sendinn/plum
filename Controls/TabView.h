#pragma once
#include "ControlsExport.h"
class CONTROLS_EXPORT TabView :public CView
{
public:
	TabView();
	~TabView();

	DECLARE_DYNCREATE(TabView)

	//CView�����ӿ�ʵ��OnDraw
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ

	DECLARE_MESSAGE_MAP()

public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);




public:
	CTabCtrl m_tab;
	int m_CurSelTab;

	virtual void OnInitialUpdate();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);


	void OnTcnSelchangeTab(NMHDR *pNMHDR, LRESULT *pResult);
	virtual void DoDataExchange(CDataExchange* pDX);
};

