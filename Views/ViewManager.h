#pragma once
#include "ViewsExport.h"

class CView;
class VIEWS_EXPORT CViewManager
{
public:
	~CViewManager() {};

	typedef CViewManager* Instance;
	static Instance GetInstance();

	void AddView(const String& key, CView* pviev);
	CView* GetView(const String& key);
	void SetActiveView(CView* pview);
	CView* GetActiveView();

protected:
	CViewManager() {};
private:
	map<String, CView*> m_pViews;
	CView* m_ActiveView;
};

class VIEWS_EXPORT CViewsService
{
public:
	~CViewsService() {};

	typedef CViewsService* Instance;
	static Instance GetInstance();
protected:
	CViewsService() {};
public:
	CRuntimeClass* GetMainViewRuntimeClass();
};
