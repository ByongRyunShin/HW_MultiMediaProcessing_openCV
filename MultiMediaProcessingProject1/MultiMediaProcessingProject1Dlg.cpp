
// MultiMediaProcessingProject1Dlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "MultiMediaProcessingProject1.h"
#include "MultiMediaProcessingProject1Dlg.h"
#include "afxdialogex.h"
#include "BitPlaneDig.h"
#include "ThresholdDlg.h"
#include "Blurring.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP();

public:
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)

END_MESSAGE_MAP()


// CMultiMediaProcessingProject1Dlg 대화 상자



CMultiMediaProcessingProject1Dlg::CMultiMediaProcessingProject1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MULTIMEDIAPROCESSINGPROJECT1_DIALOG, pParent)
	, m_opened(false)
	, m_NowImgPath(_T(""))
	, m_didwork(false)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMultiMediaProcessingProject1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMultiMediaProcessingProject1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_32771, &CMultiMediaProcessingProject1Dlg::OnFileOpen)
	ON_COMMAND(ID_32772, &CMultiMediaProcessingProject1Dlg::OnSave)
	ON_COMMAND(ID_32773, &CMultiMediaProcessingProject1Dlg::OnSaveAs)
	ON_COMMAND(ID_32774, &CMultiMediaProcessingProject1Dlg::OnQuitProgram)
	ON_COMMAND(ID_32775, &CMultiMediaProcessingProject1Dlg::OnUndo)
	ON_COMMAND(ID_32776, &CMultiMediaProcessingProject1Dlg::OnRGB2GRAY)
	ON_COMMAND(ID_32777, &CMultiMediaProcessingProject1Dlg::OnChangeLeftRight)
	ON_COMMAND(ID_32778, &CMultiMediaProcessingProject1Dlg::OnUpsideDown)
	ON_COMMAND(ID_32779, &CMultiMediaProcessingProject1Dlg::OnPrintBitPlane)
	ON_COMMAND(ID_PIXEL32780, &CMultiMediaProcessingProject1Dlg::OnHistogramStretching)
	ON_COMMAND(ID_PIXEL32781, &CMultiMediaProcessingProject1Dlg::OnHistogramEqualization)
	ON_COMMAND(ID_PIXEL32782, &CMultiMediaProcessingProject1Dlg::OnNegativeImage)
	ON_COMMAND(ID_PIXEL32783, &CMultiMediaProcessingProject1Dlg::OnThresholdFiltering)
	ON_COMMAND(ID_NEIGHBORHOOD32784, &CMultiMediaProcessingProject1Dlg::OnBlurring)
	ON_COMMAND(ID_NEIGHBORHOOD32785, &CMultiMediaProcessingProject1Dlg::OnUnSharpMasking)
	ON_COMMAND(ID_NEIGHBORHOOD32786, &CMultiMediaProcessingProject1Dlg::OnAverageFiltering)
	ON_COMMAND(ID_NEIGHBORHOOD32787, &CMultiMediaProcessingProject1Dlg::OnMedianFiltering)
	ON_COMMAND(ID_EDGE32789, &CMultiMediaProcessingProject1Dlg::OnSobelMasking)
	ON_COMMAND(ID_EDGE32790, &CMultiMediaProcessingProject1Dlg::OnLaplacianMasking)
END_MESSAGE_MAP()


// CMultiMediaProcessingProject1Dlg 메시지 처리기

BOOL CMultiMediaProcessingProject1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	m_opened = false;
	m_didwork = false;
	/*
	CMenu *p_menu = GetMenu();
	if (p_menu != NULL) {
		CMenu *p_sub_menu = p_menu->GetSubMenu(1);
		if (p_sub_menu != NULL) {
			p_sub_menu->EnableMenuItem(ID_32775, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
		}
	}
	*/
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMultiMediaProcessingProject1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMultiMediaProcessingProject1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
		if (m_opened == true) DisplayImage(IDC_PIC, m_NowImg);
	}

}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMultiMediaProcessingProject1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMultiMediaProcessingProject1Dlg::DisplayImage(int IDC_PICTURE_TARGET, Mat targetMat)
{
	IplImage* targetIplImage = new IplImage(targetMat);
	if (targetIplImage != nullptr) {
		CWnd* pWnd_ImageTraget = GetDlgItem(IDC_PICTURE_TARGET);
		CClientDC dcImageTraget(pWnd_ImageTraget);
		RECT rcImageTraget;
		pWnd_ImageTraget->GetClientRect(&rcImageTraget);

		BITMAPINFO bitmapInfo;
		memset(&bitmapInfo, 0, sizeof(bitmapInfo));
		bitmapInfo.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
		bitmapInfo.bmiHeader.biPlanes = 1;
		bitmapInfo.bmiHeader.biCompression = BI_RGB;
		bitmapInfo.bmiHeader.biWidth = targetIplImage->width;
		bitmapInfo.bmiHeader.biHeight = -targetIplImage->height;

		IplImage *tempImage = nullptr;

		if (targetIplImage->nChannels == 1)
		{
			tempImage = cvCreateImage(cvSize(targetIplImage->width, targetIplImage->height), IPL_DEPTH_8U, 3);
			cvCvtColor(targetIplImage, tempImage, CV_GRAY2BGR);
		}
		else if (targetIplImage->nChannels == 3)
		{
			tempImage = cvCloneImage(targetIplImage);
		}

		bitmapInfo.bmiHeader.biBitCount = tempImage->depth * tempImage->nChannels;

		dcImageTraget.SetStretchBltMode(COLORONCOLOR);
		::StretchDIBits(dcImageTraget.GetSafeHdc(), rcImageTraget.left, rcImageTraget.top, rcImageTraget.right, rcImageTraget.bottom,
			0, 0, tempImage->width, tempImage->height, tempImage->imageData, &bitmapInfo, DIB_RGB_COLORS, SRCCOPY);

		cvReleaseImage(&tempImage);
	}
}

//File Open
void CMultiMediaProcessingProject1Dlg::OnFileOpen()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	char szFilter[] = "Image (*.BMP, *.GIF, *.JPG, *.PNG) | *.BMP;*.GIF;*.JPG;*.PNG;*.bmp;*.gif;*.jpg;*.png | All Files(*.*)|*.*||";
	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter, AfxGetMainWnd());
	if (dlg.DoModal() == IDOK)
	{
		m_NowImgPath = dlg.GetPathName();
		//AfxMessageBox(cstrImgPath);

		Mat src = imread(string(m_NowImgPath));
		m_NowImg = src.clone();
		DisplayImage(IDC_PIC, src);
		m_opened = true;
	}
}

//File Save
void CMultiMediaProcessingProject1Dlg::OnSave()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	if (m_opened == true) {
		imwrite(string(m_NowImgPath), m_NowImg);
		AfxMessageBox("저장완료!");
	}
	else {
		AfxMessageBox("이미지를 먼저 여세여~!");
	}
}




void CMultiMediaProcessingProject1Dlg::OnSaveAs()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	if (m_opened == true) {
		char szFilter[] = "JPEG Image (*.jpg)|*.jpg|PNG Image (*.png)|*.png|Bitmap Image (*.bmp)|*.bmp|";
		CFileDialog dlg(FALSE, "jpg", "*.jpg", OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT | OFN_NOCHANGEDIR, szFilter, NULL);
		if (dlg.DoModal() == IDOK) {
			CString SavePath=dlg.GetPathName();
			imwrite(string(SavePath), m_NowImg);
			AfxMessageBox("저장완료!");
		}
	}
	else {
		AfxMessageBox("이미지를 먼저 여세여~!");
	}
}

void CMultiMediaProcessingProject1Dlg::OnQuitProgram()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	PostQuitMessage(0);
}


void CMultiMediaProcessingProject1Dlg::OnUndo()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_NowImg = m_PrevImg.clone();

	DisplayImage(IDC_PIC, m_NowImg);
}

void CMultiMediaProcessingProject1Dlg::OnRGB2GRAY()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_PrevImg = m_NowImg.clone();
	Mat grayImg;
	cvtColor(m_NowImg, grayImg, CV_BGR2GRAY);
	m_NowImg = grayImg.clone();
	DisplayImage(IDC_PIC, m_NowImg);
}



void CMultiMediaProcessingProject1Dlg::OnChangeLeftRight()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_PrevImg = m_NowImg.clone();

	Mat temp;
	flip(m_NowImg, temp, 1);
	m_NowImg = temp.clone();

	DisplayImage(IDC_PIC, m_NowImg);
}


void CMultiMediaProcessingProject1Dlg::OnUpsideDown()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_PrevImg = m_NowImg.clone();

	Mat temp;
	flip(m_NowImg, temp, 0);
	m_NowImg = temp.clone();

	DisplayImage(IDC_PIC, m_NowImg);

}

void getBitPlane(Mat &srcImg, Mat &dstImg, int n)//(원본이미지 , bitplane될 이미지,n칸 
{
	uchar mask = 0x01 << n; //쉬프트연산자를 이용하여 n칸 밀어버림니다. 나머지 밀어져 버린 부분은 0으로 숫자가 초기화 됨니다.


	Mat_<uchar> s = Mat_<uchar>(srcImg);
	Mat_<uchar> d = Mat_<uchar>(dstImg);

	for (int r = 0; r < srcImg.rows; r++)
	{
		uchar *p = srcImg.ptr<uchar>(r);//첫번째행의 값을 가져온다.
		uchar *dp = dstImg.ptr<uchar>(r);
		for (int c = 0; c < srcImg.cols; c++)
		{
			uchar pixelvalue = p[c];
			uchar one_zero = pixelvalue & mask;
			if (one_zero > 0)
				dp[c] = 255;
			else
				dp[c] = 0;
		}
	}
}

void CMultiMediaProcessingProject1Dlg::OnPrintBitPlane()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_PrevImg = m_NowImg.clone();

	Mat temp=m_NowImg.clone();
	CBitPlaneDig dlg;
	dlg.DoModal();

	getBitPlane(m_NowImg, temp, dlg.m_nBit);
	m_NowImg = temp.clone();
	DisplayImage(IDC_PIC, m_NowImg);
}

void histogramStretching(Mat img, Mat& out)
{
	int lowvalue = 255, highvalue = 0;
	int i, j;
	for (i = 0; i < img.rows; i++)
	{
		for (j = 0; j < img.cols; j++)
		{
			if (lowvalue > img.at<uchar>(i, j))
				lowvalue = img.at<uchar>(i, j);
			if (highvalue < img.at<uchar>(i, j))
				highvalue = img.at<uchar>(i, j);
		}
	}
	// histogram stretching 계산
	float mult = 255 / (float)(highvalue - lowvalue);
	for (i = 0; i < img.rows; i++)
	{
		for (j = 0; j < img.cols; j++)
			out.at<uchar>(i, j) = (uchar)(img.at<uchar>(i, j) - lowvalue) * mult;
	}
}

void CMultiMediaProcessingProject1Dlg::OnHistogramStretching()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_PrevImg = m_NowImg.clone();

	Mat temp = m_NowImg.clone();
	histogramStretching(m_NowImg, temp);
	m_NowImg = temp.clone();
	DisplayImage(IDC_PIC, m_NowImg);
}

void histogramEqualization(Mat img, Mat& out)
{
	int i, j;
	unsigned int hist[256] = { 0, };
	float cdf[256] = { 0, };
	int pixel, max;

	for (i = 0; i < img.rows; i++)
	{
		for (j = 0; j < img.cols; j++)
		{
			hist[img.at<uchar>(i, j)]++;
		}
	}

	cdf[0] = hist[0];

	for (i = 1; i < 256; i++)
		cdf[i] = cdf[i - 1] + hist[i];

	max = cdf[255];

	for (i = 0; i < img.rows; i++)
	{
		for (j = 0; j < img.cols; j++)
		{
			pixel = cdf[img.at<uchar>(i, j)] / max * 255;
			out.at<uchar>(i, j) = (pixel > 255) ? 255 : pixel;
		}
	}
}

void CMultiMediaProcessingProject1Dlg::OnHistogramEqualization()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_PrevImg = m_NowImg.clone();

	Mat temp = m_NowImg.clone();
	histogramEqualization(m_NowImg, temp);
	m_NowImg = temp.clone();
	DisplayImage(IDC_PIC, m_NowImg);
}


void CMultiMediaProcessingProject1Dlg::OnNegativeImage()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_PrevImg = m_NowImg.clone();

	IplImage *temp = new IplImage(m_NowImg);
	cvNot(new IplImage(m_NowImg), temp);

	m_NowImg = cvarrToMat(temp).clone();
	DisplayImage(IDC_PIC, m_NowImg);
}


void CMultiMediaProcessingProject1Dlg::OnThresholdFiltering()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_PrevImg = m_NowImg.clone();

	Mat temp = m_NowImg.clone();

	CThresholdDlg dlg;
	dlg.DoModal();

	threshold(m_NowImg, temp, dlg.m_nThrValue, 255, THRESH_BINARY);
	
	m_NowImg = temp.clone();
	DisplayImage(IDC_PIC, m_NowImg);
}


void CMultiMediaProcessingProject1Dlg::OnBlurring()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_PrevImg = m_NowImg.clone();
	Mat temp = m_NowImg.clone();

	CBlurring dlg;
	dlg.DoModal();

	GaussianBlur(m_NowImg, temp, Size(dlg.m_size, dlg.m_size), 0);

	m_NowImg = temp.clone();
	DisplayImage(IDC_PIC, m_NowImg);
}


void CMultiMediaProcessingProject1Dlg::OnUnSharpMasking()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_PrevImg = m_NowImg.clone();
	Mat temp = m_NowImg.clone();

	GaussianBlur(m_NowImg, temp, Size(3, 3), 0);
	addWeighted(m_NowImg, 1.5, temp, -0.5, 0, m_NowImg);

	m_NowImg = temp.clone();
	DisplayImage(IDC_PIC, m_NowImg);
}

void averageFilter(Mat& Input, Mat& Output)
{
	int row = Input.rows;
	int col = Input.cols;
	int size = 1;
	uchar count = 0;
	uchar sum = 0;

	for (int j = 1; j < (Input.rows-1); ++j)
	{
		const uchar* previous = Input.ptr<uchar>(j - 1);
		const uchar* current = Input.ptr<uchar>(j);
		const uchar* next = Input.ptr<uchar>(j + 1);

		uchar* output = Output.ptr<uchar>(j);

		for (int i = 1; i < (Output.cols-1); ++i)
		{
			double dResult = (current[i] + current[i - 1] + current[i + 1] +
				previous[i] + next[i] + previous[i - 1] + previous[i + 1] +
				next[i - 1] + next[i + 1]) / 9.0;
			*output++ = (unsigned char)dResult;
		}
	}
}

void CMultiMediaProcessingProject1Dlg::OnAverageFiltering()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_PrevImg = m_NowImg.clone();
	Mat temp = m_NowImg.clone();

	averageFilter(m_NowImg, temp);

	m_NowImg = temp.clone();
	DisplayImage(IDC_PIC, m_NowImg);
}


void CMultiMediaProcessingProject1Dlg::OnMedianFiltering()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_PrevImg = m_NowImg.clone();
	Mat temp = m_NowImg.clone();

	medianBlur(m_NowImg, temp, 3);

	m_NowImg = temp.clone();
	DisplayImage(IDC_PIC, m_NowImg);
}


void CMultiMediaProcessingProject1Dlg::OnSobelMasking()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_PrevImg = m_NowImg.clone();
	Mat temp = m_NowImg.clone();

	Mat sobelX, sobelY, sobel;
	Sobel(m_NowImg, sobelX, CV_16S, 1, 0);
	Sobel(m_NowImg, sobelY, CV_16S, 0, 1);
	sobel = abs(sobelX) + abs(sobelY);    // L1 놈(norm) 계산

	double sobmin, sobmax;
	minMaxLoc(sobel, &sobmin, &sobmax); // sobel 최댓값 찾기

	sobel.convertTo(temp, CV_8U, -255. / sobmax, 255); // 8bit 영상으로 변환

	m_NowImg = temp.clone();
	DisplayImage(IDC_PIC, m_NowImg);
}


void CMultiMediaProcessingProject1Dlg::OnLaplacianMasking()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_PrevImg = m_NowImg.clone();

	//물음표..?
	IplImage *temp = new IplImage(m_NowImg);
	cvLaplace(new IplImage(m_NowImg), temp, 3);

	m_NowImg = cvarrToMat(temp).clone();
	DisplayImage(IDC_PIC, m_NowImg);
}
