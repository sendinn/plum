
// PlumView.cpp : CPlumView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Plum.h"
#endif

#include "PlumDoc.h"
#include "PlumView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPlumView

IMPLEMENT_DYNCREATE(CPlumView, CView)

BEGIN_MESSAGE_MAP(CPlumView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CPlumView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CPlumView ����/����

CPlumView::CPlumView()
{
	// TODO: �ڴ˴���ӹ������

}

CPlumView::~CPlumView()
{
}

BOOL CPlumView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CPlumView ����

void CPlumView::OnDraw(CDC* /*pDC*/)
{
	CPlumDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CPlumView ��ӡ


void CPlumView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CPlumView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CPlumView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CPlumView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void CPlumView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CPlumView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CPlumView ���

#ifdef _DEBUG
void CPlumView::AssertValid() const
{
	CView::AssertValid();
}

void CPlumView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPlumDoc* CPlumView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPlumDoc)));
	return (CPlumDoc*)m_pDocument;
}
#endif //_DEBUG


// CPlumView ��Ϣ�������
