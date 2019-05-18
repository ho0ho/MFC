// CInputDlg.cpp: 구현 파일
//

#include "pch.h"
#include "MFC0429.h"
#include "CInputDlg.h"
#include "afxdialogex.h"


// CInputDlg 대화 상자

IMPLEMENT_DYNAMIC(CInputDlg, CDialogEx)

CInputDlg::CInputDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_IN, pParent)
	, strNum(_T(""))
	, strName(_T(""))
{

}

CInputDlg::~CInputDlg()
{
}

void CInputDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_NUM, strNum);
	DDX_Text(pDX, IDC_EDIT_NAME, strName);
}


BEGIN_MESSAGE_MAP(CInputDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT_NAME, &CInputDlg::OnEnChangeEditName)
	ON_BN_CLICKED(IDOK, &CInputDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CInputDlg 메시지 처리기



void CInputDlg::OnEnChangeEditName()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CInputDlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnOK();
	// IDOK는 특별한 ID값. 
	// 1. 자동으로 내부에서 OnOK()추가 
	// 2. UpdateData(TRUE)를 자동으로 추가실행하여 부모 다이얼로 데이터가 전송됨
}
