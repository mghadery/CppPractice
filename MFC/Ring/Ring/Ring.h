
// Ring.h : main header file for the Ring application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CRingApp:
// See Ring.cpp for the implementation of this class
//

class CRingApp : public CWinApp
{
public:
	CRingApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CRingApp theApp;
