
// ITK+VTK+MFC_GUI.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CITKVTKMFC_GUIApp:
// �йش����ʵ�֣������ ITK+VTK+MFC_GUI.cpp
//

class CITKVTKMFC_GUIApp : public CWinApp
{
public:
	CITKVTKMFC_GUIApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CITKVTKMFC_GUIApp theApp;