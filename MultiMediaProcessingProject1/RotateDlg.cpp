// RotateDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MultiMediaProcessingProject1.h"
#include "RotateDlg.h"
#include "afxdialogex.h"


// CRotateDlg 대화 상자입니다.

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


// CRotateDlg 메시지 처리기입니다.


BOOL CRotateDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	m_spinCtrl.SetRange(0, 360);
	m_rotAngle = 0;
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
