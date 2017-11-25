#pragma once
#include "afxcmn.h"
#include <opencv2/opencv.hpp>

// CExpandDlg 대화 상자입니다.

class CExpandDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CExpandDlg)

public:
	CExpandDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CExpandDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EXPAND };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	int m_Inter;
	UINT m_ratiov;
	virtual BOOL OnInitDialog();
	afx_msg void OnDeltaposSpinratio(NMHDR *pNMHDR, LRESULT *pResult);
	CSpinButtonCtrl m_spinRatio;
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedOkbtn();
};
