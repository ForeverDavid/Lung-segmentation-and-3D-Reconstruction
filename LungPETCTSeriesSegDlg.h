#pragma once
#include "afxwin.h"
#include "Global.h"


// CLungPETCTSeriesSegDlg �Ի���

class CLungPETCTSeriesSegDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CLungPETCTSeriesSegDlg)

public:
	CLungPETCTSeriesSegDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CLungPETCTSeriesSegDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_LungPETCT_SeriesSeg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString strInitCT;   //���ѡ��ĳ�˴��ָ��CT�ļ���·��
	CString strInitPET;   //���ѡ����˴��ָ��PET�ļ���·��

	CString strSegCT;   //��Ŵ洢�������зָ���CT�ļ���·��
	CString strSegPET;   //��Ŵ洢�������зָ���PET�ļ���·��

	CString strPETCTSeriesSeg;   //��ŷβ�PET-CT���зָ�����״̬
	
public:
	//==============�β�PET-CT���зָ�����뺯������========================

	typedef struct QNode   //���н��
	{
		int x;//ͼ��x��������
		int y;//ͼ��y��������
		struct QNode *next;
	}QNode,*QueuePtr;

	typedef struct
	{
		QNode *front;//����ͷ
		QNode *rear;//����β
	}LinkQueue;

	bool flag[1000][1000];    //ͼ��ÿ�����ص��Ƿ񱻷��ʱ�־

	void InitQueue(LinkQueue &Q);  //���г�ʼ��

	bool IsEmpty(LinkQueue Q);//�����п�

	void EnQueue(LinkQueue &Q,int x,int y);//���

	bool DeQueue(LinkQueue &Q,int &x,int &y);//����

	int LungPET_CTSeriesSeg();//�β�PET-CT���зָ�

	//======================================================================

public:
	afx_msg void OnPaint();
	CEdit m_editInitCT; //ѡ��ĳ�˴��ָ��CT�ļ����ı��༭�����
	CEdit m_editInitPET;//ѡ����˴��ָ��PET�ļ����ı��༭�����
	CEdit m_editSegCT;//�洢�������зָ���CT�ļ����ı��༭�����
	CEdit m_editSegPET;//�洢�������зָ���PET�ļ����ı��༭�����
	CEdit m_editPETCTSeriesSeg_View;//�β�PET-CT���зָ�����״̬�۲���ı��༭�����
	afx_msg void OnBnClickedButtonInitct();//���ѡ��ĳ�˴��ָ��CT�ļ��а�ť�¼�
	afx_msg void OnBnClickedButtonInitpet();//���ѡ����˴��ָ��PET�ļ��а�ť�¼�
	afx_msg void OnBnClickedButtonSegct();//����洢�������зָ���CT�ļ��а�ť�¼�
	afx_msg void OnBnClickedButtonSegpet();//����洢�������зָ���PET�ļ��а�ť�¼�
	afx_msg void OnBnClickedButtonPetctseriessegStart();//����β�PET-CT���зָ�������ť�¼�

	CButton m_buttonPETCTSeriesSegStart;//�β�PET-CT���зָ�������ť����
};
