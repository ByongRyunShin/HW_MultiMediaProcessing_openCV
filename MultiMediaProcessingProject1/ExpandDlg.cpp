// ExpandDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MultiMediaProcessingProject1.h"
#include "ExpandDlg.h"
#include "afxdialogex.h"


// CExpandDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CExpandDlg, CDialogEx)

CExpandDlg::CExpandDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_EXPAND, pParent)
	, m_Inter(-1)
	, m_ratiov(0)
{

}

CExpandDlg::~CExpandDlg()
{
}

void CExpandDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDITRATIO, m_ratiov);
	DDX_Control(pDX, IDC_SPINRATIO, m_spinRatio);
}


BEGIN_MESSAGE_MAP(CExpandDlg, CDialogEx)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPINRATIO, &CExpandDlg::OnDeltaposSpinratio)
	ON_BN_CLICKED(IDC_RADIO1, &CExpandDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CExpandDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_OKBTN, &CExpandDlg::OnBnClickedOkbtn)
END_MESSAGE_MAP()

// CExpandDlg �޽��� ó�����Դϴ�.

BOOL CExpandDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	//m_spinRatio.SetRange(0, 100);
	m_ratiov = 100;
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void CExpandDlg::OnDeltaposSpinratio(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	*pResult = 0;
}


void CExpandDlg::OnBnClickedRadio1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_Inter = cv::INTER_NEAREST;
}

void CExpandDlg::OnBnClickedRadio2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_Inter = cv::INTER_LINEAR;
}

void CExpandDlg::OnBnClickedOkbtn()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (m_Inter == -1) AfxMessageBox("���! ���� ����� �����ϼ���!");
	else CDialog::OnOK();
}