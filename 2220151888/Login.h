#if !defined(AFX_LOGIN_H__545F636F_AA6E_4BB0_94C7_8DA44466CBB6__INCLUDED_)
#define AFX_LOGIN_H__545F636F_AA6E_4BB0_94C7_8DA44466CBB6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Login.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Login dialog

class Login : public CDialog
{
// Construction
public:
	Login(CWnd* pParent = NULL);   // standard constructor
	
	bool flag;

	void Show_Log();
	void Show_Reg();
	long jiami(CString &s);
	int dj1, dj2, dj3, money, jindu;
	long spwd;
// Dialog Data
	//{{AFX_DATA(Login)
	enum { IDD = IDD_DIALOG2 };
	CString	acount;
	CString	pwd;
	CString	repwd;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Login)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Login)
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnStatic3();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOGIN_H__545F636F_AA6E_4BB0_94C7_8DA44466CBB6__INCLUDED_)
