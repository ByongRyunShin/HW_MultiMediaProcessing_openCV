#pragma once
#include "afxcmn.h"


// CBitPlaneDig ��ȭ �����Դϴ�.

class CBitPlaneDig : public CDialogEx
{
	DECLARE_DYNAMIC(CBitPlaneDig)

public:
	CBitPlaneDig(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CBitPlaneDig();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BITPLANE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	UINT m_nBit;
	CSpinButtonCtrl m_spinBit;
	virtual BOOL OnInitDialog();
	int m_spinval;
	afx_msg void OnBnClickedOkbtn();
};
