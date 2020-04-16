#pragma once
#include <afxbutton.h>
#include "ControlsExport.h"
class CONTROLS_EXPORT LoginView :public CView
{
public:
	LoginView();
	~LoginView();

	DECLARE_DYNCREATE(LoginView)


	//CView虚基类接口实现OnDraw
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图





	virtual void OnInitialUpdate();





	DECLARE_MESSAGE_MAP()


protected:
	CStatic UserName_Btn;
	CStatic PassWord_Btn;
	CEdit	UserName_Edit;
	CEdit	PassWord_Edit;


public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};

