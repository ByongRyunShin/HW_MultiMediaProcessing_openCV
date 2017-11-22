#include <opencv2/opencv.hpp>
#include "C:\opencv\build\include\opencv2\core\mat.hpp"
using namespace std;
using namespace cv;

// MultiMediaProcessingProject1Dlg.h : ��� ����
//

#pragma once


// CMultiMediaProcessingProject1Dlg ��ȭ ����
class CMultiMediaProcessingProject1Dlg : public CDialogEx
{
// �����Դϴ�.
public:
	CMultiMediaProcessingProject1Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MULTIMEDIAPROCESSINGPROJECT1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.
public:
	void DisplayImage(int IDC_PICTURE_TARGET, Mat targetMat);

// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileOpen();
	Mat m_NowImg;
	bool m_opened=false;
	afx_msg void OnSave();
	afx_msg void OnSaveAs();
	afx_msg void OnQuitProgram();
	CString m_NowImgPath;
	Mat m_PrevImg;
	afx_msg void OnUndo();
	bool m_didwork=false;
	afx_msg void OnRGB2GRAY();
	afx_msg void OnChangeLeftRight();
	afx_msg void OnUpsideDown();
	afx_msg void OnPrintBitPlane();
};
