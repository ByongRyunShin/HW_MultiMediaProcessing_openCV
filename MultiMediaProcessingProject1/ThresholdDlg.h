#pragma once


// CThresholdDlg ��ȭ �����Դϴ�.

class CThresholdDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CThresholdDlg)

public:
	CThresholdDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CThresholdDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_THRES };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	UINT m_nThrValue;
	afx_msg void OnBnClickedOkbtn();
};
