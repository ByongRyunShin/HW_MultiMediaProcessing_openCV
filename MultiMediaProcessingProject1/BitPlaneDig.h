#pragma once
#include "afxcmn.h"


// CBitPlaneDig 대화 상자입니다.

class CBitPlaneDig : public CDialogEx
{
	DECLARE_DYNAMIC(CBitPlaneDig)

public:
	CBitPlaneDig(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CBitPlaneDig();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BITPLANE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	UINT m_nBit;
	CSpinButtonCtrl m_spinBit;
	virtual BOOL OnInitDialog();
	int m_spinval;
	afx_msg void OnBnClickedOkbtn();
};
