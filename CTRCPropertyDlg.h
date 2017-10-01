#pragma once
#include "afxwin.h"
#include "Macro.h"

// CCTRCPropertyDlg �Ի���

class CCTRCPropertyDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCTRCPropertyDlg)

public:
	CCTRCPropertyDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CCTRCPropertyDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_CT_RC_Property };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_strCaption;//���öԻ������

	CScrollBar m_scrollbar_CTRCProp_LungCT;//CT��������ԶԻ������ֵ������
	CScrollBar m_scrollbar_CTRCProp_LungR;//��ɫR
	CScrollBar m_scrollbar_CTRCProp_LungG;//��ɫG
	CScrollBar m_scrollbar_CTRCProp_LungB;//��ɫB
	CScrollBar m_scrollbar_CTRCProp_LungOpacity;//͸����


	CScrollBar m_scrollbar_CTRCProp_InterCT;//CT��������ԶԻ�����ڲ���ֵ������
	CScrollBar m_scrollbar_CTRCProp_InterR;//��ɫR
	CScrollBar m_scrollbar_CTRCProp_InterG;//��ɫG
	CScrollBar m_scrollbar_CTRCProp_InterB;//��ɫB
	CScrollBar m_scrollbar_CTRCProp_InterOpacity;//͸����

	CScrollBar m_scrollbar_CTRCProp_Ambient;//CT��������ԶԻ��򻷾���ϵ��������
	CScrollBar m_scrollbar_CTRCProp_Diffuse;//�����ϵ��
	CScrollBar m_scrollbar_CTRCProp_Specular;//�����ϵ��
	CScrollBar m_scrollbar_CTRCProp_SpecularPower;//�����ǿ��

public:
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

	int CTRC_Ambient_pos;//CTRC������ϵ��������λ��
	int CTRC_Diffuse_pos;//CTRC�����ϵ��������λ��
	int CTRC_Specular_pos;//CTRC�����ϵ��������λ��
	int CTRC_SpecularPower_pos;//CTRC�����ǿ�ȹ�����λ��

	afx_msg void OnPaint();
	afx_msg void OnBnClickedRadioCtrcpropRc();
	afx_msg void OnBnClickedRadioCtrcpropFixrc();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
};
