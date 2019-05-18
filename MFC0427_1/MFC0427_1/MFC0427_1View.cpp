
// MFC0427_1View.cpp: CMFC04271View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "MFC0427_1.h"
#endif

#include "MFC0427_1Doc.h"
#include "MFC0427_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC04271View

IMPLEMENT_DYNCREATE(CMFC04271View, CView)

BEGIN_MESSAGE_MAP(CMFC04271View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFC04271View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMFC04271View 생성/소멸

CMFC04271View::CMFC04271View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMFC04271View::~CMFC04271View()
{
}

BOOL CMFC04271View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMFC04271View 그리기

void CMFC04271View::OnDraw(CDC* /*pDC*/)
{
	CMFC04271Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	CClientDC dc(this);
	CString strPoint;		// MFC스타일의 문자열타입
	strPoint.Format(_T("마우스좌표 (%4d, %4d)"), pos.x, pos.y); // _T 혹은 TEXT
	dc.TextOutW(0, 0, strPoint);
}


// CMFC04271View 인쇄


void CMFC04271View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFC04271View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMFC04271View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMFC04271View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CMFC04271View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFC04271View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFC04271View 진단

#ifdef _DEBUG
void CMFC04271View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC04271View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC04271Doc* CMFC04271View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC04271Doc)));
	return (CMFC04271Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC04271View 메시지 처리기


void CMFC04271View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	pos = point;		// 우리가 만들어준 CPoint pos;
	Invalidate();
	CView::OnMouseMove(nFlags, point);




	CView::OnMouseMove(nFlags, point);
}
