#pragma once
class TabView :public CView
{
public:
	TabView();
	~TabView();

	DECLARE_DYNCREATE(TabView)

	//CView虚基类接口实现OnDraw
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图

	DECLARE_MESSAGE_MAP()

public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);




public:
	CTabCtrl m_tab;


	virtual void OnInitialUpdate();
};

