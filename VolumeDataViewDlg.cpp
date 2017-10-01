// VolumeDataViewDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ITK+VTK+MFC_GUI.h"
#include "VolumeDataViewDlg.h"
#include "afxdialogex.h"


// VolumeDataViewDlg �Ի���

IMPLEMENT_DYNAMIC(VolumeDataViewDlg, CDialogEx)

VolumeDataViewDlg::VolumeDataViewDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(VolumeDataViewDlg::IDD, pParent)
{
	init_level_pos = 100;
	init_window_pos = 500;

	seg_level_pos = 128;
	seg_window_pos = 255;

	Init_CT_PET_dicm_data = vtkImageData::New();
	Seg_CT_PET_dicm_data = vtkImageData::New();

	//==============ԭʼCT/PETԤ����Ա����=======================
	init_render = vtkRenderer::New();
	init_renWin = vtkWin32OpenGLRenderWindow::New();
	init_mapper = vtkImageMapper::New();
	init_actor = vtkActor2D::New();
	init_textActor = vtkTextActor::New();
	init_iren = vtkWin32RenderWindowInteractor::New();
	init_pCall = vtkNextDcmCallbk::New(); 
	//===========================================================

	//==============�ָ��CT/PETԤ����Ա����=======================
	seg_render = vtkRenderer::New();
	seg_renWin = vtkWin32OpenGLRenderWindow::New();
	seg_mapper = vtkImageMapper::New();
	seg_actor = vtkActor2D::New();
	seg_textActor = vtkTextActor::New();
	seg_iren = vtkWin32RenderWindowInteractor::New();
	seg_pCall = vtkNextDcmCallbk::New(); 
	//===========================================================

}

VolumeDataViewDlg::~VolumeDataViewDlg()
{
	//�������ڴ����ٶ���
	//Init_CT_PET_dicm_data->Delete();
	//Seg_CT_PET_dicm_data->Delete();

	////==============ԭʼCT/PETԤ����Ա����=======================
	//init_render->Delete();
	//init_renWin->Delete();
	//init_mapper->Delete();
	//init_actor->Delete();
	//init_textActor->Delete();
	//init_iren->Delete();
	//init_pCall->Delete();
	////===========================================================

	////==============�ָ��CT/PETԤ����Ա����=======================
	//seg_render->Delete();
	//seg_renWin->Delete();
	//seg_mapper->Delete();
	//seg_actor->Delete();
	//seg_textActor->Delete();
	//seg_iren->Delete();
	//seg_pCall->Delete();
	////===========================================================
}

void VolumeDataViewDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_VIEW_Import, m_comboViewImport);
	DDX_Control(pDX, IDC_SCROLLBAR_Init_Level, m_scrollbar_init_level);
	DDX_Control(pDX, IDC_SCROLLBAR_Init_Window, m_scrollbar_init_window);
	DDX_Control(pDX, IDC_SCROLLBAR_Seg_Level, m_scrollbar_seg_level);
	DDX_Control(pDX, IDC_SCROLLBAR_Seg_Window, m_scrollbar_seg_window);
}


BEGIN_MESSAGE_MAP(VolumeDataViewDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT_VIEW_RunStatus, &VolumeDataViewDlg::OnEnChangeEditViewRunstatus)
	ON_WM_PAINT()
	ON_WM_HSCROLL()
	ON_CBN_SELENDOK(IDC_COMBO_VIEW_Import, &VolumeDataViewDlg::OnCbnSelendokComboViewImport)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// VolumeDataViewDlg ��Ϣ�������


void VolumeDataViewDlg::OnEnChangeEditViewRunstatus()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void VolumeDataViewDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()

	// Ϊ������Ͽ�ؼ����б������б���    
    m_comboViewImport.AddString(_T("һ���ָ��CT�ļ���")); 
	m_comboViewImport.AddString(_T("һ���ָ��PET�ļ���")); 
	m_comboViewImport.AddString(_T("һ��ԭʼCT�ļ���"));   
	m_comboViewImport.AddString(_T("һ��ԭʼPET�ļ���"));
    // Ĭ��ѡ���һ��   
    m_comboViewImport.SetCurSel(0);  

	// ����ԭʼCT/PET Levelˮƽ�������Ĺ�����ΧΪ-3201��1324   
	m_scrollbar_init_level.SetScrollRange(-3201, 1324);   
    // ����ˮƽ�������ĳ�ʼλ��Ϊ100   
    m_scrollbar_init_level.SetScrollPos(init_level_pos);   
    // �ڱ༭������ʾ100   
    SetDlgItemInt(IDC_STATIC_Init_Level, init_level_pos); 

	// ����ԭʼCT/PET Windowˮƽ�������Ĺ�����ΧΪ0��30000   
	m_scrollbar_init_window.SetScrollRange(0, 30000);   
    // ����ˮƽ�������ĳ�ʼλ��Ϊ500   
    m_scrollbar_init_window.SetScrollPos(init_window_pos);   
    // �ڱ༭������ʾ500   
    SetDlgItemInt(IDC_STATIC_Init_Window, init_window_pos); 

	// ���÷ָ��CT/PET Levelˮƽ�������Ĺ�����ΧΪ0��255   
	m_scrollbar_seg_level.SetScrollRange(0, 255);   
    // ����ˮƽ�������ĳ�ʼλ��Ϊ128   
    m_scrollbar_seg_level.SetScrollPos(seg_level_pos);   
    // �ڱ༭������ʾ128   
    SetDlgItemInt(IDC_STATIC_Seg_Level, seg_level_pos); 

	// ���÷ָ��CT/PET Windowˮƽ�������Ĺ�����ΧΪ0��10880 
	m_scrollbar_seg_window.SetScrollRange(0, 10880);   
    // ����ˮƽ�������ĳ�ʼλ��Ϊ255   
    m_scrollbar_seg_window.SetScrollPos(seg_window_pos);   
    // �ڱ༭������ʾ255   
    SetDlgItemInt(IDC_STATIC_Seg_Window, seg_window_pos); 

	//��ʼ״̬���й�������ֹʹ��
	m_scrollbar_init_level.EnableWindow(FALSE);
	m_scrollbar_init_window.EnableWindow(FALSE);

	m_scrollbar_seg_level.EnableWindow(FALSE);
	m_scrollbar_seg_window.EnableWindow(FALSE);
}


void VolumeDataViewDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	// ����CSliderCtrl ID ���ж�����һ��CSliderCtrl
	if(pScrollBar->GetDlgCtrlID() == IDC_SCROLLBAR_Init_Level)  //ԭʼCT/PET Level
	{
		SetDlgItemText(IDC_EDIT_VIEW_RunStatus, _T("ԭʼCT/PET������ʾLevel���������޸�..."));
		init_level_pos = pScrollBar->GetScrollPos();    // ��ȡˮƽ��������ǰλ��   
  
		switch (nSBCode)    
		{    
			// ����������һ�У���pos��1   
			case SB_LINEUP:    
				init_level_pos -= 1;    
				break;    
			// ������ҹ���һ�У���pos��1   
			case SB_LINEDOWN:    
				init_level_pos  += 1;    
				break;    
			// ����������һҳ����pos��10   
			case SB_PAGEUP:    
				init_level_pos -= 10;    
				break;    
			// ������ҹ���һҳ����pos��10   
			case SB_PAGEDOWN:    
				init_level_pos  += 10;    
				break;    
			// �������������ˣ���posΪ1   
			case SB_TOP:    
				init_level_pos = 1;    
				break;    
			// ������������Ҷˣ���posΪ100   
			case SB_BOTTOM:    
				init_level_pos = 100;    
				break;      
			// ����϶������������ָ��λ�ã���pos��ֵΪnPos��ֵ   
			case SB_THUMBPOSITION:    
				init_level_pos = nPos;    
				break;    
			// �����m_horiScrollbar.SetScrollPos(pos);ִ��ʱ��ڶ��ν���˺���������ȷ��������λ�ã����һ�ֱ�ӵ�default��֧�������ڴ˴����ñ༭������ʾ��ֵ   
			default:    
				SetDlgItemInt(IDC_STATIC_Init_Level,init_level_pos);   
				return;    
		}    
  
		// ���ù�����λ��   
		pScrollBar->SetScrollPos(init_level_pos);   

		CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);

		//�����¼�
		if (!init_iren->GetInitialized())
		{
			init_renWin->AddRenderer(init_render);
			init_renWin->SetParentId(GetDlgItem(IDC_STATIC_InitImage_View)->m_hWnd); //ע����һ�������û��ƴ���
			
			init_iren->SetRenderWindow(init_renWin);
			CRect rect;
			GetDlgItem(IDC_STATIC_InitImage_View)->GetWindowRect(&rect);
			init_iren->Initialize();
			init_renWin->SetSize(rect.right-rect.left,rect.bottom-rect.top);
			init_render->ResetCamera();
	
		}
		//����Init_CT_PET_VIEW()
		Init_CT_PET_VIEW();
		init_renWin->Render();
		SetDlgItemText(IDC_EDIT_VIEW_RunStatus, _T("ԭʼCT/PET������ʾLevel�����޸ĳɹ���"));

	}
	else if(pScrollBar->GetDlgCtrlID() == IDC_SCROLLBAR_Init_Window)  //ԭʼCT/PET Window
	{
		SetDlgItemText(IDC_EDIT_VIEW_RunStatus, _T("ԭʼCT/PET������ʾWindow���������޸�..."));
		init_window_pos = pScrollBar->GetScrollPos();    // ��ȡˮƽ��������ǰλ��   
  
		switch (nSBCode)    
		{    
			// ����������һ�У���pos��1   
			case SB_LINEUP:    
				init_window_pos -= 1;    
				break;    
			// ������ҹ���һ�У���pos��1   
			case SB_LINEDOWN:    
				init_window_pos  += 1;    
				break;    
			// ����������һҳ����pos��10   
			case SB_PAGEUP:    
				init_window_pos -= 10;    
				break;    
			// ������ҹ���һҳ����pos��10   
			case SB_PAGEDOWN:    
				init_window_pos  += 10;    
				break;    
			// �������������ˣ���posΪ1   
			case SB_TOP:    
				init_window_pos = 1;    
				break;    
			// ������������Ҷˣ���posΪ100   
			case SB_BOTTOM:    
				init_window_pos = 100;    
				break;      
			// ����϶������������ָ��λ�ã���pos��ֵΪnPos��ֵ   
			case SB_THUMBPOSITION:    
				init_window_pos = nPos;    
				break;    
			// �����m_horiScrollbar.SetScrollPos(pos);ִ��ʱ��ڶ��ν���˺���������ȷ��������λ�ã����һ�ֱ�ӵ�default��֧�������ڴ˴����ñ༭������ʾ��ֵ   
			default:    
				SetDlgItemInt(IDC_STATIC_Init_Window,init_window_pos);   
				return;    
		}    
  
		// ���ù�����λ��   
		pScrollBar->SetScrollPos(init_window_pos);   

		CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);

		//�����¼�
		if (!init_iren->GetInitialized())
		{
			init_renWin->AddRenderer(init_render);
			init_renWin->SetParentId(GetDlgItem(IDC_STATIC_InitImage_View)->m_hWnd); //ע����һ�������û��ƴ���
			
			init_iren->SetRenderWindow(init_renWin);
			CRect rect;
			GetDlgItem(IDC_STATIC_InitImage_View)->GetWindowRect(&rect);
			init_iren->Initialize();
			init_renWin->SetSize(rect.right-rect.left,rect.bottom-rect.top);
			init_render->ResetCamera();
	
		}
		//����Init_CT_PET_VIEW()
		Init_CT_PET_VIEW();
		init_renWin->Render();
		SetDlgItemText(IDC_EDIT_VIEW_RunStatus, _T("ԭʼCT/PET������ʾWindow�����޸ĳɹ���"));
	}
	else if(pScrollBar->GetDlgCtrlID() == IDC_SCROLLBAR_Seg_Level)  //�ָ��CT/PET Level
	{
		SetDlgItemText(IDC_EDIT_VIEW_RunStatus, _T("�ָ��CT/PET������ʾLevel���������޸�..."));
		seg_level_pos = pScrollBar->GetScrollPos();    // ��ȡˮƽ��������ǰλ��   
  
		switch (nSBCode)    
		{    
			// ����������һ�У���pos��1   
			case SB_LINEUP:    
				seg_level_pos -= 1;    
				break;    
			// ������ҹ���һ�У���pos��1   
			case SB_LINEDOWN:    
				seg_level_pos  += 1;    
				break;    
			// ����������һҳ����pos��10   
			case SB_PAGEUP:    
				seg_level_pos -= 10;    
				break;    
			// ������ҹ���һҳ����pos��10   
			case SB_PAGEDOWN:    
				seg_level_pos  += 10;    
				break;    
			// �������������ˣ���posΪ1   
			case SB_TOP:    
				seg_level_pos = 1;    
				break;    
			// ������������Ҷˣ���posΪ100   
			case SB_BOTTOM:    
				seg_level_pos = 100;    
				break;      
			// ����϶������������ָ��λ�ã���pos��ֵΪnPos��ֵ   
			case SB_THUMBPOSITION:    
				seg_level_pos = nPos;    
				break;    
			// �����m_horiScrollbar.SetScrollPos(pos);ִ��ʱ��ڶ��ν���˺���������ȷ��������λ�ã����һ�ֱ�ӵ�default��֧�������ڴ˴����ñ༭������ʾ��ֵ   
			default:    
				SetDlgItemInt(IDC_STATIC_Seg_Level,seg_level_pos);   
				return;    
		}    
  
		// ���ù�����λ��   
		pScrollBar->SetScrollPos(seg_level_pos);   

		CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);

		//�����¼�
		if (!seg_iren->GetInitialized())
		{
			seg_renWin->AddRenderer(seg_render);
			seg_renWin->SetParentId(GetDlgItem(IDC_STATIC_SegImage_View)->m_hWnd); //ע����һ�������û��ƴ���
			
			seg_iren->SetRenderWindow(seg_renWin);
			CRect rect;
			GetDlgItem(IDC_STATIC_SegImage_View)->GetWindowRect(&rect);
			seg_iren->Initialize();
			seg_renWin->SetSize(rect.right-rect.left,rect.bottom-rect.top);
			seg_render->ResetCamera();
	
		}
		//����Seg_CT_PET_VIEW()
		Seg_CT_PET_VIEW();
		seg_renWin->Render();
		SetDlgItemText(IDC_EDIT_VIEW_RunStatus, _T("�ָ��CT/PET������ʾLevel�����޸ĳɹ���"));
	}
	else if(pScrollBar->GetDlgCtrlID() == IDC_SCROLLBAR_Seg_Window)  //�ָ��CT/PET Window
	{
		SetDlgItemText(IDC_EDIT_VIEW_RunStatus, _T("�ָ��CT/PET������ʾWindow���������޸�..."));
		seg_window_pos = pScrollBar->GetScrollPos();    // ��ȡˮƽ��������ǰλ��   
  
		switch (nSBCode)    
		{    
			// ����������һ�У���pos��1   
			case SB_LINEUP:    
				seg_window_pos -= 1;    
				break;    
			// ������ҹ���һ�У���pos��1   
			case SB_LINEDOWN:    
				seg_window_pos  += 1;    
				break;    
			// ����������һҳ����pos��10   
			case SB_PAGEUP:    
				seg_window_pos -= 10;    
				break;    
			// ������ҹ���һҳ����pos��10   
			case SB_PAGEDOWN:    
				seg_window_pos  += 10;    
				break;    
			// �������������ˣ���posΪ1   
			case SB_TOP:    
				seg_window_pos = 1;    
				break;    
			// ������������Ҷˣ���posΪ100   
			case SB_BOTTOM:    
				seg_window_pos = 100;    
				break;      
			// ����϶������������ָ��λ�ã���pos��ֵΪnPos��ֵ   
			case SB_THUMBPOSITION:    
				seg_window_pos = nPos;    
				break;    
			// �����m_horiScrollbar.SetScrollPos(pos);ִ��ʱ��ڶ��ν���˺���������ȷ��������λ�ã����һ�ֱ�ӵ�default��֧�������ڴ˴����ñ༭������ʾ��ֵ   
			default:    
				SetDlgItemInt(IDC_STATIC_Seg_Window,seg_window_pos);   
				return;    
		}    
  
		// ���ù�����λ��   
		pScrollBar->SetScrollPos(seg_window_pos);   

		CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);

		//�����¼�
		if (!seg_iren->GetInitialized())
		{
			seg_renWin->AddRenderer(seg_render);
			seg_renWin->SetParentId(GetDlgItem(IDC_STATIC_SegImage_View)->m_hWnd); //ע����һ�������û��ƴ���
			
			seg_iren->SetRenderWindow(seg_renWin);
			CRect rect;
			GetDlgItem(IDC_STATIC_SegImage_View)->GetWindowRect(&rect);
			seg_iren->Initialize();
			seg_renWin->SetSize(rect.right-rect.left,rect.bottom-rect.top);
			seg_render->ResetCamera();
	
		}
		//����Seg_CT_PET_VIEW()
		Seg_CT_PET_VIEW();
		seg_renWin->Render();
		SetDlgItemText(IDC_EDIT_VIEW_RunStatus, _T("�ָ��CT/PET������ʾWindow�����޸ĳɹ���"));
	}

}


//����
void VolumeDataViewDlg::OnCbnSelendokComboViewImport()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	CString strImport;   
    int nSel;   
  
    // ��ȡ��Ͽ�ؼ����б����ѡ���������   
    nSel = m_comboViewImport.GetCurSel();   
    // ����ѡ����������ȡ�����ַ���   
    m_comboViewImport.GetLBText(nSel, strImport);   
	strImport +=_T("���ڵ���...");
	SetDlgItemText(IDC_EDIT_VIEW_RunStatus, strImport);
	if(nSel == 0) //����һ���ָ��CT�ļ���
	{
		//��չ����
		BROWSEINFO bi;
		char chDir[MAX_PATH] = {0};
		memset((char *)&bi, 0, sizeof(bi));
		bi.hwndOwner = this->m_hWnd;
		bi.lpszTitle = "ѡ��һ���ָ��CT�ļ���";

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
	
		Seg_CT_PET_dicm_data = pRead->GetOutput();	

		SetDlgItemText(IDC_EDIT_VIEW_RunStatus, _T("����ɹ���->�ָ��CT������������ʾ��������..."));

		if (!seg_iren->GetInitialized())
		{
			seg_renWin->AddRenderer(seg_render);
			seg_renWin->SetParentId(GetDlgItem(IDC_STATIC_SegImage_View)->m_hWnd); //ע����һ�������û��ƴ���
			
			seg_iren->SetRenderWindow(seg_renWin);
			CRect rect;
			GetDlgItem(IDC_STATIC_SegImage_View)->GetWindowRect(&rect);
			seg_iren->Initialize();
			seg_renWin->SetSize(rect.right-rect.left,rect.bottom-rect.top);
			seg_render->ResetCamera();
	
		}
		//����Seg_CT_PET_VIEW()
		Seg_CT_PET_VIEW();
		seg_renWin->Render();
		SetDlgItemText(IDC_EDIT_VIEW_RunStatus, _T("�ָ��CT������������ʾ�ɹ���"));

		//����������ʹ��
		m_scrollbar_seg_level.EnableWindow(TRUE);
		m_scrollbar_seg_window.EnableWindow(TRUE);

	}
	else if(nSel == 1)//����һ���ָ��PET�ļ���
	{
		//��չ����
		BROWSEINFO bi;
		char chDir[MAX_PATH] = {0};
		memset((char *)&bi, 0, sizeof(bi));
		bi.hwndOwner = this->m_hWnd;
		bi.lpszTitle = "ѡ��һ���ָ��PET�ļ���";

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
	
		Seg_CT_PET_dicm_data = pRead->GetOutput();	

		SetDlgItemText(IDC_EDIT_VIEW_RunStatus, _T("����ɹ���->�ָ��PET������������ʾ��������..."));

		if (!seg_iren->GetInitialized())
		{
			seg_renWin->AddRenderer(seg_render);
			seg_renWin->SetParentId(GetDlgItem(IDC_STATIC_SegImage_View)->m_hWnd); //ע����һ�������û��ƴ���
			
			seg_iren->SetRenderWindow(seg_renWin);
			CRect rect;
			GetDlgItem(IDC_STATIC_SegImage_View)->GetWindowRect(&rect);
			seg_iren->Initialize();
			seg_renWin->SetSize(rect.right-rect.left,rect.bottom-rect.top);
			seg_render->ResetCamera();
	
		}
		//����Seg_CT_PET_VIEW()
		Seg_CT_PET_VIEW();
		seg_renWin->Render();
		SetDlgItemText(IDC_EDIT_VIEW_RunStatus, _T("�ָ��PET������������ʾ�ɹ���"));

		//����������ʹ��
		m_scrollbar_seg_level.EnableWindow(TRUE);
		m_scrollbar_seg_window.EnableWindow(TRUE);
	}
	else if(nSel == 2)//����һ��ԭʼCT�ļ���
	{
		//��չ����
		BROWSEINFO bi;
		char chDir[MAX_PATH] = {0};
		memset((char *)&bi, 0, sizeof(bi));
		bi.hwndOwner = this->m_hWnd;
		bi.lpszTitle = "ѡ��һ��ԭʼCT�ļ���";

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
	
		Init_CT_PET_dicm_data = pRead->GetOutput();	

		SetDlgItemText(IDC_EDIT_VIEW_RunStatus, _T("����ɹ���->ԭʼCT������������ʾ��������..."));

		if (!init_iren->GetInitialized())
		{
			init_renWin->AddRenderer(init_render);
			init_renWin->SetParentId(GetDlgItem(IDC_STATIC_InitImage_View)->m_hWnd); //ע����һ�������û��ƴ���
			
			init_iren->SetRenderWindow(init_renWin);
			CRect rect;
			GetDlgItem(IDC_STATIC_InitImage_View)->GetWindowRect(&rect);
			init_iren->Initialize();
			init_renWin->SetSize(rect.right-rect.left,rect.bottom-rect.top);
			init_render->ResetCamera();
	
		}
		//����Init_CT_PET_VIEW()
		Init_CT_PET_VIEW();
		init_renWin->Render();
		SetDlgItemText(IDC_EDIT_VIEW_RunStatus, _T("ԭʼCT������������ʾ�ɹ���"));

		//����������ʹ��
		m_scrollbar_init_level.EnableWindow(TRUE);
		m_scrollbar_init_window.EnableWindow(TRUE);
	}
	else if(nSel == 3)//����һ��ԭʼPET�ļ���
	{
		//��չ����
		BROWSEINFO bi;
		char chDir[MAX_PATH] = {0};
		memset((char *)&bi, 0, sizeof(bi));
		bi.hwndOwner = this->m_hWnd;
		bi.lpszTitle = "ѡ��һ��ԭʼPET�ļ���";

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
	
		Init_CT_PET_dicm_data = pRead->GetOutput();	

		SetDlgItemText(IDC_EDIT_VIEW_RunStatus, _T("����ɹ���->ԭʼPET������������ʾ��������..."));

		if (!init_iren->GetInitialized())
		{
			init_renWin->AddRenderer(init_render);
			init_renWin->SetParentId(GetDlgItem(IDC_STATIC_InitImage_View)->m_hWnd); //ע����һ�������û��ƴ���
			
			init_iren->SetRenderWindow(init_renWin);
			CRect rect;
			GetDlgItem(IDC_STATIC_InitImage_View)->GetWindowRect(&rect);
			init_iren->Initialize();
			init_renWin->SetSize(rect.right-rect.left,rect.bottom-rect.top);
			init_render->ResetCamera();
	
		}
		//����Init_CT_PET_VIEW()
		Init_CT_PET_VIEW();
		init_renWin->Render();
		SetDlgItemText(IDC_EDIT_VIEW_RunStatus, _T("ԭʼPET������������ʾ�ɹ���"));

		//����������ʹ��
		m_scrollbar_init_level.EnableWindow(TRUE);
		m_scrollbar_init_window.EnableWindow(TRUE);
	}
}


//ԭʼCT/PETԤ������
void VolumeDataViewDlg::Init_CT_PET_VIEW()
{
	init_mapper->SetColorWindow(init_window_pos); // Set an initial window that makes sense for you.
	init_mapper->SetColorLevel(init_level_pos); // Set an initial level  that makes sense for you.

	init_mapper->SetInputData(Init_CT_PET_dicm_data);   

	init_actor->SetMapper(init_mapper); 
	init_render->AddActor(init_actor); //��Ƭ������

	init_textActor->SetPosition(0, 20); 
	char buf[64] = {0};
	sprintf(buf, "%d / %d", init_mapper->GetZSlice(), init_mapper->GetWholeZMax());
	init_textActor->SetInput(buf);
	init_render->AddActor(init_textActor);//���ֱ�����

	init_iren->AddObserver(vtkCommand::MouseWheelBackwardEvent, init_pCall); 
	init_iren->AddObserver(vtkCommand::MouseWheelForwardEvent, init_pCall);
}

//�ָ��CT/PETԤ������
void VolumeDataViewDlg::Seg_CT_PET_VIEW()
{
	seg_mapper->SetColorWindow(seg_window_pos); // Set an initial window that makes sense for you.
	seg_mapper->SetColorLevel(seg_level_pos); // Set an initial level  that makes sense for you.

	seg_mapper->SetInputData(Seg_CT_PET_dicm_data);   

	seg_actor->SetMapper(seg_mapper); 
	seg_render->AddActor(seg_actor); //��Ƭ������

	seg_textActor->SetPosition(0, 20); 
	char buf[64] = {0};
	sprintf(buf, "%d / %d", seg_mapper->GetZSlice(), seg_mapper->GetWholeZMax());
	seg_textActor->SetInput(buf);
	seg_render->AddActor(seg_textActor);//���ֱ�����

	seg_iren->AddObserver(vtkCommand::MouseWheelBackwardEvent, seg_pCall); 
	seg_iren->AddObserver(vtkCommand::MouseWheelForwardEvent, seg_pCall);
}

void VolumeDataViewDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: �ڴ˴������Ϣ����������
	Init_CT_PET_dicm_data->Delete();
	Seg_CT_PET_dicm_data->Delete();

	//==============ԭʼCT/PETԤ����Ա����=======================
	init_render->Delete();
	init_renWin->Delete();
	init_mapper->Delete();
	init_actor->Delete();
	init_textActor->Delete();
	init_iren->Delete();
	init_pCall->Delete();
	//===========================================================

	//==============�ָ��CT/PETԤ����Ա����=======================
	seg_render->Delete();
	seg_renWin->Delete();
	seg_mapper->Delete();
	seg_actor->Delete();
	seg_textActor->Delete();
	seg_iren->Delete();
	seg_pCall->Delete();
	//===========================================================
}
