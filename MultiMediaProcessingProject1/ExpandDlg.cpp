// ExpandDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MultiMediaProcessingProject1.h"
#include "ExpandDlg.h"
#include "afxdialogex.h"


// CExpandDlg ��ȭ �����Դϴ�.

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


// CExpandDlg �޽��� ó�����Դϴ�.
