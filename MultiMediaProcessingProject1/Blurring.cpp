// Blurring.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MultiMediaProcessingProject1.h"
#include "Blurring.h"
#include "afxdialogex.h"


// CBlurring ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CBlurring, CDialogEx)

CBlurring::CBlurring(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_BLUR, pParent)
	, m_size(0)
{

}

CBlurring::~CBlurring()
{
}

void CBlurring::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CBlurring, CDialogEx)
	ON_BN_CLICKED(IDC_RADIO2, &CBlurring::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO5, &CBlurring::OnBnClickedRadio5)
	ON_BN_CLICKED(IDC_OKBTN, &CBlurring::OnBnClickedOkbtn)
END_MESSAGE_MAP()


// CBlurring �޽��� ó�����Դϴ�.


void CBlurring::OnBnClickedRadio2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_size = 3;
}


void CBlurring::OnBnClickedRadio5()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_size = 5;
}


void CBlurring::OnBnClickedOkbtn()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (m_size == 0) AfxMessageBox("���~!, ����� �����ϼ���.");
	else CDialog::OnOK();
}
