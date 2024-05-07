// 2220151888Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "2220151888.h"
#include "2220151888Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy2220151888Dlg dialog

CMy2220151888Dlg::CMy2220151888Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMy2220151888Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMy2220151888Dlg)
	list_v = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	int i, j;
	for(i = 0;i < 50;i++) pic[i] = i;
	for(i = 0;i < 5;i++){
		for(j = 0;j < 8;j++){
			record[i][j] = 9992 + j;
			rname[i][j] = "无名氏";
		}
	}
	playernow = "crazy_lee";
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy2220151888Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMy2220151888Dlg)
	for(int i=0;i<100;i++)
		DDX_Control(pDX, IDC_STATIC0 + i, tu[i]);
	DDX_Control(pDX, IDC_LIST1, list_c);
	DDX_LBString(pDX, IDC_LIST1, list_v);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMy2220151888Dlg, CDialog)
	//{{AFX_MSG_MAP(CMy2220151888Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5)
	ON_BN_CLICKED(IDC_BUTTON6, OnButton6)
	ON_BN_CLICKED(IDC_BUTTON7, OnButton7)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy2220151888Dlg message handlers

BOOL CMy2220151888Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	SetWindowPos(&wndTop, 300, 100, 400 + 10*66, 200 + 10 * 66, SWP_SHOWWINDOW);

	GetDlgItem(IDC_BUTTON1) -> SetWindowPos(NULL, 100, 150, 150, 30, SWP_SHOWWINDOW);
	GetDlgItem(IDC_BUTTON2) -> SetWindowPos(NULL, 100, 200, 150, 30, SWP_SHOWWINDOW);
	GetDlgItem(IDC_BUTTON3) -> SetWindowPos(NULL, 100, 250, 150, 30, SWP_SHOWWINDOW);
	GetDlgItem(IDC_BUTTON4) -> SetWindowPos(NULL, 100, 300, 150, 30, SWP_SHOWWINDOW);
	GetDlgItem(IDC_BUTTON5) -> SetWindowPos(NULL, 100, 350, 150, 30, SWP_SHOWWINDOW);
	GetDlgItem(IDC_BUTTON6) -> SetWindowPos(NULL, 100, 450, 150, 30, SWP_SHOWWINDOW);
	GetDlgItem(IDC_BUTTON7) -> SetWindowPos(NULL, 100, 400, 150, 30, SWP_SHOWWINDOW);
	GetDlgItem(IDC_LIST1) -> SetWindowPos(NULL, 50, 500, 300, 200, SWP_SHOWWINDOW);

	GetDlgItem(IDC_BUTTON6) -> EnableWindow(false);
	GetDlgItem(IDC_LIST1) -> ShowWindow(false);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMy2220151888Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMy2220151888Dlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMy2220151888Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMy2220151888Dlg::RandPut(){
	srand(time(0));
	int i;
	int n = (diff.N*diff.M);
	// 打乱图片顺序
	std::random_shuffle(pic, pic + 50);
	for(i = 0;i < n/2;i++){
		ans[i*2] = pic[i];
		ans[i*2 + 1] = pic[i];
	}
	//如果有k个四个的，就将最后k个数字变成0 - k -1 注意判断 N*M是奇数的情况
	for(i = 0;i < diff.n4;i++){
		ans[n - i*2 - (n&1) -1] = pic[i];
		ans[n - i*2 - (n&1) -2] = pic[i];
	}
	std::random_shuffle(ans, ans + (diff.N*diff.M) );
	// 把奇数的最后一个放中间
	if(n&1){
		for(i = 0;i < n;i++){
			if(ans[i] == -1){
				std::swap(ans[i], ans[n/2]);
			}
		}
	}
}

void CMy2220151888Dlg::Show(){
	right = 1;
	int i;
	int n = diff.N*diff.M;
	for(i = 0;i < n;i++){
		if((n&1) && i == n/2) continue;
	//	if(tu[i].Load(MAKEINTRESOURCE(IDR_JPG1+ans[i]),_T("jpg")))	tu[i].Draw();
		if(flag[i] == 0){
			right = 0;
			if(tu[i].Load(MAKEINTRESOURCE(bg),_T("jpg")))	tu[i].Draw();
		}
		else{
			if(tu[i].Load(MAKEINTRESOURCE(IDR_JPG1+ans[i]),_T("jpg")))	tu[i].Draw();
		}
	}
	if(right == 1){
		GameWin();
	}
}

void CMy2220151888Dlg::Start(){
	start = 0;
	if(mode == 0){
		GetDlgItem(IDC_BUTTON1) -> EnableWindow(false);
		GetDlgItem(IDC_BUTTON2) -> EnableWindow(false);
		GetDlgItem(IDC_BUTTON3) -> EnableWindow(false);
		GetDlgItem(IDC_BUTTON4) -> EnableWindow(false);
		GetDlgItem(IDC_BUTTON5) -> EnableWindow(false);
		GetDlgItem(IDC_BUTTON7) -> EnableWindow(false);
		GetDlgItem(IDC_BUTTON6) -> EnableWindow(true);
	}
	lastnum = -1;
	odd = 1;
	right = 0;
	int i;
	int n = diff.N*diff.M;
	for(i = 0;i < n;i++){
		ans[i] = -1;
		flag[i] = 0;
		GetDlgItem(IDC_STATIC0 + i) -> SetWindowPos(NULL, 360 + 66*(i%diff.M), 100 + 66*(i/diff.M), 65, 65, SWP_SHOWWINDOW);
	}
	if( n&1 ) GetDlgItem(IDC_STATIC0 + n/2) -> ShowWindow(false);
	RandPut();
	Show();
	ShowRank();
}

void CMy2220151888Dlg::GameWin(){
	end = time(0);
	CString temp;
	temp.Format("  恭喜你过关啦！\n  你一共用时 %5d 秒", end- start);
	MessageBox(temp, "过关");
	int i = 0;
	if(end - start < record[level][7]){
		temp.Format("w(°ｏ°)w 你打破了记录，太厉害啦!");
		MessageBox(temp, "新记录");
		record[level][7] = end - start;
		rname[level][7] = playernow;
		for(i = 6;i >= 0;i--){
			if(record[level][i] > record[level][i+1]){
				std::swap(record[level][i], record[level][i+1]);
				std::swap(rname[level][i], rname[level][i+1]);
			}
		}
		ShowRank();
	}
}

void CMy2220151888Dlg::ShowRank(){
	if(mode != 0 || level > 4) return ;
	int i;
	CString temp;
	list_c.ResetContent();
	for(i = 0;i < 8;i++){
		temp.Format("第%1d名：%6s 用时%4d秒",i+1, rname[level][i], record[level][i]);
		list_c.AddString(temp);
	}
	switch(level){
		case 0:temp = "新手难度排行榜";break;
		case 1:temp = "普通难度排行榜";break;
		case 2:temp = "中级难度排行榜";break;
		case 3:temp = "困难难度排行榜";break;
		case 4:temp = "地狱难度排行榜";break;
	}
	list_c.InsertString(0, temp);
	GetDlgItem(IDC_LIST1) -> ShowWindow(true);

}
void CMy2220151888Dlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	diff.N = 2;
	diff.M = 2;
	diff.t = 5000;
	diff.n4 = 0;
	diff.boss = 0;
	diff.T = 10;
	level = 0;
	Start();
}

void CMy2220151888Dlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	diff.N = 5;
	diff.M = 5;
	diff.t = 4000;
	diff.n4 = 2;
	diff.boss = 0;
	diff.T = 30;
	level = 1;
	Start();
}

void CMy2220151888Dlg::OnButton3() 
{
	// TODO: Add your control notification handler code here
	diff.N = 6;
	diff.M = 6;
	diff.t = 3000;
	diff.n4 = 0;
	diff.boss = 0;
	diff.T = 150;
	level = 2;
	Start();
}

void CMy2220151888Dlg::OnButton4() 
{
	// TODO: Add your control notification handler code here
	diff.N = 8;
	diff.M = 8;
	diff.t = 2000;
	diff.n4 = 0;
	diff.boss = 0;
	diff.T = 300;
	level = 3;
	Start();
}

void CMy2220151888Dlg::OnButton5() 
{
	// TODO: Add your control notification handler code here
	diff.N = 10;
	diff.M = 10;
	diff.t = 1500;
	diff.n4 = 6;
	diff.boss = 0;
	diff.T = 720;
	level = 4;
	Start();
}

void CMy2220151888Dlg::OnButton6() 
{
	// TODO: Add your control notification handler code here
	int i;
	for(i = 0;i < 100;i++) GetDlgItem(IDC_STATIC0 + i) -> ShowWindow(false);
	
	GetDlgItem(IDC_BUTTON1) -> EnableWindow(true);
	GetDlgItem(IDC_BUTTON2) -> EnableWindow(true);
	GetDlgItem(IDC_BUTTON3) -> EnableWindow(true);
	GetDlgItem(IDC_BUTTON4) -> EnableWindow(true);
	GetDlgItem(IDC_BUTTON5) -> EnableWindow(true);
	GetDlgItem(IDC_BUTTON7) -> EnableWindow(true);
	GetDlgItem(IDC_BUTTON6) -> EnableWindow(false);
	GetDlgItem(IDC_LIST1) -> ShowWindow(false);

}

void CMy2220151888Dlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	switch(nIDEvent){
		case 1:
			Show();
			lastnum = -1;
			odd = 1;
			KillTimer(1);
			break;
		default: break;
	}
	CDialog::OnTimer(nIDEvent);
}

void CMy2220151888Dlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(right == 1) return;
	
	CPoint pt;
	GetCursorPos(&pt);
	CRect rectBtn;
	GetDlgItem(IDC_STATIC0)->GetWindowRect(&rectBtn);
	int x=(pt.y-rectBtn.top)/(65+1);
	int y=(pt.x-rectBtn.left)/(65+1);
	nownum = x*diff.M+y;
	
	if(lastnum == nownum) return ;
	if(pt.y-rectBtn.top<0 || x>diff.N-1|| pt.x-rectBtn.left<0 || y>diff.M-1)	return;
	if(flag[nownum] == 1) return ;
	if(start == 0) start = time(0);
	KillTimer(1);
	if(odd == 1){
		Show();
		if(tu[nownum].Load(MAKEINTRESOURCE(IDR_JPG1+ans[nownum]),_T("jpg")))	tu[nownum].Draw();
		SetTimer(1, diff.t, NULL);
	}
	else{
		if(tu[nownum].Load(MAKEINTRESOURCE(IDR_JPG1+ans[nownum]),_T("jpg")))	tu[nownum].Draw();
		if(ans[lastnum] == ans[nownum]){
			flag[lastnum] = 1;
			flag[nownum] = 1;
			Show();
		}
		else{
			SetTimer(1, diff.t, NULL);
		}
	}
	lastnum = nownum;
	odd ^= 1;

	CDialog::OnLButtonDown(nFlags, point);
}

BOOL CMy2220151888Dlg::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CDialog::PreTranslateMessage(pMsg);
}

void CMy2220151888Dlg::OnButton7() 
{
	// TODO: Add your control notification handler code here
	DIY diy;
	if(diy.DoModal() == 1){
		diff.N = diy.N;
		diff.M = diy.M;
		diff.n4 = diy.n4;
		diff.t = diy.t;
		diff.T = diff.T;
		diff.boss = 0;
		level = 5; 
		Start();
	}
}
