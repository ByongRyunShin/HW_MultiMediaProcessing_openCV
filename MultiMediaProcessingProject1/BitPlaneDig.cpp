// BitPlaneDig.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MultiMediaProcessingProject1.h"
#include "BitPlaneDig.h"
#include "afxdialogex.h"


// CBitPlaneDig 대화 상자입니다.

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


// CBitPlaneDig 메시지 처리기입니다.


BOOL CBitPlaneDig::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	m_spinBit.SetRange(0, 7);
	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CBitPlaneDig::OnBnClickedOkbtn()
{
	CDialogEx::OnOK();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

}
