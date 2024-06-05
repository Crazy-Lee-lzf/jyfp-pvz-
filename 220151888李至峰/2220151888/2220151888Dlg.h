// 2220151888Dlg.h : header file
//

#include "PictureEx.h"
#include <algorithm>
#include "DIY.h"
#include <fstream>
#include "Login.h"

using namespace std;

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
	int pic[50];	//��������ͼƬ˳�� ��ͬһ���Ѷȵ�ͼҲ��һ��
	int timecnt;
	int mode;  // 0 ��ս 1 ���� 2 �Զ���
	int level; //�ڼ��أ���սģʽ����ʲô�Ѷȴ� 0 ��ʼ)
	int record[5][8];	//���а��¼
	int page;			//����ģʽ�ڼ����
	int TIME;			//��ǰ�ؿ������˶��
	int money;			//�������
	int dj1;			//������������
	int dj2;
	int dj3;
	int jindu;			//��ǰ��ҽ��е��˵ڼ���
	int where;			//��ǰ���ĸ�ҳ��

	long spwd;

	bool odd;
	bool right;
	bool running;		//�Ƿ��������� 
	bool flag[100];

	CString rname[5][8];	//����
	CString playernow;	//��ǰ���
	CString temp;

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
	DIFF diffcg[4][5];
	DIFF diff;
	
	void HideAll();		//�������еĿؼ�
	void Start();
	void Show();
	void RandPut();
	void GameWin();		//����ģʽӮ�� �������а� 
	void ShowRank();	//ˢ�����а�
	void Home();		//�ص�������
	void LevelInit();	//��ʼ���ؿ�����
	void Log();			//��¼����
	void Updatedj();	//���µ���
	void Usedj1();
	void Usedj2();
	void Usedj3();
	void BossRand();
// Dialog Data
	
	//{{AFX_DATA(CMy2220151888Dlg)
	enum { IDD = IDD_MY2220151888_DIALOG };
	CPictureEx	tul[5];
	CPictureEx	tu[100];
	CPictureEx	tuZ;
	CPictureEx	tuH;
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
	afx_msg void OnButton11();
	afx_msg void OnButton10();
	afx_msg void OnButton12();
	afx_msg void OnButton13();
	afx_msg void OnButton14();
	afx_msg void OnButton8();
	afx_msg void OnButton9();
	afx_msg void OnButton15();
	afx_msg void OnButton16();
	afx_msg void OnHomepage();
	afx_msg void OnDiff1();
	afx_msg void OnDiff2();
	afx_msg void OnDiff3();
	afx_msg void OnDiff4();
	afx_msg void OnDiff5();
	afx_msg void OnStaticl1();
	afx_msg void OnStaticl2();
	afx_msg void OnStaticl3();
	afx_msg void OnStaticl4();
	afx_msg void OnStaticl5();
	afx_msg void OnButton17();
	afx_msg void OnButton18();
	afx_msg void OnButton19();
	afx_msg void OnPlay();
	afx_msg void OnNoPlay();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_2220151888DLG_H__B40C4B4D_5514_45B1_ACCF_40870B006950__INCLUDED_)
