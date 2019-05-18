// CTextDlg2.cpp: 구현 파일
//

#include "pch.h"
#include "MFC0429_2.h"
#include "CTextDlg2.h"
#include "afxdialogex.h"


// CTextDlg2 대화 상자

IMPLEMENT_DYNAMIC(CTextDlg2, CDialogEx)

CTextDlg2::CTextDlg2(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_TEXT, pParent)
{

}

CTextDlg2::~CTextDlg2()
{
}

void CTextDlg2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTextDlg2, CDialogEx)
END_MESSAGE_MAP()


// CTextDlg2 메시지 처리기
