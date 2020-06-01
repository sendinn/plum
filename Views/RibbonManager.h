#pragma once
#include "ViewsExport.h"

enum RibbonCategory
{
	MainView = 1,                 //Ö÷Ò³
	TestView					  //²âÊÔ
};


class VIEWS_EXPORT CRibbonManager
{
private:
	CRibbonManager() {
		m_wndRibbonBar = nullptr;
	};
public:
	~CRibbonManager() {};

	typedef CRibbonManager* Instance;
	static Instance GetInstance();
	void SetCurrentRibbonBar(CMFCRibbonBar* wndRibbonBar);
	void OnCloseProject();
	void OnOpenProject();
	void OnOpenResourceLibrary();
	String  GetEleText(UINT id);
	void SetEleText(UINT id, String text);
	void  AddOption(UINT id, String text);
	void  AddOptions(UINT id, vector<String> textvec);
	void GetComboxSelection(UINT id, String& text);
private:
	void HideAllCategory();

private:
	CMFCRibbonBar*			m_wndRibbonBar;
};


