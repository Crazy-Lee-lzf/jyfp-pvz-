// Login.cpp : implementation file
//

#include "stdafx.h"
#include "2220151888.h"
#include "Login.h"
#include <fstream>

using namespace std;
const long M = 10000019;	//c++98 long最大只支持2147483647, 选择一个1e7稍大的质数防止发生溢出

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Login dialog


Login::Login(CWnd* pParent /*=NULL*/)
	: CDialog(Login::IDD, pParent)
{
	//{{AFX_DATA_INIT(Login)
	acount = _T("");
	pwd = _T("");
	repwd = _T("");
	//}}AFX_DATA_INIT
}


void Login::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Login)
	DDX_Text(pDX, IDC_EDIT1, acount);
	DDX_Text(pDX, IDC_EDIT2, pwd);
	DDV_MaxChars(pDX, pwd, 16);
	DDX_Text(pDX, IDC_EDIT3, repwd);
	DDV_MaxChars(pDX, repwd, 16);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Login, CDialog)
	//{{AFX_MSG_MAP(Login)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_STATIC3, OnStatic3)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Login message handlers
long Login::jiami(CString &s){
	long ans = 1;
	for(int i = 0;i < s.GetLength();i++){
		ans = (ans * s[i]) % M;
		ans = (ans * (i + 1)) % M;	//防止位次不对也能密码正确
	}
	return ans;
}
void Login::Show_Log(){
	GetDlgItem(IDC_STATIC2) -> ShowWindow(false);
	GetDlgItem(IDC_EDIT3) -> ShowWindow(false);
	GetDlgItem(IDC_EDIT3) -> SetWindowText("");
	GetDlgItem(IDC_BUTTON1) -> ShowWindow(true);
	GetDlgItem(IDC_BUTTON2) -> ShowWindow(false);

	GetDlgItem(IDC_STATIC3) -> SetWindowText("已有账号？点我登录");
}

void Login::Show_Reg(){
	GetDlgItem(IDC_STATIC2) -> ShowWindow(true);
	GetDlgItem(IDC_EDIT3) -> ShowWindow(true);
	GetDlgItem(IDC_EDIT3) -> SetWindowText("");
	GetDlgItem(IDC_BUTTON2) -> ShowWindow(true);
	GetDlgItem(IDC_BUTTON1) -> ShowWindow(false);

	GetDlgItem(IDC_STATIC3) -> SetWindowText("没有账号？点我注册");
}


void Login::OnButton1() 
{
	// TODO: Add your control notification handler code here

	UpdateData(true);
	CString txt = "players/" + acount + ".txt";
	ifstream ifile(txt, ios_base::in);
	long spwd;
	if(ifile){
		
		ifile >> spwd;
		if(spwd == jiami(pwd)){
			MessageBox("登录成功！欢迎", "登录成功");
			EndDialog(1);
			ifile.close();
		}
		else{
			MessageBox("账号或密码错误！","登录失败");
		}
	}
	else {
		MessageBox("该账号不存在！","登录失败");
	}
	ifile.close();
}

void Login::OnButton2() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	CString txt = "players/" + acount + ".txt";

	ifstream ifile(txt, ios_base::in);
	if(ifile){
		MessageBox("该账号已存在！","注册失败");
		ifile.close();
		return;
	}
	if(pwd != repwd){
		MessageBox("两次输入的密码不一致！","注册失败");
		return ;
	}
	if(acount.IsEmpty() || pwd.IsEmpty() || repwd.IsEmpty()){
		MessageBox("请输入完整信息！","注册失败");
		return ;
	}
	ofstream tfile(txt,ios_base::out);
	tfile << jiami(pwd) << '\n';
	tfile << "0 0 0 0\n";
	tfile.close();

	MessageBox("注册成功，请登录", "注册成功");
	Show_Log();
}

void Login::OnStatic3() 
{
	// TODO: Add your control notification handler code here
	if(flag) Show_Reg();
	else Show_Log();
	flag ^= 1;
}

BOOL Login::OnInitDialog() 
{
	CDialog::OnInitDialog();
	// TODO: Add extra initialization here
	Show_Log();
	flag = 1;
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
