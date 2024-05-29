// 605.h : main header file for the 605 application
//

#if !defined(AFX_605_H__A1E840C3_CA6F_4EBC_923F_64246DD68F8E__INCLUDED_)
#define AFX_605_H__A1E840C3_CA6F_4EBC_923F_64246DD68F8E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMy605App:
// See 605.cpp for the implementation of this class
//

class CMy605App : public CWinApp
{
public:
	CMy605App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy605App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMy605App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_605_H__A1E840C3_CA6F_4EBC_923F_64246DD68F8E__INCLUDED_)
