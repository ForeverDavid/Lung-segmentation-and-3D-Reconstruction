// CTMCPropertyDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ITK+VTK+MFC_GUI.h"
#include "CTMCPropertyDlg.h"
#include "afxdialogex.h"


// CCTMCPropertyDlg �Ի���

IMPLEMENT_DYNAMIC(CCTMCPropertyDlg, CDialogEx)

CCTMCPropertyDlg::CCTMCPropertyDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCTMCPropertyDlg::IDD, pParent)
{
	/*CTMC_Style = MC;//Ĭ���������MC

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
	CTMC_SpecularPower_pos = 20;*/
}

CCTMCPropertyDlg::~CCTMCPropertyDlg()
{
}

void CCTMCPropertyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SCROLLBAR_CTMCProp_LungCT, m_scrollbar_CTMCProp_LungCT);
	DDX_Control(pDX, IDC_SCROLLBAR_CTMCProp_LungSmooth, m_scrollbar_CTMCProp_LungSmooth);
	DDX_Control(pDX, IDC_SCROLLBAR_CTMCProp_LungR, m_scrollbar_CTMCProp_LungR);
	DDX_Control(pDX, IDC_SCROLLBAR_CTMCProp_LungG, m_scrollbar_CTMCProp_LungG);
	DDX_Control(pDX, IDC_SCROLLBAR_CTMCProp_LungB, m_scrollbar_CTMCProp_LungB);
	DDX_Control(pDX, IDC_SCROLLBAR_CTMCProp_LungOpacity, m_scrollbar_CTMCProp_LungOpacity);
	DDX_Control(pDX, IDC_SCROLLBAR_CTMCProp_InterCT, m_scrollbar_CTMCProp_InterCT);
	DDX_Control(pDX, IDC_SCROLLBAR_CTMCProp_InterSmooth, m_scrollbar_CTMCProp_InterSmooth);
	DDX_Control(pDX, IDC_SCROLLBAR_CTMCProp_InterR, m_scrollbar_CTMCProp_InterR);
	DDX_Control(pDX, IDC_SCROLLBAR_CTMCProp_InterG, m_scrollbar_CTMCProp_InterG);
	DDX_Control(pDX, IDC_SCROLLBAR_CTMCProp_InterB, m_scrollbar_CTMCProp_InterB);
	DDX_Control(pDX, IDC_SCROLLBAR_CTMCProp_InterOpacity, m_scrollbar_CTMCProp_InterOpacity);
	DDX_Control(pDX, IDC_SCROLLBAR_CTMCProp_Ambient, m_scrollbar_CTMCProp_Ambient);
	DDX_Control(pDX, IDC_SCROLLBAR_CTMCProp_Diffuse, m_scrollbar_CTMCProp_Diffuse);
	DDX_Control(pDX, IDC_SCROLLBAR_CTMCProp_Specular, m_scrollbar_CTMCProp_Specular);
	DDX_Control(pDX, IDC_SCROLLBAR_CTMCProp_SpecularPower, m_scrollbar_CTMCProp_SpecularPower);
}


BEGIN_MESSAGE_MAP(CCTMCPropertyDlg, CDialogEx)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_RADIO_CTMCProp_MC, &CCTMCPropertyDlg::OnBnClickedRadioCtmcpropMc)
	ON_BN_CLICKED(IDC_RADIO_CTMCProp_AccMC, &CCTMCPropertyDlg::OnBnClickedRadioCtmcpropAccmc)
	ON_WM_HSCROLL()
END_MESSAGE_MAP()


// CCTMCPropertyDlg ��Ϣ�������


void CCTMCPropertyDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()

	//��ʼ��
	//��̬���öԻ������
	SetWindowText(m_strCaption);

	// ���÷���ֵˮƽ�������Ĺ�����ΧΪ0��255   
    m_scrollbar_CTMCProp_LungCT.SetScrollRange(0, 255);   
    // ����ˮƽ�������ĳ�ʼλ��Ϊ103   
    m_scrollbar_CTMCProp_LungCT.SetScrollPos(CTMC_LungCT_pos);   
    // �ڱ༭������ʾ103   
    SetDlgItemInt(IDC_STATIC_CTMCProp_LungCT, CTMC_LungCT_pos); 

	// ���÷�ƽ����������ˮƽ�������Ĺ�����ΧΪ0��1000   
    m_scrollbar_CTMCProp_LungSmooth.SetScrollRange(0, 1000);   
    // ����ˮƽ�������ĳ�ʼλ��Ϊ500  
    m_scrollbar_CTMCProp_LungSmooth.SetScrollPos(CTMC_LungSmooth_pos);   
    // �ڱ༭������ʾ500   
    SetDlgItemInt(IDC_STATIC_CTMCProp_LungSmooth, CTMC_LungSmooth_pos); 

	// ���÷���ɫRˮƽ�������Ĺ�����ΧΪ0��100 
    m_scrollbar_CTMCProp_LungR.SetScrollRange(0, 100);   
    // ����ˮƽ�������ĳ�ʼλ��Ϊ100  
    m_scrollbar_CTMCProp_LungR.SetScrollPos(CTMC_LungR_pos);   
    // �ڱ༭������ʾ100   
    SetDlgItemInt(IDC_STATIC_CTMCProp_LungR, CTMC_LungR_pos); 

	// ���÷���ɫGˮƽ�������Ĺ�����ΧΪ0��100 
    m_scrollbar_CTMCProp_LungG.SetScrollRange(0, 100);   
    // ����ˮƽ�������ĳ�ʼλ��Ϊ19  
    m_scrollbar_CTMCProp_LungG.SetScrollPos(CTMC_LungG_pos);   
    // �ڱ༭������ʾ19   
    SetDlgItemInt(IDC_STATIC_CTMCProp_LungG, CTMC_LungG_pos); 

	// ���÷���ɫBˮƽ�������Ĺ�����ΧΪ0��100 
    m_scrollbar_CTMCProp_LungB.SetScrollRange(0, 100);   
    // ����ˮƽ�������ĳ�ʼλ��Ϊ15  
    m_scrollbar_CTMCProp_LungB.SetScrollPos(CTMC_LungB_pos);   
    // �ڱ༭������ʾ15   
    SetDlgItemInt(IDC_STATIC_CTMCProp_LungB, CTMC_LungB_pos); 

	// ���÷�͸����ˮƽ�������Ĺ�����ΧΪ0��100 
    m_scrollbar_CTMCProp_LungOpacity.SetScrollRange(0, 100);   
    // ����ˮƽ�������ĳ�ʼλ��Ϊ100  
    m_scrollbar_CTMCProp_LungOpacity.SetScrollPos(CTMC_LungOpacity_pos);   
    // �ڱ༭������ʾ100   
    SetDlgItemInt(IDC_STATIC_CTMCProp_LungOpacity, CTMC_LungOpacity_pos); 


	// ���÷��ڲ���ֵˮƽ�������Ĺ�����ΧΪ0��255  
    m_scrollbar_CTMCProp_InterCT.SetScrollRange(0, 255);   
    // ����ˮƽ�������ĳ�ʼλ��Ϊ160   
    m_scrollbar_CTMCProp_InterCT.SetScrollPos(CTMC_InterCT_pos);   
    // �ڱ༭������ʾ160   
    SetDlgItemInt(IDC_STATIC_CTMCProp_InterCT, CTMC_InterCT_pos); 

	// ���÷��ڲ�ƽ����������ˮƽ�������Ĺ�����ΧΪ0��1000   
    m_scrollbar_CTMCProp_InterSmooth.SetScrollRange(0, 1000);   
    // ����ˮƽ�������ĳ�ʼλ��Ϊ100  
    m_scrollbar_CTMCProp_InterSmooth.SetScrollPos(CTMC_InterSmooth_pos);   
    // �ڱ༭������ʾ100   
    SetDlgItemInt(IDC_STATIC_CTMCProp_InterSmooth, CTMC_InterSmooth_pos); 

	// ���÷��ڲ���ɫRˮƽ�������Ĺ�����ΧΪ0��100 
    m_scrollbar_CTMCProp_InterR.SetScrollRange(0, 100);   
    // ����ˮƽ�������ĳ�ʼλ��Ϊ100  
    m_scrollbar_CTMCProp_InterR.SetScrollPos(CTMC_InterR_pos);   
    // �ڱ༭������ʾ100   
    SetDlgItemInt(IDC_STATIC_CTMCProp_InterR, CTMC_InterR_pos); 

	// ���÷��ڲ���ɫGˮƽ�������Ĺ�����ΧΪ0��100 
    m_scrollbar_CTMCProp_InterG.SetScrollRange(0, 100);   
    // ����ˮƽ�������ĳ�ʼλ��Ϊ19  
    m_scrollbar_CTMCProp_InterG.SetScrollPos(CTMC_InterG_pos);   
    // �ڱ༭������ʾ19   
    SetDlgItemInt(IDC_STATIC_CTMCProp_InterG, CTMC_InterG_pos); 

	// ���÷��ڲ���ɫBˮƽ�������Ĺ�����ΧΪ0��100 
    m_scrollbar_CTMCProp_InterB.SetScrollRange(0, 100);   
    // ����ˮƽ�������ĳ�ʼλ��Ϊ15  
    m_scrollbar_CTMCProp_InterB.SetScrollPos(CTMC_InterB_pos);   
    // �ڱ༭������ʾ15   
    SetDlgItemInt(IDC_STATIC_CTMCProp_InterB, CTMC_InterB_pos); 

	// ���÷��ڲ�͸����ˮƽ�������Ĺ�����ΧΪ0��100 
    m_scrollbar_CTMCProp_InterOpacity.SetScrollRange(0, 100);   
    // ����ˮƽ�������ĳ�ʼλ��Ϊ100  
    m_scrollbar_CTMCProp_InterOpacity.SetScrollPos(CTMC_InterOpacity_pos);   
    // �ڱ༭������ʾ100   
    SetDlgItemInt(IDC_STATIC_CTMCProp_InterOpacity, CTMC_InterOpacity_pos); 

	// ���÷λ�����ϵ��ˮƽ�������Ĺ�����ΧΪ0��100 
    m_scrollbar_CTMCProp_Ambient.SetScrollRange(0, 100);   
    // ����ˮƽ�������ĳ�ʼλ��Ϊ30  
    m_scrollbar_CTMCProp_Ambient.SetScrollPos(CTMC_Ambient_pos);   
    // �ڱ༭������ʾ30   
    SetDlgItemInt(IDC_STATIC_CTMCProp_Ambient, CTMC_Ambient_pos); 

	// ���÷������ϵ��ˮƽ�������Ĺ�����ΧΪ0��100 
    m_scrollbar_CTMCProp_Diffuse.SetScrollRange(0, 100);   
    // ����ˮƽ�������ĳ�ʼλ��Ϊ60  
    m_scrollbar_CTMCProp_Diffuse.SetScrollPos(CTMC_Diffuse_pos);   
    // �ڱ༭������ʾ60   
    SetDlgItemInt(IDC_STATIC_CTMCProp_Diffuse, CTMC_Diffuse_pos); 

	// ���÷ξ����ϵ��ˮƽ�������Ĺ�����ΧΪ0��100 
    m_scrollbar_CTMCProp_Specular.SetScrollRange(0, 100);   
    // ����ˮƽ�������ĳ�ʼλ��Ϊ20  
    m_scrollbar_CTMCProp_Specular.SetScrollPos(CTMC_Specular_pos);   
    // �ڱ༭������ʾ20   
    SetDlgItemInt(IDC_STATIC_CTMCProp_Specular, CTMC_Specular_pos); 

	// ���÷ξ����ǿ��ˮƽ�������Ĺ�����ΧΪ0��100 
    m_scrollbar_CTMCProp_SpecularPower.SetScrollRange(0, 100);   
    // ����ˮƽ�������ĳ�ʼλ��Ϊ20  
    m_scrollbar_CTMCProp_SpecularPower.SetScrollPos(CTMC_SpecularPower_pos);   
    // �ڱ༭������ʾ20   
    SetDlgItemInt(IDC_STATIC_CTMCProp_SpecularPower, CTMC_SpecularPower_pos); 

	if(CTMC_Style == MC)
	{
		// Ĭ��ѡ�С�MC����ѡ��ť   
		CheckDlgButton(IDC_RADIO_CTMCProp_MC, 1);  
		OnBnClickedRadioCtmcpropMc();
	}
	else if(CTMC_Style == ACC_MC)
	{
		// Ĭ��ѡ�С�ACC_MC����ѡ��ť   
		CheckDlgButton(IDC_RADIO_CTMCProp_AccMC, 1);  
		OnBnClickedRadioCtmcpropAccmc();
	}
	

}


//����MC��ѡ��ť�¼�
void CCTMCPropertyDlg::OnBnClickedRadioCtmcpropMc()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	 CTMC_Style = MC;  //����CTMC��������ΪMC
}


//��������MC��ѡ��ť�¼�
void CCTMCPropertyDlg::OnBnClickedRadioCtmcpropAccmc()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CTMC_Style = ACC_MC;  //����CTMC��������Ϊ����MC
}


void CCTMCPropertyDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	// ����CSliderCtrl ID ���ж�����һ��CSliderCtrl
	if(pScrollBar->GetDlgCtrlID() == IDC_SCROLLBAR_CTMCProp_LungCT)  //����ֵ
	{
		CTMC_LungCT_pos = pScrollBar->GetScrollPos();    // ��ȡˮƽ��������ǰλ��   
  
		switch (nSBCode)    
		{    
			// ����������һ�У���pos��1   
			case SB_LINEUP:    
				CTMC_LungCT_pos -= 1;    
				break;    
			// ������ҹ���һ�У���pos��1   
			case SB_LINEDOWN:    
				CTMC_LungCT_pos  += 1;    
				break;    
			// ����������һҳ����pos��10   
			case SB_PAGEUP:    
				CTMC_LungCT_pos -= 10;    
				break;    
			// ������ҹ���һҳ����pos��10   
			case SB_PAGEDOWN:    
				CTMC_LungCT_pos  += 10;    
				break;    
			// �������������ˣ���posΪ1   
			case SB_TOP:    
				CTMC_LungCT_pos = 1;    
				break;    
			// ������������Ҷˣ���posΪ100   
			case SB_BOTTOM:    
				CTMC_LungCT_pos = 100;    
				break;      
			// ����϶������������ָ��λ�ã���pos��ֵΪnPos��ֵ   
			case SB_THUMBPOSITION:    
				CTMC_LungCT_pos = nPos;    
				break;    
			// �����m_horiScrollbar.SetScrollPos(pos);ִ��ʱ��ڶ��ν���˺���������ȷ��������λ�ã����һ�ֱ�ӵ�default��֧�������ڴ˴����ñ༭������ʾ��ֵ   
			default:    
				SetDlgItemInt(IDC_STATIC_CTMCProp_LungCT,CTMC_LungCT_pos);   
				return;    
		}    
  
		// ���ù�����λ��   
		pScrollBar->SetScrollPos(CTMC_LungCT_pos);   

		CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	}
	else if(pScrollBar->GetDlgCtrlID() == IDC_SCROLLBAR_CTMCProp_LungSmooth)//ƽ����������
	{
		CTMC_LungSmooth_pos = pScrollBar->GetScrollPos();    // ��ȡˮƽ��������ǰλ��   
  
		switch (nSBCode)    
		{    
			// ����������һ�У���pos��1   
			case SB_LINEUP:    
				CTMC_LungSmooth_pos -= 1;    
				break;    
			// ������ҹ���һ�У���pos��1   
			case SB_LINEDOWN:    
				CTMC_LungSmooth_pos  += 1;    
				break;    
			// ����������һҳ����pos��10   
			case SB_PAGEUP:    
				CTMC_LungSmooth_pos -= 10;    
				break;    
			// ������ҹ���һҳ����pos��10   
			case SB_PAGEDOWN:    
				CTMC_LungSmooth_pos  += 10;    
				break;    
			// �������������ˣ���posΪ1   
			case SB_TOP:    
				CTMC_LungSmooth_pos = 1;    
				break;    
			// ������������Ҷˣ���posΪ100   
			case SB_BOTTOM:    
				CTMC_LungSmooth_pos = 100;    
				break;      
			// ����϶������������ָ��λ�ã���pos��ֵΪnPos��ֵ   
			case SB_THUMBPOSITION:    
				CTMC_LungSmooth_pos = nPos;    
				break;    
			// �����m_horiScrollbar.SetScrollPos(pos);ִ��ʱ��ڶ��ν���˺���������ȷ��������λ�ã����һ�ֱ�ӵ�default��֧�������ڴ˴����ñ༭������ʾ��ֵ   
			default:    
				SetDlgItemInt(IDC_STATIC_CTMCProp_LungSmooth,CTMC_LungSmooth_pos);   
				return;    
		}    
  
		// ���ù�����λ��   
		pScrollBar->SetScrollPos(CTMC_LungSmooth_pos);   

		CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	}
	else if(pScrollBar->GetDlgCtrlID() == IDC_SCROLLBAR_CTMCProp_LungR)//����ɫR
	{
		CTMC_LungR_pos = pScrollBar->GetScrollPos();    // ��ȡˮƽ��������ǰλ��   
  
		switch (nSBCode)    
		{    
			// ����������һ�У���pos��1   
			case SB_LINEUP:    
				CTMC_LungR_pos -= 1;    
				break;    
			// ������ҹ���һ�У���pos��1   
			case SB_LINEDOWN:    
				CTMC_LungR_pos  += 1;    
				break;    
			// ����������һҳ����pos��10   
			case SB_PAGEUP:    
				CTMC_LungR_pos -= 10;    
				break;    
			// ������ҹ���һҳ����pos��10   
			case SB_PAGEDOWN:    
				CTMC_LungR_pos  += 10;    
				break;    
			// �������������ˣ���posΪ1   
			case SB_TOP:    
				CTMC_LungR_pos = 1;    
				break;    
			// ������������Ҷˣ���posΪ100   
			case SB_BOTTOM:    
				CTMC_LungR_pos = 100;    
				break;      
			// ����϶������������ָ��λ�ã���pos��ֵΪnPos��ֵ   
			case SB_THUMBPOSITION:    
				CTMC_LungR_pos = nPos;    
				break;    
			// �����m_horiScrollbar.SetScrollPos(pos);ִ��ʱ��ڶ��ν���˺���������ȷ��������λ�ã����һ�ֱ�ӵ�default��֧�������ڴ˴����ñ༭������ʾ��ֵ   
			default:    
				SetDlgItemInt(IDC_STATIC_CTMCProp_LungR,CTMC_LungR_pos);   
				return;    
		}    
  
		// ���ù�����λ��   
		pScrollBar->SetScrollPos(CTMC_LungR_pos);   

		CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	}
	else if(pScrollBar->GetDlgCtrlID() == IDC_SCROLLBAR_CTMCProp_LungG)//����ɫG
	{
		CTMC_LungG_pos = pScrollBar->GetScrollPos();    // ��ȡˮƽ��������ǰλ��   
  
		switch (nSBCode)    
		{    
			// ����������һ�У���pos��1   
			case SB_LINEUP:    
				CTMC_LungG_pos -= 1;    
				break;    
			// ������ҹ���һ�У���pos��1   
			case SB_LINEDOWN:    
				CTMC_LungG_pos  += 1;    
				break;    
			// ����������һҳ����pos��10   
			case SB_PAGEUP:    
				CTMC_LungG_pos -= 10;    
				break;    
			// ������ҹ���һҳ����pos��10   
			case SB_PAGEDOWN:    
				CTMC_LungG_pos  += 10;    
				break;    
			// �������������ˣ���posΪ1   
			case SB_TOP:    
				CTMC_LungG_pos = 1;    
				break;    
			// ������������Ҷˣ���posΪ100   
			case SB_BOTTOM:    
				CTMC_LungG_pos = 100;    
				break;      
			// ����϶������������ָ��λ�ã���pos��ֵΪnPos��ֵ   
			case SB_THUMBPOSITION:    
				CTMC_LungG_pos = nPos;    
				break;    
			// �����m_horiScrollbar.SetScrollPos(pos);ִ��ʱ��ڶ��ν���˺���������ȷ��������λ�ã����һ�ֱ�ӵ�default��֧�������ڴ˴����ñ༭������ʾ��ֵ   
			default:    
				SetDlgItemInt(IDC_STATIC_CTMCProp_LungG,CTMC_LungG_pos);   
				return;    
		}    
  
		// ���ù�����λ��   
		pScrollBar->SetScrollPos(CTMC_LungG_pos);   

		CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	}
	else if(pScrollBar->GetDlgCtrlID() == IDC_SCROLLBAR_CTMCProp_LungB)//����ɫB
	{
		CTMC_LungB_pos = pScrollBar->GetScrollPos();    // ��ȡˮƽ��������ǰλ��   
  
		switch (nSBCode)    
		{    
			// ����������һ�У���pos��1   
			case SB_LINEUP:    
				CTMC_LungB_pos -= 1;    
				break;    
			// ������ҹ���һ�У���pos��1   
			case SB_LINEDOWN:    
				CTMC_LungB_pos  += 1;    
				break;    
			// ����������һҳ����pos��10   
			case SB_PAGEUP:    
				CTMC_LungB_pos -= 10;    
				break;    
			// ������ҹ���һҳ����pos��10   
			case SB_PAGEDOWN:    
				CTMC_LungB_pos  += 10;    
				break;    
			// �������������ˣ���posΪ1   
			case SB_TOP:    
				CTMC_LungB_pos = 1;    
				break;    
			// ������������Ҷˣ���posΪ100   
			case SB_BOTTOM:    
				CTMC_LungB_pos = 100;    
				break;      
			// ����϶������������ָ��λ�ã���pos��ֵΪnPos��ֵ   
			case SB_THUMBPOSITION:    
				CTMC_LungB_pos = nPos;    
				break;    
			// �����m_horiScrollbar.SetScrollPos(pos);ִ��ʱ��ڶ��ν���˺���������ȷ��������λ�ã����һ�ֱ�ӵ�default��֧�������ڴ˴����ñ༭������ʾ��ֵ   
			default:    
				SetDlgItemInt(IDC_STATIC_CTMCProp_LungB,CTMC_LungB_pos);   
				return;    
		}    
  
		// ���ù�����λ��   
		pScrollBar->SetScrollPos(CTMC_LungB_pos);   

		CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	}
	else if(pScrollBar->GetDlgCtrlID() == IDC_SCROLLBAR_CTMCProp_LungOpacity)//��͸����
	{
		CTMC_LungOpacity_pos = pScrollBar->GetScrollPos();    // ��ȡˮƽ��������ǰλ��   
  
		switch (nSBCode)    
		{    
			// ����������һ�У���pos��1   
			case SB_LINEUP:    
				CTMC_LungOpacity_pos -= 1;    
				break;    
			// ������ҹ���һ�У���pos��1   
			case SB_LINEDOWN:    
				CTMC_LungOpacity_pos  += 1;    
				break;    
			// ����������һҳ����pos��10   
			case SB_PAGEUP:    
				CTMC_LungOpacity_pos -= 10;    
				break;    
			// ������ҹ���һҳ����pos��10   
			case SB_PAGEDOWN:    
				CTMC_LungOpacity_pos  += 10;    
				break;    
			// �������������ˣ���posΪ1   
			case SB_TOP:    
				CTMC_LungOpacity_pos = 1;    
				break;    
			// ������������Ҷˣ���posΪ100   
			case SB_BOTTOM:    
				CTMC_LungOpacity_pos = 100;    
				break;      
			// ����϶������������ָ��λ�ã���pos��ֵΪnPos��ֵ   
			case SB_THUMBPOSITION:    
				CTMC_LungOpacity_pos = nPos;    
				break;    
			// �����m_horiScrollbar.SetScrollPos(pos);ִ��ʱ��ڶ��ν���˺���������ȷ��������λ�ã����һ�ֱ�ӵ�default��֧�������ڴ˴����ñ༭������ʾ��ֵ   
			default:    
				SetDlgItemInt(IDC_STATIC_CTMCProp_LungOpacity,CTMC_LungOpacity_pos);   
				return;    
		}    
  
		// ���ù�����λ��   
		pScrollBar->SetScrollPos(CTMC_LungOpacity_pos);   

		CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	}
	else if(pScrollBar->GetDlgCtrlID() == IDC_SCROLLBAR_CTMCProp_InterCT)//���ڲ���ֵ
	{
		CTMC_InterCT_pos = pScrollBar->GetScrollPos();    // ��ȡˮƽ��������ǰλ��   
  
		switch (nSBCode)    
		{    
			// ����������һ�У���pos��1   
			case SB_LINEUP:    
				CTMC_InterCT_pos -= 1;    
				break;    
			// ������ҹ���һ�У���pos��1   
			case SB_LINEDOWN:    
				CTMC_InterCT_pos  += 1;    
				break;    
			// ����������һҳ����pos��10   
			case SB_PAGEUP:    
				CTMC_InterCT_pos -= 10;    
				break;    
			// ������ҹ���һҳ����pos��10   
			case SB_PAGEDOWN:    
				CTMC_InterCT_pos  += 10;    
				break;    
			// �������������ˣ���posΪ1   
			case SB_TOP:    
				CTMC_InterCT_pos = 1;    
				break;    
			// ������������Ҷˣ���posΪ100   
			case SB_BOTTOM:    
				CTMC_InterCT_pos = 100;    
				break;      
			// ����϶������������ָ��λ�ã���pos��ֵΪnPos��ֵ   
			case SB_THUMBPOSITION:    
				CTMC_InterCT_pos = nPos;    
				break;    
			// �����m_horiScrollbar.SetScrollPos(pos);ִ��ʱ��ڶ��ν���˺���������ȷ��������λ�ã����һ�ֱ�ӵ�default��֧�������ڴ˴����ñ༭������ʾ��ֵ   
			default:    
				SetDlgItemInt(IDC_STATIC_CTMCProp_InterCT,CTMC_InterCT_pos);   
				return;    
		}    
  
		// ���ù�����λ��   
		pScrollBar->SetScrollPos(CTMC_InterCT_pos);   

		CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	}
	else if(pScrollBar->GetDlgCtrlID() == IDC_SCROLLBAR_CTMCProp_InterSmooth)//���ڲ�ƽ����������
	{
		CTMC_InterSmooth_pos = pScrollBar->GetScrollPos();    // ��ȡˮƽ��������ǰλ��   
  
		switch (nSBCode)    
		{    
			// ����������һ�У���pos��1   
			case SB_LINEUP:    
				CTMC_InterSmooth_pos -= 1;    
				break;    
			// ������ҹ���һ�У���pos��1   
			case SB_LINEDOWN:    
				CTMC_InterSmooth_pos  += 1;    
				break;    
			// ����������һҳ����pos��10   
			case SB_PAGEUP:    
				CTMC_InterSmooth_pos -= 10;    
				break;    
			// ������ҹ���һҳ����pos��10   
			case SB_PAGEDOWN:    
				CTMC_InterSmooth_pos  += 10;    
				break;    
			// �������������ˣ���posΪ1   
			case SB_TOP:    
				CTMC_InterSmooth_pos = 1;    
				break;    
			// ������������Ҷˣ���posΪ100   
			case SB_BOTTOM:    
				CTMC_InterSmooth_pos = 100;    
				break;      
			// ����϶������������ָ��λ�ã���pos��ֵΪnPos��ֵ   
			case SB_THUMBPOSITION:    
				CTMC_InterSmooth_pos = nPos;    
				break;    
			// �����m_horiScrollbar.SetScrollPos(pos);ִ��ʱ��ڶ��ν���˺���������ȷ��������λ�ã����һ�ֱ�ӵ�default��֧�������ڴ˴����ñ༭������ʾ��ֵ   
			default:    
				SetDlgItemInt(IDC_STATIC_CTMCProp_InterSmooth,CTMC_InterSmooth_pos);   
				return;    
		}    
  
		// ���ù�����λ��   
		pScrollBar->SetScrollPos(CTMC_InterSmooth_pos);   

		CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	}
	else if(pScrollBar->GetDlgCtrlID() == IDC_SCROLLBAR_CTMCProp_InterR)//���ڲ���ɫR
	{
		CTMC_InterR_pos = pScrollBar->GetScrollPos();    // ��ȡˮƽ��������ǰλ��   
  
		switch (nSBCode)    
		{    
			// ����������һ�У���pos��1   
			case SB_LINEUP:    
				CTMC_InterR_pos -= 1;    
				break;    
			// ������ҹ���һ�У���pos��1   
			case SB_LINEDOWN:    
				CTMC_InterR_pos  += 1;    
				break;    
			// ����������һҳ����pos��10   
			case SB_PAGEUP:    
				CTMC_InterR_pos -= 10;    
				break;    
			// ������ҹ���һҳ����pos��10   
			case SB_PAGEDOWN:    
				CTMC_InterR_pos  += 10;    
				break;    
			// �������������ˣ���posΪ1   
			case SB_TOP:    
				CTMC_InterR_pos = 1;    
				break;    
			// ������������Ҷˣ���posΪ100   
			case SB_BOTTOM:    
				CTMC_InterR_pos = 100;    
				break;      
			// ����϶������������ָ��λ�ã���pos��ֵΪnPos��ֵ   
			case SB_THUMBPOSITION:    
				CTMC_InterR_pos = nPos;    
				break;    
			// �����m_horiScrollbar.SetScrollPos(pos);ִ��ʱ��ڶ��ν���˺���������ȷ��������λ�ã����һ�ֱ�ӵ�default��֧�������ڴ˴����ñ༭������ʾ��ֵ   
			default:    
				SetDlgItemInt(IDC_STATIC_CTMCProp_InterR,CTMC_InterR_pos);   
				return;    
		}    
  
		// ���ù�����λ��   
		pScrollBar->SetScrollPos(CTMC_InterR_pos);   

		CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	}
	else if(pScrollBar->GetDlgCtrlID() == IDC_SCROLLBAR_CTMCProp_InterG)//���ڲ���ɫG
	{
		CTMC_InterG_pos = pScrollBar->GetScrollPos();    // ��ȡˮƽ��������ǰλ��   
  
		switch (nSBCode)    
		{    
			// ����������һ�У���pos��1   
			case SB_LINEUP:    
				CTMC_InterG_pos -= 1;    
				break;    
			// ������ҹ���һ�У���pos��1   
			case SB_LINEDOWN:    
				CTMC_InterG_pos  += 1;    
				break;    
			// ����������һҳ����pos��10   
			case SB_PAGEUP:    
				CTMC_InterG_pos -= 10;    
				break;    
			// ������ҹ���һҳ����pos��10   
			case SB_PAGEDOWN:    
				CTMC_InterG_pos  += 10;    
				break;    
			// �������������ˣ���posΪ1   
			case SB_TOP:    
				CTMC_InterG_pos = 1;    
				break;    
			// ������������Ҷˣ���posΪ100   
			case SB_BOTTOM:    
				CTMC_InterG_pos = 100;    
				break;      
			// ����϶������������ָ��λ�ã���pos��ֵΪnPos��ֵ   
			case SB_THUMBPOSITION:    
				CTMC_InterG_pos = nPos;    
				break;    
			// �����m_horiScrollbar.SetScrollPos(pos);ִ��ʱ��ڶ��ν���˺���������ȷ��������λ�ã����һ�ֱ�ӵ�default��֧�������ڴ˴����ñ༭������ʾ��ֵ   
			default:    
				SetDlgItemInt(IDC_STATIC_CTMCProp_InterG,CTMC_InterG_pos);   
				return;    
		}    
  
		// ���ù�����λ��   
		pScrollBar->SetScrollPos(CTMC_InterG_pos);   

		CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	}
	else if(pScrollBar->GetDlgCtrlID() == IDC_SCROLLBAR_CTMCProp_InterB)//���ڲ���ɫB
	{
		CTMC_InterB_pos = pScrollBar->GetScrollPos();    // ��ȡˮƽ��������ǰλ��   
  
		switch (nSBCode)    
		{    
			// ����������һ�У���pos��1   
			case SB_LINEUP:    
				CTMC_InterB_pos -= 1;    
				break;    
			// ������ҹ���һ�У���pos��1   
			case SB_LINEDOWN:    
				CTMC_InterB_pos  += 1;    
				break;    
			// ����������һҳ����pos��10   
			case SB_PAGEUP:    
				CTMC_InterB_pos -= 10;    
				break;    
			// ������ҹ���һҳ����pos��10   
			case SB_PAGEDOWN:    
				CTMC_InterB_pos  += 10;    
				break;    
			// �������������ˣ���posΪ1   
			case SB_TOP:    
				CTMC_InterB_pos = 1;    
				break;    
			// ������������Ҷˣ���posΪ100   
			case SB_BOTTOM:    
				CTMC_InterB_pos = 100;    
				break;      
			// ����϶������������ָ��λ�ã���pos��ֵΪnPos��ֵ   
			case SB_THUMBPOSITION:    
				CTMC_InterB_pos = nPos;    
				break;    
			// �����m_horiScrollbar.SetScrollPos(pos);ִ��ʱ��ڶ��ν���˺���������ȷ��������λ�ã����һ�ֱ�ӵ�default��֧�������ڴ˴����ñ༭������ʾ��ֵ   
			default:    
				SetDlgItemInt(IDC_STATIC_CTMCProp_InterB,CTMC_InterB_pos);   
				return;    
		}    
  
		// ���ù�����λ��   
		pScrollBar->SetScrollPos(CTMC_InterB_pos);   

		CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	}
	else if(pScrollBar->GetDlgCtrlID() == IDC_SCROLLBAR_CTMCProp_InterOpacity)//���ڲ�͸����
	{
		CTMC_InterOpacity_pos = pScrollBar->GetScrollPos();    // ��ȡˮƽ��������ǰλ��   
  
		switch (nSBCode)    
		{    
			// ����������һ�У���pos��1   
			case SB_LINEUP:    
				CTMC_InterOpacity_pos -= 1;    
				break;    
			// ������ҹ���һ�У���pos��1   
			case SB_LINEDOWN:    
				CTMC_InterOpacity_pos  += 1;    
				break;    
			// ����������һҳ����pos��10   
			case SB_PAGEUP:    
				CTMC_InterOpacity_pos -= 10;    
				break;    
			// ������ҹ���һҳ����pos��10   
			case SB_PAGEDOWN:    
				CTMC_InterOpacity_pos  += 10;    
				break;    
			// �������������ˣ���posΪ1   
			case SB_TOP:    
				CTMC_InterOpacity_pos = 1;    
				break;    
			// ������������Ҷˣ���posΪ100   
			case SB_BOTTOM:    
				CTMC_InterOpacity_pos = 100;    
				break;      
			// ����϶������������ָ��λ�ã���pos��ֵΪnPos��ֵ   
			case SB_THUMBPOSITION:    
				CTMC_InterOpacity_pos = nPos;    
				break;    
			// �����m_horiScrollbar.SetScrollPos(pos);ִ��ʱ��ڶ��ν���˺���������ȷ��������λ�ã����һ�ֱ�ӵ�default��֧�������ڴ˴����ñ༭������ʾ��ֵ   
			default:    
				SetDlgItemInt(IDC_STATIC_CTMCProp_InterOpacity,CTMC_InterOpacity_pos);   
				return;    
		}    
  
		// ���ù�����λ��   
		pScrollBar->SetScrollPos(CTMC_InterOpacity_pos);   

		CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	}
	else if(pScrollBar->GetDlgCtrlID() == IDC_SCROLLBAR_CTMCProp_Ambient)//������ϵ��
	{
		CTMC_Ambient_pos = pScrollBar->GetScrollPos();    // ��ȡˮƽ��������ǰλ��   
  
		switch (nSBCode)    
		{    
			// ����������һ�У���pos��1   
			case SB_LINEUP:    
				CTMC_Ambient_pos -= 1;    
				break;    
			// ������ҹ���һ�У���pos��1   
			case SB_LINEDOWN:    
				CTMC_Ambient_pos  += 1;    
				break;    
			// ����������һҳ����pos��10   
			case SB_PAGEUP:    
				CTMC_Ambient_pos -= 10;    
				break;    
			// ������ҹ���һҳ����pos��10   
			case SB_PAGEDOWN:    
				CTMC_Ambient_pos  += 10;    
				break;    
			// �������������ˣ���posΪ1   
			case SB_TOP:    
				CTMC_Ambient_pos = 1;    
				break;    
			// ������������Ҷˣ���posΪ100   
			case SB_BOTTOM:    
				CTMC_Ambient_pos = 100;    
				break;      
			// ����϶������������ָ��λ�ã���pos��ֵΪnPos��ֵ   
			case SB_THUMBPOSITION:    
				CTMC_Ambient_pos = nPos;    
				break;    
			// �����m_horiScrollbar.SetScrollPos(pos);ִ��ʱ��ڶ��ν���˺���������ȷ��������λ�ã����һ�ֱ�ӵ�default��֧�������ڴ˴����ñ༭������ʾ��ֵ   
			default:    
				SetDlgItemInt(IDC_STATIC_CTMCProp_Ambient,CTMC_Ambient_pos);   
				return;    
		}    
  
		// ���ù�����λ��   
		pScrollBar->SetScrollPos(CTMC_Ambient_pos);   

		CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	}
	else if(pScrollBar->GetDlgCtrlID() == IDC_SCROLLBAR_CTMCProp_Diffuse)//�����ϵ��
	{
		CTMC_Diffuse_pos = pScrollBar->GetScrollPos();    // ��ȡˮƽ��������ǰλ��   
  
		switch (nSBCode)    
		{    
			// ����������һ�У���pos��1   
			case SB_LINEUP:    
				CTMC_Diffuse_pos -= 1;    
				break;    
			// ������ҹ���һ�У���pos��1   
			case SB_LINEDOWN:    
				CTMC_Diffuse_pos  += 1;    
				break;    
			// ����������һҳ����pos��10   
			case SB_PAGEUP:    
				CTMC_Diffuse_pos -= 10;    
				break;    
			// ������ҹ���һҳ����pos��10   
			case SB_PAGEDOWN:    
				CTMC_Diffuse_pos  += 10;    
				break;    
			// �������������ˣ���posΪ1   
			case SB_TOP:    
				CTMC_Diffuse_pos = 1;    
				break;    
			// ������������Ҷˣ���posΪ100   
			case SB_BOTTOM:    
				CTMC_Diffuse_pos = 100;    
				break;      
			// ����϶������������ָ��λ�ã���pos��ֵΪnPos��ֵ   
			case SB_THUMBPOSITION:    
				CTMC_Diffuse_pos = nPos;    
				break;    
			// �����m_horiScrollbar.SetScrollPos(pos);ִ��ʱ��ڶ��ν���˺���������ȷ��������λ�ã����һ�ֱ�ӵ�default��֧�������ڴ˴����ñ༭������ʾ��ֵ   
			default:    
				SetDlgItemInt(IDC_STATIC_CTMCProp_Diffuse,CTMC_Diffuse_pos);   
				return;    
		}    
  
		// ���ù�����λ��   
		pScrollBar->SetScrollPos(CTMC_Diffuse_pos);   

		CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	}
	else if(pScrollBar->GetDlgCtrlID() == IDC_SCROLLBAR_CTMCProp_Specular)//�����ϵ��
	{
		CTMC_Specular_pos = pScrollBar->GetScrollPos();    // ��ȡˮƽ��������ǰλ��   
  
		switch (nSBCode)    
		{    
			// ����������һ�У���pos��1   
			case SB_LINEUP:    
				CTMC_Specular_pos -= 1;    
				break;    
			// ������ҹ���һ�У���pos��1   
			case SB_LINEDOWN:    
				CTMC_Specular_pos  += 1;    
				break;    
			// ����������һҳ����pos��10   
			case SB_PAGEUP:    
				CTMC_Specular_pos -= 10;    
				break;    
			// ������ҹ���һҳ����pos��10   
			case SB_PAGEDOWN:    
				CTMC_Specular_pos  += 10;    
				break;    
			// �������������ˣ���posΪ1   
			case SB_TOP:    
				CTMC_Specular_pos = 1;    
				break;    
			// ������������Ҷˣ���posΪ100   
			case SB_BOTTOM:    
				CTMC_Specular_pos = 100;    
				break;      
			// ����϶������������ָ��λ�ã���pos��ֵΪnPos��ֵ   
			case SB_THUMBPOSITION:    
				CTMC_Specular_pos = nPos;    
				break;    
			// �����m_horiScrollbar.SetScrollPos(pos);ִ��ʱ��ڶ��ν���˺���������ȷ��������λ�ã����һ�ֱ�ӵ�default��֧�������ڴ˴����ñ༭������ʾ��ֵ   
			default:    
				SetDlgItemInt(IDC_STATIC_CTMCProp_Specular,CTMC_Specular_pos);   
				return;    
		}    
  
		// ���ù�����λ��   
		pScrollBar->SetScrollPos(CTMC_Specular_pos);   

		CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	}
	else if(pScrollBar->GetDlgCtrlID() == IDC_SCROLLBAR_CTMCProp_SpecularPower)//�����ǿ��
	{
		CTMC_SpecularPower_pos = pScrollBar->GetScrollPos();    // ��ȡˮƽ��������ǰλ��   
  
		switch (nSBCode)    
		{    
			// ����������һ�У���pos��1   
			case SB_LINEUP:    
				CTMC_SpecularPower_pos -= 1;    
				break;    
			// ������ҹ���һ�У���pos��1   
			case SB_LINEDOWN:    
				CTMC_SpecularPower_pos  += 1;    
				break;    
			// ����������һҳ����pos��10   
			case SB_PAGEUP:    
				CTMC_SpecularPower_pos -= 10;    
				break;    
			// ������ҹ���һҳ����pos��10   
			case SB_PAGEDOWN:    
				CTMC_SpecularPower_pos  += 10;    
				break;    
			// �������������ˣ���posΪ1   
			case SB_TOP:    
				CTMC_SpecularPower_pos = 1;    
				break;    
			// ������������Ҷˣ���posΪ100   
			case SB_BOTTOM:    
				CTMC_SpecularPower_pos = 100;    
				break;      
			// ����϶������������ָ��λ�ã���pos��ֵΪnPos��ֵ   
			case SB_THUMBPOSITION:    
				CTMC_SpecularPower_pos = nPos;    
				break;    
			// �����m_horiScrollbar.SetScrollPos(pos);ִ��ʱ��ڶ��ν���˺���������ȷ��������λ�ã����һ�ֱ�ӵ�default��֧�������ڴ˴����ñ༭������ʾ��ֵ   
			default:    
				SetDlgItemInt(IDC_STATIC_CTMCProp_SpecularPower,CTMC_SpecularPower_pos);   
				return;    
		}    
  
		// ���ù�����λ��   
		pScrollBar->SetScrollPos(CTMC_SpecularPower_pos);   

		CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	}


	
}
