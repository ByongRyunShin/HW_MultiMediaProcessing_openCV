#pragma once


// CBlurring ��ȭ �����Դϴ�.

class CBlurring : public CDialogEx
{
	DECLARE_DYNAMIC(CBlurring)

public:
	CBlurring(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CBlurring();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BLUR };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedRadio2();
	int m_size;
	afx_msg void OnBnClickedRadio5();
	afx_msg void OnBnClickedOkbtn();
};
