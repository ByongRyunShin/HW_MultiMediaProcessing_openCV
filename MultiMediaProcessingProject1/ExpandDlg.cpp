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
	, m_Inter(0)
{

}

CExpandDlg::~CExpandDlg()
{
}

void CExpandDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CExpandDlg, CDialogEx)
END_MESSAGE_MAP()


// CExpandDlg 메시지 처리기입니다.
