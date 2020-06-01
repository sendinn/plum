#include "stdafx.h"
#include "ViewManager.h"
#include "MainView.h"

CViewManager::Instance CViewManager::GetInstance()
{
	static CViewManager theInstance;
	return &theInstance;
}

void CViewManager::AddView(const String& key, CView* pviev)
{
	if (m_pViews.find(key) == m_pViews.end())
	{
		m_pViews.insert(std::make_pair(key, pviev));
	}
}
CView* CViewManager::GetView(const String& key)
{
	auto itor = m_pViews.find(key);
	if (itor != m_pViews.end())
	{
		return itor->second;
	}
	else
	{
		return NULL;
	}
}
void CViewManager::SetActiveView(CView* pview)
{
	if (pview != m_ActiveView)
	{
		m_ActiveView = pview;
	}
}

CView* CViewManager::GetActiveView()
{
	return m_ActiveView;
}


CViewsService::Instance CViewsService::GetInstance()
{
	static CViewsService theInstance;
	return &theInstance;
}

CRuntimeClass* CViewsService::GetMainViewRuntimeClass()
{
	return RUNTIME_CLASS(MainView);
}
