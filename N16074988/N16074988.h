
// N16074988.h : PROJECT_NAME ���ε{�����D�n���Y��
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �]�t���ɮ׫e���]�t 'stdafx.h'"
#endif

#include "resource.h"		// �D�n�Ÿ�


// CN16074988App: 
// �аѾ\��@�����O�� N16074988.cpp
//

class CN16074988App : public CWinApp
{
public:
	CN16074988App();

// �мg
public:
	virtual BOOL InitInstance();

// �{���X��@

	DECLARE_MESSAGE_MAP()
};

extern CN16074988App theApp;