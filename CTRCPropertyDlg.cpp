// CTRCPropertyDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ITK+VTK+MFC_GUI.h"
#include "CTRCPropertyDlg.h"
#include "afxdialogex.h"


// CCTRCPropertyDlg �Ի���

IMPLEMENT_DYNAMIC(CCTRCPropertyDlg, CDialogEx)

CCTRCPropertyDlg::CCTRCPropertyDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCTRCPropertyDlg::IDD, pParent)
{
	/*CTRC_Style = RC;//Ĭ���������RC

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
	CTRC_SpecularPower_pos = 20;*/

}

CCTRCPropertyDlg::~CCTRCPropertyDlg()
{
}

void CCTRCPropertyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SCROLLBAR_CTRCProp_LungCT, m_scrollbar_CTRCProp_LungCT);
	DDX_Control(pDX, IDC_SCROLLBAR_CTRCProp_LungR, m_scrollbar_CTRCProp_LungR);
	DDX_Control(pDX, IDC_SCROLLBAR_CTRCProp_LungG, m_scrollbar_CTRCProp_LungG);
	DDX_Control(pDX, IDC_SCROLLBAR_CTRCProp_LungB, m_scrollbar_CTRCProp_LungB);
	DDX_Control(pDX, IDC_SCROLLBAR_CTRCProp_LungOpacity, m_scrollbar_CTRCProp_LungOpacity);
	DDX_Control(pDX, IDC_SCROLLBAR_CTRCProp_InterCT, m_scrollbar_CTRCProp_InterCT);
	DDX_Control(pDX, IDC_SCROLLBAR_CTRCProp_InterR, m_scrollbar_CTRCProp_InterR);
	DDX_Control(pDX, IDC_SCROLLBAR_CTRCProp_InterG, m_scrollbar_CTRCProp_InterG);
	DDX_Control(pDX, IDC_SCROLLBAR_CTRCProp_InterB, m_scrollbar_CTRCProp_InterB);
	DDX_Control(pDX, IDC_SCROLLBAR_CTRCProp_InterOpacity, m_scrollbar_CTRCProp_InterOpacity);
	DDX_Control(pDX, IDC_SCROLLBAR_CTRCProp_Ambient, m_scrollbar_CTRCProp_Ambient);
	DDX_Control(pDX, IDC_SCROLLBAR_CTRCProp_Diffuse, m_scrollbar_CTRCProp_Diffuse);
	DDX_Control(pDX, IDC_SCROLLBAR_CTRCProp_Specular, m_scrollbar_CTRCProp_Specular);
	DDX_Control(pDX, IDC_SCROLLBAR_CTRCProp_SpecularPower, m_scrollbar_CTRCProp_SpecularPower);
}


BEGIN_MESSAGE_MAP(CCTRCPropertyDlg, CDialogEx)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_RADIO_CTRCProp_RC, &CCTRCPropertyDlg::OnBnClickedRadioCtrcpropRc)
	ON_BN_CLICKED(IDC_RADIO_CTRCProp_FixRC, &CCTRCPropertyDlg::OnBnClickedRadioCtrcpropFixrc)
	ON_WM_HSCROLL()
END_MESSAGE_MAP()


// CCTRCPropertyDlg ��Ϣ�������


void CCTRCPropertyDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()

	//��ʼ��
	//���öԻ������
	SetWindowText(m_strCaption);

	// ���÷���ֵˮƽ�������Ĺ�����ΧΪ0��255   
    m_scrollbar_CTRCProp_LungCT.SetScrollRange(0, 255);   
    // ����ˮƽ�������ĳ�ʼλ��Ϊ140   
    m_scrollbar_CTRCProp_LungCT.SetScrollPos(CTRC_LungCT_pos);   
    // �ڱ༭������ʾ140   
    SetDlgItemInt(IDC_STATIC_CTRCProp_LungCT, CTRC_LungCT_pos); 

	// ���÷���ɫRˮƽ�������Ĺ�����ΧΪ0��100 
    m_scrollbar_CTRCProp_LungR.SetScrollRange(0, 100);   
    // ����ˮƽ�������ĳ�ʼλ��Ϊ100  
    m_scrollbar_CTRCProp_LungR.SetScrollPos(CTRC_LungR_pos);   
    // �ڱ༭������ʾ100   
    SetDlgItemInt(IDC_STATIC_CTRCProp_LungR, CTRC_LungR_pos); 

	// ���÷���ɫGˮƽ�������Ĺ�����ΧΪ0��100 
    m_scrollbar_CTRCProp_LungG.SetScrollRange(0, 100);   
    // ����ˮƽ�������ĳ�ʼλ��Ϊ19  
    m_scrollbar_CTRCProp_LungG.SetScrollPos(CTRC_LungG_pos);   
    // �ڱ༭������ʾ19   
    SetDlgItemInt(IDC_STATIC_CTRCProp_LungG, CTRC_LungG_pos); 

	// ���÷���ɫBˮƽ�������Ĺ�����ΧΪ0��100 
    m_scrollbar_CTRCProp_LungB.SetScrollRange(0, 100);   
    // ����ˮƽ�������ĳ�ʼλ��Ϊ15  
    m_scrollbar_CTRCProp_LungB.SetScrollPos(CTRC_LungB_pos);   
    // �ڱ༭������ʾ15   
    SetDlgItemInt(IDC_STATIC_CTRCProp_LungB, CTRC_LungB_pos); 

	// ���÷�͸����ˮƽ�������Ĺ�����ΧΪ0��100 
    m_scrollbar_CTRCProp_LungOpacity.SetScrollRange(0, 100);   
    // ����ˮƽ�������ĳ�ʼλ��Ϊ100  
    m_scrollbar_CTRCProp_LungOpacity.SetScrollPos(CTRC_LungOpacity_pos);   
    // �ڱ༭������ʾ100   
    SetDlgItemInt(IDC_STATIC_CTRCProp_LungOpacity, CTRC_LungOpacity_pos); 


	// ���÷��ڲ���ֵˮƽ�������Ĺ�����ΧΪ0��255  
    m_scrollbar_CTRCProp_InterCT.SetScrollRange(0, 255);   
    // ����ˮƽ�������ĳ�ʼλ��Ϊ170   
    m_scrollbar_CTRCProp_InterCT.SetScrollPos(CTRC_InterCT_pos);   
    // �ڱ༭������ʾ170   
    SetDlgItemInt(IDC_STATIC_CTRCProp_InterCT, CTRC_InterCT_pos); 

	// ���÷��ڲ���ɫRˮƽ�������Ĺ�����ΧΪ0��100 
    m_scrollbar_CTRCProp_InterR.SetScrollRange(0, 100);   
    // ����ˮƽ�������ĳ�ʼλ��Ϊ100  
    m_scrollbar_CTRCProp_InterR.SetScrollPos(CTRC_InterR_pos);   
    // �ڱ༭������ʾ100   
    SetDlgItemInt(IDC_STATIC_CTRCProp_InterR, CTRC_InterR_pos); 

	// ���÷��ڲ���ɫGˮƽ�������Ĺ�����ΧΪ0��100 
    m_scrollbar_CTRCProp_InterG.SetScrollRange(0, 100);   
    // ����ˮƽ�������ĳ�ʼλ��Ϊ19  
    m_scrollbar_CTRCProp_InterG.SetScrollPos(CTRC_InterG_pos);   
    // �ڱ༭������ʾ19   
    SetDlgItemInt(IDC_STATIC_CTRCProp_InterG, CTRC_InterG_pos); 

	// ���÷��ڲ���ɫBˮƽ�������Ĺ�����ΧΪ0��100 
    m_scrollbar_CTRCProp_InterB.SetScrollRange(0, 100);   
    // ����ˮƽ�������ĳ�ʼλ��Ϊ15  
    m_scrollbar_CTRCProp_InterB.SetScrollPos(CTRC_InterB_pos);   
    // �ڱ༭������ʾ15   
    SetDlgItemInt(IDC_STATIC_CTRCProp_InterB, CTRC_InterB_pos); 

	// ���÷��ڲ�͸����ˮƽ�������Ĺ�����ΧΪ0��100 
    m_scrollbar_CTRCProp_InterOpacity.SetScrollRange(0, 100);   
    // ����ˮƽ�������ĳ�ʼλ��Ϊ100  
    m_scrollbar_CTRCProp_InterOpacity.SetScrollPos(CTRC_InterOpacity_pos);   
    // �ڱ༭������ʾ100   
    SetDlgItemInt(IDC_STATIC_CTRCProp_InterOpacity, CTRC_InterOpacity_pos); 

	// ���÷λ�����ϵ��ˮƽ�������Ĺ�����ΧΪ0��100 
    m_scrollbar_CTRCProp_Ambient.SetScrollRange(0, 100);   
    // ����ˮƽ�������ĳ�ʼλ��Ϊ30  
    m_scrollbar_CTRCProp_Ambient.SetScrollPos(CTRC_Ambient_pos);   
    // �ڱ༭������ʾ30   
    SetDlgItemInt(IDC_STATIC_CTRCProp_Ambient, CTRC_Ambient_pos); 

	// ���÷������ϵ��ˮƽ�������Ĺ�����ΧΪ0��100 
    m_scrollbar_CTRCProp_Diffuse.SetScrollRange(0, 100);   
    // ����ˮƽ�������ĳ�ʼλ��Ϊ60  
    m_scrollbar_CTRCProp_Diffuse.SetScrollPos(CTRC_Diffuse_pos);   
    // �ڱ༭������ʾ60   
    SetDlgItemInt(IDC_STATIC_CTRCProp_Diffuse, CTRC_Diffuse_pos); 

	// ���÷ξ����ϵ��ˮƽ�������Ĺ�����ΧΪ0��100 
    m_scrollbar_CTRCProp_Specular.SetScrollRange(0, 100);   
    // ����ˮƽ�������ĳ�ʼλ��Ϊ20  
    m_scrollbar_CTRCProp_Specular.SetScrollPos(CTRC_Specular_pos);   
    // �ڱ༭������ʾ20   
    SetDlgItemInt(IDC_STATIC_CTRCProp_Specular, CTRC_Specular_pos); 

	// ���÷ξ����ǿ��ˮƽ�������Ĺ�����ΧΪ0��100 
    m_scrollbar_CTRCProp_SpecularPower.SetScrollRange(0, 100);   
    // ����ˮƽ�������ĳ�ʼλ��Ϊ20  
    m_scrollbar_CTRCProp_SpecularPower.SetScrollPos(CTRC_SpecularPower_pos);   
    // �ڱ༭������ʾ20   
    SetDlgItemInt(IDC_STATIC_CTRCProp_SpecularPower, CTRC_SpecularPower_pos); 

	if(CTRC_Style == RC)
	{
		// Ĭ��ѡ�С�RC����ѡ��ť   
		CheckDlgButton(IDC_RADIO_CTRCProp_RC, 1);  
		OnBnClickedRadioCtrcpropRc();
	}
	else if(CTRC_Style == FIX_RC)
	{
		// Ĭ��ѡ�С�FIX_RC����ѡ��ť   
		CheckDlgButton(IDC_RADIO_CTRCProp_FixRC, 1);  
		OnBnClickedRadioCtrcpropFixrc();
	}
	
}


//����RC��ѡ��ť�¼�
void CCTRCPropertyDlg::OnBnClickedRadioCtrcpropRc()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CTRC_Style = RC;  //����CTRC��������ΪRC
}


//�����̶���RC��ѡ��ť�¼�
void CCTRCPropertyDlg::OnBnClickedRadioCtrcpropFixrc()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CTRC_Style = FIX_RC;  //����CTRC��������ΪFIX_RC
}


void CCTRCPropertyDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	// ����CSliderCtrl ID ���ж�����һ��CSliderCtrl
	if(pScrollBar->GetDlgCtrlID() == IDC_SCROLLBAR_CTRCProp_LungCT)  //����ֵ
	{
		CTRC_LungCT_pos = pScrollBar->GetScrollPos();    // ��ȡˮƽ��������ǰλ��   
  
		switch (nSBCode)    
		{    
			// ����������һ�У���pos��1   
			case SB_LINEUP:    
				CTRC_LungCT_pos -= 1;    
				break;    
			// ������ҹ���һ�У���pos��1   
			case SB_LINEDOWN:    
				CTRC_LungCT_pos  += 1;    
				break;    
			// ����������һҳ����pos��10   
			case SB_PAGEUP:    
				CTRC_LungCT_pos -= 10;    
				break;    
			// ������ҹ���һҳ����pos��10   
			case SB_PAGEDOWN:    
				CTRC_LungCT_pos  += 10;    
				break;    
			// �������������ˣ���posΪ1   
			case SB_TOP:    
				CTRC_LungCT_pos = 1;    
				break;    
			// ������������Ҷˣ���posΪ100   
			case SB_BOTTOM:    
				CTRC_LungCT_pos = 100;    
				break;      
			// ����϶������������ָ��λ�ã���pos��ֵΪnPos��ֵ   
			case SB_THUMBPOSITION:    
				CTRC_LungCT_pos = nPos;    
				break;    
			// �����m_horiScrollbar.SetScrollPos(pos);ִ��ʱ��ڶ��ν���˺���������ȷ��������λ�ã����һ�ֱ�ӵ�default��֧�������ڴ˴����ñ༭������ʾ��ֵ   
			default:    
				SetDlgItemInt(IDC_STATIC_CTRCProp_LungCT,CTRC_LungCT_pos);   
				return;    
		}    
  
		// ���ù�����λ��   
		pScrollBar->SetScrollPos(CTRC_LungCT_pos);   

		CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	}
	else if(pScrollBar->GetDlgCtrlID() == IDC_SCROLLBAR_CTRCProp_LungR)//����ɫR
	{
		CTRC_LungR_pos = pScrollBar->GetScrollPos();    // ��ȡˮƽ��������ǰλ��   
  
		switch (nSBCode)    
		{    
			// ����������һ�У���pos��1   
			case SB_LINEUP:    
				CTRC_LungR_pos -= 1;    
				break;    
			// ������ҹ���һ�У���pos��1   
			case SB_LINEDOWN:    
				CTRC_LungR_pos  += 1;    
				break;    
			// ����������һҳ����pos��10   
			case SB_PAGEUP:    
				CTRC_LungR_pos -= 10;    
				break;    
			// ������ҹ���һҳ����pos��10   
			case SB_PAGEDOWN:    
				CTRC_LungR_pos  += 10;    
				break;    
			// �������������ˣ���posΪ1   
			case SB_TOP:    
				CTRC_LungR_pos = 1;    
				break;    
			// ������������Ҷˣ���posΪ100   
			case SB_BOTTOM:    
				CTRC_LungR_pos = 100;    
				break;      
			// ����϶������������ָ��λ�ã���pos��ֵΪnPos��ֵ   
			case SB_THUMBPOSITION:    
				CTRC_LungR_pos = nPos;    
				break;    
			// �����m_horiScrollbar.SetScrollPos(pos);ִ��ʱ��ڶ��ν���˺���������ȷ��������λ�ã����һ�ֱ�ӵ�default��֧�������ڴ˴����ñ༭������ʾ��ֵ   
			default:    
				SetDlgItemInt(IDC_STATIC_CTRCProp_LungR,CTRC_LungR_pos);   
				return;    
		}    
  
		// ���ù�����λ��   
		pScrollBar->SetScrollPos(CTRC_LungR_pos);   

		CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	}
	else if(pScrollBar->GetDlgCtrlID() == IDC_SCROLLBAR_CTRCProp_LungG)//����ɫG
	{
		CTRC_LungG_pos = pScrollBar->GetScrollPos();    // ��ȡˮƽ��������ǰλ��   
  
		switch (nSBCode)    
		{    
			// ����������һ�У���pos��1   
			case SB_LINEUP:    
				CTRC_LungG_pos -= 1;    
				break;    
			// ������ҹ���һ�У���pos��1   
			case SB_LINEDOWN:    
				CTRC_LungG_pos  += 1;    
				break;    
			// ����������һҳ����pos��10   
			case SB_PAGEUP:    
				CTRC_LungG_pos -= 10;    
				break;    
			// ������ҹ���һҳ����pos��10   
			case SB_PAGEDOWN:    
				CTRC_LungG_pos  += 10;    
				break;    
			// �������������ˣ���posΪ1   
			case SB_TOP:    
				CTRC_LungG_pos = 1;    
				break;    
			// ������������Ҷˣ���posΪ100   
			case SB_BOTTOM:    
				CTRC_LungG_pos = 100;    
				break;      
			// ����϶������������ָ��λ�ã���pos��ֵΪnPos��ֵ   
			case SB_THUMBPOSITION:    
				CTRC_LungG_pos = nPos;    
				break;    
			// �����m_horiScrollbar.SetScrollPos(pos);ִ��ʱ��ڶ��ν���˺���������ȷ��������λ�ã����һ�ֱ�ӵ�default��֧�������ڴ˴����ñ༭������ʾ��ֵ   
			default:    
				SetDlgItemInt(IDC_STATIC_CTRCProp_LungG,CTRC_LungG_pos);   
				return;    
		}    
  
		// ���ù�����λ��   
		pScrollBar->SetScrollPos(CTRC_LungG_pos);   

		CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	}
	else if(pScrollBar->GetDlgCtrlID() == IDC_SCROLLBAR_CTRCProp_LungB)//����ɫB
	{
		CTRC_LungB_pos = pScrollBar->GetScrollPos();    // ��ȡˮƽ��������ǰλ��   
  
		switch (nSBCode)    
		{    
			// ����������һ�У���pos��1   
			case SB_LINEUP:    
				CTRC_LungB_pos -= 1;    
				break;    
			// ������ҹ���һ�У���pos��1   
			case SB_LINEDOWN:    
				CTRC_LungB_pos  += 1;    
				break;    
			// ����������һҳ����pos��10   
			case SB_PAGEUP:    
				CTRC_LungB_pos -= 10;    
				break;    
			// ������ҹ���һҳ����pos��10   
			case SB_PAGEDOWN:    
				CTRC_LungB_pos  += 10;    
				break;    
			// �������������ˣ���posΪ1   
			case SB_TOP:    
				CTRC_LungB_pos = 1;    
				break;    
			// ������������Ҷˣ���posΪ100   
			case SB_BOTTOM:    
				CTRC_LungB_pos = 100;    
				break;      
			// ����϶������������ָ��λ�ã���pos��ֵΪnPos��ֵ   
			case SB_THUMBPOSITION:    
				CTRC_LungB_pos = nPos;    
				break;    
			// �����m_horiScrollbar.SetScrollPos(pos);ִ��ʱ��ڶ��ν���˺���������ȷ��������λ�ã����һ�ֱ�ӵ�default��֧�������ڴ˴����ñ༭������ʾ��ֵ   
			default:    
				SetDlgItemInt(IDC_STATIC_CTRCProp_LungB,CTRC_LungB_pos);   
				return;    
		}    
  
		// ���ù�����λ��   
		pScrollBar->SetScrollPos(CTRC_LungB_pos);   

		CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	}
	else if(pScrollBar->GetDlgCtrlID() == IDC_SCROLLBAR_CTRCProp_LungOpacity)//��͸����
	{
		CTRC_LungOpacity_pos = pScrollBar->GetScrollPos();    // ��ȡˮƽ��������ǰλ��   
  
		switch (nSBCode)    
		{    
			// ����������һ�У���pos��1   
			case SB_LINEUP:    
				CTRC_LungOpacity_pos -= 1;    
				break;    
			// ������ҹ���һ�У���pos��1   
			case SB_LINEDOWN:    
				CTRC_LungOpacity_pos  += 1;    
				break;    
			// ����������һҳ����pos��10   
			case SB_PAGEUP:    
				CTRC_LungOpacity_pos -= 10;    
				break;    
			// ������ҹ���һҳ����pos��10   
			case SB_PAGEDOWN:    
				CTRC_LungOpacity_pos  += 10;    
				break;    
			// �������������ˣ���posΪ1   
			case SB_TOP:    
				CTRC_LungOpacity_pos = 1;    
				break;    
			// ������������Ҷˣ���posΪ100   
			case SB_BOTTOM:    
				CTRC_LungOpacity_pos = 100;    
				break;      
			// ����϶������������ָ��λ�ã���pos��ֵΪnPos��ֵ   
			case SB_THUMBPOSITION:    
				CTRC_LungOpacity_pos = nPos;    
				break;    
			// �����m_horiScrollbar.SetScrollPos(pos);ִ��ʱ��ڶ��ν���˺���������ȷ��������λ�ã����һ�ֱ�ӵ�default��֧�������ڴ˴����ñ༭������ʾ��ֵ   
			default:    
				SetDlgItemInt(IDC_STATIC_CTRCProp_LungOpacity,CTRC_LungOpacity_pos);   
				return;    
		}    
  
		// ���ù�����λ��   
		pScrollBar->SetScrollPos(CTRC_LungOpacity_pos);   

		CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	}
	else if(pScrollBar->GetDlgCtrlID() == IDC_SCROLLBAR_CTRCProp_InterCT)//���ڲ���ֵ
	{
		CTRC_InterCT_pos = pScrollBar->GetScrollPos();    // ��ȡˮƽ��������ǰλ��   
  
		switch (nSBCode)    
		{    
			// ����������һ�У���pos��1   
			case SB_LINEUP:    
				CTRC_InterCT_pos -= 1;    
				break;    
			// ������ҹ���һ�У���pos��1   
			case SB_LINEDOWN:    
				CTRC_InterCT_pos  += 1;    
				break;    
			// ����������һҳ����pos��10   
			case SB_PAGEUP:    
				CTRC_InterCT_pos -= 10;    
				break;    
			// ������ҹ���һҳ����pos��10   
			case SB_PAGEDOWN:    
				CTRC_InterCT_pos  += 10;    
				break;    
			// �������������ˣ���posΪ1   
			case SB_TOP:    
				CTRC_InterCT_pos = 1;    
				break;    
			// ������������Ҷˣ���posΪ100   
			case SB_BOTTOM:    
				CTRC_InterCT_pos = 100;    
				break;      
			// ����϶������������ָ��λ�ã���pos��ֵΪnPos��ֵ   
			case SB_THUMBPOSITION:    
				CTRC_InterCT_pos = nPos;    
				break;    
			// �����m_horiScrollbar.SetScrollPos(pos);ִ��ʱ��ڶ��ν���˺���������ȷ��������λ�ã����һ�ֱ�ӵ�default��֧�������ڴ˴����ñ༭������ʾ��ֵ   
			default:    
				SetDlgItemInt(IDC_STATIC_CTRCProp_InterCT,CTRC_InterCT_pos);   
				return;    
		}    
  
		// ���ù�����λ��   
		pScrollBar->SetScrollPos(CTRC_InterCT_pos);   

		CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	}
	else if(pScrollBar->GetDlgCtrlID() == IDC_SCROLLBAR_CTRCProp_InterR)//���ڲ���ɫR
	{
		CTRC_InterR_pos = pScrollBar->GetScrollPos();    // ��ȡˮƽ��������ǰλ��   
  
		switch (nSBCode)    
		{    
			// ����������һ�У���pos��1   
			case SB_LINEUP:    
				CTRC_InterR_pos -= 1;    
				break;    
			// ������ҹ���һ�У���pos��1   
			case SB_LINEDOWN:    
				CTRC_InterR_pos  += 1;    
				break;    
			// ����������һҳ����pos��10   
			case SB_PAGEUP:    
				CTRC_InterR_pos -= 10;    
				break;    
			// ������ҹ���һҳ����pos��10   
			case SB_PAGEDOWN:    
				CTRC_InterR_pos  += 10;    
				break;    
			// �������������ˣ���posΪ1   
			case SB_TOP:    
				CTRC_InterR_pos = 1;    
				break;    
			// ������������Ҷˣ���posΪ100   
			case SB_BOTTOM:    
				CTRC_InterR_pos = 100;    
				break;      
			// ����϶������������ָ��λ�ã���pos��ֵΪnPos��ֵ   
			case SB_THUMBPOSITION:    
				CTRC_InterR_pos = nPos;    
				break;    
			// �����m_horiScrollbar.SetScrollPos(pos);ִ��ʱ��ڶ��ν���˺���������ȷ��������λ�ã����һ�ֱ�ӵ�default��֧�������ڴ˴����ñ༭������ʾ��ֵ   
			default:    
				SetDlgItemInt(IDC_STATIC_CTRCProp_InterR,CTRC_InterR_pos);   
				return;    
		}    
  
		// ���ù�����λ��   
		pScrollBar->SetScrollPos(CTRC_InterR_pos);   

		CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	}
	else if(pScrollBar->GetDlgCtrlID() == IDC_SCROLLBAR_CTRCProp_InterG)//���ڲ���ɫG
	{
		CTRC_InterG_pos = pScrollBar->GetScrollPos();    // ��ȡˮƽ��������ǰλ��   
  
		switch (nSBCode)    
		{    
			// ����������һ�У���pos��1   
			case SB_LINEUP:    
				CTRC_InterG_pos -= 1;    
				break;    
			// ������ҹ���һ�У���pos��1   
			case SB_LINEDOWN:    
				CTRC_InterG_pos  += 1;    
				break;    
			// ����������һҳ����pos��10   
			case SB_PAGEUP:    
				CTRC_InterG_pos -= 10;    
				break;    
			// ������ҹ���һҳ����pos��10   
			case SB_PAGEDOWN:    
				CTRC_InterG_pos  += 10;    
				break;    
			// �������������ˣ���posΪ1   
			case SB_TOP:    
				CTRC_InterG_pos = 1;    
				break;    
			// ������������Ҷˣ���posΪ100   
			case SB_BOTTOM:    
				CTRC_InterG_pos = 100;    
				break;      
			// ����϶������������ָ��λ�ã���pos��ֵΪnPos��ֵ   
			case SB_THUMBPOSITION:    
				CTRC_InterG_pos = nPos;    
				break;    
			// �����m_horiScrollbar.SetScrollPos(pos);ִ��ʱ��ڶ��ν���˺���������ȷ��������λ�ã����һ�ֱ�ӵ�default��֧�������ڴ˴����ñ༭������ʾ��ֵ   
			default:    
				SetDlgItemInt(IDC_STATIC_CTRCProp_InterG,CTRC_InterG_pos);   
				return;    
		}    
  
		// ���ù�����λ��   
		pScrollBar->SetScrollPos(CTRC_InterG_pos);   

		CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	}
	else if(pScrollBar->GetDlgCtrlID() == IDC_SCROLLBAR_CTRCProp_InterB)//���ڲ���ɫB
	{
		CTRC_InterB_pos = pScrollBar->GetScrollPos();    // ��ȡˮƽ��������ǰλ��   
  
		switch (nSBCode)    
		{    
			// ����������һ�У���pos��1   
			case SB_LINEUP:    
				CTRC_InterB_pos -= 1;    
				break;    
			// ������ҹ���һ�У���pos��1   
			case SB_LINEDOWN:    
				CTRC_InterB_pos  += 1;    
				break;    
			// ����������һҳ����pos��10   
			case SB_PAGEUP:    
				CTRC_InterB_pos -= 10;    
				break;    
			// ������ҹ���һҳ����pos��10   
			case SB_PAGEDOWN:    
				CTRC_InterB_pos  += 10;    
				break;    
			// �������������ˣ���posΪ1   
			case SB_TOP:    
				CTRC_InterB_pos = 1;    
				break;    
			// ������������Ҷˣ���posΪ100   
			case SB_BOTTOM:    
				CTRC_InterB_pos = 100;    
				break;      
			// ����϶������������ָ��λ�ã���pos��ֵΪnPos��ֵ   
			case SB_THUMBPOSITION:    
				CTRC_InterB_pos = nPos;    
				break;    
			// �����m_horiScrollbar.SetScrollPos(pos);ִ��ʱ��ڶ��ν���˺���������ȷ��������λ�ã����һ�ֱ�ӵ�default��֧�������ڴ˴����ñ༭������ʾ��ֵ   
			default:    
				SetDlgItemInt(IDC_STATIC_CTRCProp_InterB,CTRC_InterB_pos);   
				return;    
		}    
  
		// ���ù�����λ��   
		pScrollBar->SetScrollPos(CTRC_InterB_pos);   

		CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	}
	else if(pScrollBar->GetDlgCtrlID() == IDC_SCROLLBAR_CTRCProp_InterOpacity)//���ڲ�͸����
	{
		CTRC_InterOpacity_pos = pScrollBar->GetScrollPos();    // ��ȡˮƽ��������ǰλ��   
  
		switch (nSBCode)    
		{    
			// ����������һ�У���pos��1   
			case SB_LINEUP:    
				CTRC_InterOpacity_pos -= 1;    
				break;    
			// ������ҹ���һ�У���pos��1   
			case SB_LINEDOWN:    
				CTRC_InterOpacity_pos  += 1;    
				break;    
			// ����������һҳ����pos��10   
			case SB_PAGEUP:    
				CTRC_InterOpacity_pos -= 10;    
				break;    
			// ������ҹ���һҳ����pos��10   
			case SB_PAGEDOWN:    
				CTRC_InterOpacity_pos  += 10;    
				break;    
			// �������������ˣ���posΪ1   
			case SB_TOP:    
				CTRC_InterOpacity_pos = 1;    
				break;    
			// ������������Ҷˣ���posΪ100   
			case SB_BOTTOM:    
				CTRC_InterOpacity_pos = 100;    
				break;      
			// ����϶������������ָ��λ�ã���pos��ֵΪnPos��ֵ   
			case SB_THUMBPOSITION:    
				CTRC_InterOpacity_pos = nPos;    
				break;    
			// �����m_horiScrollbar.SetScrollPos(pos);ִ��ʱ��ڶ��ν���˺���������ȷ��������λ�ã����һ�ֱ�ӵ�default��֧�������ڴ˴����ñ༭������ʾ��ֵ   
			default:    
				SetDlgItemInt(IDC_STATIC_CTRCProp_InterOpacity,CTRC_InterOpacity_pos);   
				return;    
		}    
  
		// ���ù�����λ��   
		pScrollBar->SetScrollPos(CTRC_InterOpacity_pos);   

		CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	}
	else if(pScrollBar->GetDlgCtrlID() == IDC_SCROLLBAR_CTRCProp_Ambient)//������ϵ��
	{
		CTRC_Ambient_pos = pScrollBar->GetScrollPos();    // ��ȡˮƽ��������ǰλ��   
  
		switch (nSBCode)    
		{    
			// ����������һ�У���pos��1   
			case SB_LINEUP:    
				CTRC_Ambient_pos -= 1;    
				break;    
			// ������ҹ���һ�У���pos��1   
			case SB_LINEDOWN:    
				CTRC_Ambient_pos  += 1;    
				break;    
			// ����������һҳ����pos��10   
			case SB_PAGEUP:    
				CTRC_Ambient_pos -= 10;    
				break;    
			// ������ҹ���һҳ����pos��10   
			case SB_PAGEDOWN:    
				CTRC_Ambient_pos  += 10;    
				break;    
			// �������������ˣ���posΪ1   
			case SB_TOP:    
				CTRC_Ambient_pos = 1;    
				break;    
			// ������������Ҷˣ���posΪ100   
			case SB_BOTTOM:    
				CTRC_Ambient_pos = 100;    
				break;      
			// ����϶������������ָ��λ�ã���pos��ֵΪnPos��ֵ   
			case SB_THUMBPOSITION:    
				CTRC_Ambient_pos = nPos;    
				break;    
			// �����m_horiScrollbar.SetScrollPos(pos);ִ��ʱ��ڶ��ν���˺���������ȷ��������λ�ã����һ�ֱ�ӵ�default��֧�������ڴ˴����ñ༭������ʾ��ֵ   
			default:    
				SetDlgItemInt(IDC_STATIC_CTRCProp_Ambient,CTRC_Ambient_pos);   
				return;    
		}    
  
		// ���ù�����λ��   
		pScrollBar->SetScrollPos(CTRC_Ambient_pos);   

		CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	}
	else if(pScrollBar->GetDlgCtrlID() == IDC_SCROLLBAR_CTRCProp_Diffuse)//�����ϵ��
	{
		CTRC_Diffuse_pos = pScrollBar->GetScrollPos();    // ��ȡˮƽ��������ǰλ��   
  
		switch (nSBCode)    
		{    
			// ����������һ�У���pos��1   
			case SB_LINEUP:    
				CTRC_Diffuse_pos -= 1;    
				break;    
			// ������ҹ���һ�У���pos��1   
			case SB_LINEDOWN:    
				CTRC_Diffuse_pos  += 1;    
				break;    
			// ����������һҳ����pos��10   
			case SB_PAGEUP:    
				CTRC_Diffuse_pos -= 10;    
				break;    
			// ������ҹ���һҳ����pos��10   
			case SB_PAGEDOWN:    
				CTRC_Diffuse_pos  += 10;    
				break;    
			// �������������ˣ���posΪ1   
			case SB_TOP:    
				CTRC_Diffuse_pos = 1;    
				break;    
			// ������������Ҷˣ���posΪ100   
			case SB_BOTTOM:    
				CTRC_Diffuse_pos = 100;    
				break;      
			// ����϶������������ָ��λ�ã���pos��ֵΪnPos��ֵ   
			case SB_THUMBPOSITION:    
				CTRC_Diffuse_pos = nPos;    
				break;    
			// �����m_horiScrollbar.SetScrollPos(pos);ִ��ʱ��ڶ��ν���˺���������ȷ��������λ�ã����һ�ֱ�ӵ�default��֧�������ڴ˴����ñ༭������ʾ��ֵ   
			default:    
				SetDlgItemInt(IDC_STATIC_CTRCProp_Diffuse,CTRC_Diffuse_pos);   
				return;    
		}    
  
		// ���ù�����λ��   
		pScrollBar->SetScrollPos(CTRC_Diffuse_pos);   

		CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	}
	else if(pScrollBar->GetDlgCtrlID() == IDC_SCROLLBAR_CTRCProp_Specular)//�����ϵ��
	{
		CTRC_Specular_pos = pScrollBar->GetScrollPos();    // ��ȡˮƽ��������ǰλ��   
  
		switch (nSBCode)    
		{    
			// ����������һ�У���pos��1   
			case SB_LINEUP:    
				CTRC_Specular_pos -= 1;    
				break;    
			// ������ҹ���һ�У���pos��1   
			case SB_LINEDOWN:    
				CTRC_Specular_pos  += 1;    
				break;    
			// ����������һҳ����pos��10   
			case SB_PAGEUP:    
				CTRC_Specular_pos -= 10;    
				break;    
			// ������ҹ���һҳ����pos��10   
			case SB_PAGEDOWN:    
				CTRC_Specular_pos  += 10;    
				break;    
			// �������������ˣ���posΪ1   
			case SB_TOP:    
				CTRC_Specular_pos = 1;    
				break;    
			// ������������Ҷˣ���posΪ100   
			case SB_BOTTOM:    
				CTRC_Specular_pos = 100;    
				break;      
			// ����϶������������ָ��λ�ã���pos��ֵΪnPos��ֵ   
			case SB_THUMBPOSITION:    
				CTRC_Specular_pos = nPos;    
				break;    
			// �����m_horiScrollbar.SetScrollPos(pos);ִ��ʱ��ڶ��ν���˺���������ȷ��������λ�ã����һ�ֱ�ӵ�default��֧�������ڴ˴����ñ༭������ʾ��ֵ   
			default:    
				SetDlgItemInt(IDC_STATIC_CTRCProp_Specular,CTRC_Specular_pos);   
				return;    
		}    
  
		// ���ù�����λ��   
		pScrollBar->SetScrollPos(CTRC_Specular_pos);   

		CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	}
	else if(pScrollBar->GetDlgCtrlID() == IDC_SCROLLBAR_CTRCProp_SpecularPower)//�����ǿ��
	{
		CTRC_SpecularPower_pos = pScrollBar->GetScrollPos();    // ��ȡˮƽ��������ǰλ��   
  
		switch (nSBCode)    
		{    
			// ����������һ�У���pos��1   
			case SB_LINEUP:    
				CTRC_SpecularPower_pos -= 1;    
				break;    
			// ������ҹ���һ�У���pos��1   
			case SB_LINEDOWN:    
				CTRC_SpecularPower_pos  += 1;    
				break;    
			// ����������һҳ����pos��10   
			case SB_PAGEUP:    
				CTRC_SpecularPower_pos -= 10;    
				break;    
			// ������ҹ���һҳ����pos��10   
			case SB_PAGEDOWN:    
				CTRC_SpecularPower_pos  += 10;    
				break;    
			// �������������ˣ���posΪ1   
			case SB_TOP:    
				CTRC_SpecularPower_pos = 1;    
				break;    
			// ������������Ҷˣ���posΪ100   
			case SB_BOTTOM:    
				CTRC_SpecularPower_pos = 100;    
				break;      
			// ����϶������������ָ��λ�ã���pos��ֵΪnPos��ֵ   
			case SB_THUMBPOSITION:    
				CTRC_SpecularPower_pos = nPos;    
				break;    
			// �����m_horiScrollbar.SetScrollPos(pos);ִ��ʱ��ڶ��ν���˺���������ȷ��������λ�ã����һ�ֱ�ӵ�default��֧�������ڴ˴����ñ༭������ʾ��ֵ   
			default:    
				SetDlgItemInt(IDC_STATIC_CTRCProp_SpecularPower,CTRC_SpecularPower_pos);   
				return;    
		}    
  
		// ���ù�����λ��   
		pScrollBar->SetScrollPos(CTRC_SpecularPower_pos);   

		CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	}
}
