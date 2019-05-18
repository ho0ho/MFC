#pragma once


// CTextDlg 대화 상자

class CTextDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CTextDlg);

public:
	CTextDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CTextDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_TEXT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP();
public:
	// CTextDlg 클래스 IDC_EDIT_TEXT_INPUT 에 멤버변수 추가	// CTextDlg 클래스 IDC_EDIT_TEXT_INPUT 에 멤버변수 추가	// CTextDlg 클래스 IDC_EDIT_TEXT_INPUT 에 멤버변수 추가	// CTextDlg 클래스 IDC_EDIT_TEXT_INPUT 에 멤버변수 추가	// CTextDlg 클래스 IDC_EDIT_TEXT_INPUT 에 멤버변수 추가	// CTextDlg 클래스 IDC_EDIT_TEXT_INPUT 에 멤버변수 추가	// CTextDlg 클래스 IDC_EDIT_TEXT_INPUT 에 멤버변수 추가	// CTextDlg 클래스 IDC_EDIT_TEXT_INPUT 에 멤버변수 추가
	CString strTextInput;
	afx_msg void OnEnChangeEditTextInput();
};
