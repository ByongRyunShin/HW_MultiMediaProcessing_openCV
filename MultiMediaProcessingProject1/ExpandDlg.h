#pragma once


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
};
