// 2220151888Dlg.h : header file
//

#include "PictureEx.h"
#include <algorithm>
#include "DIY.h"

#if !defined(AFX_2220151888DLG_H__B40C4B4D_5514_45B1_ACCF_40870B006950__INCLUDED_)
#define AFX_2220151888DLG_H__B40C4B4D_5514_45B1_ACCF_40870B006950__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMy2220151888Dlg dialog

class CMy2220151888Dlg : public CDialog
{
// Construction
public:
	CMy2220151888Dlg(CWnd* pParent = NULL);	// standard constructor
	int lastnum, nownum;
	int ans[100];
	int pic[50];	//用来打乱图片顺序 让同一个难度的图也不一样
	int timecnt;
	int mode;  // 0 挑战 1 闯关 2 自定义
	int level; //第几关（挑战模式则是什么难度从 0 开始
	int record[5][8];	//排行榜记录

	bool odd;
	bool right;
	bool flag[100];

	CString rname[5][8];	//姓名
	CString playernow;	//当前玩家

	time_t start;
	time_t end;

	struct DIFF{
		int N, M, t;
		int	n4;
		int T;
		bool boss;
		DIFF(){
			N = 0, M = 0, t = 0;
			n4 = 0;
			T = 0;
			boss = 0;
		};
		DIFF(int n,int m,int time, int cnt4, int TIME, bool flag):N(n), M(m), t(time), n4(cnt4), T(TIME), boss(flag){};
		DIFF(const DIFF &p){
			N = p.N;
			M = p.M;
			t = p.t;
			n4 = p.n4;
			boss = p.boss;
			T = p.T;
		};
	};
	DIFF diffgz[20];
	DIFF diff;

	void Start();
	void Show();
	void RandPut();
	void GameWin();		//闯关模式赢了 更新排行榜 
	void ShowRank();	//刷新排行榜
// Dialog Data
	//{{AFX_DATA(CMy2220151888Dlg)
	enum { IDD = IDD_MY2220151888_DIALOG };
	CPictureEx	tu[100];
	CListBox	list_c;
	CString	list_v;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy2220151888Dlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMy2220151888Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	afx_msg void OnButton4();
	afx_msg void OnButton5();
	afx_msg void OnButton6();
	afx_msg void OnButton7();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_2220151888DLG_H__B40C4B4D_5514_45B1_ACCF_40870B006950__INCLUDED_)
