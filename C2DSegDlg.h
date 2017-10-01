#pragma once
#include "afxwin.h"
#include "Global.h"


//=============�ص�����=========================================================
class vtkWidgetCall : public vtkCommand
{
public:

 static vtkWidgetCall *New()
 {
	return new vtkWidgetCall;
 }
public:
 virtual void Execute(vtkObject *caller, unsigned long eventId, void *callData)
 {
	vtkPlaneWidget *pWidget = vtkPlaneWidget::SafeDownCast(caller);
	pWidget->GetPlane(pPlane);// GetPlane() can be used to update a vtkPlane implicit function.
 }
public:
 vtkPlane *pPlane ;
 
};
//=======================================================================================

// C2DSegDlg �Ի���

class C2DSegDlg : public CDialogEx
{
	DECLARE_DYNAMIC(C2DSegDlg)

public:
	C2DSegDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~C2DSegDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_2DSeg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

public:
	CString m_strCaption;//�Ի������
	vtkImageData  *TwoDSeg_dicm_data;//�����2D�������и��dicm������

	vtkImageShiftScale *shiftScale;

	vtkFixedPointVolumeRayCastMapper *pMapper;  //�̶���RC
	vtkColorTransferFunction* pColor;
	vtkPiecewiseFunction* pPiceFun;
	vtkPiecewiseFunction* pGradientFun;
	vtkVolumeProperty* pProperty;

	vtkVolume *volume;

	vtkRenderer *RC_ren;
	vtkWin32OpenGLRenderWindow *RC_renWin;
	vtkWin32RenderWindowInteractor *RC_iren;

	vtkRenderer *Plane_ren;
	vtkWin32OpenGLRenderWindow *Plane_renWin;
	vtkWin32RenderWindowInteractor *Plane_iren;

	vtkPlaneWidget *pWidget;
	vtkPlane *pPlane;
	vtkCutter *pCut;
	vtkPolyDataMapper *selectMapper;
	vtkActor *pActor; 
	vtkWidgetCall *pCall;

	afx_msg void OnPaint();

	void TwoDSeg(); //2D������ʵʱ�и�
	afx_msg void OnDestroy();
};