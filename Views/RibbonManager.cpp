#include "stdafx.h"
#include "RibbonManager.h"
#include <afxribboncombobox.h>

CRibbonManager::Instance CRibbonManager::GetInstance()
{
	static CRibbonManager theInstance;
	return &theInstance;
}

void CRibbonManager::SetCurrentRibbonBar(CMFCRibbonBar* wndRibbonBar)
{
	m_wndRibbonBar = wndRibbonBar;
}
void CRibbonManager::OnCloseProject()
{
	HideAllCategory();
	m_wndRibbonBar->ShowCategory(RibbonCategory::MainView, TRUE);
	m_wndRibbonBar->SetActiveCategory(m_wndRibbonBar->GetCategory(RibbonCategory::MainView));

	//CBCGPRibbonButton* button=(CBCGPRibbonButton*)m_wndRibbonBar->FindByID(ID_CLOSE_PROJECT);
	//SetVisible无效暂时用SetApplicationModes代替
	//button->SetVisible(FALSE);
	//button->SetApplicationModes(FALSE);
	//其它模块，调用ShowCategory没有效果，用RecalcLayout刷新
	m_wndRibbonBar->RecalcLayout();

}
void CRibbonManager::OnOpenProject()
{
	//隐藏主页以外所有category
	OnCloseProject();

	//显示部分category
	m_wndRibbonBar->ShowCategory(TestView, TRUE);


	//CBCGPRibbonButton* button = (CBCGPRibbonButton*)m_wndRibbonBar->FindByID(ID_CLOSE_PROJECT);
	////SetVisible无效暂时用SetApplicationModes代替
	//button->SetVisible(TRUE);
	//button->SetApplicationModes(TRUE);

	//其它模块，调用ShowCategory没有效果，用RecalcLayout刷新
	m_wndRibbonBar->RecalcLayout();
}

void CRibbonManager::OnOpenResourceLibrary()
{
	HideAllCategory();

	m_wndRibbonBar->ShowCategory(TestView, TRUE);

	//其它模块，调用ShowCategory没有效果，用RecalcLayout刷新
	m_wndRibbonBar->RecalcLayout();
}

String CRibbonManager::GetEleText(UINT id)
{
	CMFCRibbonComboBox* pElement = (CMFCRibbonComboBox*)m_wndRibbonBar->FindByID(id);
	String text = pElement->GetEditText();
	return text;
}

void CRibbonManager::SetEleText(UINT id, String text)
{
	CMFCRibbonComboBox* pElement = (CMFCRibbonComboBox*)m_wndRibbonBar->FindByID(id);
	pElement->SetEditText(text.c_str());
}

void  CRibbonManager::AddOption(UINT id, String text)
{
	CMFCRibbonComboBox* pElement = (CMFCRibbonComboBox*)m_wndRibbonBar->FindByID(id);
	pElement->AddItem(text.c_str());
}
void  CRibbonManager::AddOptions(UINT id, vector<String> textvec)
{
	CMFCRibbonComboBox* pElement = (CMFCRibbonComboBox*)m_wndRibbonBar->FindByID(id);
	for (String text : textvec)
	{
		pElement->AddItem(text.c_str());
	}
}

void CRibbonManager::GetComboxSelection(UINT id, String& text)
{
	CMFCRibbonComboBox* pElement = (CMFCRibbonComboBox*)m_wndRibbonBar->FindByID(id);

	int index = pElement->GetCurSel();
	if (index != -1)
	{
		text = pElement->GetItem(index);
	}
}
void CRibbonManager::HideAllCategory()
{
	int count = m_wndRibbonBar->GetCategoryCount();
	for (int i = 1; i < count; i++)
	{
		m_wndRibbonBar->ShowCategory(i, FALSE);
	}
}