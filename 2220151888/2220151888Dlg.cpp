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
	
	int i, j, time;
	bool flag;
	char ch;
	ifstream ifile("phb.txt",ios_base::in);
	i = 0;
	j = 0;
	time = 0;
	flag = 0;
	while((ch=ifile.get())!=EOF){
		if(ch == '\n') continue;
		if(ch == ' '){
			if(flag == 0) flag = 1;
			else{
				record[i][j] = time;
				time = 0;
				j ++;
				if(j == 8){
					i ++;
					j = 0;
				}
				flag = 0;
			}
		}
		else{
			if(flag == 0) rname[i][j] += ch;
			else time = time * 10 + ch - '0';
		}
	}
	for(i = 0;i < 50;i++) pic[i] = i;
	ifile.close();

	playernow = "crazy_lee";
	page = 1;

	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy2220151888Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
		
	//{{AFX_DATA_MAP(CMy2220151888Dlg)
	for(int i = 0;i < 100;i++)
		DDX_Control(pDX, IDC_STATIC0 + i, tu[i]);
	DDX_Control(pDX, IDC_STATICZombie, tuZ);
	DDX_Control(pDX, IDC_STATICHouse, tuH);
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
	ON_BN_CLICKED(IDC_BUTTON11, OnButton11)
	ON_BN_CLICKED(IDC_BUTTON10, OnButton10)
	ON_BN_CLICKED(IDC_BUTTON12, OnButton12)
	ON_BN_CLICKED(IDC_BUTTON13, OnButton13)
	ON_BN_CLICKED(IDC_BUTTON14, OnButton14)
	ON_BN_CLICKED(IDC_BUTTON8, OnButton8)
	ON_BN_CLICKED(IDC_BUTTON9, OnButton9)
	ON_BN_CLICKED(IDC_BUTTON15, OnButton15)
	ON_BN_CLICKED(IDC_BUTTON16, OnButton16)
	ON_COMMAND(ID_MENUITEM32771, OnHomepage)
	ON_COMMAND(ID_MENUITEM32772, OnDiff1)
	ON_COMMAND(ID_MENUITEM32773, OnDiff2)
	ON_COMMAND(ID_MENUITEM32774, OnDiff3)
	ON_COMMAND(ID_MENUITEM32775, OnDiff4)
	ON_COMMAND(ID_MENUITEM32776, OnDiff5)
	ON_BN_CLICKED(IDC_STATICL1, OnStaticl1)
	ON_BN_CLICKED(IDC_STATICL2, OnStaticl2)
	ON_BN_CLICKED(IDC_STATICL3, OnStaticl3)
	ON_BN_CLICKED(IDC_STATICL4, OnStaticl4)
	ON_BN_CLICKED(IDC_STATICL5, OnStaticl5)
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
	Home();
	

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
		KillTimer(2);
	}
}

void CMy2220151888Dlg::Start(){
	HideAll();
	
	SetWindowPos(&wndTop, 0, 0, diff.M * 66 + 250 , diff.N * 66 + 250 , SWP_SHOWWINDOW);

	CString temp = "欢迎:  " + playernow;
	GetDlgItem(IDC_STATICName) -> SetWindowText(temp);
	GetDlgItem(IDC_STATICName) -> SetWindowPos(NULL, 0, 0, 250, 30, SWP_SHOWWINDOW);

	GetDlgItem(IDC_BUTTON6) -> SetWindowPos(NULL, diff.N * 66 + 148, 0, 100, 30, SWP_SHOWWINDOW);

	GetDlgItem(IDC_STATICHouse) -> SetWindowPos(NULL, 5, 35, 35, 35, SWP_SHOWWINDOW);
	if(tuH.Load(MAKEINTRESOURCE(IDR_JPG51),_T("jpg")))	tuH.Draw();

	GetDlgItem(IDC_STATICZombie) -> SetWindowPos(NULL, 50 + 66 * diff.M, 35, 35, 35, SWP_SHOWWINDOW);
	if(tuZ.Load(MAKEINTRESOURCE(IDR_GIF1),_T("gif")))	tuZ.Draw();


	start = 0;
	lastnum = -1;
	odd = 1;
	right = 0;
	int i;
	int n = diff.N*diff.M;
	for(i = 0;i < n;i++){
		ans[i] = -1;
		flag[i] = 0;
		GetDlgItem(IDC_STATIC0 + i) -> SetWindowPos(NULL,  50 + 66*(i%diff.M), 70 + 66*(i/diff.M), 65, 65, SWP_SHOWWINDOW);
	}
	if( n&1 ) GetDlgItem(IDC_STATIC0 + n/2) -> ShowWindow(false);
	RandPut();
	Show();


}

void CMy2220151888Dlg::GameWin(){
	end = time(0);
	CString temp;
	temp.Format("  恭喜你过关啦！\n  你一共用时 %5d 秒", end- start);
	MessageBox(temp, "过关");
	int i, j, p;
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
	}
	ofstream tfile("phb.txt",ios_base::out);
	for(i = 0;i < 5;i++){
		for(j = 0;j <8;j++){
			p = 0;
			while(rname[i][j].GetAt(p)!=0)
				tfile << rname[i][j].GetAt(p++);
			tfile << " ";
			tfile << record[i][j] << " \n";
		}
	}
	tfile.close();
}

void CMy2220151888Dlg::ShowRank(){
	SetWindowPos(&wndTop, 500, 100, 450 , 300 , SWP_SHOWWINDOW);

	GetDlgItem(IDC_LIST1) -> SetWindowPos(NULL, 50, 30, 350, 200, SWP_SHOWWINDOW);

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
	

}

void CMy2220151888Dlg::HideAll(){
	int i = 0;
	for(i = 1000;i <= 1110;i++) GetDlgItem(i) -> ShowWindow(false);
	for(i = 1124;i <= 1138;i++) GetDlgItem(i) -> ShowWindow(false);
}

void CMy2220151888Dlg::Home(){
	HideAll();

	SetWindowPos(&wndTop, 500, 100, 350 , 450 , SWP_SHOWWINDOW);
	
	CString temp = "欢迎:  " + playernow;
	GetDlgItem(IDC_STATICName) -> SetWindowText(temp);
	GetDlgItem(IDC_STATICName) -> SetWindowPos(NULL, 0, 0, 250, 30, SWP_SHOWWINDOW);
	GetDlgItem(IDC_BUTTON11) -> SetWindowPos(NULL, 250, 0, 100, 30, SWP_SHOWWINDOW);

	GetDlgItem(IDC_BUTTON12) -> SetWindowPos(NULL, 100, 120, 150, 40, SWP_SHOWWINDOW);
	GetDlgItem(IDC_BUTTON13) -> SetWindowPos(NULL, 100, 170, 150, 40, SWP_SHOWWINDOW);
	GetDlgItem(IDC_BUTTON14) -> SetWindowPos(NULL, 100, 220, 150, 40, SWP_SHOWWINDOW);
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
	Home();
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
		case 2:
			TIME++;
			int l = 66 * diff.M;
			double x = (diff.T - TIME) * 1.0 / diff.T;
			GetDlgItem(IDC_STATICZombie) -> SetWindowPos(NULL, 50 + l * x, 35, 35, 35, SWP_SHOWWINDOW);
			if(TIME == diff.T){
				KillTimer(2);
				MessageBox("僵尸吃掉了你的脑子","失败");
				OnButton13();
			}

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
	if(start == 0){
		start = time(0);
		SetTimer(2, 1000, NULL);
	}
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

void CMy2220151888Dlg::OnButton11() 
{
	// TODO: Add your control notification handler code here
	
}

void CMy2220151888Dlg::OnButton10() 
{
	// TODO: Add your control notification handler code here
	
}

void CMy2220151888Dlg::OnButton12() 
{
	// TODO: Add your control notification handler code here
	HideAll();
	mode = 1;

	SetWindowPos(&wndTop, 500, 100, 350 , 450 , SWP_SHOWWINDOW);
	
	CString temp = "欢迎:  " + playernow;
	GetDlgItem(IDC_STATICName) -> SetWindowText(temp);
	GetDlgItem(IDC_STATICName) -> SetWindowPos(NULL, 0, 0, 350, 30, SWP_SHOWWINDOW);

	GetDlgItem(IDC_BUTTON9) -> SetWindowPos(NULL, 100, 70 + 50 * 1, 150, 40, SWP_SHOWWINDOW);
	GetDlgItem(IDC_BUTTON8) -> SetWindowPos(NULL, 100, 70 + 50 * 2, 150, 40, SWP_SHOWWINDOW);
	GetDlgItem(IDC_BUTTON10) -> SetWindowPos(NULL, 100, 70 + 50 * 3, 150, 40, SWP_SHOWWINDOW);
	GetDlgItem(IDC_BUTTON6) -> SetWindowPos(NULL, 100, 70 + 50 * 4, 150, 40, SWP_SHOWWINDOW);


}

void CMy2220151888Dlg::OnButton13() 
{
	// TODO: Add your control notification handler code here
	HideAll();
	SetWindowPos(&wndTop, 500, 100, 350 , 550 , SWP_SHOWWINDOW);
	
	CString temp = "欢迎:  " + playernow;
	GetDlgItem(IDC_STATICName) -> SetWindowText(temp);
	GetDlgItem(IDC_STATICName) -> SetWindowPos(NULL, 0, 0, 350, 30, SWP_SHOWWINDOW);

	int i;
	for(i = 0;i < 5;i++){
		GetDlgItem(IDC_BUTTON1 + i) -> SetWindowPos(NULL, 100, 70 + 50 * i, 150, 40, SWP_SHOWWINDOW);
	}
	GetDlgItem(IDC_BUTTON6) -> SetWindowPos(NULL, 100, 70 + 50 * 6, 150, 40, SWP_SHOWWINDOW);
	GetDlgItem(IDC_BUTTON7) -> SetWindowPos(NULL, 100, 70 + 50 * 5, 150, 40, SWP_SHOWWINDOW);
	
	mode = 0;

}

void CMy2220151888Dlg::OnButton14() 
{
	// TODO: Add your control notification handler code here
	
}

void CMy2220151888Dlg::OnButton8() 
{
	// TODO: Add your control notification handler code here
	HideAll();
	SetWindowPos(&wndTop, 400, 250, 550, 250, SWP_SHOWWINDOW);
	
	CString temp = "欢迎:  " + playernow;
	GetDlgItem(IDC_STATICName) -> SetWindowText(temp);
	GetDlgItem(IDC_STATICName) -> SetWindowPos(NULL, 0, 0, 350, 30, SWP_SHOWWINDOW);

	GetDlgItem(IDC_BUTTON15) -> SetWindowPos(NULL, 70, 150, 100, 30, SWP_SHOWWINDOW);
	GetDlgItem(IDC_BUTTON16) -> SetWindowPos(NULL, 330, 150, 100, 30, SWP_SHOWWINDOW);

	int i = 0;
//	CString temp;
	for(i = 0;i < 5;i++){
		GetDlgItem(IDC_STATIC0 + i) -> SetWindowPos(NULL,  50 + 100 * i, 40, 70, 70, SWP_SHOWWINDOW);
		if(tu[i].Load(MAKEINTRESOURCE(IDR_JPG52),_T("jpg")))	tu[i].Draw();

		GetDlgItem(IDC_STATICL1 + i) -> SetWindowPos(NULL,  50 + 100 * i, 120, 70, 30, SWP_SHOWWINDOW);

		temp.Format("%d - %d", page, i + 1);
		GetDlgItem(IDC_STATICL1 + i) -> SetWindowText(temp);
	}

}

void CMy2220151888Dlg::OnButton9() 
{
	// TODO: Add your control notification handler code here
	
}

void CMy2220151888Dlg::OnButton15() 
{
	// TODO: Add your control notification handler code here
	if(page != 1){
		page --;
		OnButton8();
	}
}

void CMy2220151888Dlg::OnButton16() 
{
	// TODO: Add your control notification handler code here
	if(page != 4){
		page ++;
		OnButton8();
	}
}

void CMy2220151888Dlg::OnHomepage() 
{
	// TODO: Add your command handler code here
	Home();
}

void CMy2220151888Dlg::OnDiff1() 
{
	// TODO: Add your command handler code here
	HideAll();
	level = 0;
	ShowRank();
}

void CMy2220151888Dlg::OnDiff2() 
{
	// TODO: Add your command handler code here
	HideAll();
	level = 1;
	ShowRank();
}

void CMy2220151888Dlg::OnDiff3() 
{
	// TODO: Add your command handler code here
	HideAll();
	level = 2;
	ShowRank();
}

void CMy2220151888Dlg::OnDiff4() 
{
	// TODO: Add your command handler code here
	HideAll();
	level = 3;
	ShowRank();
}

void CMy2220151888Dlg::OnDiff5() 
{
	// TODO: Add your command handler code here
	HideAll();
	level = 4;
	ShowRank();
}


void CMy2220151888Dlg::LevelInit(){

}

void CMy2220151888Dlg::OnStaticl1() 
{
	// TODO: Add your control notification handler code here
	
}

void CMy2220151888Dlg::OnStaticl2() 
{
	// TODO: Add your control notification handler code here
	
}

void CMy2220151888Dlg::OnStaticl3() 
{
	// TODO: Add your control notification handler code here
	
}

void CMy2220151888Dlg::OnStaticl4() 
{
	// TODO: Add your control notification handler code here
	
}

void CMy2220151888Dlg::OnStaticl5() 
{
	// TODO: Add your control notification handler code here
	
}
