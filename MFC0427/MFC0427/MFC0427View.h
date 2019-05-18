
// MFC0427View.h: CMFC0427View 클래스의 인터페이스
//

#pragma once


class CMFC0427View : public CView
{
protected: // serialization에서만 만들어집니다.
	CMFC0427View() noexcept;
	DECLARE_DYNCREATE(CMFC0427View)

// 특성입니다.
public:
	CMFC0427Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CMFC0427View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFC0427View.cpp의 디버그 버전
inline CMFC0427Doc* CMFC0427View::GetDocument() const
   { return reinterpret_cast<CMFC0427Doc*>(m_pDocument); }
#endif

