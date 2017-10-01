
// ITK+VTK+MFC_GUIDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "Global.h"
#include "CTMCPropertyDlg.h"
#include "CTRCPropertyDlg.h"
#include "C2DSegDlg.h"
#include "C2DThreePlaneDlg.h"
#include "VolumeDataViewDlg.h"
#include "LungPETCTSeriesSegDlg.h"
#include "AboutDlg.h"
#include "Macro.h"


//===============CTMC 3D�������и�ص�����========================
class VTKWidgetCallCTMC3DSeg : public vtkCommand
{
public:
    static VTKWidgetCallCTMC3DSeg *New()
    {
		return new VTKWidgetCallCTMC3DSeg;
    }
public:
    virtual void Execute(vtkObject *caller, unsigned long eventId, void *callData)
    {
        vtkImplicitPlaneWidget2 *pWidget = reinterpret_cast<vtkImplicitPlaneWidget2*>(caller);
        if (pWidget)
        {
            // update the clip plane and the renderer
             vtkImplicitPlaneRepresentation *rep = 
				reinterpret_cast<vtkImplicitPlaneRepresentation*>(pWidget->GetRepresentation());

            vtkSmartPointer<vtkPlane> planeNew = vtkPlane::New();
            rep->GetPlane(planeNew);
        
            lung_surface_cliper->SetClipFunction(planeNew);
            lung_surface_cliper->Update();

			inter_surface_cliper->SetClipFunction(planeNew);
            inter_surface_cliper->Update();

            vtkSmartPointer<vtkPolyData> clipedData = vtkPolyData::New();
            clipedData->DeepCopy(lung_surface_cliper->GetOutput());

            vtkSmartPointer<vtkPolyDataMapper> mapper = vtkPolyDataMapper::New();
            mapper->SetInputData(clipedData);
            lung_surface_actor->SetMapper(mapper); //actor�α���

			lung_surface_actor->GetProperty()->SetColor((double)CTMC3DSeg_LungR_pos/100, (double)CTMC3DSeg_LungG_pos/100, (double)CTMC3DSeg_LungB_pos/100);

			lung_surface_actor->GetProperty()->SetAmbient((double)CTMC3DSeg_Ambient_pos/100);
			lung_surface_actor->GetProperty()->SetDiffuse((double)CTMC3DSeg_Diffuse_pos/100);
			lung_surface_actor->GetProperty()->SetSpecular((double)CTMC3DSeg_Specular_pos/100);
			lung_surface_actor->GetProperty()->SetSpecularPower(CTMC3DSeg_SpecularPower_pos);
			lung_surface_actor->GetProperty()->SetOpacity((double)CTMC3DSeg_LungOpacity_pos/100);

			vtkSmartPointer<vtkPolyData> clipedData2 = vtkPolyData::New();
            clipedData2->DeepCopy(inter_surface_cliper->GetOutput());

            vtkSmartPointer<vtkPolyDataMapper> mapper2 = vtkPolyDataMapper::New();
            mapper2->SetInputData(clipedData2);
            inter_surface_actor->SetMapper(mapper2);//actor2���ڲ�

			inter_surface_actor->GetProperty()->SetColor((double)CTMC3DSeg_InterR_pos/100, (double)CTMC3DSeg_InterG_pos/100, (double)CTMC3DSeg_InterB_pos/100);

			inter_surface_actor->GetProperty()->SetAmbient((double)CTMC3DSeg_Ambient_pos/100);
			inter_surface_actor->GetProperty()->SetDiffuse((double)CTMC3DSeg_Diffuse_pos/100);
			inter_surface_actor->GetProperty()->SetSpecular((double)CTMC3DSeg_Specular_pos/100);
			inter_surface_actor->GetProperty()->SetSpecularPower(CTMC3DSeg_SpecularPower_pos);
			inter_surface_actor->GetProperty()->SetOpacity((double)CTMC3DSeg_InterOpacity_pos/100);
        }
    }
	void setPlane(vtkSmartPointer<vtkPlane> other){pPlane = other;}

    void setCliper_lung_surface(vtkSmartPointer<vtkClipPolyData> other){lung_surface_cliper = other;}
    void setActor_lung_surface(vtkSmartPointer<vtkActor> other){lung_surface_actor = other;}

	void setCliper_inter_surface(vtkSmartPointer<vtkClipPolyData> other){inter_surface_cliper = other;}
	void setActor_inter_surface(vtkSmartPointer<vtkActor> other){inter_surface_actor = other;}

	void SetProperty_CTMC3DSeg(int CTMC_LungR_pos1,int CTMC_LungG_pos1,int CTMC_LungB_pos1,int CTMC_LungOpacity_pos1,int CTMC_InterR_pos1,int CTMC_InterG_pos1,int CTMC_InterB_pos1,int CTMC_InterOpacity_pos1,int CTMC_Ambient_pos1,int CTMC_Diffuse_pos1,int CTMC_Specular_pos1,int CTMC_SpecularPower_pos1)
	{
		CTMC3DSeg_LungR_pos = CTMC_LungR_pos1;
		CTMC3DSeg_LungG_pos = CTMC_LungG_pos1;
		CTMC3DSeg_LungB_pos = CTMC_LungB_pos1;
		CTMC3DSeg_LungOpacity_pos = CTMC_LungOpacity_pos1;

		CTMC3DSeg_InterR_pos = CTMC_InterR_pos1;
		CTMC3DSeg_InterG_pos = CTMC_InterG_pos1;
		CTMC3DSeg_InterB_pos = CTMC_InterB_pos1;
		CTMC3DSeg_InterOpacity_pos = CTMC_InterOpacity_pos1;

		CTMC3DSeg_Ambient_pos = CTMC_Ambient_pos1;
		CTMC3DSeg_Diffuse_pos = CTMC_Diffuse_pos1;
		CTMC3DSeg_Specular_pos = CTMC_Specular_pos1;
		CTMC3DSeg_SpecularPower_pos = CTMC_SpecularPower_pos1;
	}

private:
    vtkSmartPointer<vtkPlane> pPlane;
    vtkSmartPointer<vtkActor> lung_surface_actor;
    vtkSmartPointer<vtkClipPolyData> lung_surface_cliper;

	vtkSmartPointer<vtkActor> inter_surface_actor;
    vtkSmartPointer<vtkClipPolyData> inter_surface_cliper;

	int CTMC3DSeg_LungR_pos;//����ɫR������λ��
	int CTMC3DSeg_LungG_pos;//����ɫG������λ��
	int CTMC3DSeg_LungB_pos;//����ɫB������λ��
	int CTMC3DSeg_LungOpacity_pos;//��͸���ȹ�����λ��

	int CTMC3DSeg_InterR_pos;//���ڲ���ɫR������λ��
	int CTMC3DSeg_InterG_pos;//���ڲ���ɫG������λ��
	int CTMC3DSeg_InterB_pos;//���ڲ���ɫB������λ��
	int CTMC3DSeg_InterOpacity_pos;//���ڲ�͸���ȹ�����λ��

	int CTMC3DSeg_Ambient_pos;//CTMC������ϵ��������λ��
	int CTMC3DSeg_Diffuse_pos;//CTMC�����ϵ��������λ��
	int CTMC3DSeg_Specular_pos;//CTMC�����ϵ��������λ��
	int CTMC3DSeg_SpecularPower_pos;//CTMC�����ǿ�ȹ�����λ��
};
//================================================================



// CITKVTKMFC_GUIDlg �Ի���
class CITKVTKMFC_GUIDlg : public CDialogEx
{
// ����
public:
	CITKVTKMFC_GUIDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_ITKVTKMFC_GUI_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_comboImport;  //������Ͽ�Ŀ��Ʊ���
	CComboBox m_combo3DRebuild;//3D�ؽ���Ͽ�Ŀ��Ʊ���
	CComboBox m_comboProperty;//������Ͽ�Ŀ��Ʊ���
	CComboBox m_comboHelp;//������Ͽ�Ŀ��Ʊ���
	CComboBox m_comboPrevious;//��ʷ������Ͽ�Ŀ��Ʊ���

public: //CT��������ԶԻ���
	int CTMC_Style;  //CT��������ͣ�����MC/����MC��

	int CTMC_LungCT_pos;//����ֵ������λ��
	int CTMC_LungSmooth_pos;//��ƽ����������������λ��
	int CTMC_LungR_pos;//����ɫR������λ��
	int CTMC_LungG_pos;//����ɫG������λ��
	int CTMC_LungB_pos;//����ɫB������λ��
	int CTMC_LungOpacity_pos;//��͸���ȹ�����λ��

	int CTMC_InterCT_pos;//���ڲ���ֵ������λ��
	int CTMC_InterSmooth_pos;//���ڲ�ƽ����������������λ��
	int CTMC_InterR_pos;//���ڲ���ɫR������λ��
	int CTMC_InterG_pos;//���ڲ���ɫG������λ��
	int CTMC_InterB_pos;//���ڲ���ɫB������λ��
	int CTMC_InterOpacity_pos;//���ڲ�͸���ȹ�����λ��

	int CTMC_Ambient_pos;//CTMC������ϵ��������λ��
	int CTMC_Diffuse_pos;//CTMC�����ϵ��������λ��
	int CTMC_Specular_pos;//CTMC�����ϵ��������λ��
	int CTMC_SpecularPower_pos;//CTMC�����ǿ�ȹ�����λ��

public: //PET��������ԶԻ���
	int PETMC_Style;  //PET��������ͣ�����MC/����MC��

	int PETMC_LungCT_pos;//����ֵ������λ��
	int PETMC_LungSmooth_pos;//��ƽ����������������λ��
	int PETMC_LungR_pos;//����ɫR������λ��
	int PETMC_LungG_pos;//����ɫG������λ��
	int PETMC_LungB_pos;//����ɫB������λ��
	int PETMC_LungOpacity_pos;//��͸���ȹ�����λ��

	int PETMC_InterCT_pos;//���ڲ���ֵ������λ��
	int PETMC_InterSmooth_pos;//���ڲ�ƽ����������������λ��
	int PETMC_InterR_pos;//���ڲ���ɫR������λ��
	int PETMC_InterG_pos;//���ڲ���ɫG������λ��
	int PETMC_InterB_pos;//���ڲ���ɫB������λ��
	int PETMC_InterOpacity_pos;//���ڲ�͸���ȹ�����λ��

	int PETMC_Ambient_pos;//CTMC������ϵ��������λ��
	int PETMC_Diffuse_pos;//CTMC�����ϵ��������λ��
	int PETMC_Specular_pos;//CTMC�����ϵ��������λ��
	int PETMC_SpecularPower_pos;//CTMC�����ǿ�ȹ�����λ��

public: //CT��������ԶԻ���
	int CTRC_Style;  //CT��������ͣ�����RC/�̶���RC��

	int CTRC_LungCT_pos;//����ֵ������λ��
	int CTRC_LungR_pos;//����ɫR������λ��
	int CTRC_LungG_pos;//����ɫG������λ��
	int CTRC_LungB_pos;//����ɫB������λ��
	int CTRC_LungOpacity_pos;//��͸���ȹ�����λ��

	int CTRC_InterCT_pos;//���ڲ���ֵ������λ��
	int CTRC_InterR_pos;//���ڲ���ɫR������λ��
	int CTRC_InterG_pos;//���ڲ���ɫG������λ��
	int CTRC_InterB_pos;//���ڲ���ɫB������λ��
	int CTRC_InterOpacity_pos;//���ڲ�͸���ȹ�����λ��

	int CTRC_Ambient_pos;//CTMC������ϵ��������λ��
	int CTRC_Diffuse_pos;//CTMC�����ϵ��������λ��
	int CTRC_Specular_pos;//CTMC�����ϵ��������λ��
	int CTRC_SpecularPower_pos;//CTMC�����ǿ�ȹ�����λ��

public: //PET��������ԶԻ���
	int PETRC_Style;  //PET��������ͣ�����RC/�̶���RC��

	int PETRC_LungCT_pos;//����ֵ������λ��
	int PETRC_LungR_pos;//����ɫR������λ��
	int PETRC_LungG_pos;//����ɫG������λ��
	int PETRC_LungB_pos;//����ɫB������λ��
	int PETRC_LungOpacity_pos;//��͸���ȹ�����λ��

	int PETRC_InterCT_pos;//���ڲ���ֵ������λ��
	int PETRC_InterR_pos;//���ڲ���ɫR������λ��
	int PETRC_InterG_pos;//���ڲ���ɫG������λ��
	int PETRC_InterB_pos;//���ڲ���ɫB������λ��
	int PETRC_InterOpacity_pos;//���ڲ�͸���ȹ�����λ��

	int PETRC_Ambient_pos;//CTMC������ϵ��������λ��
	int PETRC_Diffuse_pos;//CTMC�����ϵ��������λ��
	int PETRC_Specular_pos;//CTMC�����ϵ��������λ��
	int PETRC_SpecularPower_pos;//CTMC�����ǿ�ȹ�����λ��

public:
	//vtkImageData  *CTRebuild_dicm_data;//������ؽ���CT_dicm������

	typedef struct DicmDataNode   //dicm�����ݽ��,������ʷ����
	{
		int dataStyle;
		vtkImageData  *data;//����CT_dicm������
		struct DicmDataNode *next;
	}DicmDataNode,*DicmDataLinkList;
	
	DicmDataNode *head,*rear;//������ʷ���������ͷ���ָ�롢β���ָ��
	DicmDataLinkList dataList;//������ʷ����

	DicmDataNode  *CTRebuild_dicm_data;//������ؽ���CT_dicm������
	DicmDataNode  *PETRebuild_dicm_data;//������ؽ���PET_dicm������

	//==============CT����Ƴ�Ա==========================
	vtkMarchingCubes *CT_lungExtractor;
	vtkDecimatePro *CT_lungDeci;
	vtkSmoothPolyDataFilter *CT_lungSmooth;
	vtkPolyDataNormals *CT_lungNormals;
	vtkStripper *CT_lungStripper;
	vtkPolyDataMapper *CT_lung_surface_Mapper;
	vtkActor *CT_lung_surface_actor;


	vtkMarchingCubes *CT_interExtractor;
	vtkDecimatePro *CT_interDeci;
	vtkSmoothPolyDataFilter *CT_interSmooth;
	vtkPolyDataNormals *CT_interNormals;
	vtkStripper *CT_interStripper;
	vtkPolyDataMapper *CT_inter_surface_Mapper;
	vtkActor *CT_inter_surface_actor;

	vtkImageShrink3D *CT_shrink;//���β���  ��ȡ���㣬��ʾ���������ٴ�ӿ�

	vtkRenderer *CT_MC_ren;
	vtkWin32OpenGLRenderWindow *CT_MC_renWin;
	vtkWin32RenderWindowInteractor *CT_MC_iren;

	//====================================================

	//==============PET����Ƴ�Ա==========================
	vtkMarchingCubes *PET_lungExtractor;
	vtkDecimatePro *PET_lungDeci;
	vtkSmoothPolyDataFilter *PET_lungSmooth;
	vtkPolyDataNormals *PET_lungNormals;
	vtkStripper *PET_lungStripper;
	vtkPolyDataMapper *PET_lung_surface_Mapper;
	vtkActor *PET_lung_surface_actor;


	vtkMarchingCubes *PET_interExtractor;
	vtkDecimatePro *PET_interDeci;
	vtkSmoothPolyDataFilter *PET_interSmooth;
	vtkPolyDataNormals *PET_interNormals;
	vtkStripper *PET_interStripper;
	vtkPolyDataMapper *PET_inter_surface_Mapper;
	vtkActor *PET_inter_surface_actor;

	vtkImageShrink3D *PET_shrink;//���β���  ��ȡ���㣬��ʾ���������ٴ�ӿ�

	vtkRenderer *PET_MC_ren;
	vtkWin32OpenGLRenderWindow *PET_MC_renWin;
	vtkWin32RenderWindowInteractor *PET_MC_iren;

	//====================================================

	//=====================CT����Ƴ�Ա===================
	vtkImageShiftScale *CT_shiftScale;

	vtkVolumeRayCastCompositeFunction *CT_rayCastFunction;  //RC
	vtkVolumeRayCastMapper *CT_volumeMapper;
	vtkColorTransferFunction *CT_volumeColor;
	vtkPiecewiseFunction *CT_volumeScalarOpacity;
	vtkPiecewiseFunction *CT_volumeGradientOpacity;
	vtkVolumeProperty *CT_volumeProperty;

	vtkFixedPointVolumeRayCastMapper *CT_pMapper;  //�̶���RC
	vtkColorTransferFunction* CT_pColor;
	vtkPiecewiseFunction* CT_pPiceFun;
	vtkPiecewiseFunction* CT_pGradientFun;
	vtkVolumeProperty* CT_pProperty;

	vtkVolume *CT_volume;

	vtkRenderer *CT_RC_ren;
	vtkWin32OpenGLRenderWindow *CT_RC_renWin;
	vtkWin32RenderWindowInteractor *CT_RC_iren;
	//====================================================

	//=====================PET����Ƴ�Ա===================
	vtkImageShiftScale *PET_shiftScale;

	vtkVolumeRayCastCompositeFunction *PET_rayCastFunction;  //RC
	vtkVolumeRayCastMapper *PET_volumeMapper;
	vtkColorTransferFunction *PET_volumeColor;
	vtkPiecewiseFunction *PET_volumeScalarOpacity;
	vtkPiecewiseFunction *PET_volumeGradientOpacity;
	vtkVolumeProperty *PET_volumeProperty;

	vtkFixedPointVolumeRayCastMapper *PET_pMapper;  //�̶���RC
	vtkColorTransferFunction* PET_pColor;
	vtkPiecewiseFunction* PET_pPiceFun;
	vtkPiecewiseFunction* PET_pGradientFun;
	vtkVolumeProperty* PET_pProperty;

	vtkVolume *PET_volume;

	vtkRenderer *PET_RC_ren;
	vtkWin32OpenGLRenderWindow *PET_RC_renWin;
	vtkWin32RenderWindowInteractor *PET_RC_iren;
	//====================================================

	//==================CTMC 3D�������и��Ա==============
	vtkImplicitPlaneRepresentation *CTMC3DSeg_rep;
	vtkImplicitPlaneWidget2 *CTMC3DSeg_implicitPlaneWidget;
	vtkPlane *CTMC3DSeg_planeNew;
	vtkClipPolyData *CTMC3DSeg_cliper;
	vtkPolyData *CTMC3DSeg_clipedData;
	VTKWidgetCallCTMC3DSeg *CTMC3DSeg_pCall;

	vtkClipPolyData *CTMC3DSegInter_cliper;
	vtkPolyData *CTMC3DSegInter_clipedData;

	int CTMC3DSeg_CheckButtonStatus;//CTMC 3D�������иѡ��ѡ��״̬

	int CTMC3DSeg_YesOrNoMC;//CTMC������Ƿ��ؽ�

	//=====================================================

	//==================CT�����ֱ�߲�����Ա===============
	int CTMCLine_CheckButtonStatus;//CT�����ֱ�߲�����ѡ��ѡ��״̬
	vtkDistanceRepresentation3D *CTMCLine_rep;
	vtkDistanceWidget *CTMCLine_distanceWidget;
	//=====================================================

	//==================CT�����ֱ�߲�����Ա===============
	int CTRCLine_CheckButtonStatus;//CT�����ֱ�߲�����ѡ��ѡ��״̬
	vtkDistanceRepresentation3D *CTRCLine_rep;
	vtkDistanceWidget *CTRCLine_distanceWidget;

	int CTRC3DSeg_YesOrNoRC;//CTRC������Ƿ��ؽ�
	//=====================================================

	//==================CT����ƽǶȲ�����Ա===============
	int CTMCAngle_CheckButtonStatus;//CT����ƽǶȲ�����ѡ��ѡ��״̬
	vtkAngleRepresentation3D *CTMCAngle_rep;
	vtkAngleWidget *CTMCAngle_angleWidget;
	//=====================================================

	//==================CT����ƽǶȲ�����Ա===============
	int CTRCAngle_CheckButtonStatus;//CT����ƽǶȲ�����ѡ��ѡ��״̬
	vtkAngleRepresentation3D *CTRCAngle_rep;
	vtkAngleWidget *CTRCAngle_angleWidget;
	//=====================================================


	CCTMCPropertyDlg CTMCPropDlg;           // ����Ի�����CCTMCPropertyDlg��ʵ�� 
	CCTRCPropertyDlg CTRCPropDlg;           // ����Ի�����CCTRCPropertyDlg��ʵ��

	CCTMCPropertyDlg PETMCPropDlg;           // ����Ի�����CCTMCPropertyDlg��ʵ��
	CCTRCPropertyDlg PETRCPropDlg;           // ����Ի�����CCTRCPropertyDlg��ʵ��

	//C2DSegDlg TwoDSegDlg;                   // ����Ի�����C2DSegDlg��ʵ��


	afx_msg void OnDestroy();
	afx_msg void OnCbnSelendokComboImport();//������Ͽ�ѡ��ѡ���¼�
	afx_msg void OnCbnSelendokCombo3drebuild();//3D�ؽ���Ͽ�ѡ��ѡ���¼�
	void Pipeline_CT_MC();//CT��������ݹܵ�����
	void SetProperty_CT_MC(int CTMC_Style1,int CTMC_LungCT_pos1,int CTMC_LungSmooth_pos1,int CTMC_LungR_pos1,int CTMC_LungG_pos1,int CTMC_LungB_pos1,int CTMC_LungOpacity_pos1,int CTMC_InterCT_pos1,int CTMC_InterSmooth_pos1,int CTMC_InterR_pos1,int CTMC_InterG_pos1,int CTMC_InterB_pos1,int CTMC_InterOpacity_pos1,int CTMC_Ambient_pos1,int CTMC_Diffuse_pos1,int CTMC_Specular_pos1,int CTMC_SpecularPower_pos1);
	
	void Pipeline_PET_MC();//PET��������ݹܵ�����
	void SetProperty_PET_MC(int PETMC_Style1,int PETMC_LungCT_pos1,int PETMC_LungSmooth_pos1,int PETMC_LungR_pos1,int PETMC_LungG_pos1,int PETMC_LungB_pos1,int PETMC_LungOpacity_pos1,int PETMC_InterCT_pos1,int PETMC_InterSmooth_pos1,int PETMC_InterR_pos1,int PETMC_InterG_pos1,int PETMC_InterB_pos1,int PETMC_InterOpacity_pos1,int PETMC_Ambient_pos1,int PETMC_Diffuse_pos1,int PETMC_Specular_pos1,int PETMC_SpecularPower_pos1);

	void Pipeline_CT_RC();//CT��������ݹܵ�����
	void SetProperty_CT_RC(int CTRC_Style1,int CTRC_LungCT_pos1,int CTRC_LungR_pos1,int CTRC_LungG_pos1,int CTRC_LungB_pos1,int CTRC_LungOpacity_pos1,int CTRC_InterCT_pos1,int CTRC_InterR_pos1,int CTRC_InterG_pos1,int CTRC_InterB_pos1,int CTRC_InterOpacity_pos1,int CTRC_Ambient_pos1,int CTRC_Diffuse_pos1,int CTRC_Specular_pos1,int CTRC_SpecularPower_pos1);

	void Pipeline_PET_RC();//PET��������ݹܵ�����
	void SetProperty_PET_RC(int PETRC_Style1,int PETRC_LungCT_pos1,int PETRC_LungR_pos1,int PETRC_LungG_pos1,int PETRC_LungB_pos1,int PETRC_LungOpacity_pos1,int PETRC_InterCT_pos1,int PETRC_InterR_pos1,int PETRC_InterG_pos1,int PETRC_InterB_pos1,int PETRC_InterOpacity_pos1,int PETRC_Ambient_pos1,int PETRC_Diffuse_pos1,int PETRC_Specular_pos1,int PETRC_SpecularPower_pos1);

	afx_msg void OnCbnSelendokComboProperty();//������Ͽ�ѡ��ѡ���¼�
	
	afx_msg void OnCbnSelendokComboPrevious();//��ʷ������Ͽ�ѡ��ѡ���¼�
	afx_msg void OnBnClickedRadio2dseg(); //���2D�������и��¼�
	afx_msg void OnBnClickedRadio2dthreeplane();//���2D��ʸ�������¼�
	afx_msg void OnBnClickedRadioVolumesliceview();//�����������Ƭ������ʾ�¼�
	afx_msg void OnBnClickedCheck3dctmcseg();//���CTMC 3D�������и��¼�
	CButton m_check_3DCTMCSeg;//CTMC 3D�������иѡ�����
	CButton m_check_3DCTMCSeg_Hide;//CTMC 3D�������и��������ظ�ѡ�����
	afx_msg void OnBnClickedCheck3dctmcsegHide();//���CTMC 3D�������и����������¼�

	afx_msg void OnBnClickedCheckCtmcLine();//���CT�����ֱ�߲����¼�
	CButton m_check_CTMC_Line;//CT�����ֱ�߲�����ѡ�����

	afx_msg void OnBnClickedCheckCtrcLine();//���CT�����ֱ�߲����¼�
	CButton m_check_CTRC_Line;//CT�����ֱ�߲�����ѡ�����

	afx_msg void OnBnClickedCheckCtmcAngle();//���CT����ƽǶȲ����¼�
	CButton m_check_CTMC_Angle;//CT����ƽǶȲ�����ѡ�����

	afx_msg void OnBnClickedCheckCtrcAngle();//���CT����ƽǶȲ����¼�
	CButton m_check_CTRC_Angle;//CT����ƽǶȲ�����ѡ�����
	afx_msg void OnBnClickedButtonSeg();//����β�PET-CT���зָ��¼�

	afx_msg void OnCbnSelendokComboHelp();//������Ͽ�ѡ��ѡ���¼�
};
