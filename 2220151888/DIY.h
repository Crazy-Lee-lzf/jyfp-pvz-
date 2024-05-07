#if !defined(AFX_DIY_H__C82186BF_0FB3_4185_8CB3_3DBF18E78A79__INCLUDED_)
#define AFX_DIY_H__C82186BF_0FB3_4185_8CB3_3DBF18E78A79__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DIY.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// DIY dialog

class DIY : public CDialog
{
// Construction
public:
	DIY(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DIY)
	enum { IDD = IDD_DIALOG1 };
	int		N;
	int		M;
	int		n4;
	int		t;
	int		T;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DIY)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DIY)
	afx_msg void OnButton1();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIY_H__C82186BF_0FB3_4185_8CB3_3DBF18E78A79__INCLUDED_)
