﻿#pragma once


// CInputDlg 대화 상자

class CInputDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CInputDlg)

public:
	CInputDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CInputDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_IN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CString strNum;
	CString strName;
	afx_msg void OnEnChangeEditName();
	afx_msg void OnBnClickedOk();
};
