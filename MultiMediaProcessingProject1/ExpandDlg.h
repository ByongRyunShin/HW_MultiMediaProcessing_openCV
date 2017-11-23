#pragma once


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
};
