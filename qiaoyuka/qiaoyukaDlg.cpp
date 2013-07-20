
// qiaoyukaDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "qiaoyuka.h"
#include "qiaoyukaDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define  TIMER_CHECKQYK     1000
// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CqiaoyukaDlg �Ի���




CqiaoyukaDlg::CqiaoyukaDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CqiaoyukaDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_hQyk = NULL;
}

void CqiaoyukaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_QIAOYUKAEXE, m_Edit_QiaoyukaExe);
	DDX_Control(pDX, IDC_STATICMEI, m_hyperlink);
	DDX_Control(pDX, IDC_STATICDSNIXI, m_Static_DiaoSiNiXi);
}

BEGIN_MESSAGE_MAP(CqiaoyukaDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON_SEND, &CqiaoyukaDlg::OnBnClickedButtonSend)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CqiaoyukaDlg ��Ϣ��������

BOOL CqiaoyukaDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��������...���˵������ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��
    //m_hyperlink.SetColors(RGB(255,0,0));
    m_hyperlink.SetURL(L"http://blog.sina.com.cn/s/blog_ac930a9f01018ouq.html");
	// TODO: �ڴ����Ӷ���ĳ�ʼ������
    m_Static_DiaoSiNiXi.SetURL(_T("http://blog.sina.com.cn/s/blog_8335c2af01013j8a.html"));
   SetTimer(TIMER_CHECKQYK,1000,0);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CqiaoyukaDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի���������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CqiaoyukaDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CqiaoyukaDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CqiaoyukaDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ�������Ϣ������������/�����Ĭ��ֵ
   if(nIDEvent == TIMER_CHECKQYK)
   {
      CWnd *hQiaoYuKa = FindWindow(NULL,_T("������"));
     

	  if(hQiaoYuKa != NULL)
	  {
		  m_hQyk = hQiaoYuKa->GetSafeHwnd();
		  m_Edit_QiaoyukaExe.SetWindowText(_T("������������"));
	  }
	  else
	  {
          m_Edit_QiaoyukaExe.SetWindowText(_T("������������"));
	  }

   }
	CDialog::OnTimer(nIDEvent);
}

void CqiaoyukaDlg::OnBnClickedButtonSend()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	if(m_hQyk != NULL)
	{  
		CRect  cli;
		::GetClientRect(m_hQyk,cli);
		  ScreenToClient(cli);
		//mouse_event(

	}
	else
	{
      AfxMessageBox(_T("���ȴ�������"));
	}

}

HBRUSH CqiaoyukaDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	if(pWnd->m_hWnd == GetDlgItem(IDC_EDIT_QIAOYUKAEXE)->GetSafeHwnd() ||pWnd->m_hWnd == GetDlgItem(IDC_STATICMEI)->GetSafeHwnd())   
	{   
		//pDC->SetBkColor(RGB(0,255,0));
		pDC->SetTextColor(RGB(255,0,0));
		return   (HBRUSH)m_brush;   
	} 
	// TODO:  �ڴ˸��� DC ���κ�����

	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return hbr;
}