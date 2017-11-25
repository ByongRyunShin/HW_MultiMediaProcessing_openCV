// ExpandDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MultiMediaProcessingProject1.h"
#include "ExpandDlg.h"
#include "afxdialogex.h"


// CExpandDlg 대화 상자입니다.

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

// CExpandDlg 메시지 처리기입니다.

BOOL CExpandDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	//m_spinRatio.SetRange(0, 100);
	m_ratiov = 100;
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CExpandDlg::OnDeltaposSpinratio(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;
}


void CExpandDlg::OnBnClickedRadio1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_Inter = cv::INTER_NEAREST;
}

void CExpandDlg::OnBnClickedRadio2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_Inter = cv::INTER_LINEAR;
}

void CExpandDlg::OnBnClickedOkbtn()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_Inter == -1) AfxMessageBox("띠용! 보간 방식을 선택하세요!");
	else CDialog::OnOK();
}