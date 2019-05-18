
// MFC0429_listDlg.h: 헤더 파일
//

#pragma once


// CMFC0429listDlg 대화 상자
class CMFC0429listDlg : public CDialogEx
{
// 생성입니다.
public:
	CMFC0429listDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC0429_LIST_DIALOG };
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
	afx_msg void OnLvnItemchangedList3(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnLvnItemchangedListResult(NMHDR* pNMHDR, LRESULT* pResult);
	CString studentID;
	CString studentName;
	CString studentCALL;
	CButton online;
	CButton offline;
	BOOL chA;
	BOOL chB;
	CComboBox cbA;
	CComboBox cbB;
	CListCtrl listView;
	void Init();
	afx_msg void OnBnClickedButtonIn();
	afx_msg void OnBnClickedButtonDelete();
	afx_msg void OnBnClickedButtonInit();
	afx_msg void OnBnClickedButtonExit();
	afx_msg void OnLvnItemchangedListView(NMHDR* pNMHDR, LRESULT* pResult);
};
