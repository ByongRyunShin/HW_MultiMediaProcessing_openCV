// RotateDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MultiMediaProcessingProject1.h"
#include "RotateDlg.h"
#include "afxdialogex.h"


// CRotateDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CRotateDlg, CDialogEx)

CRotateDlg::CRotateDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ROTATE, pParent)
	, m_rotAngle(0)
{

}

CRotateDlg::~CRotateDlg()
{
}

void CRotateDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDITANGLE, m_rotAngle);
	DDX_Control(pDX, IDC_SPINANGLE, m_spinCtrl);
}


BEGIN_MESSAGE_MAP(CRotateDlg, CDialogEx)
END_MESSAGE_MAP()


// CRotateDlg �޽��� ó�����Դϴ�.


BOOL CRotateDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	m_spinCtrl.SetRange(0, 360);
	m_rotAngle = 0;
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}
