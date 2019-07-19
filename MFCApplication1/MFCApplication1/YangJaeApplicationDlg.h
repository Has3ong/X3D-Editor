
// YangJaeApplicationDlg.h : ��� ����
//

#pragma once
#include "afxwin.h"
#include <vector>
#include <algorithm>

using namespace std;

// YangJaeApplicationDlg ��ȭ ����
class YangJaeApplicationDlg : public CDialogEx
{
// �����Դϴ�.
public:
	YangJaeApplicationDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOpenButton();
	afx_msg void OnBnClickedSaveButton();
	afx_msg void OnBnClickedFindButton();
	afx_msg void OnBnClickedReplaceButton();
	afx_msg void OnBnClickedReplaceallButton();

	CString m_Open;
	CString m_Save;
	CString m_strFind;
	CString m_strReplace;
	CEdit m_editData;
	CEdit *pEdit;
	vector<CString> v_strData;
	afx_msg void OnBnClickedClearButton();
	int length;
	int nDelimiter;
};
