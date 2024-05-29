// 605Dlg.h : header file
//

#include <mmsystem.h>
#pragma comment(lib, "WINMM.LIB");

#if !defined(AFX_605DLG_H__939B167B_045F_4645_A4F4_E037137D8B38__INCLUDED_)
#define AFX_605DLG_H__939B167B_045F_4645_A4F4_E037137D8B38__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMy605Dlg dialog

class CMy605Dlg : public CDialog
{
// Construction
public:
	CMy605Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMy605Dlg)
	enum { IDD = IDD_MY605_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy605Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMy605Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_605DLG_H__939B167B_045F_4645_A4F4_E037137D8B38__INCLUDED_)
