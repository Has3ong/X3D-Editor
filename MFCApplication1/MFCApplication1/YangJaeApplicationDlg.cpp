
// YangJaeApplicationDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "YangJaeApplication.h"
#include "YangJaeApplicationDlg.h"
#include "afxdialogex.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	// �����Դϴ�.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// YangJaeApplicationDlg ��ȭ ����



YangJaeApplicationDlg::YangJaeApplicationDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(YangJaeApplicationDlg::IDD, pParent)
	, m_strFind(_T(""))
	, m_strReplace(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void YangJaeApplicationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_FIND_EDIT, m_strFind);
	DDX_Text(pDX, IDC_REPLACE_EDIT, m_strReplace);
	DDX_Control(pDX, IDC_CHANGE_EDIT, m_editData);
}

BEGIN_MESSAGE_MAP(YangJaeApplicationDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_OPEN_BUTTON, &YangJaeApplicationDlg::OnBnClickedOpenButton)
	ON_BN_CLICKED(IDC_SAVE_BUTTON, &YangJaeApplicationDlg::OnBnClickedSaveButton)
	ON_BN_CLICKED(IDC_FIND_BUTTON, &YangJaeApplicationDlg::OnBnClickedFindButton)
	ON_BN_CLICKED(IDC_REPLACE_BUTTON, &YangJaeApplicationDlg::OnBnClickedReplaceButton)
	ON_BN_CLICKED(IDC_REPLACEALL_BUTTON, &YangJaeApplicationDlg::OnBnClickedReplaceallButton)
	ON_BN_CLICKED(IDC_CLEAR_BUTTON, &YangJaeApplicationDlg::OnBnClickedClearButton)
END_MESSAGE_MAP()


// YangJaeApplicationDlg �޽��� ó����

BOOL YangJaeApplicationDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
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

	// �� ��ȭ ������ �������� �����մϴ�. ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	ShowWindow(SW_MINIMIZE);

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void YangJaeApplicationDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�. ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void YangJaeApplicationDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);

		CRect rect;
		GetClientRect(&rect);

		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR YangJaeApplicationDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void YangJaeApplicationDlg::OnBnClickedOpenButton()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	static TCHAR BASED_CODE Filter[] = _T(" X3D Files (*.x3d) |*.X3D| All Files(*.*)|*.*||");
	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY, Filter);
	
	if (IDOK == dlg.DoModal())
	{
		m_Open = dlg.GetPathName();
		CStdioFile file;  
		if(file.Open(m_Open, CFile::modeRead | CFile::typeText)) 
		{ 
			CString strDisplay, strData; 
			strData=""; 
			strDisplay=""; 

			while(file.ReadString(strData)) 
			{ 
				strDisplay += strData; 
				strDisplay += _T("\r\n"); 
			} 

			SetDlgItemText(IDC_ORIGINAL_EDIT, strDisplay); 
			SetDlgItemText(IDC_CHANGE_EDIT, strDisplay);
		} 
	}	
	/*
	if (IDOK == dlg.DoModal())
	{
		m_Open = dlg.GetPathName();
		CStdioFile file;
		if(file.Open(m_Open, CFile::modeRead | CFile::typeText))
		{
			CString strData;
			while(file.ReadString(strData))
			{
				v_strData.push_back(strData);
				strData += "\r\n";
				
				SetDlgItemText(IDC_ORIGINAL_EDIT, strData); 
				SetDlgItemText(IDC_CHANGE_EDIT, strData);
			}
			file.Close(); 
		}
	}
	*/
}



void YangJaeApplicationDlg::OnBnClickedSaveButton()
{

	CString strData;
	static TCHAR BASED_CODE Filter[] = _T(" X3D Files (*.x3d) |*.X3D| WRL Files (*.wrl) |*.wrl| All Files(*.*)|*.*||");
	CFileDialog dlg(FALSE, NULL, NULL, OFN_HIDEREADONLY, Filter);

	if (IDOK == dlg.DoModal())
	{
		m_Save = dlg.GetPathName();
		CStdioFile file;
		if(file.Open(m_Save, CFile::modeWrite | CFile::modeCreate))
		{
			GetDlgItemText(IDC_CHANGE_EDIT, strData);
			strData.Replace(_T("\r\n"), _T("\n"));
			file.WriteString(strData);
		}

		MessageBox(_T("Complete"));
		SetDlgItemText(IDC_ORIGINAL_EDIT, _T(""));
		SetDlgItemText(IDC_CHANGE_EDIT, _T(""));
	}
}


void YangJaeApplicationDlg::OnBnClickedClearButton()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	MessageBox(_T("Clear"));
	SetDlgItemText(IDC_ORIGINAL_EDIT, _T(""));
	SetDlgItemText(IDC_CHANGE_EDIT, _T(""));
}

void YangJaeApplicationDlg::OnBnClickedFindButton()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	
	CString strData;
	
	pEdit = (CEdit*)GetDlgItem(IDC_CHANGE_EDIT);
	/*
	CString check;
	pEdit->GetWindowTextW(check);
	if(check.IsEmpty())
	{
		MessageBox(_T("STRING NULL"));
		return;
	}
	*/

	GetDlgItemText(IDC_FIND_EDIT, m_strFind);
	GetDlgItemText(IDC_CHANGE_EDIT, strData);
	length = m_strFind.GetLength();

	if (nDelimiter < 0)
		nDelimiter = strData.Find(m_strFind);
	else 
		nDelimiter = strData.Find(m_strFind, nDelimiter);

	if (nDelimiter < 0)
	{
		MessageBox(_T("FIND NULL"));
		return;
	}
	else
	{
		pEdit->SetSel(nDelimiter, nDelimiter + length);
		pEdit->SetFocus();
		nDelimiter = nDelimiter + length;
	}
}


void YangJaeApplicationDlg::OnBnClickedReplaceButton()
{
	CString strData;

	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	GetDlgItemText(IDC_FIND_EDIT, m_strFind);
	GetDlgItemText(IDC_REPLACE_EDIT, m_strReplace);
	
	pEdit->Clear();
	pEdit->ReplaceSel(m_strReplace);


	pEdit = (CEdit*)GetDlgItem(IDC_CHANGE_EDIT);
	GetDlgItemText(IDC_CHANGE_EDIT, strData);

 	length = m_strFind.GetLength();

	if (nDelimiter < 0)
		nDelimiter = strData.Find(m_strFind);
	else 
		nDelimiter = strData.Find(m_strFind, nDelimiter);


	if (nDelimiter < 0)
	{
		MessageBox(_T("FIND NULL"));
		return;
	}
	else
	{
		pEdit->SetSel(nDelimiter, nDelimiter + length);
		pEdit->SetFocus();
		nDelimiter = nDelimiter + length;
	}
}


void YangJaeApplicationDlg::OnBnClickedReplaceallButton()
{
	CString strData;
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	GetDlgItemText(IDC_FIND_EDIT, m_strFind);
	GetDlgItemText(IDC_REPLACE_EDIT, m_strReplace);

	while(1)
	{
		pEdit = (CEdit*)GetDlgItem(IDC_CHANGE_EDIT);
		GetDlgItemText(IDC_CHANGE_EDIT, strData);

 		length = m_strFind.GetLength();

		if (nDelimiter < 0)
			nDelimiter = strData.Find(m_strFind);
		else 
			nDelimiter = strData.Find(m_strFind, nDelimiter);

		if (nDelimiter < 0)
		{
			MessageBox(_T("REPLACE ALL"));
			return;
		}
		else
		{
			pEdit->SetSel(nDelimiter, nDelimiter + length);
			pEdit->SetFocus();
			pEdit->Clear();
			pEdit->ReplaceSel(m_strReplace);
			nDelimiter = nDelimiter + length;
		}
	}
	
}

