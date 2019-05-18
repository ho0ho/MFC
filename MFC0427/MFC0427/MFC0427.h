
// MFC0427.h: MFC0427 애플리케이션의 기본 헤더 파일
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH에 대해 이 파일을 포함하기 전에 'pch.h'를 포함합니다."
#endif

#include "resource.h"       // 주 기호입니다.


// CMFC0427App:
// 이 클래스의 구현에 대해서는 MFC0427.cpp을(를) 참조하세요.
//

class CMFC0427App : public CWinApp
{
public:
	CMFC0427App() noexcept;


// 재정의입니다.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 구현입니다.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFC0427App theApp;
