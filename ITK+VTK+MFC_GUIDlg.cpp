
// ITK+VTK+MFC_GUIDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ITK+VTK+MFC_GUI.h"
#include "ITK+VTK+MFC_GUIDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CITKVTKMFC_GUIDlg �Ի���




CITKVTKMFC_GUIDlg::CITKVTKMFC_GUIDlg(CWnd* pParent /*=NULL*/)//���캯��
	: CDialogEx(CITKVTKMFC_GUIDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	//ʵ��������
	//CTRebuild_dicm_data = vtkImageData::New();
	CTRebuild_dicm_data = (DicmDataNode *)malloc(sizeof(DicmDataNode));
	CTRebuild_dicm_data->data = vtkImageData::New();
	CTRebuild_dicm_data->next = NULL;
	CTRebuild_dicm_data->dataStyle = -1;

	PETRebuild_dicm_data = (DicmDataNode *)malloc(sizeof(DicmDataNode));
	PETRebuild_dicm_data->data = vtkImageData::New();
	PETRebuild_dicm_data->next = NULL;
	PETRebuild_dicm_data->dataStyle = -1;

	 //��ʷ����ͷ����ʼ��
	head = (DicmDataNode *)malloc(sizeof(DicmDataNode));
	head->next = NULL;
	dataList = head;
	rear = head;

	//==============CT����Ƴ�Աʵ����======================
	CT_lungExtractor = vtkMarchingCubes::New();
	CT_lungDeci = vtkDecimatePro::New();
	CT_lungSmooth = vtkSmoothPolyDataFilter::New();
	CT_lungNormals = vtkPolyDataNormals::New();
	CT_lungStripper = vtkStripper::New();
	CT_lung_surface_Mapper = vtkPolyDataMapper::New();
	CT_lung_surface_actor = vtkActor::New();

	CT_interExtractor = vtkMarchingCubes::New();
	CT_interDeci = vtkDecimatePro::New();
	CT_interSmooth = vtkSmoothPolyDataFilter::New();
	CT_interNormals = vtkPolyDataNormals::New();
	CT_interStripper = vtkStripper::New();
	CT_inter_surface_Mapper = vtkPolyDataMapper::New();
	CT_inter_surface_actor = vtkActor::New();

	CT_shrink = vtkImageShrink3D::New();

	CT_MC_ren = vtkRenderer::New();
	CT_MC_renWin = vtkWin32OpenGLRenderWindow::New();
	CT_MC_iren = vtkWin32RenderWindowInteractor::New();
	//======================================================

	//==============PET����Ƴ�Աʵ����======================
	PET_lungExtractor = vtkMarchingCubes::New();
	PET_lungDeci = vtkDecimatePro::New();
	PET_lungSmooth = vtkSmoothPolyDataFilter::New();
	PET_lungNormals = vtkPolyDataNormals::New();
	PET_lungStripper = vtkStripper::New();
	PET_lung_surface_Mapper = vtkPolyDataMapper::New();
	PET_lung_surface_actor = vtkActor::New();

	PET_interExtractor = vtkMarchingCubes::New();
	PET_interDeci = vtkDecimatePro::New();
	PET_interSmooth = vtkSmoothPolyDataFilter::New();
	PET_interNormals = vtkPolyDataNormals::New();
	PET_interStripper = vtkStripper::New();
	PET_inter_surface_Mapper = vtkPolyDataMapper::New();
	PET_inter_surface_actor = vtkActor::New();

	PET_shrink = vtkImageShrink3D::New();

	PET_MC_ren = vtkRenderer::New();
	PET_MC_renWin = vtkWin32OpenGLRenderWindow::New();
	PET_MC_iren = vtkWin32RenderWindowInteractor::New();
	//======================================================

	//================CT����Ƴ�Աʵ����====================
	CT_shiftScale = vtkImageShiftScale::New();

	CT_rayCastFunction = vtkVolumeRayCastCompositeFunction::New();
	CT_volumeMapper = vtkVolumeRayCastMapper::New();
	CT_volumeColor = vtkColorTransferFunction::New();
	CT_volumeScalarOpacity = vtkPiecewiseFunction::New();
	CT_volumeGradientOpacity = vtkPiecewiseFunction::New();
	CT_volumeProperty = vtkVolumeProperty::New();

	CT_pMapper = vtkFixedPointVolumeRayCastMapper::New();  //�̶���RC
	CT_pColor = vtkColorTransferFunction::New();
	CT_pPiceFun = vtkPiecewiseFunction::New();
	CT_pGradientFun = vtkPiecewiseFunction::New();
	CT_pProperty = vtkVolumeProperty::New();

	CT_volume = vtkVolume::New();

	CT_RC_ren = vtkRenderer::New();
	CT_RC_renWin = vtkWin32OpenGLRenderWindow::New();
	CT_RC_iren = vtkWin32RenderWindowInteractor::New();
	//======================================================

	//================PET����Ƴ�Աʵ����====================
	PET_shiftScale = vtkImageShiftScale::New();

	PET_rayCastFunction = vtkVolumeRayCastCompositeFunction::New();
	PET_volumeMapper = vtkVolumeRayCastMapper::New();
	PET_volumeColor = vtkColorTransferFunction::New();
	PET_volumeScalarOpacity = vtkPiecewiseFunction::New();
	PET_volumeGradientOpacity = vtkPiecewiseFunction::New();
	PET_volumeProperty = vtkVolumeProperty::New();

	PET_pMapper = vtkFixedPointVolumeRayCastMapper::New();  //�̶���RC
	PET_pColor = vtkColorTransferFunction::New();
	PET_pPiceFun = vtkPiecewiseFunction::New();
	PET_pGradientFun = vtkPiecewiseFunction::New();
	PET_pProperty = vtkVolumeProperty::New();

	PET_volume = vtkVolume::New();

	PET_RC_ren = vtkRenderer::New();
	PET_RC_renWin = vtkWin32OpenGLRenderWindow::New();
	PET_RC_iren = vtkWin32RenderWindowInteractor::New();
	//======================================================

	//===========CT��������ԶԻ���=========================
	CTMC_Style = MC;//Ĭ���������MC

	CTMC_LungCT_pos = 103;
	CTMC_LungSmooth_pos = 500;
	CTMC_LungR_pos = 100;
	CTMC_LungG_pos = 19;
	CTMC_LungB_pos = 15;
	CTMC_LungOpacity_pos = 100;

	CTMC_InterCT_pos = 160;
	CTMC_InterSmooth_pos = 100;
	CTMC_InterR_pos = 100;
	CTMC_InterG_pos = 19;
	CTMC_InterB_pos = 15;
	CTMC_InterOpacity_pos = 100;

	CTMC_Ambient_pos = 30;
	CTMC_Diffuse_pos = 60;
	CTMC_Specular_pos = 20;
	CTMC_SpecularPower_pos = 20;
	//======================================================

	//===========PET��������ԶԻ���=========================
	PETMC_Style = MC;//Ĭ���������MC

	PETMC_LungCT_pos = 3;
	PETMC_LungSmooth_pos = 500;
	PETMC_LungR_pos = 100;
	PETMC_LungG_pos = 19;
	PETMC_LungB_pos = 15;
	PETMC_LungOpacity_pos = 100;

	PETMC_InterCT_pos = 170;
	PETMC_InterSmooth_pos = 100;
	PETMC_InterR_pos = 100;
	PETMC_InterG_pos = 19;
	PETMC_InterB_pos = 15;
	PETMC_InterOpacity_pos = 100;

	PETMC_Ambient_pos = 30;
	PETMC_Diffuse_pos = 60;
	PETMC_Specular_pos = 20;
	PETMC_SpecularPower_pos = 20;
	//======================================================

	//===========CT��������ԶԻ���=========================
	CTRC_Style = RC;//Ĭ���������RC

	CTRC_LungCT_pos = 140;
	CTRC_LungR_pos = 100;
	CTRC_LungG_pos = 19;
	CTRC_LungB_pos = 15;
	CTRC_LungOpacity_pos = 100;

	CTRC_InterCT_pos = 170;
	CTRC_InterR_pos = 100;
	CTRC_InterG_pos = 19;
	CTRC_InterB_pos = 15;
	CTRC_InterOpacity_pos = 100;

	CTRC_Ambient_pos = 30;
	CTRC_Diffuse_pos = 60;
	CTRC_Specular_pos = 20;
	CTRC_SpecularPower_pos = 20;

	//======================================================

	//===========PET��������ԶԻ���=========================
	PETRC_Style = RC;//Ĭ���������RC

	PETRC_LungCT_pos = 4;
	PETRC_LungR_pos = 100;
	PETRC_LungG_pos = 19;
	PETRC_LungB_pos = 15;
	PETRC_LungOpacity_pos = 100;

	PETRC_InterCT_pos = 200;
	PETRC_InterR_pos = 100;
	PETRC_InterG_pos = 19;
	PETRC_InterB_pos = 15;
	PETRC_InterOpacity_pos = 100;

	PETRC_Ambient_pos = 30;
	PETRC_Diffuse_pos = 60;
	PETRC_Specular_pos = 20;
	PETRC_SpecularPower_pos = 20;

	//======================================================

	//=======CT��������ԶԻ����Ա������ʼ��===============
	CTMCPropDlg.CTMC_Style = MC;//Ĭ���������MC

	CTMCPropDlg.CTMC_LungCT_pos = 103;
	CTMCPropDlg.CTMC_LungSmooth_pos = 500;
	CTMCPropDlg.CTMC_LungR_pos = 100;
	CTMCPropDlg.CTMC_LungG_pos = 19;
	CTMCPropDlg.CTMC_LungB_pos = 15;
	CTMCPropDlg.CTMC_LungOpacity_pos = 100;

	CTMCPropDlg.CTMC_InterCT_pos = 160;
	CTMCPropDlg.CTMC_InterSmooth_pos = 100;
	CTMCPropDlg.CTMC_InterR_pos = 100;
	CTMCPropDlg.CTMC_InterG_pos = 19;
	CTMCPropDlg.CTMC_InterB_pos = 15;
	CTMCPropDlg.CTMC_InterOpacity_pos = 100;

	CTMCPropDlg.CTMC_Ambient_pos = 30;
	CTMCPropDlg.CTMC_Diffuse_pos = 60;
	CTMCPropDlg.CTMC_Specular_pos = 20;
	CTMCPropDlg.CTMC_SpecularPower_pos = 20;
	//======================================================

	//=======PET��������ԶԻ����Ա������ʼ��===============
	PETMCPropDlg.CTMC_Style = MC;//Ĭ���������MC

	PETMCPropDlg.CTMC_LungCT_pos = 3;
	PETMCPropDlg.CTMC_LungSmooth_pos = 500;
	PETMCPropDlg.CTMC_LungR_pos = 100;
	PETMCPropDlg.CTMC_LungG_pos = 19;
	PETMCPropDlg.CTMC_LungB_pos = 15;
	PETMCPropDlg.CTMC_LungOpacity_pos = 100;

	PETMCPropDlg.CTMC_InterCT_pos = 170;
	PETMCPropDlg.CTMC_InterSmooth_pos = 100;
	PETMCPropDlg.CTMC_InterR_pos = 100;
	PETMCPropDlg.CTMC_InterG_pos = 19;
	PETMCPropDlg.CTMC_InterB_pos = 15;
	PETMCPropDlg.CTMC_InterOpacity_pos = 100;

	PETMCPropDlg.CTMC_Ambient_pos = 30;
	PETMCPropDlg.CTMC_Diffuse_pos = 60;
	PETMCPropDlg.CTMC_Specular_pos = 20;
	PETMCPropDlg.CTMC_SpecularPower_pos = 20;
	//======================================================

	//=======CT��������ԶԻ����Ա������ʼ��===============
	CTRCPropDlg.CTRC_Style = RC;//Ĭ���������RC

	CTRCPropDlg.CTRC_LungCT_pos = 140;
	CTRCPropDlg.CTRC_LungR_pos = 100;
	CTRCPropDlg.CTRC_LungG_pos = 19;
	CTRCPropDlg.CTRC_LungB_pos = 15;
	CTRCPropDlg.CTRC_LungOpacity_pos = 100;

	CTRCPropDlg.CTRC_InterCT_pos = 170;
	CTRCPropDlg.CTRC_InterR_pos = 100;
	CTRCPropDlg.CTRC_InterG_pos = 19;
	CTRCPropDlg.CTRC_InterB_pos = 15;
	CTRCPropDlg.CTRC_InterOpacity_pos = 100;

	CTRCPropDlg.CTRC_Ambient_pos = 30;
	CTRCPropDlg.CTRC_Diffuse_pos = 60;
	CTRCPropDlg.CTRC_Specular_pos = 20;
	CTRCPropDlg.CTRC_SpecularPower_pos = 20;
	//======================================================

	//=======PET��������ԶԻ����Ա������ʼ��===============
	PETRCPropDlg.CTRC_Style = RC;//Ĭ���������RC

	PETRCPropDlg.CTRC_LungCT_pos = 4;
	PETRCPropDlg.CTRC_LungR_pos = 100;
	PETRCPropDlg.CTRC_LungG_pos = 19;
	PETRCPropDlg.CTRC_LungB_pos = 15;
	PETRCPropDlg.CTRC_LungOpacity_pos = 100;

	PETRCPropDlg.CTRC_InterCT_pos = 200;
	PETRCPropDlg.CTRC_InterR_pos = 100;
	PETRCPropDlg.CTRC_InterG_pos = 19;
	PETRCPropDlg.CTRC_InterB_pos = 15;
	PETRCPropDlg.CTRC_InterOpacity_pos = 100;

	PETRCPropDlg.CTRC_Ambient_pos = 30;
	PETRCPropDlg.CTRC_Diffuse_pos = 60;
	PETRCPropDlg.CTRC_Specular_pos = 20;
	PETRCPropDlg.CTRC_SpecularPower_pos = 20;
	//======================================================

	//==================CTMC 3D�������и��Աʵ����==============
	CTMC3DSeg_rep = vtkImplicitPlaneRepresentation::New();
	CTMC3DSeg_implicitPlaneWidget = vtkImplicitPlaneWidget2::New();
	CTMC3DSeg_planeNew = vtkPlane::New();
	CTMC3DSeg_cliper = vtkClipPolyData::New();
	CTMC3DSeg_clipedData = vtkPolyData::New();
	CTMC3DSeg_pCall = VTKWidgetCallCTMC3DSeg::New();

	CTMC3DSegInter_cliper = vtkClipPolyData::New();
	CTMC3DSegInter_clipedData = vtkPolyData::New();

	CTMC3DSeg_CheckButtonStatus = CTMC3DSEG_UNCHECK;//CTMC 3D�������иѡ��ѡ��״̬��ʼδѡ��

	CTMC3DSeg_YesOrNoMC = NO;//CTMC������Ƿ��ؽ���ʼ״̬Ϊδ��ά�ؽ�

	CTRC3DSeg_YesOrNoRC = NO;//CTRC������Ƿ��ؽ���ʼ״̬Ϊδ��ά�ؽ�

	//=====================================================

	//==============CT�����ֱ�߲�����Աʵ����=====================
	CTMCLine_CheckButtonStatus = NO;//CT�����ֱ�߲�����ѡ��ѡ��״̬��ʼδѡ��
	CTMCLine_rep = vtkDistanceRepresentation3D::New();
	CTMCLine_distanceWidget = vtkDistanceWidget::New();
	//=====================================================

	//==============CT�����ֱ�߲�����Աʵ����=====================
	CTRCLine_CheckButtonStatus = NO;//CT�����ֱ�߲�����ѡ��ѡ��״̬��ʼδѡ��
	CTRCLine_rep = vtkDistanceRepresentation3D::New();
	CTRCLine_distanceWidget = vtkDistanceWidget::New();
	//=====================================================

	//==================CT����ƽǶȲ�����Աʵ����===============
	CTMCAngle_CheckButtonStatus = NO;//CT����ƽǶȲ�����ѡ��ѡ��״̬��ʼδѡ��
	CTMCAngle_rep = vtkAngleRepresentation3D::New();
	CTMCAngle_angleWidget = vtkAngleWidget::New();
	//=====================================================

	//==================CT����ƽǶȲ�����Աʵ����===============
	CTRCAngle_CheckButtonStatus = NO;//CT����ƽǶȲ�����ѡ��ѡ��״̬��ʼδѡ��
	CTRCAngle_rep = vtkAngleRepresentation3D::New();
	CTRCAngle_angleWidget = vtkAngleWidget::New();
	//=====================================================

}

void CITKVTKMFC_GUIDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_Import, m_comboImport);
	DDX_Control(pDX, IDC_COMBO_3DRebuild, m_combo3DRebuild);
	DDX_Control(pDX, IDC_COMBO_Property, m_comboProperty);
	DDX_Control(pDX, IDC_COMBO_Help, m_comboHelp);
	DDX_Control(pDX, IDC_COMBO_Previous, m_comboPrevious);
	DDX_Control(pDX, IDC_CHECK_3DCTMCSeg, m_check_3DCTMCSeg);
	DDX_Control(pDX, IDC_CHECK_3DCTMCSeg_Hide, m_check_3DCTMCSeg_Hide);
	DDX_Control(pDX, IDC_CHECK_CTMC_Line, m_check_CTMC_Line);
	DDX_Control(pDX, IDC_CHECK_CTRC_Line, m_check_CTRC_Line);
	DDX_Control(pDX, IDC_CHECK_CTMC_Angle, m_check_CTMC_Angle);
	DDX_Control(pDX, IDC_CHECK_CTRC_Angle, m_check_CTRC_Angle);
}

BEGIN_MESSAGE_MAP(CITKVTKMFC_GUIDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DESTROY()
	ON_CBN_SELENDOK(IDC_COMBO_Import, &CITKVTKMFC_GUIDlg::OnCbnSelendokComboImport)
	ON_CBN_SELENDOK(IDC_COMBO_3DRebuild, &CITKVTKMFC_GUIDlg::OnCbnSelendokCombo3drebuild)
	ON_CBN_SELENDOK(IDC_COMBO_Property, &CITKVTKMFC_GUIDlg::OnCbnSelendokComboProperty)
	ON_CBN_SELENDOK(IDC_COMBO_Previous, &CITKVTKMFC_GUIDlg::OnCbnSelendokComboPrevious)
	ON_BN_CLICKED(IDC_RADIO_2DSeg, &CITKVTKMFC_GUIDlg::OnBnClickedRadio2dseg)
	ON_BN_CLICKED(IDC_RADIO_2DThreePlane, &CITKVTKMFC_GUIDlg::OnBnClickedRadio2dthreeplane)
	ON_BN_CLICKED(IDC_RADIO_VolumeSliceView, &CITKVTKMFC_GUIDlg::OnBnClickedRadioVolumesliceview)
	ON_BN_CLICKED(IDC_CHECK_3DCTMCSeg, &CITKVTKMFC_GUIDlg::OnBnClickedCheck3dctmcseg)
	ON_BN_CLICKED(IDC_CHECK_3DCTMCSeg_Hide, &CITKVTKMFC_GUIDlg::OnBnClickedCheck3dctmcsegHide)
	ON_BN_CLICKED(IDC_CHECK_CTMC_Line, &CITKVTKMFC_GUIDlg::OnBnClickedCheckCtmcLine)
	ON_BN_CLICKED(IDC_CHECK_CTRC_Line, &CITKVTKMFC_GUIDlg::OnBnClickedCheckCtrcLine)
	ON_BN_CLICKED(IDC_CHECK_CTMC_Angle, &CITKVTKMFC_GUIDlg::OnBnClickedCheckCtmcAngle)
	ON_BN_CLICKED(IDC_CHECK_CTRC_Angle, &CITKVTKMFC_GUIDlg::OnBnClickedCheckCtrcAngle)
	ON_BN_CLICKED(IDC_BUTTON_Seg, &CITKVTKMFC_GUIDlg::OnBnClickedButtonSeg)
	ON_CBN_SELENDOK(IDC_COMBO_Help, &CITKVTKMFC_GUIDlg::OnCbnSelendokComboHelp)
END_MESSAGE_MAP()


// CITKVTKMFC_GUIDlg ��Ϣ�������

BOOL CITKVTKMFC_GUIDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	// Ϊ������Ͽ�ؼ����б������б���  
   /* m_comboImport.AddString(_T("һ�����ָ��CT�ļ���"));     
    m_comboImport.AddString(_T("һ�����ָ��PET�ļ���")); */
	m_comboImport.AddString(_T("һ�����ؽ���CT�ļ���"));
	m_comboImport.AddString(_T("һ�����ؽ���PET�ļ���")); 
    // Ĭ��ѡ���һ��   
    m_comboImport.SetCurSel(0);  

	// Ϊ3D�ؽ���Ͽ�ؼ����б������б���  
    m_combo3DRebuild.AddString(_T("CT�����"));     
    m_combo3DRebuild.AddString(_T("PET�����")); 
	m_combo3DRebuild.AddString(_T("CT�����"));
	m_combo3DRebuild.AddString(_T("PET�����")); 
    // Ĭ��ѡ���һ��   
    m_combo3DRebuild.SetCurSel(0);  

	// Ϊ������Ͽ�ؼ����б������б���  
    m_comboProperty.AddString(_T("CT�����"));     
    m_comboProperty.AddString(_T("PET�����")); 
	m_comboProperty.AddString(_T("CT�����"));
	m_comboProperty.AddString(_T("PET�����")); 
    // Ĭ��ѡ���һ��   
    m_comboProperty.SetCurSel(0);  

	// Ϊ������Ͽ�ؼ����б������б���  
    m_comboHelp.AddString(_T("�ֲ�"));     
    m_comboHelp.AddString(_T("����")); 
    // Ĭ��ѡ���һ��   
    m_comboHelp.SetCurSel(0);  

	m_check_3DCTMCSeg_Hide.EnableWindow(FALSE);//CTMC 3D�������и��������ظ�ѡ���ֹʹ��

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CITKVTKMFC_GUIDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CITKVTKMFC_GUIDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CITKVTKMFC_GUIDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CITKVTKMFC_GUIDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: �ڴ˴������Ϣ����������

	//���ٶ���
	//CTRebuild_dicm_data->Delete();
	free(CTRebuild_dicm_data);
	free(PETRebuild_dicm_data);

	//==========CT��������ٶ���===================
	CT_lungExtractor->Delete();
	CT_lungDeci->Delete();
	CT_lungSmooth->Delete();
	CT_lungNormals->Delete();
	CT_lungStripper->Delete();
	CT_lung_surface_Mapper->Delete();
	CT_lung_surface_actor->Delete();

	CT_interExtractor->Delete();
	CT_interDeci->Delete();
	CT_interSmooth->Delete();
	CT_interNormals->Delete();
	CT_interStripper->Delete();
	CT_inter_surface_Mapper->Delete();
	CT_inter_surface_actor->Delete();

	CT_shrink->Delete();


	CT_MC_ren->Delete();
	CT_MC_renWin->Delete();
	CT_MC_iren->Delete();
	//=============================================

	//==========PET��������ٶ���===================
	PET_lungExtractor->Delete();
	PET_lungDeci->Delete();
	PET_lungSmooth->Delete();
	PET_lungNormals->Delete();
	PET_lungStripper->Delete();
	PET_lung_surface_Mapper->Delete();
	PET_lung_surface_actor->Delete();

	PET_interExtractor->Delete();
	PET_interDeci->Delete();
	PET_interSmooth->Delete();
	PET_interNormals->Delete();
	PET_interStripper->Delete();
	PET_inter_surface_Mapper->Delete();
	PET_inter_surface_actor->Delete();

	PET_shrink->Delete();


	PET_MC_ren->Delete();
	PET_MC_renWin->Delete();
	PET_MC_iren->Delete();
	//=============================================

	//=============CT��������ٶ���================
	CT_shiftScale->Delete();

	CT_rayCastFunction->Delete();
	CT_volumeMapper->Delete();
	CT_volumeColor->Delete();
	CT_volumeScalarOpacity->Delete();
	CT_volumeGradientOpacity->Delete();
	CT_volumeProperty->Delete();

	CT_pMapper->Delete();  //�̶���RC
	CT_pColor->Delete();
	CT_pPiceFun->Delete();
	CT_pGradientFun->Delete();
	CT_pProperty->Delete();

	CT_volume->Delete();

	CT_RC_ren->Delete();
	CT_RC_renWin->Delete();
	CT_RC_iren->Delete();
	//=============================================

	//=============PET��������ٶ���================
	PET_shiftScale->Delete();

	PET_rayCastFunction->Delete();
	PET_volumeMapper->Delete();
	PET_volumeColor->Delete();
	PET_volumeScalarOpacity->Delete();
	PET_volumeGradientOpacity->Delete();
	PET_volumeProperty->Delete();

	PET_pMapper->Delete();  //�̶���RC
	PET_pColor->Delete();
	PET_pPiceFun->Delete();
	PET_pGradientFun->Delete();
	PET_pProperty->Delete();

	PET_volume->Delete();

	PET_RC_ren->Delete();
	PET_RC_renWin->Delete();
	PET_RC_iren->Delete();
	//=============================================

	delete CTMCPropDlg;
	delete CTRCPropDlg;

	delete PETMCPropDlg;
	delete PETRCPropDlg;

	//=============�ͷ���ʷ��������================
	DicmDataNode *temp,*temp1;//�ƶ�ָ��
	temp = dataList;
	while(temp!=NULL)
	{
		temp1 = temp;
		temp = temp->next;
		free(temp1);
	}
	//=============================================

	//==================CTMC 3D�������и����ٶ���==============
	CTMC3DSeg_rep->Delete();
	CTMC3DSeg_implicitPlaneWidget->Delete();
	CTMC3DSeg_planeNew->Delete();
	CTMC3DSeg_cliper->Delete();
	CTMC3DSeg_clipedData->Delete();
	CTMC3DSeg_pCall->Delete();

	CTMC3DSegInter_cliper->Delete();
	CTMC3DSegInter_clipedData->Delete();

	//=====================================================

	//==============CT�����ֱ�߲������ٶ���=====================
	CTMCLine_rep->Delete();
	CTMCLine_distanceWidget->Delete();
	//=====================================================

	//==============CT�����ֱ�߲������ٶ���=====================
	CTRCLine_rep->Delete();
	CTRCLine_distanceWidget->Delete();
	//=====================================================

	//==================CT����ƽǶȲ������ٶ���===============
	CTMCAngle_rep->Delete();
	CTMCAngle_angleWidget->Delete();
	//=====================================================

	//==================CT����ƽǶȲ������ٶ���===============
	CTRCAngle_rep->Delete();
	CTRCAngle_angleWidget->Delete();
	//=====================================================

}


//������Ͽ�ѡ��ѡ���¼�
void CITKVTKMFC_GUIDlg::OnCbnSelendokComboImport()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	CString strImport;   
    int nSel;   
  
    // ��ȡ��Ͽ�ؼ����б����ѡ���������   
    nSel = m_comboImport.GetCurSel();   
    // ����ѡ����������ȡ�����ַ���   
    m_comboImport.GetLBText(nSel, strImport);   
	strImport +=_T("���ڵ���...");
	SetDlgItemText(IDC_EDIT_RunStatus, strImport);
	//if(nSel == 0) //����һ�����ָ��CT�ļ���
	//{
	//	//��չ����
	//}
	//else if(nSel == 1)//����һ�����ָ��PET�ļ���
	//{
	//	//��չ����
	//}
	if(nSel == 0)//����һ�����ؽ���CT�ļ���
	{
		//��չ����
		BROWSEINFO bi;
		char chDir[MAX_PATH] = {0};
		memset((char *)&bi, 0, sizeof(bi));
		bi.hwndOwner = this->m_hWnd;
		bi.lpszTitle = "ѡ��һ�����ؽ���CT�ļ���";

		bi.ulFlags = BIF_BROWSEFORCOMPUTER | BIF_RETURNONLYFSDIRS;	
			ITEMIDLIST *pList = NULL;
		pList = SHBrowseForFolder(&bi);

		if (pList == NULL)
		{
			return;		
		}
		SHGetPathFromIDList(pList, chDir);
		vtkDICOMImageReader *pRead = vtkDICOMImageReader::New();
		pRead->SetDirectoryName(chDir);
		pRead->SetDataByteOrderToLittleEndian();
		
		pRead->Update();

		if (pRead->GetDataExtent()[5] == -1)
		{
			MessageBox("��ȡ����");
			return;
		}
	
		CTRebuild_dicm_data->data = pRead->GetOutput();	
		CTRebuild_dicm_data->dataStyle = REBUILD_CT;

		SetDlgItemText(IDC_EDIT_RunStatus, _T("����ɹ���"));

		//�ѵ����dicm������ӵ���ʷ������Ͽ���
		m_comboPrevious.AddString(_T(chDir));     
		// Ĭ��ѡ���һ��   
		m_comboPrevious.SetCurSel(0);  

		//�ѵ������������ӵ���ʷ��������ı�β
		DicmDataNode *p;//�����½ڵ�ָ��
		p = (DicmDataNode *)malloc(sizeof(DicmDataNode));
		p->data = CTRebuild_dicm_data->data;
		p->dataStyle = REBUILD_CT;
		p->next = NULL;
		rear->next = p;
		rear = p;
	}
	else if(nSel == 1)//����һ�����ؽ���PET�ļ���
	{
		//��չ����
		BROWSEINFO bi;
		char chDir[MAX_PATH] = {0};
		memset((char *)&bi, 0, sizeof(bi));
		bi.hwndOwner = this->m_hWnd;
		bi.lpszTitle = "ѡ��һ�����ؽ���PET�ļ���";

		bi.ulFlags = BIF_BROWSEFORCOMPUTER | BIF_RETURNONLYFSDIRS;	
		ITEMIDLIST *pList = NULL;
		pList = SHBrowseForFolder(&bi);

		if (pList == NULL)
		{
			return;		
		}
		SHGetPathFromIDList(pList, chDir);
		vtkDICOMImageReader *pRead = vtkDICOMImageReader::New();
		pRead->SetDirectoryName(chDir);
		pRead->SetDataByteOrderToLittleEndian();
		
		pRead->Update();

		if (pRead->GetDataExtent()[5] == -1)
		{
			MessageBox("��ȡ����");
			return;
		}
	
		PETRebuild_dicm_data->data = pRead->GetOutput();	
		PETRebuild_dicm_data->dataStyle = REBUILD_PET;

		SetDlgItemText(IDC_EDIT_RunStatus, _T("����ɹ���"));

		//�ѵ����dicm������ӵ���ʷ������Ͽ���
		m_comboPrevious.AddString(_T(chDir));     
		// Ĭ��ѡ���һ��   
		m_comboPrevious.SetCurSel(0);  

		//�ѵ������������ӵ���ʷ��������ı�β
		DicmDataNode *p;//�����½ڵ�ָ��
		p = (DicmDataNode *)malloc(sizeof(DicmDataNode));
		p->data = PETRebuild_dicm_data->data;
		p->dataStyle = REBUILD_PET;
		p->next = NULL;
		rear->next = p;
		rear = p;
	}
}


//3D�ؽ���Ͽ�ѡ��ѡ���¼�
void CITKVTKMFC_GUIDlg::OnCbnSelendokCombo3drebuild()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	CString str3DRebuild;   
    int nSel;   
  
    // ��ȡ��Ͽ�ؼ����б����ѡ���������   
    nSel = m_combo3DRebuild.GetCurSel();   
    // ����ѡ����������ȡ�����ַ���   
    m_combo3DRebuild.GetLBText(nSel, str3DRebuild);   
	str3DRebuild +=_T("���ڻ���...");
	SetDlgItemText(IDC_EDIT_RunStatus, str3DRebuild);
	if(nSel == 0) //3D�ؽ�CT�����
	{
		//��չ����
		if(CTRebuild_dicm_data->dataStyle!=REBUILD_CT) //�״β���ʱ�ж��Ƿ�����һ�����ؽ���CT�ļ���
		{  
  
			// ��ʾ��Ϣ�Ի���   
			MessageBox(_T("���ȵ���һ�����ؽ���CT�ļ��У�"), _T("��ʾ"), MB_OK | MB_ICONWARNING);    

			SetDlgItemText(IDC_EDIT_RunStatus, _T("���ȵ���һ�����ؽ���CT�ļ��У�"));
			return;
		}
		if (!CT_MC_iren->GetInitialized())
		{
			CT_MC_renWin->AddRenderer(CT_MC_ren);
			CT_MC_renWin->SetParentId(GetDlgItem(IDC_STATIC_CT_MCVIEW)->m_hWnd); //ע����һ�������û��ƴ���
			
			CT_MC_iren->SetRenderWindow(CT_MC_renWin);
			CRect rect;
			GetDlgItem(IDC_STATIC_CT_MCVIEW)->GetWindowRect(&rect);
			CT_MC_iren->Initialize();
			CT_MC_renWin->SetSize(rect.right-rect.left,rect.bottom-rect.top);
			CT_MC_ren->ResetCamera();
	
		}
		//���ùܵ���pipeline()
		Pipeline_CT_MC();
		CT_MC_renWin->Render();
		SetDlgItemText(IDC_EDIT_RunStatus, _T("CT����Ƴɹ���"));
	}
	else if(nSel == 1) //3D�ؽ�PET�����
	{
		//��չ����
		if(PETRebuild_dicm_data->dataStyle!=REBUILD_PET) //�״β���ʱ�ж��Ƿ�����һ�����ؽ���PET�ļ���
		{  
  
			// ��ʾ��Ϣ�Ի���   
			MessageBox(_T("���ȵ���һ�����ؽ���PET�ļ��У�"), _T("��ʾ"), MB_OK | MB_ICONWARNING);    

			SetDlgItemText(IDC_EDIT_RunStatus, _T("���ȵ���һ�����ؽ���PET�ļ��У�"));
			return;
		}
		if (!PET_MC_iren->GetInitialized())
		{
			PET_MC_renWin->AddRenderer(PET_MC_ren);
			PET_MC_renWin->SetParentId(GetDlgItem(IDC_STATIC_PET_MCVIEW)->m_hWnd); //ע����һ�������û��ƴ���
			
			PET_MC_iren->SetRenderWindow(PET_MC_renWin);
			CRect rect;
			GetDlgItem(IDC_STATIC_PET_MCVIEW)->GetWindowRect(&rect);
			PET_MC_iren->Initialize();
			PET_MC_renWin->SetSize(rect.right-rect.left,rect.bottom-rect.top);
			PET_MC_ren->ResetCamera();
	
		}
		//���ùܵ���pipeline()
		Pipeline_PET_MC();
		PET_MC_renWin->Render();
		SetDlgItemText(IDC_EDIT_RunStatus, _T("PET����Ƴɹ���"));
	}
	else if(nSel == 2) //3D�ؽ�CT�����
	{
		//��չ����
		if(CTRebuild_dicm_data->dataStyle!=REBUILD_CT) //�״β���ʱ�ж��Ƿ�����һ�����ؽ���CT�ļ���
		{  
  
			// ��ʾ��Ϣ�Ի���   
			MessageBox(_T("���ȵ���һ�����ؽ���CT�ļ��У�"), _T("��ʾ"), MB_OK | MB_ICONWARNING);    

			SetDlgItemText(IDC_EDIT_RunStatus, _T("���ȵ���һ�����ؽ���CT�ļ��У�"));
			return;
		}
		if (!CT_RC_iren->GetInitialized())
		{
			CT_RC_renWin->AddRenderer(CT_RC_ren);
			CT_RC_renWin->SetParentId(GetDlgItem(IDC_STATIC_CT_RCVIEW)->m_hWnd); //ע����һ�������û��ƴ���
			
			CT_RC_iren->SetRenderWindow(CT_RC_renWin);
			CRect rect;
			GetDlgItem(IDC_STATIC_CT_RCVIEW)->GetWindowRect(&rect);
			CT_RC_iren->Initialize();
			CT_RC_renWin->SetSize(rect.right-rect.left,rect.bottom-rect.top);
			CT_RC_ren->ResetCamera();
	
		}
		//���ùܵ���pipeline()
		Pipeline_CT_RC();
		CT_RC_renWin->Render();
		SetDlgItemText(IDC_EDIT_RunStatus, _T("CT����Ƴɹ���"));
	}
	else if(nSel == 3) //3D�ؽ�PET�����
	{
		//��չ����
		if(PETRebuild_dicm_data->dataStyle!=REBUILD_PET) //�״β���ʱ�ж��Ƿ�����һ�����ؽ���PET�ļ���
		{  
  
			// ��ʾ��Ϣ�Ի���   
			MessageBox(_T("���ȵ���һ�����ؽ���PET�ļ��У�"), _T("��ʾ"), MB_OK | MB_ICONWARNING);    

			SetDlgItemText(IDC_EDIT_RunStatus, _T("���ȵ���һ�����ؽ���PET�ļ��У�"));
			return;
		}
		if (!PET_RC_iren->GetInitialized())
		{
			PET_RC_renWin->AddRenderer(PET_RC_ren);
			PET_RC_renWin->SetParentId(GetDlgItem(IDC_STATIC_PET_RCVIEW)->m_hWnd); //ע����һ�������û��ƴ���
			
			PET_RC_iren->SetRenderWindow(PET_RC_renWin);
			CRect rect;
			GetDlgItem(IDC_STATIC_PET_RCVIEW)->GetWindowRect(&rect);
			PET_RC_iren->Initialize();
			PET_RC_renWin->SetSize(rect.right-rect.left,rect.bottom-rect.top);
			PET_RC_ren->ResetCamera();
	
		}
		//���ùܵ���pipeline()
		Pipeline_PET_RC();
		PET_RC_renWin->Render();
		SetDlgItemText(IDC_EDIT_RunStatus, _T("PET����Ƴɹ���"));
	}
}

void CITKVTKMFC_GUIDlg::SetProperty_CT_MC(int CTMC_Style1,int CTMC_LungCT_pos1,int CTMC_LungSmooth_pos1,int CTMC_LungR_pos1,int CTMC_LungG_pos1,int CTMC_LungB_pos1,int CTMC_LungOpacity_pos1,int CTMC_InterCT_pos1,int CTMC_InterSmooth_pos1,int CTMC_InterR_pos1,int CTMC_InterG_pos1,int CTMC_InterB_pos1,int CTMC_InterOpacity_pos1,int CTMC_Ambient_pos1,int CTMC_Diffuse_pos1,int CTMC_Specular_pos1,int CTMC_SpecularPower_pos1)
{
	CTMC_Style = CTMC_Style1;

	CTMC_LungCT_pos = CTMC_LungCT_pos1;
	CTMC_LungSmooth_pos = CTMC_LungSmooth_pos1;
	CTMC_LungR_pos = CTMC_LungR_pos1;
	CTMC_LungG_pos = CTMC_LungG_pos1;
	CTMC_LungB_pos = CTMC_LungB_pos1;
	CTMC_LungOpacity_pos = CTMC_LungOpacity_pos1;

	CTMC_InterCT_pos = CTMC_InterCT_pos1;
	CTMC_InterSmooth_pos = CTMC_InterSmooth_pos1;
	CTMC_InterR_pos = CTMC_InterR_pos1;
	CTMC_InterG_pos = CTMC_InterG_pos1;
	CTMC_InterB_pos = CTMC_InterB_pos1;
	CTMC_InterOpacity_pos = CTMC_InterOpacity_pos1;

	CTMC_Ambient_pos = CTMC_Ambient_pos1;
	CTMC_Diffuse_pos = CTMC_Diffuse_pos1;
	CTMC_Specular_pos = CTMC_Specular_pos1;
	CTMC_SpecularPower_pos = CTMC_SpecularPower_pos1;
}

void CITKVTKMFC_GUIDlg::SetProperty_PET_MC(int PETMC_Style1,int PETMC_LungCT_pos1,int PETMC_LungSmooth_pos1,int PETMC_LungR_pos1,int PETMC_LungG_pos1,int PETMC_LungB_pos1,int PETMC_LungOpacity_pos1,int PETMC_InterCT_pos1,int PETMC_InterSmooth_pos1,int PETMC_InterR_pos1,int PETMC_InterG_pos1,int PETMC_InterB_pos1,int PETMC_InterOpacity_pos1,int PETMC_Ambient_pos1,int PETMC_Diffuse_pos1,int PETMC_Specular_pos1,int PETMC_SpecularPower_pos1)
{
	PETMC_Style = PETMC_Style1;

	PETMC_LungCT_pos = PETMC_LungCT_pos1;
	PETMC_LungSmooth_pos = PETMC_LungSmooth_pos1;
	PETMC_LungR_pos = PETMC_LungR_pos1;
	PETMC_LungG_pos = PETMC_LungG_pos1;
	PETMC_LungB_pos = PETMC_LungB_pos1;
	PETMC_LungOpacity_pos = PETMC_LungOpacity_pos1;

	PETMC_InterCT_pos = PETMC_InterCT_pos1;
	PETMC_InterSmooth_pos = PETMC_InterSmooth_pos1;
	PETMC_InterR_pos = PETMC_InterR_pos1;
	PETMC_InterG_pos = PETMC_InterG_pos1;
	PETMC_InterB_pos = PETMC_InterB_pos1;
	PETMC_InterOpacity_pos = PETMC_InterOpacity_pos1;

	PETMC_Ambient_pos = PETMC_Ambient_pos1;
	PETMC_Diffuse_pos = PETMC_Diffuse_pos1;
	PETMC_Specular_pos = PETMC_Specular_pos1;
	PETMC_SpecularPower_pos = PETMC_SpecularPower_pos1;
}

void CITKVTKMFC_GUIDlg::SetProperty_CT_RC(int CTRC_Style1,int CTRC_LungCT_pos1,int CTRC_LungR_pos1,int CTRC_LungG_pos1,int CTRC_LungB_pos1,int CTRC_LungOpacity_pos1,int CTRC_InterCT_pos1,int CTRC_InterR_pos1,int CTRC_InterG_pos1,int CTRC_InterB_pos1,int CTRC_InterOpacity_pos1,int CTRC_Ambient_pos1,int CTRC_Diffuse_pos1,int CTRC_Specular_pos1,int CTRC_SpecularPower_pos1)
{
	CTRC_Style = CTRC_Style1;

	CTRC_LungCT_pos = CTRC_LungCT_pos1;
	CTRC_LungR_pos = CTRC_LungR_pos1;
	CTRC_LungG_pos = CTRC_LungG_pos1;
	CTRC_LungB_pos = CTRC_LungB_pos1;
	CTRC_LungOpacity_pos = CTRC_LungOpacity_pos1;

	CTRC_InterCT_pos = CTRC_InterCT_pos1;
	CTRC_InterR_pos = CTRC_InterR_pos1;
	CTRC_InterG_pos = CTRC_InterG_pos1;
	CTRC_InterB_pos = CTRC_InterB_pos1;
	CTRC_InterOpacity_pos = CTRC_InterOpacity_pos1;

	CTRC_Ambient_pos = CTRC_Ambient_pos1;
	CTRC_Diffuse_pos = CTRC_Diffuse_pos1;
	CTRC_Specular_pos = CTRC_Specular_pos1;
	CTRC_SpecularPower_pos = CTRC_SpecularPower_pos1;
}

void CITKVTKMFC_GUIDlg::SetProperty_PET_RC(int PETRC_Style1,int PETRC_LungCT_pos1,int PETRC_LungR_pos1,int PETRC_LungG_pos1,int PETRC_LungB_pos1,int PETRC_LungOpacity_pos1,int PETRC_InterCT_pos1,int PETRC_InterR_pos1,int PETRC_InterG_pos1,int PETRC_InterB_pos1,int PETRC_InterOpacity_pos1,int PETRC_Ambient_pos1,int PETRC_Diffuse_pos1,int PETRC_Specular_pos1,int PETRC_SpecularPower_pos1)
{
	PETRC_Style = PETRC_Style1;

	PETRC_LungCT_pos = PETRC_LungCT_pos1;
	PETRC_LungR_pos = PETRC_LungR_pos1;
	PETRC_LungG_pos = PETRC_LungG_pos1;
	PETRC_LungB_pos = PETRC_LungB_pos1;
	PETRC_LungOpacity_pos = PETRC_LungOpacity_pos1;

	PETRC_InterCT_pos = PETRC_InterCT_pos1;
	PETRC_InterR_pos = PETRC_InterR_pos1;
	PETRC_InterG_pos = PETRC_InterG_pos1;
	PETRC_InterB_pos = PETRC_InterB_pos1;
	PETRC_InterOpacity_pos = PETRC_InterOpacity_pos1;

	PETRC_Ambient_pos = PETRC_Ambient_pos1;
	PETRC_Diffuse_pos = PETRC_Diffuse_pos1;
	PETRC_Specular_pos = PETRC_Specular_pos1;
	PETRC_SpecularPower_pos = PETRC_SpecularPower_pos1;
}

void CITKVTKMFC_GUIDlg::Pipeline_CT_MC()
{
	CTMC3DSeg_YesOrNoMC = YES; //CTMC�������ά�ؽ�

	if(CTMC_Style == MC)//MC
	{
		CT_lungExtractor->SetInputData(CTRebuild_dicm_data->data);  //�������ȡ��CT ����
		CT_lungExtractor->SetValue(0,CTMC_LungCT_pos);//��CTֵ  
		CT_lungExtractor->ComputeNormalsOn();   
		CT_lungExtractor->ComputeGradientsOn();

		CT_lungSmooth->SetInputConnection(CT_lungExtractor->GetOutputPort());
		CT_lungSmooth->SetNumberOfIterations(CTMC_LungSmooth_pos) ;//����Laplaceƽ���ĵ�������

		CT_lungNormals->SetInputConnection(CT_lungSmooth->GetOutputPort());  
		CT_lungNormals->SetFeatureAngle(60.0);  // ָ���ڷ�����Ե�ĽǶ�ֵ
		CT_lungStripper->SetInputConnection(CT_lungNormals->GetOutputPort());   //�����ɵ�����Ƭ���ӳ����Ǵ�

		CT_lung_surface_Mapper->SetInputConnection(CT_lungStripper->GetOutputPort());   //�����Ǵ�ӳ��Ϊ��������
		CT_lung_surface_Mapper->ScalarVisibilityOff(); 

		CT_lung_surface_actor->SetMapper(CT_lung_surface_Mapper);  
	
		CT_lung_surface_actor->GetProperty()->SetColor((double)CTMC_LungR_pos/100, (double)CTMC_LungG_pos/100, (double)CTMC_LungB_pos/100);

		CT_lung_surface_actor->GetProperty()->SetAmbient((double)CTMC_Ambient_pos/100);
		CT_lung_surface_actor->GetProperty()->SetDiffuse((double)CTMC_Diffuse_pos/100);
		CT_lung_surface_actor->GetProperty()->SetSpecular((double)CTMC_Specular_pos/100);
		CT_lung_surface_actor->GetProperty()->SetSpecularPower(CTMC_SpecularPower_pos);
		CT_lung_surface_actor->GetProperty()->SetOpacity((double)CTMC_LungOpacity_pos/100);


		CT_interExtractor->SetInputData(CTRebuild_dicm_data->data);  //�������ȡ��CT ����
		CT_interExtractor->SetValue(0,CTMC_InterCT_pos);//���ڲ�Ѫ�ܽ��CTֵ  
		CT_interExtractor->ComputeNormalsOn();   
		CT_interExtractor->ComputeGradientsOn();

		CT_interSmooth->SetInputConnection(CT_interExtractor->GetOutputPort());
		CT_interSmooth->SetNumberOfIterations(CTMC_InterSmooth_pos) ;//����Laplaceƽ���ĵ�������

		//ͨ��vtkPolyDataNormals�ڵ�ֵ���ϲ���������
		CT_interNormals->SetInputConnection(CT_interSmooth->GetOutputPort());  
		CT_interNormals->SetFeatureAngle(60.0);  // ָ���ڷ�����Ե�ĽǶ�ֵ

		// �޳��ɵĻ�ϳ������ݵ�Ԫ����߻����ٶ�
		//ͨ��vtkStripper�ڵ�ֵ���ϲ��������������Ƭ
		CT_interStripper->SetInputConnection(CT_interNormals->GetOutputPort());   //�����ɵ�����Ƭ���ӳ����Ǵ�

		CT_inter_surface_Mapper->SetInputConnection(CT_interStripper->GetOutputPort());   //�����Ǵ�ӳ��Ϊ��������
		CT_inter_surface_Mapper->ScalarVisibilityOff(); 

		CT_inter_surface_actor->SetMapper(CT_inter_surface_Mapper);  

		CT_inter_surface_actor->GetProperty()->SetColor((double)CTMC_InterR_pos/100, (double)CTMC_InterG_pos/100, (double)CTMC_InterB_pos/100);

		CT_inter_surface_actor->GetProperty()->SetAmbient((double)CTMC_Ambient_pos/100);
		CT_inter_surface_actor->GetProperty()->SetDiffuse((double)CTMC_Diffuse_pos/100);
		CT_inter_surface_actor->GetProperty()->SetSpecular((double)CTMC_Specular_pos/100);
		CT_inter_surface_actor->GetProperty()->SetSpecularPower(CTMC_SpecularPower_pos);
		CT_inter_surface_actor->GetProperty()->SetOpacity((double)CTMC_InterOpacity_pos/100);

		CT_MC_ren->SetBackground(0.5,0.5,0.5);  
		CT_MC_ren->ResetCameraClippingRange();  
		CT_MC_ren->AddActor(CT_lung_surface_actor);
		CT_MC_ren->AddActor(CT_inter_surface_actor);
	}
	else if(CTMC_Style == ACC_MC)//����MC
	{
		CT_shrink->SetInputData(CTRebuild_dicm_data->data);
		CT_shrink->SetShrinkFactors(4,4,1);//��������

		CT_lungExtractor->SetInputConnection(CT_shrink->GetOutputPort());  //�������ȡ��CT ����
		CT_lungExtractor->SetValue(0,CTMC_LungCT_pos);//��CTֵ  
		CT_lungExtractor->ComputeNormalsOn();   
		CT_lungExtractor->ComputeGradientsOn();

		CT_lungDeci->SetInputConnection(CT_lungExtractor->GetOutputPort());
		CT_lungDeci->SetTargetReduction(0.3);//��ԭ�ȵ�������Ƭ���ٵ�ԭ���İٷ�֮��ʮ

		CT_lungSmooth->SetInputConnection(CT_lungDeci->GetOutputPort());
		CT_lungSmooth->SetNumberOfIterations(CTMC_LungSmooth_pos) ;//����Laplaceƽ���ĵ�������

		CT_lungNormals->SetInputConnection(CT_lungSmooth->GetOutputPort());  
		CT_lungNormals->SetFeatureAngle(60.0);  // ָ���ڷ�����Ե�ĽǶ�ֵ
		CT_lungStripper->SetInputConnection(CT_lungNormals->GetOutputPort());   //�����ɵ�����Ƭ���ӳ����Ǵ�

		CT_lung_surface_Mapper->SetInputConnection(CT_lungStripper->GetOutputPort());   //�����Ǵ�ӳ��Ϊ��������
		CT_lung_surface_Mapper->ScalarVisibilityOff(); 

		CT_lung_surface_actor->SetMapper(CT_lung_surface_Mapper);  
	
		CT_lung_surface_actor->GetProperty()->SetColor((double)CTMC_LungR_pos/100, (double)CTMC_LungG_pos/100, (double)CTMC_LungB_pos/100);

		CT_lung_surface_actor->GetProperty()->SetAmbient((double)CTMC_Ambient_pos/100);
		CT_lung_surface_actor->GetProperty()->SetDiffuse((double)CTMC_Diffuse_pos/100);
		CT_lung_surface_actor->GetProperty()->SetSpecular((double)CTMC_Specular_pos/100);
		CT_lung_surface_actor->GetProperty()->SetSpecularPower(CTMC_SpecularPower_pos);
		CT_lung_surface_actor->GetProperty()->SetOpacity((double)CTMC_LungOpacity_pos/100);

		CT_interExtractor->SetInputData(CTRebuild_dicm_data->data);  //�������ȡ��CT ����
		CT_interExtractor->SetValue(0,CTMC_InterCT_pos);//���ڲ�Ѫ�ܽ��CTֵ  
		CT_interExtractor->ComputeNormalsOn();   
		CT_interExtractor->ComputeGradientsOn();

		CT_interSmooth->SetInputConnection(CT_interExtractor->GetOutputPort());
		CT_interSmooth->SetNumberOfIterations(CTMC_InterSmooth_pos) ;//����Laplaceƽ���ĵ�������

		//ͨ��vtkPolyDataNormals�ڵ�ֵ���ϲ���������
		CT_interNormals->SetInputConnection(CT_interSmooth->GetOutputPort());  
		CT_interNormals->SetFeatureAngle(60.0);  // ָ���ڷ�����Ե�ĽǶ�ֵ

		// �޳��ɵĻ�ϳ������ݵ�Ԫ����߻����ٶ�
		//ͨ��vtkStripper�ڵ�ֵ���ϲ��������������Ƭ
		CT_interStripper->SetInputConnection(CT_interNormals->GetOutputPort());   //�����ɵ�����Ƭ���ӳ����Ǵ�

		CT_inter_surface_Mapper->SetInputConnection(CT_interStripper->GetOutputPort());   //�����Ǵ�ӳ��Ϊ��������
		CT_inter_surface_Mapper->ScalarVisibilityOff(); 

		CT_inter_surface_actor->SetMapper(CT_inter_surface_Mapper);  

		CT_inter_surface_actor->GetProperty()->SetColor((double)CTMC_InterR_pos/100, (double)CTMC_InterG_pos/100, (double)CTMC_InterB_pos/100);

		CT_inter_surface_actor->GetProperty()->SetAmbient((double)CTMC_Ambient_pos/100);
		CT_inter_surface_actor->GetProperty()->SetDiffuse((double)CTMC_Diffuse_pos/100);
		CT_inter_surface_actor->GetProperty()->SetSpecular((double)CTMC_Specular_pos/100);
		CT_inter_surface_actor->GetProperty()->SetSpecularPower(CTMC_SpecularPower_pos);
		CT_inter_surface_actor->GetProperty()->SetOpacity((double)CTMC_InterOpacity_pos/100);

		CT_MC_ren->SetBackground(0.5,0.5,0.5);  
		CT_MC_ren->ResetCameraClippingRange();  
		CT_MC_ren->AddActor(CT_lung_surface_actor);
		CT_MC_ren->AddActor(CT_inter_surface_actor);
	}

	if(CTMC3DSeg_CheckButtonStatus == CTMC3DSEG_CHECKED)//����CTMC 3D�������и�
	{
		CTMC3DSeg_rep->SetPlaceFactor(1.25); // This must be set prior to placing the widget
		CTMC3DSeg_rep->PlaceWidget(CT_lung_surface_actor->GetBounds());

		CTMC3DSeg_implicitPlaneWidget->SetInteractor(CT_MC_iren);
		CTMC3DSeg_implicitPlaneWidget->SetRepresentation(CTMC3DSeg_rep);

		CTMC3DSeg_cliper->SetInputConnection(CT_lungStripper->GetOutputPort());
		CTMC3DSeg_cliper->SetClipFunction(CTMC3DSeg_planeNew);
		CTMC3DSeg_cliper->Update();

		CTMC3DSegInter_cliper->SetInputConnection(CT_interStripper->GetOutputPort());
		CTMC3DSegInter_cliper->SetClipFunction(CTMC3DSeg_planeNew);
		CTMC3DSegInter_cliper->Update();

		CTMC3DSeg_clipedData->DeepCopy(CTMC3DSeg_cliper->GetOutput());

		CTMC3DSegInter_clipedData->DeepCopy(CTMC3DSegInter_cliper->GetOutput());

		CTMC3DSeg_pCall->setPlane(CTMC3DSeg_planeNew);
		CTMC3DSeg_pCall->setActor_lung_surface(CT_lung_surface_actor);
		CTMC3DSeg_pCall->setCliper_lung_surface(CTMC3DSeg_cliper);

		CTMC3DSeg_pCall->setActor_inter_surface(CT_inter_surface_actor);
		CTMC3DSeg_pCall->setCliper_inter_surface(CTMC3DSegInter_cliper);

		CTMC3DSeg_pCall->SetProperty_CTMC3DSeg(CTMC_LungR_pos,CTMC_LungG_pos,CTMC_LungB_pos,CTMC_LungOpacity_pos,CTMC_InterR_pos,CTMC_InterG_pos,CTMC_InterB_pos,CTMC_InterOpacity_pos,CTMC_Ambient_pos,CTMC_Diffuse_pos,CTMC_Specular_pos,CTMC_SpecularPower_pos);

		CTMC3DSeg_implicitPlaneWidget->AddObserver(vtkCommand::EndInteractionEvent, CTMC3DSeg_pCall);
		CTMC3DSeg_implicitPlaneWidget->On();
	}
	else if(CTMC3DSeg_CheckButtonStatus == CTMC3DSEG_UNCHECK)//ȡ��CTMC 3D�������и�
	{
		CTMC3DSeg_implicitPlaneWidget->Off();
	}
	
}

void CITKVTKMFC_GUIDlg::Pipeline_PET_MC()
{
	if(PETMC_Style == MC)//MC
	{
		PET_lungExtractor->SetInputData(PETRebuild_dicm_data->data);  //�������ȡ��PET ����
		PET_lungExtractor->SetValue(0,PETMC_LungCT_pos);//��CTֵ  
		PET_lungExtractor->ComputeNormalsOn();   
		PET_lungExtractor->ComputeGradientsOn();

		PET_lungSmooth->SetInputConnection(PET_lungExtractor->GetOutputPort());
		PET_lungSmooth->SetNumberOfIterations(PETMC_LungSmooth_pos) ;//����Laplaceƽ���ĵ�������

		PET_lungNormals->SetInputConnection(PET_lungSmooth->GetOutputPort());  
		PET_lungNormals->SetFeatureAngle(60.0);  // ָ���ڷ�����Ե�ĽǶ�ֵ
		PET_lungStripper->SetInputConnection(PET_lungNormals->GetOutputPort());   //�����ɵ�����Ƭ���ӳ����Ǵ�

		PET_lung_surface_Mapper->SetInputConnection(PET_lungStripper->GetOutputPort());   //�����Ǵ�ӳ��Ϊ��������
		PET_lung_surface_Mapper->ScalarVisibilityOff(); 

		PET_lung_surface_actor->SetMapper(PET_lung_surface_Mapper);  
	
		PET_lung_surface_actor->GetProperty()->SetColor((double)PETMC_LungR_pos/100, (double)PETMC_LungG_pos/100, (double)PETMC_LungB_pos/100);

		PET_lung_surface_actor->GetProperty()->SetAmbient((double)PETMC_Ambient_pos/100);
		PET_lung_surface_actor->GetProperty()->SetDiffuse((double)PETMC_Diffuse_pos/100);
		PET_lung_surface_actor->GetProperty()->SetSpecular((double)PETMC_Specular_pos/100);
		PET_lung_surface_actor->GetProperty()->SetSpecularPower(PETMC_SpecularPower_pos);
		PET_lung_surface_actor->GetProperty()->SetOpacity((double)PETMC_LungOpacity_pos/100);


		PET_interExtractor->SetInputData(PETRebuild_dicm_data->data);  //�������ȡ��PET ����
		PET_interExtractor->SetValue(0,PETMC_InterCT_pos);//���ڲ�Ѫ�ܽ��CTֵ  
		PET_interExtractor->ComputeNormalsOn();   
		PET_interExtractor->ComputeGradientsOn();

		PET_interSmooth->SetInputConnection(PET_interExtractor->GetOutputPort());
		PET_interSmooth->SetNumberOfIterations(PETMC_InterSmooth_pos) ;//����Laplaceƽ���ĵ�������

		//ͨ��vtkPolyDataNormals�ڵ�ֵ���ϲ���������
		PET_interNormals->SetInputConnection(PET_interSmooth->GetOutputPort());  
		PET_interNormals->SetFeatureAngle(60.0);  // ָ���ڷ�����Ե�ĽǶ�ֵ

		// �޳��ɵĻ�ϳ������ݵ�Ԫ����߻����ٶ�
		//ͨ��vtkStripper�ڵ�ֵ���ϲ��������������Ƭ
		PET_interStripper->SetInputConnection(PET_interNormals->GetOutputPort());   //�����ɵ�����Ƭ���ӳ����Ǵ�

		PET_inter_surface_Mapper->SetInputConnection(PET_interStripper->GetOutputPort());   //�����Ǵ�ӳ��Ϊ��������
		PET_inter_surface_Mapper->ScalarVisibilityOff(); 

		PET_inter_surface_actor->SetMapper(PET_inter_surface_Mapper);  

		PET_inter_surface_actor->GetProperty()->SetColor((double)PETMC_InterR_pos/100, (double)PETMC_InterG_pos/100, (double)PETMC_InterB_pos/100);

		PET_inter_surface_actor->GetProperty()->SetAmbient((double)PETMC_Ambient_pos/100);
		PET_inter_surface_actor->GetProperty()->SetDiffuse((double)PETMC_Diffuse_pos/100);
		PET_inter_surface_actor->GetProperty()->SetSpecular((double)PETMC_Specular_pos/100);
		PET_inter_surface_actor->GetProperty()->SetSpecularPower(PETMC_SpecularPower_pos);
		PET_inter_surface_actor->GetProperty()->SetOpacity((double)PETMC_InterOpacity_pos/100);

		PET_MC_ren->SetBackground(0.5,0.5,0.5);  
		PET_MC_ren->ResetCameraClippingRange();  
		PET_MC_ren->AddActor(PET_lung_surface_actor);
		PET_MC_ren->AddActor(PET_inter_surface_actor);
	}
	else if(PETMC_Style == ACC_MC)//����MC
	{
		PET_shrink->SetInputData(PETRebuild_dicm_data->data);
		PET_shrink->SetShrinkFactors(4,4,1);//��������

		PET_lungExtractor->SetInputConnection(PET_shrink->GetOutputPort());  //�������ȡ��PET ����
		PET_lungExtractor->SetValue(0,PETMC_LungCT_pos);//��CTֵ  
		PET_lungExtractor->ComputeNormalsOn();   
		PET_lungExtractor->ComputeGradientsOn();

		PET_lungDeci->SetInputConnection(PET_lungExtractor->GetOutputPort());
		PET_lungDeci->SetTargetReduction(0.3);//��ԭ�ȵ�������Ƭ���ٵ�ԭ���İٷ�֮��ʮ

		PET_lungSmooth->SetInputConnection(PET_lungDeci->GetOutputPort());
		PET_lungSmooth->SetNumberOfIterations(PETMC_LungSmooth_pos) ;//����Laplaceƽ���ĵ�������

		PET_lungNormals->SetInputConnection(PET_lungSmooth->GetOutputPort());  
		PET_lungNormals->SetFeatureAngle(60.0);  // ָ���ڷ�����Ե�ĽǶ�ֵ
		PET_lungStripper->SetInputConnection(PET_lungNormals->GetOutputPort());   //�����ɵ�����Ƭ���ӳ����Ǵ�

		PET_lung_surface_Mapper->SetInputConnection(PET_lungStripper->GetOutputPort());   //�����Ǵ�ӳ��Ϊ��������
		PET_lung_surface_Mapper->ScalarVisibilityOff(); 

		PET_lung_surface_actor->SetMapper(PET_lung_surface_Mapper);  
	
		PET_lung_surface_actor->GetProperty()->SetColor((double)PETMC_LungR_pos/100, (double)PETMC_LungG_pos/100, (double)PETMC_LungB_pos/100);

		PET_lung_surface_actor->GetProperty()->SetAmbient((double)PETMC_Ambient_pos/100);
		PET_lung_surface_actor->GetProperty()->SetDiffuse((double)PETMC_Diffuse_pos/100);
		PET_lung_surface_actor->GetProperty()->SetSpecular((double)PETMC_Specular_pos/100);
		PET_lung_surface_actor->GetProperty()->SetSpecularPower(PETMC_SpecularPower_pos);
		PET_lung_surface_actor->GetProperty()->SetOpacity((double)PETMC_LungOpacity_pos/100);

		PET_interExtractor->SetInputData(PETRebuild_dicm_data->data);  //�������ȡ��PET ����
		PET_interExtractor->SetValue(0,PETMC_InterCT_pos);//���ڲ�Ѫ�ܽ��CTֵ  
		PET_interExtractor->ComputeNormalsOn();   
		PET_interExtractor->ComputeGradientsOn();

		PET_interSmooth->SetInputConnection(PET_interExtractor->GetOutputPort());
		PET_interSmooth->SetNumberOfIterations(PETMC_InterSmooth_pos) ;//����Laplaceƽ���ĵ�������

		//ͨ��vtkPolyDataNormals�ڵ�ֵ���ϲ���������
		PET_interNormals->SetInputConnection(PET_interSmooth->GetOutputPort());  
		PET_interNormals->SetFeatureAngle(60.0);  // ָ���ڷ�����Ե�ĽǶ�ֵ

		// �޳��ɵĻ�ϳ������ݵ�Ԫ����߻����ٶ�
		//ͨ��vtkStripper�ڵ�ֵ���ϲ��������������Ƭ
		PET_interStripper->SetInputConnection(PET_interNormals->GetOutputPort());   //�����ɵ�����Ƭ���ӳ����Ǵ�

		PET_inter_surface_Mapper->SetInputConnection(PET_interStripper->GetOutputPort());   //�����Ǵ�ӳ��Ϊ��������
		PET_inter_surface_Mapper->ScalarVisibilityOff(); 

		PET_inter_surface_actor->SetMapper(PET_inter_surface_Mapper);  

		PET_inter_surface_actor->GetProperty()->SetColor((double)PETMC_InterR_pos/100, (double)PETMC_InterG_pos/100, (double)PETMC_InterB_pos/100);

		PET_inter_surface_actor->GetProperty()->SetAmbient((double)PETMC_Ambient_pos/100);
		PET_inter_surface_actor->GetProperty()->SetDiffuse((double)PETMC_Diffuse_pos/100);
		PET_inter_surface_actor->GetProperty()->SetSpecular((double)PETMC_Specular_pos/100);
		PET_inter_surface_actor->GetProperty()->SetSpecularPower(PETMC_SpecularPower_pos);
		PET_inter_surface_actor->GetProperty()->SetOpacity((double)PETMC_InterOpacity_pos/100);

		PET_MC_ren->SetBackground(0.5,0.5,0.5);  
		PET_MC_ren->ResetCameraClippingRange();  
		PET_MC_ren->AddActor(PET_lung_surface_actor);
		PET_MC_ren->AddActor(PET_inter_surface_actor);
	}
	
}

void CITKVTKMFC_GUIDlg::Pipeline_CT_RC()
{
	CTRC3DSeg_YesOrNoRC = YES; //CTRC�������ά�ؽ�
	if(CTRC_Style == RC)//RC
	{
		CT_shiftScale->SetInputData(CTRebuild_dicm_data->data);
		CT_shiftScale->SetOutputScalarTypeToUnsignedChar();

		//��������vtkVolumeRayCastMapper�Ĺ��ߺ���vtkVolumeRayCastCompositeFunction 
		CT_volumeMapper->SetInputConnection(CT_shiftScale->GetOutputPort());
		CT_volumeMapper->SetVolumeRayCastFunction(CT_rayCastFunction);

		//������ɫת������vtkColorTransferFunction���ڽ����ص�ǿ�ҳ̶�ת���ɲ�ͬ����ɫ
		CT_volumeColor->AddRGBSegment(0, 1, 1, 1, 255, 1, 1, 1);//...............

		CT_volumeColor->AddRGBPoint(0,    0.0, 0.0, 0.0);//�Ҷ�ֵΪ��ģ���Ϊ��ɫ
		CT_volumeColor->AddRGBPoint(CTRC_LungCT_pos,  (double)CTRC_LungR_pos/100, (double)CTRC_LungG_pos/100, (double)CTRC_LungB_pos/100);///���÷ε���ɫ
		CT_volumeColor->AddRGBPoint(CTRC_InterCT_pos, (double)CTRC_InterR_pos/100, (double)CTRC_InterG_pos/100, (double)CTRC_InterB_pos/100);//���ڲ���ɫ

		//�����ֶκ������ò�ͬ��֯��͸����

		CT_volumeScalarOpacity->AddSegment(0, 0, 3000, 1);//......................

		CT_volumeScalarOpacity->AddPoint(0,    0.00);
		CT_volumeScalarOpacity->AddPoint(CTRC_LungCT_pos,  (double)CTRC_LungOpacity_pos/100);
		CT_volumeScalarOpacity->AddPoint(CTRC_InterCT_pos, (double)CTRC_InterOpacity_pos/100);

		//ͬ�ϣ����ò�ͬ�¶ȵ�͸���ȣ��ݶȣ�
		CT_volumeGradientOpacity->AddPoint(0,   0.0);
		CT_volumeGradientOpacity->AddPoint(90,  0.5);
		CT_volumeGradientOpacity->AddPoint(100, 1.0);


		/*Set/Get the blend mode. 
		Currently this is only supported by the vtkFixedPointVolumeRayCastMapper - other mappers have different 
		ways to set this (supplying a function to a vtkVolumeRayCastMapper) or don't have any options (vtkVolumeTextureMapper2D supports only compositing).
		Additive blend mode adds scalars along the ray and multiply them by their opacity mapping value.
		*/
		CT_volumeMapper->SetBlendModeToMaximumIntensity();//ȥ������Ч��...................

		//����vtkVolumeProperty����ɫ����͸������ϵ����
		CT_volumeProperty->SetColor(CT_volumeColor);
		CT_volumeProperty->SetScalarOpacity(CT_volumeScalarOpacity);
		CT_volumeProperty->SetGradientOpacity(CT_volumeGradientOpacity);
		CT_volumeProperty->SetInterpolationTypeToLinear();//���ò��������ݵĲ�������
		CT_volumeProperty->ShadeOn();//�����������ֽ��м���
		CT_volumeProperty->SetAmbient((double)CTRC_Ambient_pos/100);//���û�������ϵ����
		CT_volumeProperty->SetDiffuse((double)CTRC_Diffuse_pos/100);//������������ϵ����
		CT_volumeProperty->SetSpecular((double)CTRC_Specular_pos/100);//���þ�������ϵ����
		CT_volumeProperty->SetSpecularPower(CTRC_SpecularPower_pos); //���þ�����ǿ�ȡ�

		// The vtkVolume is a vtkProp3D (like a vtkActor) and controls the position
		// and orientation of the volume in world coordinates.
		CT_volume->SetMapper(CT_volumeMapper);
		CT_volume->SetProperty(CT_volumeProperty);

		CT_RC_ren->SetBackground(0.5,0.5,0.5);  
		CT_RC_ren->ResetCameraClippingRange();  
		CT_RC_ren->AddVolume(CT_volume);
	}
	else if(CTRC_Style == FIX_RC)//�̶���RC
	{
		CT_shiftScale->SetInputData(CTRebuild_dicm_data->data);
		CT_shiftScale->SetOutputScalarTypeToUnsignedChar();

		CT_pMapper->SetInputConnection(CT_shiftScale->GetOutputPort());

		//������ɫת������vtkColorTransferFunction���ڽ����ص�ǿ�ҳ̶�ת���ɲ�ͬ����ɫ
		CT_pColor->AddRGBSegment(0, 1, 1, 1, 255, 1, 1, 1);
		CT_pColor->AddRGBPoint(CTRC_LungCT_pos,  (double)CTRC_LungR_pos/100, (double)CTRC_LungG_pos/100, (double)CTRC_LungB_pos/100);//����ת���ķ���ɫ
		CT_pColor->AddRGBPoint(CTRC_InterCT_pos, (double)CTRC_InterR_pos/100, (double)CTRC_InterG_pos/100, (double)CTRC_InterB_pos/100);//����ת���ķ��ڲ�����ڡ�Ѫ�ܣ���ɫ

		// The opacity transfer function is used to control the opacity
		// of different tissue����֯�� types.
		 //�����ֶκ������ò�ͬ��֯��͸����
		CT_pPiceFun->AddSegment(0, 0, 3000, 1);
		CT_pPiceFun->AddPoint(CTRC_LungCT_pos,  (double)CTRC_LungOpacity_pos/100); //���÷ε�͸���ȣ�1.0��ȫ��͸����
		CT_pPiceFun->AddPoint(CTRC_InterCT_pos, (double)CTRC_InterOpacity_pos/100); //���÷��ڲ�����ڡ�Ѫ�ܣ���͸����

		// The gradient(�ݶ�) opacity function is used to decrease the opacity
		// in the "flat" regions of the volume while maintaining the opacity
		// at the boundaries between tissue types.  The gradient is measured
		// as the amount by which the intensity changes over unit distance.
		// For most medical data, the unit distance is 1mm.

		//ͬ�ϣ����ò�ͬ�¶ȵ�͸���ȣ��ݶȣ�
		CT_pGradientFun->AddPoint(0,   0.0);
		CT_pGradientFun->AddPoint(90,  0.5);
		CT_pGradientFun->AddPoint(100, 1.0);

		CT_pMapper->SetBlendModeToMaximumIntensity();

		//����vtkVolumeProperty����ɫ����͸������ϵ����
		CT_pProperty->SetColor(CT_pColor);
		CT_pProperty->SetScalarOpacity(CT_pPiceFun);
		CT_pProperty->SetGradientOpacity(CT_pGradientFun);
		CT_pProperty->SetInterpolationTypeToLinear();//���ò��������ݵĲ�������
		CT_pProperty->ShadeOn();//�����������ֽ��м���
		CT_pProperty->SetAmbient((double)CTRC_Ambient_pos/100);
		CT_pProperty->SetDiffuse((double)CTRC_Diffuse_pos/100);
		CT_pProperty->SetSpecular((double)CTRC_Specular_pos/100);
		CT_pProperty->SetSpecularPower(CTRC_SpecularPower_pos);

		CT_volume ->SetProperty(CT_pProperty);
		CT_volume ->SetMapper(CT_pMapper);

		CT_RC_ren->SetBackground(0.5,0.5,0.5);  
		CT_RC_ren->ResetCameraClippingRange(); 
		CT_RC_ren->AddVolume(CT_volume);
	}
}

void CITKVTKMFC_GUIDlg::Pipeline_PET_RC()
{
	if(PETRC_Style == RC)//RC
	{
		PET_shiftScale->SetInputData(PETRebuild_dicm_data->data);
		PET_shiftScale->SetOutputScalarTypeToUnsignedChar();

		//��������vtkVolumeRayCastMapper�Ĺ��ߺ���vtkVolumeRayCastCompositeFunction 
		PET_volumeMapper->SetInputConnection(PET_shiftScale->GetOutputPort());
		PET_volumeMapper->SetVolumeRayCastFunction(PET_rayCastFunction);

		//������ɫת������vtkColorTransferFunction���ڽ����ص�ǿ�ҳ̶�ת���ɲ�ͬ����ɫ
		PET_volumeColor->AddRGBSegment(0, 1, 1, 1, 255, 1, 1, 1);//...............

		PET_volumeColor->AddRGBPoint(0,    0.0, 0.0, 0.0);//�Ҷ�ֵΪ��ģ���Ϊ��ɫ
		PET_volumeColor->AddRGBPoint(PETRC_LungCT_pos,  (double)PETRC_LungR_pos/100, (double)PETRC_LungG_pos/100, (double)PETRC_LungB_pos/100);///���÷ε���ɫ
		PET_volumeColor->AddRGBPoint(PETRC_InterCT_pos, (double)PETRC_InterR_pos/100, (double)PETRC_InterG_pos/100, (double)PETRC_InterB_pos/100);//���ڲ���ɫ

		//�����ֶκ������ò�ͬ��֯��͸����

		PET_volumeScalarOpacity->AddSegment(0, 0, 3000, 1);//......................

		PET_volumeScalarOpacity->AddPoint(0,    0.00);
		PET_volumeScalarOpacity->AddPoint(PETRC_LungCT_pos,  (double)PETRC_LungOpacity_pos/100);
		PET_volumeScalarOpacity->AddPoint(PETRC_InterCT_pos, (double)PETRC_InterOpacity_pos/100);

		//ͬ�ϣ����ò�ͬ�¶ȵ�͸���ȣ��ݶȣ�
		PET_volumeGradientOpacity->AddPoint(0,   0.0);
		PET_volumeGradientOpacity->AddPoint(90,  0.5);
		PET_volumeGradientOpacity->AddPoint(100, 1.0);


		/*Set/Get the blend mode. 
		Currently this is only supported by the vtkFixedPointVolumeRayCastMapper - other mappers have different 
		ways to set this (supplying a function to a vtkVolumeRayCastMapper) or don't have any options (vtkVolumeTextureMapper2D supports only compositing).
		Additive blend mode adds scalars along the ray and multiply them by their opacity mapping value.
		*/
		PET_volumeMapper->SetBlendModeToMaximumIntensity();//ȥ������Ч��...................

		//����vtkVolumeProperty����ɫ����͸������ϵ����
		PET_volumeProperty->SetColor(PET_volumeColor);
		PET_volumeProperty->SetScalarOpacity(PET_volumeScalarOpacity);
		PET_volumeProperty->SetGradientOpacity(PET_volumeGradientOpacity);
		PET_volumeProperty->SetInterpolationTypeToLinear();//���ò��������ݵĲ�������
		PET_volumeProperty->ShadeOn();//�����������ֽ��м���
		PET_volumeProperty->SetAmbient((double)PETRC_Ambient_pos/100);//���û�������ϵ����
		PET_volumeProperty->SetDiffuse((double)PETRC_Diffuse_pos/100);//������������ϵ����
		PET_volumeProperty->SetSpecular((double)PETRC_Specular_pos/100);//���þ�������ϵ����
		PET_volumeProperty->SetSpecularPower(PETRC_SpecularPower_pos); //���þ�����ǿ�ȡ�

		// The vtkVolume is a vtkProp3D (like a vtkActor) and controls the position
		// and orientation of the volume in world coordinates.
		PET_volume->SetMapper(PET_volumeMapper);
		PET_volume->SetProperty(PET_volumeProperty);

		PET_RC_ren->SetBackground(0.5,0.5,0.5);  
		PET_RC_ren->ResetCameraClippingRange();  
		PET_RC_ren->AddVolume(PET_volume);
	}
	else if(PETRC_Style == FIX_RC)//�̶���RC
	{
		PET_shiftScale->SetInputData(PETRebuild_dicm_data->data);
		PET_shiftScale->SetOutputScalarTypeToUnsignedChar();

		PET_pMapper->SetInputConnection(PET_shiftScale->GetOutputPort());

		//������ɫת������vtkColorTransferFunPETion���ڽ����ص�ǿ�ҳ̶�ת���ɲ�ͬ����ɫ
		PET_pColor->AddRGBSegment(0, 1, 1, 1, 255, 1, 1, 1);
		PET_pColor->AddRGBPoint(PETRC_LungCT_pos,  (double)PETRC_LungR_pos/100, (double)PETRC_LungG_pos/100, (double)PETRC_LungB_pos/100);//����ת���ķ���ɫ
		PET_pColor->AddRGBPoint(PETRC_InterCT_pos, (double)PETRC_InterR_pos/100, (double)PETRC_InterG_pos/100, (double)PETRC_InterB_pos/100);//����ת���ķ��ڲ�����ڡ�Ѫ�ܣ���ɫ

		// The opacity transfer function is used to control the opacity
		// of different tissue����֯�� types.
		 //�����ֶκ������ò�ͬ��֯��͸����
		PET_pPiceFun->AddSegment(0, 0, 3000, 1);
		PET_pPiceFun->AddPoint(PETRC_LungCT_pos,  (double)PETRC_LungOpacity_pos/100); //���÷ε�͸���ȣ�1.0��ȫ��͸����
		PET_pPiceFun->AddPoint(PETRC_InterCT_pos, (double)PETRC_InterOpacity_pos/100); //���÷��ڲ�����ڡ�Ѫ�ܣ���͸����

		// The gradient(�ݶ�) opacity funPETion is used to decrease the opacity
		// in the "flat" regions of the volume while maintaining the opacity
		// at the boundaries between tissue types.  The gradient is measured
		// as the amount by which the intensity changes over unit distance.
		// For most medical data, the unit distance is 1mm.

		//ͬ�ϣ����ò�ͬ�¶ȵ�͸���ȣ��ݶȣ�
		PET_pGradientFun->AddPoint(0,   0.0);
		PET_pGradientFun->AddPoint(90,  0.5);
		PET_pGradientFun->AddPoint(100, 1.0);

		PET_pMapper->SetBlendModeToMaximumIntensity();

		//����vtkVolumeProperty����ɫ����͸������ϵ����
		PET_pProperty->SetColor(PET_pColor);
		PET_pProperty->SetScalarOpacity(PET_pPiceFun);
		PET_pProperty->SetGradientOpacity(PET_pGradientFun);
		PET_pProperty->SetInterpolationTypeToLinear();//���ò��������ݵĲ�������
		PET_pProperty->ShadeOn();//�����������ֽ��м���
		PET_pProperty->SetAmbient((double)PETRC_Ambient_pos/100);
		PET_pProperty->SetDiffuse((double)PETRC_Diffuse_pos/100);
		PET_pProperty->SetSpecular((double)PETRC_Specular_pos/100);
		PET_pProperty->SetSpecularPower(PETRC_SpecularPower_pos);

		PET_volume ->SetProperty(PET_pProperty);
		PET_volume ->SetMapper(PET_pMapper);

		PET_RC_ren->SetBackground(0.5,0.5,0.5);  
		PET_RC_ren->ResetCameraClippingRange(); 
		PET_RC_ren->AddVolume(PET_volume);
	}
}

//������Ͽ�ѡ��ѡ���¼�
void CITKVTKMFC_GUIDlg::OnCbnSelendokComboProperty()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	CString strProperty;   
    int nSel;   
  
    // ��ȡ��Ͽ�ؼ����б����ѡ���������   
    nSel = m_comboProperty.GetCurSel();   
    // ����ѡ����������ȡ�����ַ���   
    m_comboProperty.GetLBText(nSel, strProperty);   
	strProperty +=_T("�����޸�����...");
	SetDlgItemText(IDC_EDIT_RunStatus, strProperty);
	if(nSel == 0) //CT_�����
	{
		//��չ����
		if(CTRebuild_dicm_data->dataStyle!=REBUILD_CT) //�״β���ʱ�ж��Ƿ�����һ�����ؽ���CT�ļ���
		{  
  
			// ��ʾ��Ϣ�Ի���   
			MessageBox(_T("���ȵ���һ�����ؽ���CT�ļ��У�"), _T("��ʾ"), MB_OK | MB_ICONWARNING);    

			SetDlgItemText(IDC_EDIT_RunStatus, _T("���ȵ���һ�����ؽ���CT�ļ��У�"));
			return;
		}

		INT_PTR nRes;             // ���ڱ���DoModal�����ķ���ֵ   

		CTMCPropDlg.m_strCaption = _T("CT��������ԶԻ���");//���öԻ������
  
		//CCTMCPropertyDlg CTMCPropDlg;           // ����Ի�����CCTMCPropertyDlg��ʵ��   
		nRes = CTMCPropDlg.DoModal();  // �����Ի���   
		if (IDCANCEL == nRes)     // �ж϶Ի����˳��󷵻�ֵ�Ƿ�ΪIDCANCEL���������return�������������ִ��   
		{
			SetDlgItemText(IDC_EDIT_RunStatus, _T("CT����������޸�ȡ����"));
			return;
		}
			  
		SetProperty_CT_MC(CTMCPropDlg.CTMC_Style,CTMCPropDlg.CTMC_LungCT_pos,CTMCPropDlg.CTMC_LungSmooth_pos,CTMCPropDlg.CTMC_LungR_pos,CTMCPropDlg.CTMC_LungG_pos,CTMCPropDlg.CTMC_LungB_pos,CTMCPropDlg.CTMC_LungOpacity_pos,CTMCPropDlg.CTMC_InterCT_pos,CTMCPropDlg.CTMC_InterSmooth_pos,CTMCPropDlg.CTMC_InterR_pos,CTMCPropDlg.CTMC_InterG_pos,CTMCPropDlg.CTMC_InterB_pos,CTMCPropDlg.CTMC_InterOpacity_pos,CTMCPropDlg.CTMC_Ambient_pos,CTMCPropDlg.CTMC_Diffuse_pos,CTMCPropDlg.CTMC_Specular_pos,CTMCPropDlg.CTMC_SpecularPower_pos);
		
		if (!CT_MC_iren->GetInitialized())
		{
			CT_MC_renWin->AddRenderer(CT_MC_ren);
			CT_MC_renWin->SetParentId(GetDlgItem(IDC_STATIC_CT_MCVIEW)->m_hWnd); //ע����һ�������û��ƴ���
			
			CT_MC_iren->SetRenderWindow(CT_MC_renWin);
			CRect rect;
			GetDlgItem(IDC_STATIC_CT_MCVIEW)->GetWindowRect(&rect);
			CT_MC_iren->Initialize();
			CT_MC_renWin->SetSize(rect.right-rect.left,rect.bottom-rect.top);
			CT_MC_ren->ResetCamera();
	
		}
		//���ùܵ���pipeline()
		Pipeline_CT_MC();
		CT_MC_renWin->Render();
		SetDlgItemText(IDC_EDIT_RunStatus, _T("CT����������޸ĳɹ���"));

	}
	else if(nSel == 1) //PET_�����
	{
		//��չ����
		if(PETRebuild_dicm_data->dataStyle!=REBUILD_PET) //�״β���ʱ�ж��Ƿ�����һ�����ؽ���PET�ļ���
		{  
  
			// ��ʾ��Ϣ�Ի���   
			MessageBox(_T("���ȵ���һ�����ؽ���PET�ļ��У�"), _T("��ʾ"), MB_OK | MB_ICONWARNING);    

			SetDlgItemText(IDC_EDIT_RunStatus, _T("���ȵ���һ�����ؽ���PET�ļ��У�"));
			return;
		}

		INT_PTR nRes;             // ���ڱ���DoModal�����ķ���ֵ   

		PETMCPropDlg.m_strCaption = _T("PET��������ԶԻ���");//���öԻ������
  
		//CCTMCPropertyDlg CTMCPropDlg;           // ����Ի�����CCTMCPropertyDlg��ʵ��   
		nRes = PETMCPropDlg.DoModal();  // �����Ի���   
		if (IDCANCEL == nRes)     // �ж϶Ի����˳��󷵻�ֵ�Ƿ�ΪIDCANCEL���������return�������������ִ��   
		{
			SetDlgItemText(IDC_EDIT_RunStatus, _T("PET����������޸�ȡ����"));
			return;
		}
			  
		SetProperty_PET_MC(PETMCPropDlg.CTMC_Style,PETMCPropDlg.CTMC_LungCT_pos,PETMCPropDlg.CTMC_LungSmooth_pos,PETMCPropDlg.CTMC_LungR_pos,PETMCPropDlg.CTMC_LungG_pos,PETMCPropDlg.CTMC_LungB_pos,PETMCPropDlg.CTMC_LungOpacity_pos,PETMCPropDlg.CTMC_InterCT_pos,PETMCPropDlg.CTMC_InterSmooth_pos,PETMCPropDlg.CTMC_InterR_pos,PETMCPropDlg.CTMC_InterG_pos,PETMCPropDlg.CTMC_InterB_pos,PETMCPropDlg.CTMC_InterOpacity_pos,PETMCPropDlg.CTMC_Ambient_pos,PETMCPropDlg.CTMC_Diffuse_pos,PETMCPropDlg.CTMC_Specular_pos,PETMCPropDlg.CTMC_SpecularPower_pos);
		
		if (!PET_MC_iren->GetInitialized())
		{
			PET_MC_renWin->AddRenderer(PET_MC_ren);
			PET_MC_renWin->SetParentId(GetDlgItem(IDC_STATIC_PET_MCVIEW)->m_hWnd); //ע����һ�������û��ƴ���
			
			PET_MC_iren->SetRenderWindow(PET_MC_renWin);
			CRect rect;
			GetDlgItem(IDC_STATIC_PET_MCVIEW)->GetWindowRect(&rect);
			PET_MC_iren->Initialize();
			PET_MC_renWin->SetSize(rect.right-rect.left,rect.bottom-rect.top);
			PET_MC_ren->ResetCamera();
	
		}
		//���ùܵ���pipeline()
		Pipeline_PET_MC();
		PET_MC_renWin->Render();
		SetDlgItemText(IDC_EDIT_RunStatus, _T("PET����������޸ĳɹ���"));

	}
	else if(nSel == 2) //CT_�����
	{
		//��չ����
		if(CTRebuild_dicm_data->dataStyle!=REBUILD_CT) //�״β���ʱ�ж��Ƿ�����һ�����ؽ���CT�ļ���
		{  
  
			// ��ʾ��Ϣ�Ի���   
			MessageBox(_T("���ȵ���һ�����ؽ���CT�ļ��У�"), _T("��ʾ"), MB_OK | MB_ICONWARNING);    

			SetDlgItemText(IDC_EDIT_RunStatus, _T("���ȵ���һ�����ؽ���CT�ļ��У�"));
			return;
		}

		INT_PTR nRes;             // ���ڱ���DoModal�����ķ���ֵ   

		CTRCPropDlg.m_strCaption = _T("CT��������ԶԻ���");//���öԻ������
  
		//CCTRCPropertyDlg CTRCPropDlg;           // ����Ի�����CCTRCPropertyDlg��ʵ��   
		nRes = CTRCPropDlg.DoModal();  // �����Ի���   
		if (IDCANCEL == nRes)     // �ж϶Ի����˳��󷵻�ֵ�Ƿ�ΪIDCANCEL���������return�������������ִ��   
		{
			SetDlgItemText(IDC_EDIT_RunStatus, _T("CT����������޸�ȡ����"));
			return;
		}

		SetProperty_CT_RC(CTRCPropDlg.CTRC_Style,CTRCPropDlg.CTRC_LungCT_pos,CTRCPropDlg.CTRC_LungR_pos,CTRCPropDlg.CTRC_LungG_pos,CTRCPropDlg.CTRC_LungB_pos,CTRCPropDlg.CTRC_LungOpacity_pos,CTRCPropDlg.CTRC_InterCT_pos,CTRCPropDlg.CTRC_InterR_pos,CTRCPropDlg.CTRC_InterG_pos,CTRCPropDlg.CTRC_InterB_pos,CTRCPropDlg.CTRC_InterOpacity_pos,CTRCPropDlg.CTRC_Ambient_pos,CTRCPropDlg.CTRC_Diffuse_pos,CTRCPropDlg.CTRC_Specular_pos,CTRCPropDlg.CTRC_SpecularPower_pos);
		
		if (!CT_RC_iren->GetInitialized())
		{
			CT_RC_renWin->AddRenderer(CT_RC_ren);
			CT_RC_renWin->SetParentId(GetDlgItem(IDC_STATIC_CT_RCVIEW)->m_hWnd); //ע����һ�������û��ƴ���
			
			CT_RC_iren->SetRenderWindow(CT_RC_renWin);
			CRect rect;
			GetDlgItem(IDC_STATIC_CT_RCVIEW)->GetWindowRect(&rect);
			CT_RC_iren->Initialize();
			CT_RC_renWin->SetSize(rect.right-rect.left,rect.bottom-rect.top);
			CT_RC_ren->ResetCamera();
	
		}
		//���ùܵ���pipeline()
		Pipeline_CT_RC();
		CT_RC_renWin->Render();
		SetDlgItemText(IDC_EDIT_RunStatus, _T("CT����������޸ĳɹ���"));
	}
	else if(nSel == 3) //PET�����
	{
		//��չ����
		if(PETRebuild_dicm_data->dataStyle!=REBUILD_PET) //�״β���ʱ�ж��Ƿ�����һ�����ؽ���PET�ļ���
		{  
  
			// ��ʾ��Ϣ�Ի���   
			MessageBox(_T("���ȵ���һ�����ؽ���PET�ļ��У�"), _T("��ʾ"), MB_OK | MB_ICONWARNING);    

			SetDlgItemText(IDC_EDIT_RunStatus, _T("���ȵ���һ�����ؽ���PET�ļ��У�"));
			return;
		}

		INT_PTR nRes;             // ���ڱ���DoModal�����ķ���ֵ   

		PETRCPropDlg.m_strCaption = _T("PET��������ԶԻ���");//���öԻ������
  
		//CCTRCPropertyDlg CTRCPropDlg;           // ����Ի�����CCTRCPropertyDlg��ʵ��   
		nRes = PETRCPropDlg.DoModal();  // �����Ի���   
		if (IDCANCEL == nRes)     // �ж϶Ի����˳��󷵻�ֵ�Ƿ�ΪIDCANCEL���������return�������������ִ��   
		{
			SetDlgItemText(IDC_EDIT_RunStatus, _T("PET����������޸�ȡ����"));
			return;
		}

		SetProperty_PET_RC(PETRCPropDlg.CTRC_Style,PETRCPropDlg.CTRC_LungCT_pos,PETRCPropDlg.CTRC_LungR_pos,PETRCPropDlg.CTRC_LungG_pos,PETRCPropDlg.CTRC_LungB_pos,PETRCPropDlg.CTRC_LungOpacity_pos,PETRCPropDlg.CTRC_InterCT_pos,PETRCPropDlg.CTRC_InterR_pos,PETRCPropDlg.CTRC_InterG_pos,PETRCPropDlg.CTRC_InterB_pos,PETRCPropDlg.CTRC_InterOpacity_pos,PETRCPropDlg.CTRC_Ambient_pos,PETRCPropDlg.CTRC_Diffuse_pos,PETRCPropDlg.CTRC_Specular_pos,PETRCPropDlg.CTRC_SpecularPower_pos);
		
		if (!PET_RC_iren->GetInitialized())
		{
			PET_RC_renWin->AddRenderer(PET_RC_ren);
			PET_RC_renWin->SetParentId(GetDlgItem(IDC_STATIC_PET_RCVIEW)->m_hWnd); //ע����һ�������û��ƴ���
			
			PET_RC_iren->SetRenderWindow(PET_RC_renWin);
			CRect rect;
			GetDlgItem(IDC_STATIC_PET_RCVIEW)->GetWindowRect(&rect);
			PET_RC_iren->Initialize();
			PET_RC_renWin->SetSize(rect.right-rect.left,rect.bottom-rect.top);
			PET_RC_ren->ResetCamera();
	
		}
		//���ùܵ���pipeline()
		Pipeline_PET_RC();
		PET_RC_renWin->Render();
		SetDlgItemText(IDC_EDIT_RunStatus, _T("PET����������޸ĳɹ���"));
	}
}


//��ʷ������Ͽ�ѡ��ѡ���¼�
void CITKVTKMFC_GUIDlg::OnCbnSelendokComboPrevious()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString strPrevious;   
    int nSel;   
  
    // ��ȡ��Ͽ�ؼ����б����ѡ���������   
    nSel = m_comboPrevious.GetCurSel();   
    // ����ѡ����������ȡ�����ַ���   
    m_comboPrevious.GetLBText(nSel, strPrevious);   
	//strPrevious +=_T("���������ڱ�ѡ��...");
	SetDlgItemText(IDC_EDIT_RunStatus, "���������ڱ�ѡ��...");

	//�޸ĵ�ǰ����ʹ�õ�������
	int i;//����
	DicmDataNode *q;//�ƶ�ָ��
	i=0;
	q = dataList->next;
	while((q!=NULL)&&(i!=nSel))
	{
		q = q->next;
		i++;
	}
	if(i==nSel)
	{
		if(q->dataStyle == REBUILD_CT)//�޸Ĵ��ؽ���CT������
		{
			CTRebuild_dicm_data->data = q->data;
			strPrevious +=_T(":CT�������޸ĳɹ���");
			SetDlgItemText(IDC_EDIT_RunStatus,strPrevious);
		}
		else if(q->dataStyle == REBUILD_PET)//�޸Ĵ��ؽ���PET������....
		{
			//��չ
			PETRebuild_dicm_data->data = q->data;
			strPrevious +=_T(":PET�������޸ĳɹ���");
			SetDlgItemText(IDC_EDIT_RunStatus, strPrevious);
		}
		else if(q->dataStyle == SEG_CT)//�޸Ĵ��ָ��CT������
		{
			//��չ
		}
		else if(q->dataStyle == SEG_PET)//�޸Ĵ��ָ��PET������
		{
			//��չ
		}
	}
}


//���2D�������и��¼�
void CITKVTKMFC_GUIDlg::OnBnClickedRadio2dseg()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	SetDlgItemText(IDC_EDIT_RunStatus, _T("2D�������и���������..."));
	if(CTRebuild_dicm_data->dataStyle!=REBUILD_CT) //�״β���ʱ�ж��Ƿ�����һ�����ؽ���CT�ļ���
	{  
  
		// ��ʾ��Ϣ�Ի���   
		MessageBox(_T("���ȵ���һ�����ؽ���CT�ļ��У�"), _T("��ʾ"), MB_OK | MB_ICONWARNING);    

		SetDlgItemText(IDC_EDIT_RunStatus, _T("���ȵ���һ�����ؽ���CT�ļ��У�"));

		CheckDlgButton(IDC_RADIO_2DSeg, 0); //��ѡ��2D�������иѡ��ť
		return;
	}

	C2DSegDlg TwoDSegDlg;                   // ����Ի�����C2DSegDlg��ʵ��

	INT_PTR nRes;             // ���ڱ���DoModal�����ķ���ֵ   

	TwoDSegDlg.m_strCaption = _T("2D�������и�Ի���");//���öԻ������

	TwoDSegDlg.TwoDSeg_dicm_data = CTRebuild_dicm_data->data; //���ô�2D�������и��������
   
	nRes = TwoDSegDlg.DoModal();  // �����Ի���   
	if (IDCANCEL == nRes)     // �ж϶Ի����˳��󷵻�ֵ�Ƿ�ΪIDCANCEL���������return�������������ִ��   
	{
		SetDlgItemText(IDC_EDIT_RunStatus, _T("2D�������и���ȡ����"));
		CheckDlgButton(IDC_RADIO_2DSeg, 0); //��ѡ��2D�������иѡ��ť

		delete TwoDSegDlg;

		return;
	}

}


//���2D��ʸ�������¼�
void CITKVTKMFC_GUIDlg::OnBnClickedRadio2dthreeplane()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	SetDlgItemText(IDC_EDIT_RunStatus, _T("2D��ʸ�������и���������..."));
	if(CTRebuild_dicm_data->dataStyle!=REBUILD_CT) //�״β���ʱ�ж��Ƿ�����һ�����ؽ���CT�ļ���
	{  
  
		// ��ʾ��Ϣ�Ի���   
		MessageBox(_T("���ȵ���һ�����ؽ���CT�ļ��У�"), _T("��ʾ"), MB_OK | MB_ICONWARNING);    

		SetDlgItemText(IDC_EDIT_RunStatus, _T("���ȵ���һ�����ؽ���CT�ļ��У�"));

		CheckDlgButton(IDC_RADIO_2DThreePlane, 0); //��ѡ��2D��ʸ�������иѡ��ť
		return;
	}

	C2DThreePlaneDlg ThreePlaneDlg;                   // ����Ի�����C2DThreePlaneDlg��ʵ��

	INT_PTR nRes;             // ���ڱ���DoModal�����ķ���ֵ   

	ThreePlaneDlg.m_strCaption = _T("2D��ʸ������Ի���");//���öԻ������

	ThreePlaneDlg.ThreePlane_dicm_data = CTRebuild_dicm_data->data; //���ô�2D�������и��������
   
	nRes = ThreePlaneDlg.DoModal();  // �����Ի���   
	if (IDCANCEL == nRes)     // �ж϶Ի����˳��󷵻�ֵ�Ƿ�ΪIDCANCEL���������return�������������ִ��   
	{
		SetDlgItemText(IDC_EDIT_RunStatus, _T("2D��ʸ�������и���ȡ����"));
		CheckDlgButton(IDC_RADIO_2DThreePlane, 0); //��ѡ��2D��ʸ�����浥ѡ��ť

		delete ThreePlaneDlg;

		return;
	}
}


//�����������Ƭ������ʾ�¼�
void CITKVTKMFC_GUIDlg::OnBnClickedRadioVolumesliceview()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	SetDlgItemText(IDC_EDIT_RunStatus, _T("��������Ƭ������ʾ��������..."));
	
	VolumeDataViewDlg VolumeViewDlg;                   // ����Ի�����VolumeDataViewDlg��ʵ��

	INT_PTR nRes;             // ���ڱ���DoModal�����ķ���ֵ   
   
	nRes = VolumeViewDlg.DoModal();  // �����Ի���   
	if (IDCANCEL == nRes)     // �ж϶Ի����˳��󷵻�ֵ�Ƿ�ΪIDCANCEL���������return�������������ִ��   
	{
		delete VolumeViewDlg;

		SetDlgItemText(IDC_EDIT_RunStatus, _T("��������Ƭ������ʾ��ȡ����"));
		CheckDlgButton(IDC_RADIO_VolumeSliceView, 0); //��ѡ����������Ƭ������ʾ��ѡ��ť

		return;
	}
}


//���CTMC 3D�������и��¼�
void CITKVTKMFC_GUIDlg::OnBnClickedCheck3dctmcseg()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CTMC3DSeg_CheckButtonStatus = m_check_3DCTMCSeg.GetCheck();//��ȡCTMC 3D�������иѡ��ѡ��״̬
	if(CTMC3DSeg_CheckButtonStatus == CTMC3DSEG_CHECKED)//����CTMC 3D�������и�
	{
		SetDlgItemText(IDC_EDIT_RunStatus, _T("CTMC 3D�������и���������..."));
		if(CTRebuild_dicm_data->dataStyle!=REBUILD_CT) //�״β���ʱ�ж��Ƿ�����һ�����ؽ���CT�ļ���
		{  
  
			// ��ʾ��Ϣ�Ի���   
			MessageBox(_T("���ȵ���һ�����ؽ���CT�ļ��У�"), _T("��ʾ"), MB_OK | MB_ICONWARNING);    

			SetDlgItemText(IDC_EDIT_RunStatus, _T("���ȵ���һ�����ؽ���CT�ļ��У�"));

			CheckDlgButton(IDC_CHECK_3DCTMCSeg, 0); //��ѡ��CTMC 3D�������иѡ��ť
			CTMC3DSeg_CheckButtonStatus = CTMC3DSEG_UNCHECK;//CTMC 3D�������иѡ��ťδѡ��״̬
			return;
		}

		if(CTMC3DSeg_YesOrNoMC == NO) //�״β���ʱ�ж��Ƿ��Ѿ�CTMC��ά�ؽ�
		{  
  
			// ��ʾ��Ϣ�Ի���   
			MessageBox(_T("���Ƚ���CTMC����ƣ�"), _T("��ʾ"), MB_OK | MB_ICONWARNING);    

			SetDlgItemText(IDC_EDIT_RunStatus, _T("���Ƚ���CTMC����ƣ�"));

			CheckDlgButton(IDC_CHECK_3DCTMCSeg, 0); //��ѡ��CTMC 3D�������иѡ��ť
			CTMC3DSeg_CheckButtonStatus = CTMC3DSEG_UNCHECK;//CTMC 3D�������иѡ��ťδѡ��״̬
			return;
		}

		m_check_3DCTMCSeg_Hide.EnableWindow(TRUE);//CTMC 3D�������и��������ظ�ѡ������ʹ��

		if (!CT_MC_iren->GetInitialized())
		{
			CT_MC_renWin->AddRenderer(CT_MC_ren);
			CT_MC_renWin->SetParentId(GetDlgItem(IDC_STATIC_CT_MCVIEW)->m_hWnd); //ע����һ�������û��ƴ���
			
			CT_MC_iren->SetRenderWindow(CT_MC_renWin);
			CRect rect;
			GetDlgItem(IDC_STATIC_CT_MCVIEW)->GetWindowRect(&rect);
			CT_MC_iren->Initialize();
			CT_MC_renWin->SetSize(rect.right-rect.left,rect.bottom-rect.top);
			CT_MC_ren->ResetCamera();
	
		}
		//���ùܵ���pipeline()
		Pipeline_CT_MC();
		CT_MC_renWin->Render();
		SetDlgItemText(IDC_EDIT_RunStatus, _T("����CTMC 3D�������и���£�"));

	}
	else if(CTMC3DSeg_CheckButtonStatus == CTMC3DSEG_UNCHECK)//ȡ��CTMC 3D�������и�
	{
		//��չ
		SetDlgItemText(IDC_EDIT_RunStatus, _T("CTMC 3D�������и�����ȡ��..."));
		m_check_3DCTMCSeg_Hide.EnableWindow(FALSE);//CTMC 3D�������и��������ظ�ѡ���ֹʹ��

		if (!CT_MC_iren->GetInitialized())
		{
			CT_MC_renWin->AddRenderer(CT_MC_ren);
			CT_MC_renWin->SetParentId(GetDlgItem(IDC_STATIC_CT_MCVIEW)->m_hWnd); //ע����һ�������û��ƴ���
			
			CT_MC_iren->SetRenderWindow(CT_MC_renWin);
			CRect rect;
			GetDlgItem(IDC_STATIC_CT_MCVIEW)->GetWindowRect(&rect);
			CT_MC_iren->Initialize();
			CT_MC_renWin->SetSize(rect.right-rect.left,rect.bottom-rect.top);
			CT_MC_ren->ResetCamera();
	
		}
		//���ùܵ���pipeline()
		Pipeline_CT_MC();
		CT_MC_renWin->Render();
		SetDlgItemText(IDC_EDIT_RunStatus, _T("CTMC 3D�������и�ɹ�ȡ����"));
	}
	

}


//���CTMC 3D�������и����������¼�
void CITKVTKMFC_GUIDlg::OnBnClickedCheck3dctmcsegHide()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(m_check_3DCTMCSeg_Hide.GetCheck() == 1)//CTMC 3D�������и��������ظ�ѡ��ѡ��
	{
		CTMC3DSeg_implicitPlaneWidget->Off();
	}
	else if(m_check_3DCTMCSeg_Hide.GetCheck() == 0)//CTMC 3D�������и��������ظ�ѡ��δ��ѡ��
	{
		CTMC3DSeg_implicitPlaneWidget->On();
	}
}


//���CT�����ֱ�߲����¼�
void CITKVTKMFC_GUIDlg::OnBnClickedCheckCtmcLine()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CTMCLine_CheckButtonStatus = m_check_CTMC_Line.GetCheck();//��ȡCT�����ֱ�߲�����ѡ��ѡ��״̬
	if(CTMCLine_CheckButtonStatus == YES)//����CT�����ֱ�߲���
	{
		SetDlgItemText(IDC_EDIT_RunStatus, _T("CT�����ֱ�߲�����������..."));
		if(CTRebuild_dicm_data->dataStyle!=REBUILD_CT) //�״β���ʱ�ж��Ƿ�����һ�����ؽ���CT�ļ���
		{  
  
			// ��ʾ��Ϣ�Ի���   
			MessageBox(_T("���ȵ���һ�����ؽ���CT�ļ��У�"), _T("��ʾ"), MB_OK | MB_ICONWARNING);    

			SetDlgItemText(IDC_EDIT_RunStatus, _T("���ȵ���һ�����ؽ���CT�ļ��У�"));

			CheckDlgButton(IDC_CHECK_CTMC_Line, 0); //��ѡ��CT�����ֱ�߲�����ѡ��ť
			CTMCLine_CheckButtonStatus = NO;//CT�����ֱ�߲�����ѡ��ťδѡ��״̬
			return;
		}

		if(CTMC3DSeg_YesOrNoMC == NO) //�״β���ʱ�ж��Ƿ��Ѿ�CTMC��ά�ؽ�
		{  
  
			// ��ʾ��Ϣ�Ի���   
			MessageBox(_T("���Ƚ���CTMC����ƣ�"), _T("��ʾ"), MB_OK | MB_ICONWARNING);    

			SetDlgItemText(IDC_EDIT_RunStatus, _T("���Ƚ���CTMC����ƣ�"));

			CheckDlgButton(IDC_CHECK_CTMC_Line, 0); //��ѡ��CT�����ֱ�߲�����ѡ��ť
			CTMCLine_CheckButtonStatus = NO;//CT�����ֱ�߲�����ѡ��ťδѡ��״̬
			return;
		}

		CTMCLine_rep->SetLabelFormat("%-#6.3g mm");
		CTMCLine_rep->GetLabelProperty()->SetColor(1,1,1);//��ɫ��һ���������ʾЧ���Ϻ�
		CTMCLine_distanceWidget->SetRepresentation(CTMCLine_rep);
		CTMCLine_distanceWidget->SetInteractor(CT_MC_iren);
		CTMCLine_distanceWidget->CreateDefaultRepresentation();
		
		CT_MC_ren->Render();
		CTMCLine_distanceWidget->On();
		SetDlgItemText(IDC_EDIT_RunStatus, _T("����CT�����ֱ�߲��������£�"));

	}
	else if(CTMCLine_CheckButtonStatus == NO)//ȡ��CT�����ֱ�߲���
	{
		SetDlgItemText(IDC_EDIT_RunStatus, _T("CT�����ֱ�߲�������ȡ��..."));
		CT_MC_ren->Render();
		CTMCLine_distanceWidget->Off();
		SetDlgItemText(IDC_EDIT_RunStatus, _T("CT�����ֱ�߲����ɹ�ȡ����"));
	}
}


//���CT�����ֱ�߲����¼�
void CITKVTKMFC_GUIDlg::OnBnClickedCheckCtrcLine()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CTRCLine_CheckButtonStatus = m_check_CTRC_Line.GetCheck();//��ȡCT�����ֱ�߲�����ѡ��ѡ��״̬
	if(CTRCLine_CheckButtonStatus == YES)//����CT�����ֱ�߲���
	{
		SetDlgItemText(IDC_EDIT_RunStatus, _T("CT�����ֱ�߲�����������..."));
		if(CTRebuild_dicm_data->dataStyle!=REBUILD_CT) //�״β���ʱ�ж��Ƿ�����һ�����ؽ���CT�ļ���
		{  
  
			// ��ʾ��Ϣ�Ի���   
			MessageBox(_T("���ȵ���һ�����ؽ���CT�ļ��У�"), _T("��ʾ"), MB_OK | MB_ICONWARNING);    

			SetDlgItemText(IDC_EDIT_RunStatus, _T("���ȵ���һ�����ؽ���CT�ļ��У�"));

			CheckDlgButton(IDC_CHECK_CTRC_Line, 0); //��ѡ��CT�����ֱ�߲�����ѡ��ť
			CTRCLine_CheckButtonStatus = NO;//CT�����ֱ�߲�����ѡ��ťδѡ��״̬
			return;
		}

		if(CTRC3DSeg_YesOrNoRC == NO) //�״β���ʱ�ж��Ƿ��Ѿ�CTRC��ά�ؽ�
		{  
  
			// ��ʾ��Ϣ�Ի���   
			MessageBox(_T("���Ƚ���CTRC����ƣ�"), _T("��ʾ"), MB_OK | MB_ICONWARNING);    

			SetDlgItemText(IDC_EDIT_RunStatus, _T("���Ƚ���CTRC����ƣ�"));

			CheckDlgButton(IDC_CHECK_CTRC_Line, 0); //��ѡ��CT�����ֱ�߲�����ѡ��ť
			CTRCLine_CheckButtonStatus = NO;//CT�����ֱ�߲�����ѡ��ťδѡ��״̬
			return;
		}

		CTRCLine_rep->SetLabelFormat("%-#6.3g mm");
		CTRCLine_rep->GetLabelProperty()->SetColor(1,1,1);//��ɫ��һ���������ʾЧ���Ϻ�
		CTRCLine_distanceWidget->SetRepresentation(CTRCLine_rep);
		CTRCLine_distanceWidget->SetInteractor(CT_RC_iren);
		CTRCLine_distanceWidget->CreateDefaultRepresentation();
		
		CT_RC_ren->Render();
		CTRCLine_distanceWidget->On();
		SetDlgItemText(IDC_EDIT_RunStatus, _T("����CT�����ֱ�߲��������£�"));

	}
	else if(CTRCLine_CheckButtonStatus == NO)//ȡ��CT�����ֱ�߲���
	{
		SetDlgItemText(IDC_EDIT_RunStatus, _T("CT�����ֱ�߲�������ȡ��..."));
		CT_RC_ren->Render();
		CTRCLine_distanceWidget->Off();
		SetDlgItemText(IDC_EDIT_RunStatus, _T("CT�����ֱ�߲����ɹ�ȡ����"));
	}
}


//���CT����ƽǶȲ����¼�
void CITKVTKMFC_GUIDlg::OnBnClickedCheckCtmcAngle()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CTMCAngle_CheckButtonStatus = m_check_CTMC_Angle.GetCheck();//��ȡCT����ƽǶȲ�����ѡ��ѡ��״̬
	if(CTMCAngle_CheckButtonStatus == YES)//����CT����ƽǶȲ���
	{
		SetDlgItemText(IDC_EDIT_RunStatus, _T("CT����ƽǶȲ�����������..."));
		if(CTRebuild_dicm_data->dataStyle!=REBUILD_CT) //�״β���ʱ�ж��Ƿ�����һ�����ؽ���CT�ļ���
		{  
  
			// ��ʾ��Ϣ�Ի���   
			MessageBox(_T("���ȵ���һ�����ؽ���CT�ļ��У�"), _T("��ʾ"), MB_OK | MB_ICONWARNING);    

			SetDlgItemText(IDC_EDIT_RunStatus, _T("���ȵ���һ�����ؽ���CT�ļ��У�"));

			CheckDlgButton(IDC_CHECK_CTMC_Angle, 0); //��ѡ��CT����ƽǶȲ�����ѡ��ť
			CTMCAngle_CheckButtonStatus = NO;//CT����ƽǶȲ�����ѡ��ťδѡ��״̬
			return;
		}

		if(CTMC3DSeg_YesOrNoMC == NO) //�״β���ʱ�ж��Ƿ��Ѿ�CTMC��ά�ؽ�
		{  
  
			// ��ʾ��Ϣ�Ի���   
			MessageBox(_T("���Ƚ���CTMC����ƣ�"), _T("��ʾ"), MB_OK | MB_ICONWARNING);    

			SetDlgItemText(IDC_EDIT_RunStatus, _T("���Ƚ���CTMC����ƣ�"));

			CheckDlgButton(IDC_CHECK_CTMC_Angle, 0); //��ѡ��CT����ƽǶȲ�����ѡ��ť
			CTMCAngle_CheckButtonStatus = NO;//CT����ƽǶȲ�����ѡ��ťδѡ��״̬
			return;
		}

		CTMCAngle_rep->ArcVisibilityOn();
		CTMCAngle_angleWidget->SetRepresentation(CTMCAngle_rep);
		CTMCAngle_angleWidget->SetInteractor(CT_MC_iren);
		CTMCAngle_angleWidget->CreateDefaultRepresentation();
	
		CT_MC_ren->Render();
		CTMCAngle_angleWidget->On();

		SetDlgItemText(IDC_EDIT_RunStatus, _T("����CT����ƽǶȲ��������£�"));

	}
	else if(CTMCAngle_CheckButtonStatus == NO)//ȡ��CT����ƽǶȲ���
	{
		SetDlgItemText(IDC_EDIT_RunStatus, _T("CT����ƽǶȲ�������ȡ��..."));
		CT_MC_ren->Render();
		CTMCAngle_angleWidget->Off();
		SetDlgItemText(IDC_EDIT_RunStatus, _T("CT����ƽǶȲ����ɹ�ȡ����"));
	}
}


//���CT����ƽǶȲ����¼�
void CITKVTKMFC_GUIDlg::OnBnClickedCheckCtrcAngle()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CTRCAngle_CheckButtonStatus = m_check_CTRC_Angle.GetCheck();//��ȡCT����ƽǶȲ�����ѡ��ѡ��״̬
	if(CTRCAngle_CheckButtonStatus == YES)//����CT����ƽǶȲ���
	{
		SetDlgItemText(IDC_EDIT_RunStatus, _T("CT����ƽǶȲ�����������..."));
		if(CTRebuild_dicm_data->dataStyle!=REBUILD_CT) //�״β���ʱ�ж��Ƿ�����һ�����ؽ���CT�ļ���
		{  
  
			// ��ʾ��Ϣ�Ի���   
			MessageBox(_T("���ȵ���һ�����ؽ���CT�ļ��У�"), _T("��ʾ"), MB_OK | MB_ICONWARNING);    

			SetDlgItemText(IDC_EDIT_RunStatus, _T("���ȵ���һ�����ؽ���CT�ļ��У�"));

			CheckDlgButton(IDC_CHECK_CTRC_Angle, 0); //��ѡ��CT����ƽǶȲ�����ѡ��ť
			CTRCAngle_CheckButtonStatus = NO;//CT����ƽǶȲ�����ѡ��ťδѡ��״̬
			return;
		}

		if(CTRC3DSeg_YesOrNoRC == NO) //�״β���ʱ�ж��Ƿ��Ѿ�CTRC��ά�ؽ�
		{  
  
			// ��ʾ��Ϣ�Ի���   
			MessageBox(_T("���Ƚ���CTRC����ƣ�"), _T("��ʾ"), MB_OK | MB_ICONWARNING);    

			SetDlgItemText(IDC_EDIT_RunStatus, _T("���Ƚ���CTRC����ƣ�"));

			CheckDlgButton(IDC_CHECK_CTRC_Angle, 0); //��ѡ��CT����ƽǶȲ�����ѡ��ť
			CTRCAngle_CheckButtonStatus = NO;//CT����ƽǶȲ�����ѡ��ťδѡ��״̬
			return;
		}

		CTRCAngle_rep->ArcVisibilityOn();
		CTRCAngle_angleWidget->SetRepresentation(CTRCAngle_rep);
		CTRCAngle_angleWidget->SetInteractor(CT_RC_iren);
		CTRCAngle_angleWidget->CreateDefaultRepresentation();
	
		CT_RC_ren->Render();
		CTRCAngle_angleWidget->On();

		SetDlgItemText(IDC_EDIT_RunStatus, _T("����CT����ƽǶȲ��������£�"));

	}
	else if(CTRCAngle_CheckButtonStatus == NO)//ȡ��CT����ƽǶȲ���
	{
		SetDlgItemText(IDC_EDIT_RunStatus, _T("CT����ƽǶȲ�������ȡ��..."));
		CT_RC_ren->Render();
		CTRCAngle_angleWidget->Off();
		SetDlgItemText(IDC_EDIT_RunStatus, _T("CT����ƽǶȲ����ɹ�ȡ����"));
	}
}


//����β�PET-CT���зָ��¼�
void CITKVTKMFC_GUIDlg::OnBnClickedButtonSeg()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	SetDlgItemText(IDC_EDIT_RunStatus, _T("�β�PET-CT���зָ���������..."));
	
	CLungPETCTSeriesSegDlg LungSeriesSegDlg;                   // ����Ի�����CLungPETCTSeriesSegDlg��ʵ��

	INT_PTR nRes;             // ���ڱ���DoModal�����ķ���ֵ   
   
	nRes = LungSeriesSegDlg.DoModal();  // �����Ի���   
	if (IDCANCEL == nRes)     // �ж϶Ի����˳��󷵻�ֵ�Ƿ�ΪIDCANCEL���������return�������������ִ��   
	{
		delete LungSeriesSegDlg;

		SetDlgItemText(IDC_EDIT_RunStatus, _T("�β�PET-CT���зָ���ȡ����"));

		return;
	}
}


//������Ͽ�ѡ��ѡ���¼�
void CITKVTKMFC_GUIDlg::OnCbnSelendokComboHelp()
{
	// TODO: �ڴ���ӿؼ�֪ͨ���������� 
    int nSel;   
  
    // ��ȡ��Ͽ�ؼ����б����ѡ���������   
    nSel = m_comboHelp.GetCurSel();   
	if(nSel == 0) //�ֲ�
	{
		//��չ����
		ShellExecute(NULL,_T("open"),"E:\\vtk_cmake\\MyProject\\MFC\\ITK+VTK+MFC_GUI\\help\\help_handbook.pdf",NULL,NULL,SW_SHOW);
	}
	else if(nSel == 1)//����
	{
		//��չ����
	
		AboutDlg aboutDlg;                   // ����Ի�����AboutDlg��ʵ��

		INT_PTR nRes;             // ���ڱ���DoModal�����ķ���ֵ   
   
		nRes = aboutDlg.DoModal();  // �����Ի���   
		if (IDCANCEL == nRes)     // �ж϶Ի����˳��󷵻�ֵ�Ƿ�ΪIDCANCEL���������return�������������ִ��   
		{
			delete aboutDlg;
			return;
		}
	}
}
