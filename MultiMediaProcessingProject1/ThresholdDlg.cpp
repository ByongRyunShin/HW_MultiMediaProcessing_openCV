// ThresholdDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MultiMediaProcessingProject1.h"
#include "ThresholdDlg.h"
#include "afxdialogex.h"


// CThresholdDlg 대화 상자입니다.

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


// CThresholdDlg 메시지 처리기입니다.


BOOL CThresholdDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CThresholdDlg::OnBnClickedOkbtn()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_nThrValue < 0 || m_nThrValue>255) AfxMessageBox("0~255 사이의 숫자를 입력하세요.");
	else CDialogEx::OnOK();
}
