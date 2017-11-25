#pragma once
#include "afxcmn.h"


// CRotateDlg 대화 상자입니다.

class CRotateDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CRotateDlg)

public:
	CRotateDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CRotateDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ROTATE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	UINT m_rotAngle;
	CSpinButtonCtrl m_spinCtrl;
	virtual BOOL OnInitDialog();
};
