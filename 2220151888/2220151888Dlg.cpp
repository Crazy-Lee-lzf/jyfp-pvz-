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

#include <mmsystem.h>		
#pragma comment(lib, "WINMM.LIB")	


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
	where = 0;

	int i, j;
	bool flag;
	char ch;
	ifstream ifile("phb.txt",ios_base::in);
	i = 0;
	j = 0;
	flag = 0;
	while((ch=ifile.get())!=EOF){
		if(ch == '\n') continue;
		if(ch == ' '){
			if(flag == 1)j ++;
			if(j == 8){
				i ++;
				j = 0;
			}
			flag ^= 1;
			record[i][j] = 0;
		}
		else{
			if(flag == 0) rname[i][j] += ch;
			else record[i][j] = record[i][j] * 10 + ch - '0';
		}
	}
	for(i = 0;i < 50;i++) pic[i] = i;
	ifile.close();
	
	LevelInit();


	playernow = "游客";
	page = 1;
	running = 0;

	CString txt = "players/游客.txt";
	ifstream myfin(txt, ios_base::in);
	myfin >> spwd;
	myfin >> dj1 >> dj2 >> dj3 >> money >> jindu;
	
	myfin.close();
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy2220151888Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
		
	//{{AFX_DATA_MAP(CMy2220151888Dlg)
	int i;
	for(i = 0;i < 5;i++)
		DDX_Control(pDX, IDC_STATICL1 + i, tul[i]);
	for(i = 0;i < 100;i++)
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
	ON_BN_CLICKED(IDC_BUTTON17, OnButton17)
	ON_BN_CLICKED(IDC_BUTTON18, OnButton18)
	ON_BN_CLICKED(IDC_BUTTON19, OnButton19)
	ON_COMMAND(Play, OnPlay)
	ON_COMMAND(NoPlay, OnNoPlay)
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
	OnPlay();

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
		KillTimer(2);
		GameWin();
		
	}
}

void CMy2220151888Dlg::Start(){
	HideAll();
	where = 3;
	running = 1;
	TIME = 0;
	start = 0;
	lastnum = -1;
	odd = 1;
	right = 0;

	SetWindowPos(&wndTop, 0, 0, diff.M * 66 + 250 , diff.N * 66 + 250 , SWP_SHOWWINDOW);

	CString temp = "欢迎:  " + playernow;
	GetDlgItem(IDC_STATICName) -> SetWindowText(temp);
	GetDlgItem(IDC_STATICName) -> SetWindowPos(NULL, 0, 0, 250, 30, SWP_SHOWWINDOW);

	GetDlgItem(IDC_BUTTON6) -> SetWindowPos(NULL, diff.N * 66 + 148, 0, 100, 30, SWP_SHOWWINDOW);

	GetDlgItem(IDC_STATICHouse) -> SetWindowPos(NULL, 5, 35, 35, 35, SWP_SHOWWINDOW);
	if(tuH.Load(MAKEINTRESOURCE(IDR_JPG51),_T("jpg")))	tuH.Draw();

	GetDlgItem(IDC_STATICZombie) -> SetWindowPos(NULL, 50 + 66 * diff.M, 35, 35, 35, SWP_SHOWWINDOW);
	if(tuZ.Load(MAKEINTRESOURCE(IDR_GIF1),_T("gif")))	tuZ.Draw();
	
	GetDlgItem(IDC_STATICTime) -> SetWindowPos(NULL, 50 + 66 * diff.M + 45, 35, 200 - 35, 35, SWP_SHOWWINDOW);
	temp.Format("剩余时间：%3d秒", diff.T - TIME);
	GetDlgItem(IDC_STATICTime) -> SetWindowText(temp);
	if(mode == 1){
		GetDlgItem(IDC_STATICL9) -> SetWindowPos(NULL, 0, diff.N * 66 + 170, 200, 30, SWP_SHOWWINDOW);
		temp.Format("金币数量：%6d", money);
		GetDlgItem(IDC_STATICL9) -> SetWindowText(temp);
		if(page > 1 || level > 2){
			GetDlgItem(IDC_STATICL1) -> SetWindowPos(NULL, 70 + 66 * diff.M, 80, 100, 100, SWP_SHOWWINDOW);
			if(tul[0].Load(MAKEINTRESOURCE(IDR_JPG53),_T("jpg")))	tul[0].Draw();

			GetDlgItem(IDC_STATICL2) -> SetWindowPos(NULL, 70 + 66 * diff.M, 80 + 120, 100, 100, SWP_SHOWWINDOW);
			if(tul[1].Load(MAKEINTRESOURCE(IDR_JPG54),_T("jpg")))	tul[1].Draw();

			GetDlgItem(IDC_STATICL3) -> SetWindowPos(NULL, 70 + 66 * diff.M, 80 + 240, 100, 100, SWP_SHOWWINDOW);
			if(tul[2].Load(MAKEINTRESOURCE(IDR_JPG55),_T("jpg")))	tul[2].Draw();

			temp.Format("%d",dj1);
			GetDlgItem(IDC_STATICL6) -> SetWindowPos(NULL, 190 + 66 * diff.M, 120, 30, 30, SWP_SHOWWINDOW);
			GetDlgItem(IDC_STATICL6) -> SetWindowText(temp);

			temp.Format("%d",dj2);
			GetDlgItem(IDC_STATICL7) -> SetWindowPos(NULL, 190 + 66 * diff.M, 120 * 2, 30, 30, SWP_SHOWWINDOW);
			GetDlgItem(IDC_STATICL7) -> SetWindowText(temp);

			temp.Format("%d",dj3);
			GetDlgItem(IDC_STATICL8) -> SetWindowPos(NULL, 190 + 66 * diff.M, 120 * 3, 30, 30, SWP_SHOWWINDOW);
			GetDlgItem(IDC_STATICL8) -> SetWindowText(temp);
		}
	}
	

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
	KillTimer(1);
	KillTimer(2);
	KillTimer(3);
	KillTimer(4);
	end = time(0);
	CString temp;
	temp.Format("  恭喜你过关啦！\n  你一共用时 %5d 秒", end- start);
	MessageBox(temp, "过关");
	
	if(mode == 1){
		if(page == 1){
			money += 3 + level * 2;
		}
		else if(page == 2){
			money += 10 + level * 5;
		}
		else if(page == 3){
			money += 20 + level * 10;
		}
		else if(page == 4){
			money += 50 + level * 30;
		}
		if(money > 99999) money = 99999;
		if(page == 5 && level == 5){
			MessageBox("恭喜你通关了！！！", "通关");
			money = 99999;
		}
		if(page * 5 + level - 5 == jindu) jindu ++;

		Updatedj();
		return ;
	}
	else if(mode == 2) return;
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

	running = 0;
}

void CMy2220151888Dlg::ShowRank(){
	SetWindowPos(&wndTop, 500, 100, 450 , 300 , SWP_SHOWWINDOW);

	GetDlgItem(IDC_LIST1) -> SetWindowPos(NULL, 50, 30, 350, 200, SWP_SHOWWINDOW);

	int i;
	CString temp;
	list_c.ResetContent();
	for(i = 0;i < 8;i++){
		temp.Format("第%1d名：%10s 用时%4d秒",i+1, rname[level][i], record[level][i]);
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
	for(i = 1124;i <= 1146;i++) GetDlgItem(i) -> ShowWindow(false);
}

void CMy2220151888Dlg::Home(){
	HideAll();
	where = 0;

	SetWindowPos(&wndTop, 500, 100, 350 , 450 , SWP_SHOWWINDOW);
	
	CString temp = "欢迎:  " + playernow;
	GetDlgItem(IDC_STATICName) -> SetWindowText(temp);
	GetDlgItem(IDC_STATICName) -> SetWindowPos(NULL, 0, 0, 250, 30, SWP_SHOWWINDOW);
	GetDlgItem(IDC_BUTTON11) -> SetWindowPos(NULL, 250, 0, 100, 30, SWP_SHOWWINDOW);

	GetDlgItem(IDC_BUTTON12) -> SetWindowPos(NULL, 100, 120, 150, 40, SWP_SHOWWINDOW);
	GetDlgItem(IDC_BUTTON13) -> SetWindowPos(NULL, 100, 170, 150, 40, SWP_SHOWWINDOW);
	GetDlgItem(IDC_BUTTON14) -> SetWindowPos(NULL, 100, 220, 150, 40, SWP_SHOWWINDOW);

	running = 0;
	KillTimer(1);
	KillTimer(2);
	KillTimer(3);
	KillTimer(4);
}

void CMy2220151888Dlg::Log(){
	Login login;
	if(login.DoModal() == 1){
		spwd = login.spwd;
		playernow = login.acount;
		dj1 = login.dj1;
		dj2 = login.dj2;
		dj3 = login.dj3;
		money = login.money;
		jindu = login.jindu;
	}
	Home();
}

void CMy2220151888Dlg::Updatedj(){
	ofstream myout("players/" + playernow + ".txt",ios_base::out);
	myout << spwd << '\n';
	myout << dj1 << ' ' << dj2 << ' ' << dj3 << ' ' << money << ' ' << jindu << '\n';
	myout.close();
}

void CMy2220151888Dlg::Usedj1(){
	if(start == 0 || running == 0){
		MessageBox("我知道你很急，但是你先别急(开始之后才能使用道具,阳光使用期间也不能使用道具)", "使用失败");
		return ;
	}
	else if(dj1 == 0){
		MessageBox("道具数量不足，快去商店购买吧", "使用失败");
		return ;
	}
	dj1 --;
	temp.Format("%d",dj1);
	GetDlgItem(IDC_STATICL6) -> SetWindowPos(NULL, 190 + 66 * diff.M, 120, 30, 30, SWP_SHOWWINDOW);
	GetDlgItem(IDC_STATICL6) -> SetWindowText(temp);
	running = 0;
	int i;
	int n = diff.N*diff.M;
	for(i = 0;i < n;i++){
		if((n&1) && i == n/2) continue;
		if(tu[i].Load(MAKEINTRESOURCE(IDR_JPG1+ans[i]),_T("jpg")))	tu[i].Draw();
	}
	SetTimer(3, 5000, NULL);
	KillTimer(2);

	Updatedj();
}
void CMy2220151888Dlg::Usedj2(){
	if(start == 0 || running == 0){
		MessageBox("我知道你很急，但是你先别急(开始之后才能使用道具,阳光使用期间也不能使用道具)", "使用失败");
		return ;
	}
	else if(dj1 == 0){
		MessageBox("道具数量不足，快去商店购买吧", "使用失败");
		return ;
	}

	dj2 --;
	temp.Format("%d",dj2);
	GetDlgItem(IDC_STATICL7) -> SetWindowPos(NULL, 190 + 66 * diff.M, 120 * 2, 30, 30, SWP_SHOWWINDOW);
	GetDlgItem(IDC_STATICL7) -> SetWindowText(temp);
	int n = diff.N * diff.M;
	int tar = -1;
	for(int i = 0;i < n;i++){
		if((n&1) && i == n/2) continue;
		if(flag[i] == 0){
			if(tar == -1) tar = i;
			else if(ans[tar] == ans[i]){
				flag[tar] = 1;
				flag[i] = 1;
				Show();
				return ;
			}
		}
	}

	Updatedj();
}
void CMy2220151888Dlg::Usedj3(){
	if(start == 0 || running == 0){
		MessageBox("我知道你很急，但是你先别急(开始之后才能使用道具,阳光使用期间也不能使用道具)", "使用失败");
		return ;
	}
	else if(dj1 == 0){
		MessageBox("道具数量不足，快去商店购买吧", "使用失败");
		return ;
	}
	temp.Format("%d",dj3);
	GetDlgItem(IDC_STATICL8) -> SetWindowPos(NULL, 190 + 66 * diff.M, 120 * 3, 30, 30, SWP_SHOWWINDOW);
	GetDlgItem(IDC_STATICL8) -> SetWindowText(temp);
	diff.T += 30;

	Updatedj();
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
	diff.N = 4;
	diff.M = 4;
	diff.t = 4000;
	diff.n4 = 0;
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
	diff.T = 600;
	level = 4;
	Start();
}

void CMy2220151888Dlg::OnButton6() 
{
	// TODO: Add your control notification handler code here
	KillTimer(1);
	KillTimer(2);
	KillTimer(3);
	KillTimer(4);
	if(where == 1){
		Home();
	}
	else if(where == 2){
		OnButton12();
	}
	else if(where == 3){
		if(mode == 1)	OnButton8();
		else	OnButton13();
	}
}

void CMy2220151888Dlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	int l, i, n, p;
	double x;
	switch(nIDEvent){
		case 1:
			Show();
			lastnum = -1;
			odd = 1;
			KillTimer(1);
			break;
		case 2:
			TIME++;
			l = 66 * diff.M;
			x = (diff.T - TIME) * 1.0 / diff.T;
			GetDlgItem(IDC_STATICZombie) -> SetWindowPos(NULL, 50 + l * x, 35, 35, 35, SWP_SHOWWINDOW);
			temp.Format("剩余时间：%3d秒", diff.T - TIME);
			GetDlgItem(IDC_STATICTime) -> SetWindowText(temp);
			if(TIME == diff.T){
				KillTimer(2);
				MessageBox("僵尸吃掉了你的脑子","失败");
				Home();
			}
			if(level == 5 && TIME % 30 == 0 && mode == 1){
				MessageBox("BOSS发动了攻击打乱了你的所有卡牌（每30秒一次）", "BOSS发动攻击", MB_ICONWARNING);
				n = diff.N * diff.M;
				vector<int> temp_pic;
				for(i = 0;i < n;i++){
					if(flag[i] == 0) temp_pic.push_back(ans[i]);
				}
				std::random_shuffle(temp_pic.begin(), temp_pic.end());
				p = 0;
				for(i = 0;i < n;i++){
					if(flag[i] == 0) ans[i] = temp_pic[p++];
				}
			}
			break;
		case 3:
			running = 1;
			n = diff.N*diff.M;
			for(i = 0;i < n;i++){
				if((n&1) && i == n/2) continue;
				if(flag[i] == 0) if(tu[i].Load(MAKEINTRESOURCE(bg),_T("jpg"))) tu[i].Draw();
				else if(tu[i].Load(MAKEINTRESOURCE(IDR_JPG1+ans[i]),_T("jpg")))	tu[i].Draw();
			}
			SetTimer(2, 1000, NULL);
			break;
			
	}
	CDialog::OnTimer(nIDEvent);
}

void CMy2220151888Dlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(right == 1) return;
	if(running == 0) return;
	
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
		diff.T = diy.T;
		diff.boss = 0;
		Start();
	}
	mode = 2;
}

void CMy2220151888Dlg::OnButton11() 
{
	// TODO: Add your control notification handler code here
	Log();
}

void CMy2220151888Dlg::OnButton10() 
{
	// TODO: Add your control notification handler code here
	HideAll();
	where = 2;
	
	SetWindowPos(&wndTop, 500, 100, 650 , 550 , SWP_SHOWWINDOW);
	GetDlgItem(IDC_BUTTON6) -> SetWindowPos(NULL, 650 - 101, 0, 100, 30, SWP_SHOWWINDOW);

	CString temp = "欢迎:  " + playernow;
	GetDlgItem(IDC_STATICName) -> SetWindowText(temp);
	GetDlgItem(IDC_STATICName) -> SetWindowPos(NULL, 0, 0, 350, 30, SWP_SHOWWINDOW);

	GetDlgItem(IDC_STATIC0) -> SetWindowPos(NULL, 50, 50, 100, 100, SWP_SHOWWINDOW);
	if(tu[0].Load(MAKEINTRESOURCE(IDR_JPG53),_T("jpg")))	tu[0].Draw();
	GetDlgItem(IDC_STATIC1) -> SetWindowPos(NULL, 50, 50 + 150, 100, 100, SWP_SHOWWINDOW);
	if(tu[1].Load(MAKEINTRESOURCE(IDR_JPG54),_T("jpg")))	tu[1].Draw();
	GetDlgItem(IDC_STATIC2) -> SetWindowPos(NULL, 50, 50 + 300, 100, 100, SWP_SHOWWINDOW);
	if(tu[2].Load(MAKEINTRESOURCE(IDR_JPG55),_T("jpg")))	tu[2].Draw();
	
	GetDlgItem(IDC_STATICL6) -> SetWindowPos(NULL, 170, 50, 500, 60, SWP_SHOWWINDOW);
	temp.Format("阳光，查看全场卡片5秒，售价：20金币\n\r已有数量：%3d",dj1);
	GetDlgItem(IDC_STATICL6) -> SetWindowText(temp);

	GetDlgItem(IDC_STATICL7) -> SetWindowPos(NULL, 170, 50 + 150, 500, 60, SWP_SHOWWINDOW);
	temp.Format("钉耙，自动随机翻开一对植物，售价：10金币\n\r已有数量：%3d",dj2);
	GetDlgItem(IDC_STATICL7) -> SetWindowText(temp);

	GetDlgItem(IDC_STATICL8) -> SetWindowPos(NULL, 170, 50 + 300, 500, 60, SWP_SHOWWINDOW);
	temp.Format("小推车，阻挡僵尸进攻三十秒，售价：100金币\n\r已有数量：%3d",dj3);
	GetDlgItem(IDC_STATICL8) -> SetWindowText(temp);

	GetDlgItem(IDC_STATICL9) -> SetWindowPos(NULL, 0, 470, 200, 30, SWP_SHOWWINDOW);
	temp.Format("金币数量：%6d", money);
	GetDlgItem(IDC_STATICL9) -> SetWindowText(temp);
	

	GetDlgItem(IDC_BUTTON17) -> SetWindowPos(NULL, 170, 120, 100, 30, SWP_SHOWWINDOW);
	GetDlgItem(IDC_BUTTON18) -> SetWindowPos(NULL, 170, 120 + 150, 100, 30, SWP_SHOWWINDOW);
	GetDlgItem(IDC_BUTTON19) -> SetWindowPos(NULL, 170, 120 + 300, 100, 30, SWP_SHOWWINDOW);
	
}

void CMy2220151888Dlg::OnButton12() 
{
	// TODO: Add your control notification handler code here
	HideAll();
	mode = 1;
	where = 1;

	SetWindowPos(&wndTop, 500, 100, 350 , 450 , SWP_SHOWWINDOW);
	
	CString temp = "欢迎:  " + playernow;
	GetDlgItem(IDC_STATICName) -> SetWindowText(temp);
	GetDlgItem(IDC_STATICName) -> SetWindowPos(NULL, 0, 0, 350, 30, SWP_SHOWWINDOW);

//	GetDlgItem(IDC_BUTTON9) -> SetWindowPos(NULL, 100, 70 + 50 * 1, 150, 40, SWP_SHOWWINDOW);
	GetDlgItem(IDC_BUTTON8) -> SetWindowPos(NULL, 100, 70 + 50 * 1, 150, 40, SWP_SHOWWINDOW);
	GetDlgItem(IDC_BUTTON10) -> SetWindowPos(NULL, 100, 70 + 50 * 2, 150, 40, SWP_SHOWWINDOW);
	GetDlgItem(IDC_BUTTON6) -> SetWindowPos(NULL, 100, 70 + 50 * 3, 150, 40, SWP_SHOWWINDOW);


}

void CMy2220151888Dlg::OnButton13() 
{
	// TODO: Add your control notification handler code here
	HideAll();
	where = 1;
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
	EndDialog(1);
}

void CMy2220151888Dlg::OnButton8() 
{
	// TODO: Add your control notification handler code here
	HideAll();
	where = 2;

	SetWindowPos(&wndTop, 400, 250, 550, 250, SWP_SHOWWINDOW);
	
	CString temp = "欢迎:  " + playernow;
	GetDlgItem(IDC_STATICName) -> SetWindowText(temp);
	GetDlgItem(IDC_STATICName) -> SetWindowPos(NULL, 0, 0, 350, 30, SWP_SHOWWINDOW);

	GetDlgItem(IDC_BUTTON6) -> SetWindowPos(NULL, 550 - 101, 0, 100, 30, SWP_SHOWWINDOW);
	GetDlgItem(IDC_BUTTON15) -> SetWindowPos(NULL, 70, 150, 100, 30, SWP_SHOWWINDOW);
	GetDlgItem(IDC_BUTTON16) -> SetWindowPos(NULL, 330, 150, 100, 30, SWP_SHOWWINDOW);

	int i = 0;
	for(i = 0;i < 5;i++){
		if(page * 5 + i - 4 > jindu) break;
		GetDlgItem(IDC_STATICL1 + i) -> SetWindowPos(NULL,  50 + 100 * i, 40, 70, 70, SWP_SHOWWINDOW);
		if(tul[i].Load(MAKEINTRESOURCE(IDR_JPG52),_T("jpg")))	tul[i].Draw();

		GetDlgItem(IDC_STATICL6 + i) -> SetWindowPos(NULL,  50 + 100 * i, 120, 70, 30, SWP_SHOWWINDOW);

		temp.Format("%d - %d", page, i + 1);
		GetDlgItem(IDC_STATICL6 + i) -> SetWindowText(temp);
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
	if(page * 5 >= jindu) return;
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

/*
DIFF(){
	N = 0, M = 0, t = 0;
	n4 = 0;
	T = 0;
	boss = 0;
};
*/

void CMy2220151888Dlg::LevelInit(){
	ifstream ifile("level.txt",ios_base::in);

	int i, j;
	for(i = 0;i < 4;i++){
		for(j = 0;j < 5;j++){
			ifile >> diffcg[i][j].N;
			ifile >> diffcg[i][j].M;
			ifile >> diffcg[i][j].n4;
			ifile >> diffcg[i][j].t;
			ifile >> diffcg[i][j].T;
			ifile >> diffcg[i][j].boss;
			diffcg[i][j].t *= 1000;
		}
	}
	ifile.close();

}

void CMy2220151888Dlg::OnStaticl1() 
{
	// TODO: Add your control notification handler code here
	if(where == 3){
		Usedj1();
		return ;
	}
	diff = diffcg[page - 1][0];
	level = 1;
	Start();
}

void CMy2220151888Dlg::OnStaticl2() 
{
	// TODO: Add your control notification handler code here
	if(where == 3){
		Usedj2();
		return ;
	}
	diff = diffcg[page - 1][1];
	level = 2;
	Start();
}

void CMy2220151888Dlg::OnStaticl3() 
{
	// TODO: Add your control notification handler code here
	if(where == 3){
		Usedj3();
		return ;
	}
	diff = diffcg[page - 1][2];
	level = 3;
	Start();
}

void CMy2220151888Dlg::OnStaticl4() 
{
	// TODO: Add your control notification handler code here
	diff = diffcg[page - 1][3];
	level = 4;
	Start();
}

void CMy2220151888Dlg::OnStaticl5() 
{
	// TODO: Add your control notification handler code here
	diff = diffcg[page - 1][4];
	level = 5;
	Start();
}

void CMy2220151888Dlg::OnButton17() 
{
	// TODO: Add your control notification handler code here
	if(money < 20){
		MessageBox("金币不足！", "购买失败");
		return ;
	}
	else if(dj1 >= 9){
		MessageBox("已到达持有上限（9个）", "购买失败");
		return ;
	}
	money -= 20;
	dj1 ++;
	GetDlgItem(IDC_STATICL6) -> SetWindowPos(NULL, 170, 50, 500, 60, SWP_SHOWWINDOW);
	temp.Format("阳光，查看全场卡片5秒，售价：20金币\n\r已有数量：%3d",dj1);
	GetDlgItem(IDC_STATICL6) -> SetWindowText(temp);

	GetDlgItem(IDC_STATICL9) -> SetWindowPos(NULL, 0, 470, 200, 30, SWP_SHOWWINDOW);
	temp.Format("金币数量：%6d", money);
	GetDlgItem(IDC_STATICL9) -> SetWindowText(temp);

	Updatedj();
}

void CMy2220151888Dlg::OnButton18() 
{
	// TODO: Add your control notification handler code here
	if(money < 10){
		MessageBox("金币不足！", "购买失败");
		return ;
	}
	else if(dj2 >= 9){
		MessageBox("已到达持有上限（9个）", "购买失败");
		return ;
	}
	money -= 10;
	dj2 ++;
	
	GetDlgItem(IDC_STATICL7) -> SetWindowPos(NULL, 170, 50 + 150, 500, 60, SWP_SHOWWINDOW);
	temp.Format("钉耙，自动随机翻开一对植物，售价：10金币\n\r已有数量：%3d",dj2);
	GetDlgItem(IDC_STATICL7) -> SetWindowText(temp);

	GetDlgItem(IDC_STATICL9) -> SetWindowPos(NULL, 0, 470, 200, 30, SWP_SHOWWINDOW);
	temp.Format("金币数量：%6d", money);
	GetDlgItem(IDC_STATICL9) -> SetWindowText(temp);

	Updatedj();
}

void CMy2220151888Dlg::OnButton19() 
{
	// TODO: Add your control notification handler code here
	if(money < 100){
		MessageBox("金币不足！", "购买失败");
		return ;
	}
	else if(dj3 >= 9){
		MessageBox("已到达持有上限（9个）", "购买失败");
		return ;
	}
	money -= 100;
	dj3 ++;

	GetDlgItem(IDC_STATICL8) -> SetWindowPos(NULL, 170, 50 + 300, 500, 60, SWP_SHOWWINDOW);
	temp.Format("小推车，阻挡僵尸进攻三十秒，售价：100金币\n\r已有数量：%3d",dj3);
	GetDlgItem(IDC_STATICL8) -> SetWindowText(temp);

	GetDlgItem(IDC_STATICL9) -> SetWindowPos(NULL, 0, 470, 200, 30, SWP_SHOWWINDOW);
	temp.Format("金币数量：%6d", money);
	GetDlgItem(IDC_STATICL9) -> SetWindowText(temp);

	Updatedj();
}

void CMy2220151888Dlg::OnPlay() 
{
	// TODO: Add your command handler code here
	PlaySound(MAKEINTRESOURCE(IDR_WAVE1),NULL,SND_ASYNC|SND_RESOURCE|SND_LOOP);
}

void CMy2220151888Dlg::OnNoPlay() 
{
	// TODO: Add your command handler code here
	PlaySound(NULL,NULL,NULL);
}
