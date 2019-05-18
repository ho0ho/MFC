
// MFC0429_RGBDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFC0429_RGB.h"
#include "MFC0429_RGBDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFC0429RGBDlg 대화 상자


CMFC0429RGBDlg::CMFC0429RGBDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFC0429_RGB_DIALOG, pParent)
	, valueB(0)
	, valueG(0)
	, valueR(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC0429RGBDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_SLIDER_R, ctrlSlider);
	//  DDX_Text(pDX, IDC_EDIT_R, valueR);
	//  DDX_Text(pDX, IDC_EDIT_G, valueG);
	//  DDX_Text(pDX, IDC_EDIT_B, valueB);
	DDX_Control(pDX, IDC_SLIDER_R, ctrlSliderR);
	DDX_Control(pDX, IDC_SLIDER_G, ctrlSliderG);
	DDX_Control(pDX, IDC_SLIDER_B, ctrlSliderB);
	DDX_Control(pDX, IDC_EDIT_R, ctrlEditR);
	DDX_Control(pDX, IDC_EDIT_G, ctrlEditG);
	DDX_Control(pDX, IDC_EDIT_B, ctrlEditB);
	DDX_Text(pDX, IDC_EDIT_B, valueB);
	DDX_Text(pDX, IDC_EDIT_G, valueG);
	DDX_Text(pDX, IDC_EDIT_R, valueR);
}

BEGIN_MESSAGE_MAP(CMFC0429RGBDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CTLCOLOR()
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_R, &CMFC0429RGBDlg::OnNMCustomdrawSliderR)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_G, &CMFC0429RGBDlg::OnNMCustomdrawSliderG)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_B, &CMFC0429RGBDlg::OnNMCustomdrawSliderB)
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, &CMFC0429RGBDlg::OnBnClickedButtonClear)
	ON_BN_CLICKED(IDC_BUTTON_EXIT, &CMFC0429RGBDlg::OnBnClickedButtonExit)
	ON_EN_CHANGE(IDC_EDIT_R, &CMFC0429RGBDlg::OnEnChangeEditR)
	ON_EN_CHANGE(IDC_EDIT_G, &CMFC0429RGBDlg::OnEnChangeEditG)
	ON_EN_CHANGE(IDC_EDIT_B, &CMFC0429RGBDlg::OnEnChangeEditB)
END_MESSAGE_MAP()


// CMFC0429RGBDlg 메시지 처리기

BOOL CMFC0429RGBDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	SliderInit();
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMFC0429RGBDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFC0429RGBDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFC0429RGBDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMFC0429RGBDlg::OnNMCustomdrawSliderR(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;

	int nPos;
	CString strPos;

	// get current position of slider
	nPos = ctrlSliderR.GetPos();
	// convert position int to string
	strPos.Format(_T("%d"), nPos);
	// set edit-box position
	ctrlEditR.SetWindowTextW(strPos);
}

void CMFC0429RGBDlg::OnNMCustomdrawSliderG(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;

	int nPos;
	CString strPos;

	// get current position of slider
	nPos = ctrlSliderG.GetPos();
	// convert position int to string
	strPos.Format(_T("%d"), nPos);
	// set edit-box position
	ctrlEditG.SetWindowTextW(strPos);
}


void CMFC0429RGBDlg::OnNMCustomdrawSliderB(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;

	int nPos;
	CString strPos;

	// get current position of slider
	nPos = ctrlSliderB.GetPos();
	// convert position int to string
	strPos.Format(_T("%d"), nPos);
	// set edit-box position
	ctrlEditB.SetWindowTextW(strPos);
}

void CMFC0429RGBDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (pScrollBar)
	{
		// 어떤 슬라이더인지 검사
		if (pScrollBar == (CScrollBar*)& ctrlSliderR)
			// 슬라이더의 위치를 검사한다.
			valueR = ctrlSliderR.GetPos();
		else if (pScrollBar == (CScrollBar*)& ctrlSliderG) 
			valueG = ctrlSliderG.GetPos();
		else if (pScrollBar == (CScrollBar*)& ctrlSliderB) 
			valueB = ctrlSliderB.GetPos();
		Invalidate();
	}	
	else
	{
		// CScrollView를 상속받은 뷰의 경우 프래임의 스크롤롤 동작시 pScrollBar이 NULL된다.
	}

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);

}


void CMFC0429RGBDlg::OnBnClickedButtonClear()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SliderInit();
}


void CMFC0429RGBDlg::OnBnClickedButtonExit()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	OnOK();
}



void CMFC0429RGBDlg::SliderInit()
{
	// TODO: 여기에 구현 코드 추가.
	// Set Range
	ctrlSliderR.SetRange(0, 255);
	// Set Position(value)
	ctrlSliderR.SetPos(0);
	// set size by keyboard move-key (<-,->)
	ctrlSliderR.SetLineSize(1);
	// set size by mouse click or keyboard PgUp, PgDn key
	ctrlSliderR.SetPageSize(10);

	ctrlSliderG.SetRange(0, 255);
	// Set Position(value)
	ctrlSliderG.SetPos(0);
	// set size by keyboard move-key (<-,->)
	ctrlSliderG.SetLineSize(1);
	// set size by mouse click or keyboard PgUp, PgDn key
	ctrlSliderG.SetPageSize(10);

	ctrlSliderB.SetRange(0, 255);
	// Set Position(value)
	ctrlSliderB.SetPos(0);
	// set size by keyboard move-key (<-,->)
	ctrlSliderB.SetLineSize(1);
	// set size by mouse click or keyboard PgUp, PgDn key
	ctrlSliderB.SetPageSize(10);
}


HBRUSH CMFC0429RGBDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  여기서 DC의 특성을 변경합니다.
	switch (nCtlColor)
	{
	case CTLCOLOR_STATIC:
	{
		if (pWnd->GetDlgCtrlID() == IDC_STATIC_VIEW)
		{
			int r = ctrlSliderR.GetPos();
			int g = ctrlSliderG.GetPos();
			int b = ctrlSliderB.GetPos();
			hbr = CreateSolidBrush(RGB(r, g, b));
		}
	}
	}

	// TODO:  기본값이 적당하지 않으면 다른 브러시를 반환합니다.
	return hbr;
}


void CMFC0429RGBDlg::OnEnChangeEditR()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (UpdateData(TRUE)) {
		ctrlEditR.SetSel(0, -1);
		ctrlEditR.SetSel(-1, -1);
		ctrlSliderR.SetPos(valueR);
		CStatic* cs = (CStatic*)GetDlgItem(IDC_STATIC_VIEW);
		Myinvalidate(cs);
	}
}


void CMFC0429RGBDlg::OnEnChangeEditG()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (UpdateData(TRUE)) {
		ctrlEditG.SetSel(0, -1);
		ctrlEditG.SetSel(-1, -1);
		ctrlSliderG.SetPos(valueG);
		CStatic* cs = (CStatic*)GetDlgItem(IDC_STATIC_VIEW);
		Myinvalidate(cs);
	}
}


void CMFC0429RGBDlg::OnEnChangeEditB()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (UpdateData(TRUE)) {
		ctrlEditB.SetSel(0, -1);
		ctrlEditB.SetSel(-1, -1);
		ctrlSliderB.SetPos(valueB);
		CStatic* cs = (CStatic *)GetDlgItem(IDC_STATIC_VIEW);
		Myinvalidate(cs);
	}
}


void CMFC0429RGBDlg::Myinvalidate(CStatic* pStatic)
{
	// TODO: 여기에 구현 코드 추가.
	CRect PicRect;
	pStatic->GetWindowRect(&PicRect);
	CPoint& PointTL = PicRect.TopLeft();
	ScreenToClient(&PointTL);
	CPoint& PointBR = PicRect.BottomRight();
	ScreenToClient(&PointBR);
	InvalidateRect(PicRect, FALSE);
}
