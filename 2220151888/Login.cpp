// Login.cpp : implementation file
//

#include "stdafx.h"
#include "2220151888.h"
#include "Login.h"
#include <fstream>

using namespace std;
const long M = 10000019;	//c++98 long���ֻ֧��2147483647, ѡ��һ��1e7�Դ��������ֹ�������

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
		ans = (ans * (i + 1)) % M;	//��ֹλ�β���Ҳ��������ȷ
	}
	return ans;
}
void Login::Show_Log(){
	GetDlgItem(IDC_STATIC2) -> ShowWindow(false);
	GetDlgItem(IDC_EDIT3) -> ShowWindow(false);
	GetDlgItem(IDC_EDIT3) -> SetWindowText("");
	GetDlgItem(IDC_BUTTON1) -> ShowWindow(true);
	GetDlgItem(IDC_BUTTON2) -> ShowWindow(false);

	GetDlgItem(IDC_STATIC3) -> SetWindowText("�����˺ţ����ҵ�¼");
}

void Login::Show_Reg(){
	GetDlgItem(IDC_STATIC2) -> ShowWindow(true);
	GetDlgItem(IDC_EDIT3) -> ShowWindow(true);
	GetDlgItem(IDC_EDIT3) -> SetWindowText("");
	GetDlgItem(IDC_BUTTON2) -> ShowWindow(true);
	GetDlgItem(IDC_BUTTON1) -> ShowWindow(false);

	GetDlgItem(IDC_STATIC3) -> SetWindowText("û���˺ţ�����ע��");
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
			MessageBox("��¼�ɹ�����ӭ", "��¼�ɹ�");
			EndDialog(1);
			ifile.close();
		}
		else{
			MessageBox("�˺Ż��������","��¼ʧ��");
		}
	}
	else {
		MessageBox("���˺Ų����ڣ�","��¼ʧ��");
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
		MessageBox("���˺��Ѵ��ڣ�","ע��ʧ��");
		ifile.close();
		return;
	}
	if(pwd != repwd){
		MessageBox("������������벻һ�£�","ע��ʧ��");
		return ;
	}
	if(acount.IsEmpty() || pwd.IsEmpty() || repwd.IsEmpty()){
		MessageBox("������������Ϣ��","ע��ʧ��");
		return ;
	}
	ofstream tfile(txt,ios_base::out);
	tfile << jiami(pwd) << '\n';
	tfile << "0 0 0 0\n";
	tfile.close();

	MessageBox("ע��ɹ������¼", "ע��ɹ�");
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
