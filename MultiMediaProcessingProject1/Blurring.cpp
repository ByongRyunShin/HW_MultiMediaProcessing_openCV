// Blurring.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MultiMediaProcessingProject1.h"
#include "Blurring.h"
#include "afxdialogex.h"


// CBlurring 대화 상자입니다.

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


// CBlurring 메시지 처리기입니다.


void CBlurring::OnBnClickedRadio2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_size = 3;
}


void CBlurring::OnBnClickedRadio5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_size = 5;
}


void CBlurring::OnBnClickedOkbtn()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_size == 0) AfxMessageBox("띠용~!, 사이즈를 선택하세요.");
	else CDialog::OnOK();
}
