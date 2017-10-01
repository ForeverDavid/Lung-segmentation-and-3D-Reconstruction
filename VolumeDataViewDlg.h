#pragma once
#include "afxwin.h"
#include "Global.h"


class vtkNextDcmCallbk : public vtkCommand
{
public:
 static vtkNextDcmCallbk *New()
 {
	return new vtkNextDcmCallbk;
 }
 virtual void Execute(vtkObject *caller, unsigned long eventId, void *callData)
 {
	vtkWin32RenderWindowInteractor *pInt = vtkWin32RenderWindowInteractor::SafeDownCast(caller); //ת��Ϊ��Ӧ������
	vtkRendererCollection *pRenders = pInt->GetRenderWindow()->GetRenderers();//�õ�Renderwindow���е�render
	vtkRenderer *pRender = pRenders->GetFirstRenderer();
	vtkActor2DCollection *pActors = pRender->GetActors2D();//�õ� Render������actor
 
	vtkActor2D *pActor = (vtkActor2D *)pActors->GetItemAsObject(0);//�õ�Render���һ��Actor
	//���������Լ�ת���ķ�������֪���Բ��ԣ���������и��õķ�������˵һ�£�
	int max = ((vtkImageMapper *)pActor->GetMapper())->GetWholeZMax();//�õ�������Ƭ������
	int cur = ((vtkImageMapper *)pActor->GetMapper())->GetZSlice();//�õ���ǰ��Ƭ������
	if (eventId == vtkCommand::MouseWheelForwardEvent && (cur - 1) >=0)
	{
		((vtkImageMapper *)pActor->GetMapper())->SetZSlice(--cur);//���õ�ǰ����
	 } 
	if (eventId == vtkCommand::MouseWheelBackwardEvent && (cur + 1) <= max)
	{
		((vtkImageMapper *)pActor->GetMapper())->SetZSlice(++cur);
	}
	char buf[64] = {0};
	sprintf(buf, "%d / %d", cur, max);
	vtkTextActor *pTextActor = (vtkTextActor *)pActors->GetItemAsObject(1);
	pTextActor->SetInput(buf);
  
 }
};


// VolumeDataViewDlg �Ի���

class VolumeDataViewDlg : public CDialogEx
{
	DECLARE_DYNAMIC(VolumeDataViewDlg)

public:
	VolumeDataViewDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~VolumeDataViewDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_VolumeVIEW };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

public:
	long init_level_pos;//ԭʼCT/PET Level������λ��
	long init_window_pos;//ԭʼCT/PET window������λ��

	long seg_level_pos;//�ָ��CT/PET Level������λ��
	long seg_window_pos;//�ָ��CT/PET window������λ��

	vtkImageData  *Init_CT_PET_dicm_data;//����ԭʼCT/PET������
	vtkImageData  *Seg_CT_PET_dicm_data;//����ԭʼCT/PET������

	//==============ԭʼCT/PETԤ����Ա����=======================
	vtkRenderer *init_render;
	vtkWin32OpenGLRenderWindow *init_renWin;
	vtkImageMapper *init_mapper;
	vtkActor2D *init_actor;
	vtkTextActor *init_textActor;
	vtkWin32RenderWindowInteractor *init_iren;
	vtkNextDcmCallbk *init_pCall; 
	//===========================================================

	//==============�ָ��CT/PETԤ����Ա����=======================
	vtkRenderer *seg_render;
	vtkWin32OpenGLRenderWindow *seg_renWin;
	vtkImageMapper *seg_mapper;
	vtkActor2D *seg_actor;
	vtkTextActor *seg_textActor;
	vtkWin32RenderWindowInteractor *seg_iren;
	vtkNextDcmCallbk *seg_pCall; 
	//===========================================================

public:
	CComboBox m_comboViewImport;//������Ͽ�Ŀ��Ʊ���

	CScrollBar m_scrollbar_init_level; //ԭʼCT/PETԤ��Level������
	CScrollBar m_scrollbar_init_window;//ԭʼCT/PETԤ��Window������

	CScrollBar m_scrollbar_seg_level;//�ָ�CT/PETԤ��Level������
	CScrollBar m_scrollbar_seg_window;//�ָ�CT/PETԤ��Window������
	afx_msg void OnEnChangeEditViewRunstatus();
	afx_msg void OnPaint();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnCbnSelendokComboViewImport();//����

	void Init_CT_PET_VIEW();//ԭʼCT/PETԤ������

	void Seg_CT_PET_VIEW();//�ָ��CT/PETԤ������
	afx_msg void OnDestroy();
};
