
// MFC0429_RGBDlg.h: 헤더 파일
//

#pragma once


// CMFC0429RGBDlg 대화 상자
class CMFC0429RGBDlg : public CDialogEx
{
// 생성입니다.
public:
	CMFC0429RGBDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC0429_RGB_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CSliderCtrl ctrlSliderR;
	CSliderCtrl ctrlSliderG;
	CSliderCtrl ctrlSliderB;
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnBnClickedButtonClear();
	afx_msg void OnBnClickedButtonExit();
	CEdit ctrlEditR;
	CEdit ctrlEditG;
	CEdit ctrlEditB;
	void SliderInit();
	afx_msg void OnNMCustomdrawSliderR(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnNMCustomdrawSliderG(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnNMCustomdrawSliderB(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CBrush sliderBrush;
	afx_msg void OnEnChangeEditR();
	afx_msg void OnEnChangeEditG();
	afx_msg void OnEnChangeEditB();
	int valueB;
	int valueG;
	int valueR;
	void Myinvalidate(CStatic* pStatic);
};
