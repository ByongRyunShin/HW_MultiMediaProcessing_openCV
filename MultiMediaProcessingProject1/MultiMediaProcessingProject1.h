
// MultiMediaProcessingProject1.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CMultiMediaProcessingProject1App:
// �� Ŭ������ ������ ���ؼ��� MultiMediaProcessingProject1.cpp�� �����Ͻʽÿ�.
//

class CMultiMediaProcessingProject1App : public CWinApp
{
public:
	CMultiMediaProcessingProject1App();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CMultiMediaProcessingProject1App theApp;
