// BitPlaneDig.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MultiMediaProcessingProject1.h"
#include "BitPlaneDig.h"
#include "afxdialogex.h"


// CBitPlaneDig ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CBitPlaneDig, CDialogEx)

CBitPlaneDig::CBitPlaneDig(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_BITPLANE, pParent)
	, m_nBit(0)
	, m_spinval(0)
{

}

CBitPlaneDig::~CBitPlaneDig()
{
}

void CBitPlaneDig::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDITBIT, m_nBit);
	DDX_Control(pDX, IDC_SPINBIT, m_spinBit);
}


BEGIN_MESSAGE_MAP(CBitPlaneDig, CDialogEx)
	ON_BN_CLICKED(IDC_OKBTN, &CBitPlaneDig::OnBnClickedOkbtn)
END_MESSAGE_MAP()


// CBitPlaneDig �޽��� ó�����Դϴ�.


BOOL CBitPlaneDig::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	m_spinBit.SetRange(0, 7);
	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void CBitPlaneDig::OnBnClickedOkbtn()
{
	CDialogEx::OnOK();
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

}
