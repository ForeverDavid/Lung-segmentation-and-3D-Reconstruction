#pragma once
#include "afxwin.h"
#include "Macro.h"


// CCTMCPropertyDlg �Ի���

class CCTMCPropertyDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCTMCPropertyDlg)

public:
	CCTMCPropertyDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CCTMCPropertyDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_CT_MC_Property };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_strCaption;//�Ի������

	CScrollBar m_scrollbar_CTMCProp_LungCT;  //CT��������ԶԻ������ֵ������
	CScrollBar m_scrollbar_CTMCProp_LungSmooth;//CT��������ԶԻ����ƽ����������������
	CScrollBar m_scrollbar_CTMCProp_LungR;//CT��������ԶԻ������ɫR������
	CScrollBar m_scrollbar_CTMCProp_LungG;//CT��������ԶԻ������ɫG������
	CScrollBar m_scrollbar_CTMCProp_LungB;//CT��������ԶԻ������ɫB������
	CScrollBar m_scrollbar_CTMCProp_LungOpacity;//CT��������ԶԻ����͸���ȹ�����

	CScrollBar m_scrollbar_CTMCProp_InterCT;//CT��������ԶԻ�����ڲ���ֵ������
	CScrollBar m_scrollbar_CTMCProp_InterSmooth;//CT��������ԶԻ�����ڲ�ƽ����������������
	CScrollBar m_scrollbar_CTMCProp_InterR;//CT��������ԶԻ�����ڲ���ɫR������
	CScrollBar m_scrollbar_CTMCProp_InterG;//CT��������ԶԻ�����ڲ���ɫG������
	CScrollBar m_scrollbar_CTMCProp_InterB;//CT��������ԶԻ�����ڲ���ɫB������
	CScrollBar m_scrollbar_CTMCProp_InterOpacity;//CT��������ԶԻ�����ڲ�͸���ȹ�����

	CScrollBar m_scrollbar_CTMCProp_Ambient;//CT��������ԶԻ��򻷾���ϵ��������
	CScrollBar m_scrollbar_CTMCProp_Diffuse;//CT��������ԶԻ��������ϵ��������
	CScrollBar m_scrollbar_CTMCProp_Specular;//CT��������ԶԻ������ϵ��������
	CScrollBar m_scrollbar_CTMCProp_SpecularPower;//CT��������ԶԻ������ǿ�ȹ�����
public:
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

	afx_msg void OnPaint();
	afx_msg void OnBnClickedRadioCtmcpropMc();
	afx_msg void OnBnClickedRadioCtmcpropAccmc();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
};
