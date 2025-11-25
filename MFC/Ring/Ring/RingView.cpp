
// RingView.cpp : implementation of the CRingView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Ring.h"
#endif

#include "RingDoc.h"
#include "RingView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRingView

IMPLEMENT_DYNCREATE(CRingView, CScrollView)

BEGIN_MESSAGE_MAP(CRingView, CScrollView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CScrollView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CRingView construction/destruction

CRingView::CRingView() noexcept
{
	// TODO: add construction code here

}

CRingView::~CRingView()
{
}

BOOL CRingView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

// CRingView drawing

void CRingView::OnDraw(CDC* pDC)
{
	CRingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	PointArray& pointArray = pDoc->GetPointArray();
	ColorArray& colorArray = pDoc->GetColorArray();
	int s = pointArray.GetSize();
	for (int i = 0; i < s; i++)
	{
		auto p = pointArray[i];
		auto c = colorArray[i];
		CPen pen{ PS_SOLID, 0, BLACK };
		CBrush brush{ WHITE };
		pDC->Ellipse(p.x - 10, p.y - 10, p.x + 10, p.y + 10);
		pDC->SelectObject(&pen);
		pDC->SelectObject(&brush);
	}

	// TODO: add draw code for native data here
}

void CRingView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: calculate the total size of this view
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// CRingView printing

BOOL CRingView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CRingView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CRingView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CRingView diagnostics

#ifdef _DEBUG
void CRingView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CRingView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CRingDoc* CRingView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRingDoc)));
	return (CRingDoc*)m_pDocument;
}
#endif //_DEBUG


// CRingView message handlers


void CRingView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CRingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->MouseDown(point);

	CScrollView::OnLButtonDown(nFlags, point);
}
