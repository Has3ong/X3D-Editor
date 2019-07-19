
// YangJaeApplicationDlg.h : 헤더 파일
//

#pragma once
#include "afxwin.h"
#include <vector>
#include <algorithm>

using namespace std;

// YangJaeApplicationDlg 대화 상자
class YangJaeApplicationDlg : public CDialogEx
{
// 생성입니다.
public:
	YangJaeApplicationDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
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
