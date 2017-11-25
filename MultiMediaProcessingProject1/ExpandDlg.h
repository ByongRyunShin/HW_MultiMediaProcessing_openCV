#pragma once
#include "afxcmn.h"
#include <opencv2/opencv.hpp>

// CExpandDlg ��ȭ �����Դϴ�.

class CExpandDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CExpandDlg)

public:
	CExpandDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CExpandDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EXPAND };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

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
