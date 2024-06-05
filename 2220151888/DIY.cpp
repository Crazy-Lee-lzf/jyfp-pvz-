// DIY.cpp : implementation file
//

#include "stdafx.h"
#include "2220151888.h"
#include "DIY.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DIY dialog

DIY::DIY(CWnd* pParent /*=NULL*/)
	: CDialog(DIY::IDD, pParent)
{
	//{{AFX_DATA_INIT(DIY)
	N = 2;
	M = 2;
	n4 = 0;
	t = 5000;
	T = 10;
	//}}AFX_DATA_INIT
}


void DIY::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DIY)
	DDX_Text(pDX, IDC_EDIT1, N);
	DDX_Text(pDX, IDC_EDIT2, M);
	DDX_Text(pDX, IDC_EDIT3, n4);
	DDX_Text(pDX, IDC_EDIT4, t);
	DDX_Text(pDX, IDC_EDIT5, T);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DIY, CDialog)
	//{{AFX_MSG_MAP(DIY)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DIY message handlers
BOOL DIY::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	SetWindowPos(&wndTop, 600, 300, 300, 400, SWP_SHOWWINDOW);
//	GetDlgItem(
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void DIY::OnButton1() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	if(N * M > 100){
		MessageBox("太大了！最大N * M不能超过100", "创建失败");
		return ;
	}
	if(n4 * 4 > N * M){
		MessageBox("你算算能有这么多图出现两对吗", "创建失败");
		return ;
	}
	EndDialog(1);
}
