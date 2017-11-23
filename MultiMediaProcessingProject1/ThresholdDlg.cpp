// ThresholdDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MultiMediaProcessingProject1.h"
#include "ThresholdDlg.h"
#include "afxdialogex.h"


// CThresholdDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CThresholdDlg, CDialogEx)

CThresholdDlg::CThresholdDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_THRES, pParent)
	, m_nThrValue(0)
{

}

CThresholdDlg::~CThresholdDlg()
{
}

void CThresholdDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_nThrValue);
}


BEGIN_MESSAGE_MAP(CThresholdDlg, CDialogEx)
	ON_BN_CLICKED(IDC_OKBTN, &CThresholdDlg::OnBnClickedOkbtn)
END_MESSAGE_MAP()


// CThresholdDlg �޽��� ó�����Դϴ�.


BOOL CThresholdDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void CThresholdDlg::OnBnClickedOkbtn()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (m_nThrValue < 0 || m_nThrValue>255) AfxMessageBox("0~255 ������ ���ڸ� �Է��ϼ���.");
	else CDialogEx::OnOK();
}
