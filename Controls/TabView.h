#pragma once
class TabView :public CView
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


	virtual void OnInitialUpdate();
};

