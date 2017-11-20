#include <opencv2/opencv.hpp>
#include "C:\opencv\build\include\opencv2\core\mat.hpp"
using namespace std;
using namespace cv;

// MultiMediaProcessingProject1Dlg.h : 헤더 파일
//

#pragma once


// CMultiMediaProcessingProject1Dlg 대화 상자
class CMultiMediaProcessingProject1Dlg : public CDialogEx
{
// 생성입니다.
public:
	CMultiMediaProcessingProject1Dlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MULTIMEDIAPROCESSINGPROJECT1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.
public:
	void DisplayImage(int IDC_PICTURE_TARGET, Mat targetMat);

// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileOpen();
	Mat m_NowImg;
	bool m_opened;
	afx_msg void OnSave();
	afx_msg void OnSaveAs();
	afx_msg void OnQuitProgram();
	CString m_NowImgPath;
};
