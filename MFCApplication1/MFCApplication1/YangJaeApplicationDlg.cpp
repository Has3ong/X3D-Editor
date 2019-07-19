
// YangJaeApplicationDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "YangJaeApplication.h"
#include "YangJaeApplicationDlg.h"
#include "afxdialogex.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 대화 상자 데이터입니다.
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	// 구현입니다.
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


// YangJaeApplicationDlg 대화 상자



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


// YangJaeApplicationDlg 메시지 처리기

BOOL YangJaeApplicationDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다. 응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	ShowWindow(SW_MINIMIZE);

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다. 문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void YangJaeApplicationDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);

		CRect rect;
		GetClientRect(&rect);

		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR YangJaeApplicationDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void YangJaeApplicationDlg::OnBnClickedOpenButton()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	MessageBox(_T("Clear"));
	SetDlgItemText(IDC_ORIGINAL_EDIT, _T(""));
	SetDlgItemText(IDC_CHANGE_EDIT, _T(""));
}

void YangJaeApplicationDlg::OnBnClickedFindButton()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	
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

	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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

