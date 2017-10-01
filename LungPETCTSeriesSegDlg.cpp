// LungPETCTSeriesSegDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ITK+VTK+MFC_GUI.h"
#include "LungPETCTSeriesSegDlg.h"
#include "afxdialogex.h"


// CLungPETCTSeriesSegDlg �Ի���

IMPLEMENT_DYNAMIC(CLungPETCTSeriesSegDlg, CDialogEx)

CLungPETCTSeriesSegDlg::CLungPETCTSeriesSegDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLungPETCTSeriesSegDlg::IDD, pParent)
{

}

CLungPETCTSeriesSegDlg::~CLungPETCTSeriesSegDlg()
{
}

void CLungPETCTSeriesSegDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_InitCT, m_editInitCT);
	DDX_Control(pDX, IDC_EDIT_InitPET, m_editInitPET);
	DDX_Control(pDX, IDC_EDIT_SegCT, m_editSegCT);
	DDX_Control(pDX, IDC_EDIT_SegPET, m_editSegPET);
	DDX_Control(pDX, IDC_EDIT_PETCTSeriesSeg_View, m_editPETCTSeriesSeg_View);
	DDX_Control(pDX, IDC_BUTTON_PETCTSeriesSeg_Start, m_buttonPETCTSeriesSegStart);
}


BEGIN_MESSAGE_MAP(CLungPETCTSeriesSegDlg, CDialogEx)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON_InitCT, &CLungPETCTSeriesSegDlg::OnBnClickedButtonInitct)
	ON_BN_CLICKED(IDC_BUTTON_InitPET, &CLungPETCTSeriesSegDlg::OnBnClickedButtonInitpet)
	ON_BN_CLICKED(IDC_BUTTON_SegCT, &CLungPETCTSeriesSegDlg::OnBnClickedButtonSegct)
	ON_BN_CLICKED(IDC_BUTTON_SegPET, &CLungPETCTSeriesSegDlg::OnBnClickedButtonSegpet)
	ON_BN_CLICKED(IDC_BUTTON_PETCTSeriesSeg_Start, &CLungPETCTSeriesSegDlg::OnBnClickedButtonPetctseriessegStart)
END_MESSAGE_MAP()


// CLungPETCTSeriesSegDlg ��Ϣ�������


void CLungPETCTSeriesSegDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()

	//��ʼ���ı��༭��
	m_editInitCT.SetWindowText(_T(""));
	m_editInitPET.SetWindowText(_T(""));
	m_editSegCT.SetWindowText(_T(""));
	m_editSegPET.SetWindowText(_T(""));

	m_editPETCTSeriesSeg_View.SetWindowText(_T(""));

}


//���ѡ��ĳ�˴��ָ��CT�ļ��а�ť�¼�
void CLungPETCTSeriesSegDlg::OnBnClickedButtonInitct()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	BROWSEINFO bi;
	char chDir[MAX_PATH] = {0};
	memset((char *)&bi, 0, sizeof(bi));
	bi.hwndOwner = this->m_hWnd;
	bi.lpszTitle = "ѡ��ĳ�˴����зָ��CT�ļ���";

	bi.ulFlags = BIF_BROWSEFORCOMPUTER | BIF_RETURNONLYFSDIRS;	
	ITEMIDLIST *pList = NULL;
	pList = SHBrowseForFolder(&bi);

	if (pList == NULL)
	{
		return;		
	}
	SHGetPathFromIDList(pList, chDir);

	//�ѵ����dicm�������ѡ��ĳ�˴��ָ��CT�ļ����ı��༭����
	m_editInitCT.SetWindowText(_T(chDir)); 
}


//���ѡ����˴��ָ��PET�ļ��а�ť�¼�
void CLungPETCTSeriesSegDlg::OnBnClickedButtonInitpet()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	BROWSEINFO bi;
	char chDir[MAX_PATH] = {0};
	memset((char *)&bi, 0, sizeof(bi));
	bi.hwndOwner = this->m_hWnd;
	bi.lpszTitle = "ѡ����˴����зָ��PET�ļ���";

	bi.ulFlags = BIF_BROWSEFORCOMPUTER | BIF_RETURNONLYFSDIRS;	
	ITEMIDLIST *pList = NULL;
	pList = SHBrowseForFolder(&bi);

	if (pList == NULL)
	{
		return;		
	}
	SHGetPathFromIDList(pList, chDir);

	//�ѵ����dicm�������ѡ����˴��ָ��PET�ļ����ı��༭����
	m_editInitPET.SetWindowText(_T(chDir)); 
}


//����洢�������зָ���CT�ļ��а�ť�¼�
void CLungPETCTSeriesSegDlg::OnBnClickedButtonSegct()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	BROWSEINFO bi;
	char chDir[MAX_PATH] = {0};
	memset((char *)&bi, 0, sizeof(bi));
	bi.hwndOwner = this->m_hWnd;
	bi.lpszTitle = "ѡ��洢�������зָ���CT�ļ���";

	bi.ulFlags = BIF_BROWSEFORCOMPUTER | BIF_RETURNONLYFSDIRS;	
	ITEMIDLIST *pList = NULL;
	pList = SHBrowseForFolder(&bi);

	if (pList == NULL)
	{
		return;		
	}
	SHGetPathFromIDList(pList, chDir);

	//�ѵ����dicm������Ӵ洢�������зָ���CT�ļ����ı��༭����
	m_editSegCT.SetWindowText(_T(chDir)); 
}


//����洢�������зָ���PET�ļ��а�ť�¼�
void CLungPETCTSeriesSegDlg::OnBnClickedButtonSegpet()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	BROWSEINFO bi;
	char chDir[MAX_PATH] = {0};
	memset((char *)&bi, 0, sizeof(bi));
	bi.hwndOwner = this->m_hWnd;
	bi.lpszTitle = "ѡ��洢�������зָ���PET�ļ���";

	bi.ulFlags = BIF_BROWSEFORCOMPUTER | BIF_RETURNONLYFSDIRS;	
	ITEMIDLIST *pList = NULL;
	pList = SHBrowseForFolder(&bi);

	if (pList == NULL)
	{
		return;		
	}
	SHGetPathFromIDList(pList, chDir);

	//�ѵ����dicm������Ӵ洢�������зָ���PET�ļ����ı��༭����
	m_editSegPET.SetWindowText(_T(chDir)); 
}


//����β�PET-CT���зָ�������ť�¼�
void CLungPETCTSeriesSegDlg::OnBnClickedButtonPetctseriessegStart()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	m_buttonPETCTSeriesSegStart.SetWindowText(_T("�����������У���ȴ�..."));
	m_buttonPETCTSeriesSegStart.EnableWindow(FALSE); //����button

	strPETCTSeriesSeg =_T("");
	m_editPETCTSeriesSeg_View.SetWindowText(_T(strPETCTSeriesSeg)); 

	//��ȡ�������ı����е�����
	GetDlgItem(IDC_EDIT_InitCT)->GetWindowText(strInitCT);
	GetDlgItem(IDC_EDIT_InitPET)->GetWindowText(strInitPET);

	GetDlgItem(IDC_EDIT_SegCT)->GetWindowText(strSegCT);
	GetDlgItem(IDC_EDIT_SegPET)->GetWindowText(strSegPET);
	if(strInitCT == "")//�ж��Ƿ�ѡ����ѡ��ĳ�˴��ָ��CT�ļ���
	{
		// ��ʾ��Ϣ�Ի���   
		MessageBox(_T("����ѡ��ĳ�˴����зָ��CT�ļ��У�"), _T("��ʾ"), MB_OK | MB_ICONWARNING);  
		m_buttonPETCTSeriesSegStart.EnableWindow(TRUE); //����button
		return;
	}
	else if(strInitPET == "")//�ж��Ƿ�ѡ����ѡ��ĳ�˴��ָ��PET�ļ���
	{
		// ��ʾ��Ϣ�Ի���   
		MessageBox(_T("����ѡ����˴����зָ��PET�ļ��У�"), _T("��ʾ"), MB_OK | MB_ICONWARNING); 
		m_buttonPETCTSeriesSegStart.EnableWindow(TRUE); //����button
		return;
	}
	else if(strSegCT == "")//�ж��Ƿ�ѡ���˴洢�������зָ���CT�ļ���
	{
		// ��ʾ��Ϣ�Ի���   
		MessageBox(_T("����ѡ��洢�������зָ���CT�ļ��У�"), _T("��ʾ"), MB_OK | MB_ICONWARNING);  
		m_buttonPETCTSeriesSegStart.EnableWindow(TRUE); //����button
		return;
	}
	else if(strSegPET == "")//�ж��Ƿ�ѡ���˴洢�������зָ���PET�ļ���
	{
		// ��ʾ��Ϣ�Ի���   
		MessageBox(_T("����ѡ��洢�������зָ���PET�ļ��У�"), _T("��ʾ"), MB_OK | MB_ICONWARNING);  
		m_buttonPETCTSeriesSegStart.EnableWindow(TRUE); //����button
		return;
	}

	//�β�PET-CT���зָ�
	LungPET_CTSeriesSeg();

	m_buttonPETCTSeriesSegStart.EnableWindow(TRUE); //����button
	m_buttonPETCTSeriesSegStart.SetWindowText(_T("��ʼPET-CT���зָ�"));

	//ShellExecute(NULL,_T("open"),"E:\\itk_cmake\\accss_image_produce_text_bin\\Debug\\access_produce_text.exe",NULL,NULL,SW_SHOW);

}


//==============�β�PET-CT���зָ��ʵ��===============================
void CLungPETCTSeriesSegDlg::InitQueue(LinkQueue &Q)  //���г�ʼ��
{
	Q.front = (QNode *)malloc(sizeof(QNode));
	Q.rear = Q.front;
	Q.front->next = NULL;
}

bool CLungPETCTSeriesSegDlg::IsEmpty(LinkQueue Q)//�����п�
{
	if(Q.front == Q.rear)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void CLungPETCTSeriesSegDlg::EnQueue(LinkQueue &Q,int x,int y)//���
{
	QNode *s;
	s = (QNode *)malloc(sizeof(QNode));
	s->x = x;
	s->y = y;
	s->next = NULL;
	Q.rear->next = s;
	Q.rear = s;
}

bool CLungPETCTSeriesSegDlg::DeQueue(LinkQueue &Q,int &x,int &y)//����
{
	if(Q.front == Q.rear)//�ն�
	{
		return false;
	}
	QNode *p;
	p = Q.front->next;
	x = p->x;
	y = p->y;
	Q.front->next = p->next;
	if(Q.rear == p)
	{
		Q.rear = Q.front;//��ԭ������ֻ��һ����㣬ɾ������
	}
	free(p);
	return true;

}

//�β�PET-CT���зָ�
int CLungPETCTSeriesSegDlg::LungPET_CTSeriesSeg()
{
	//UpdateData(TRUE);
	
	const int roi_x1 = 110,roi_x2 = 400;
	const int roi_y1 = 60,roi_y2 = 420;
	double  time;   
	clock_t Start,Finish;
	Start=clock( );//��ʼ��ʱ 

	CString outputimagename[100]={"0","1","2","3","4","5","6","7","8","9",
	                             "10","11","12","13","14","15","16","17","18","19",
	                             "20","21","22","23","24","25","26","27","28","29",
	                             "30","31","32","33","34","35","36","37","38","39",
	                             "40","41","42","43","44","45","46","47","48","49",
	                             "50","51","52","53","54","55","56","57","58","59",
	                             "60","61","62","63","64","65","66","67","68","69",
	                             "70","71","72","73","74","75","76","77","78","79",
	                             "80","81","82","83","84","85","86","87","88","89",
	                             "90","91","92","93","94","95","96","97","98","99",};
	//============����dicmϵ��ͼƬ====================================================

	 typedef signed short    PixelType_series;
	 const unsigned int      Dimension_series = 3;

	 typedef itk::Image< PixelType_series, Dimension_series >      ImageType_series;
     typedef itk::ImageSeriesReader< ImageType_series >     ReaderType_series;

	 typedef itk::GDCMImageIO                        ImageIOType_series;
	 typedef itk::GDCMSeriesFileNames                NamesGeneratorType;

	 ImageIOType_series::Pointer gdcmIO_series = ImageIOType_series::New();
	 NamesGeneratorType::Pointer namesGenerator = NamesGeneratorType::New();

	 namesGenerator->SetInputDirectory( strInitCT );//����CT_dicmͼ��ϵ������Ŀ¼

	 CString outputDirectory = strSegCT;   //���CT_dicmͼ�����ڵ�Ŀ¼

	 const ReaderType_series::FileNamesContainer & filenames =
                           namesGenerator->GetInputFileNames();

	 unsigned int numberOfFilenames =  filenames.size();
	 //std::cout << numberOfFilenames << std::endl;
	 
	 char strConvert[25];
	 itoa(numberOfFilenames,strConvert,10);

	 strPETCTSeriesSeg +=_T("�����зָ��CT��PET�ļ������� ");
	 strPETCTSeriesSeg +=_T(strConvert);
	 strPETCTSeriesSeg +=_T(" ��CT��PET DICMͼ��");
	 m_editPETCTSeriesSeg_View.SetWindowText(_T(strPETCTSeriesSeg)); 

	 //====================PET���ж���===============================
	 ImageIOType_series::Pointer PET_gdcmIO_series = ImageIOType_series::New();
	 NamesGeneratorType::Pointer PET_namesGenerator = NamesGeneratorType::New();

	 PET_namesGenerator->SetInputDirectory( strInitPET );//����PET_dicmͼ��ϵ������Ŀ¼

	 CString PET_outputDirectory = strSegPET;   //���PET_dicmͼ�����ڵ�Ŀ¼

	 const ReaderType_series::FileNamesContainer & PET_filenames =
                           PET_namesGenerator->GetInputFileNames();

	 //unsigned int PET_numberOfFilenames =  filenames.size();
	 //std::cout << PET_numberOfFilenames << std::endl;
	 //==============================================================
	 int i = 0;

	 int PET_fni = 0;

	// for(unsigned int fni = 0; fni<numberOfFilenames; fni++)
	 for(int fni = numberOfFilenames-1; fni>=0; fni--)
	 {
		/*std::cout << "CT_filename # " << i << " = ";
		std::cout << filenames[fni] << std::endl;*/

		/*char strConvertCT[25];
		itoa(i,strConvertCT,10);

		strPETCTSeriesSeg +=_T("\r\nCT_filename # ");
		strPETCTSeriesSeg +=_T(strConvertCT);
		strPETCTSeriesSeg +=_T(" = ");
		//strPETCTSeriesSeg +=_T(filenames[fni]);//???????????????????????????
		m_editPETCTSeriesSeg_View.SetWindowText(_T(strPETCTSeriesSeg)); */

		//=========PET==================================
		/*std::cout << "PET_filename # " << i << " = ";
		std::cout << PET_filenames[PET_fni] << std::endl;*/
		/*char strConvertPET[25];
		itoa(i,strConvertPET,10);

		strPETCTSeriesSeg +=_T("\r\nPET_filename # ");
		strPETCTSeriesSeg +=_T(strConvertPET);
		strPETCTSeriesSeg +=_T(" = ");
		//strPETCTSeriesSeg +=_T(PET_filenames[fni]);//???????????????????????
		m_editPETCTSeriesSeg_View.SetWindowText(_T(strPETCTSeriesSeg)); */
		//==============================================

		i++;
	 //}

	 //================================================================================
		typedef signed short InputPixelType;                              //����dicomͼ������
		const unsigned int   InputDimension = 2;
		typedef itk::Image< InputPixelType, InputDimension > InputImageType;
		typedef itk::ImageFileReader< InputImageType > ReaderType;
		ReaderType::Pointer reader = ReaderType::New();
		reader->SetFileName( filenames[fni] );                                  //����dicomͼ��filenames[fni]
		typedef itk::GDCMImageIO           ImageIOType;
		ImageIOType::Pointer gdcmImageIO = ImageIOType::New();
		reader->SetImageIO( gdcmImageIO );
		try
		{
			reader->Update();
		}
		catch (itk::ExceptionObject & e)
		{
			std::cerr << "exception in file reader " << std::endl;
			std::cerr << e << std::endl;
			return EXIT_FAILURE;
		}

		typedef unsigned char WritePixelType;                     //дͼ������
		typedef itk::Image< WritePixelType, 2 > WriteImageType;

		typedef itk::RescaleIntensityImageFilter<
				InputImageType, WriteImageType > RescaleFilterType;

		RescaleFilterType::Pointer rescaler = RescaleFilterType::New();

		rescaler->SetOutputMinimum(   0 );
		rescaler->SetOutputMaximum( 255 );
		rescaler->SetInput( reader->GetOutput() );                      //�Զ����dicmͼƬ����RescaleIntensityImageFilter����
		rescaler->Update();                                             //ִ�йܵ�

		const unsigned int Dimension = 2;                                          //����ͼ��ά�� 
		typedef unsigned char  PixelType;                                          //������������ 
		typedef itk::Image< PixelType, Dimension >   ImageType;                    //ͼ������ 
		//typedef itk::ImageFileReader< ImageType >    ReaderType; 
		typedef itk::ImageFileWriter< ImageType >    WriterType; 

		//��ȡͼ�� 
		ImageType::Pointer image = rescaler->GetOutput(); 

		//ImageType::Pointer image_init = rescaler->GetOutput(); 
		//=====================��ѻҶ���ֵ�ָ�=============================================
		int pixel[256],pixel_B[256],pixel_N[256];
		int gray_min,gray_max;
		int avg_B,avg_N,sum_B=0,sum_N=0,cnt_B=0,cnt_N=0,L=0;
		int T1,T,T2=0,T_F;
		for(int i=0;i<256;i++)
		{
			pixel[i]=0;
			pixel_B[i]=0;
			pixel_N[i]=0;
		}

		//====================������Ұ�ⱳ��HUֵ��Ӱ��============================= 
		//��ȡ����ͼ��Ĵ�С 
		ImageType::SizeType size = image->GetLargestPossibleRegion().GetSize(); 
 
		//ѭ�������������� 
		for (int x=0; x<size[0]; x++) 
			for(int y=0; y<size[1]; y++) 
				{ 
					//������������ 
					ImageType::IndexType index; 
					index[0] = x; 
					index[1] = y; 
 
					//��ȡ����ֵ 
					ImageType::PixelType value = image->GetPixel(index); 
					if ((index[0]-size[0]/2)*(index[0]-size[0]/2) +   (index[1]-size[1]/2)*(index[1]-size[1]/2) > size[0]*size[0]/4 ) 
					{ 
							L++;
							image->SetPixel(  index, 0 );  
					} 
				                                      
				}
		//=====================================================================

		//�������������Ҫ����ͼ��ָ�����Ҫ���ʵ�ͼ�������С 
		typedef itk::ImageRegionIterator<ImageType> ItType; 
		ItType it( image, image->GetRequestedRegion() ); 
 
		//���������ƶ����׸�Ԫ�� 
		it.GoToBegin(); 
		//�������أ�ֱ������ 
		while( !it.IsAtEnd() ) 
		{ 
			//��ȡ����ֵ 
			ImageType::PixelType value = it.Get(); 

			pixel[int(value)]++;
   
			//�������ƶ�����һԪ�� 
			++it; 
		} 

		for(int i=0;i<256;i++)
		{
			if(pixel[i]>0)
			{
				gray_min=i;
				break;
			}
		}
		for(int i=255;i>=0;i--)
		{
			if(pixel[i]>0)
			{
				gray_max=i;
				break;
			}
		}
	
		T=(gray_min+gray_max)/2;
		T1=T;

		for(int i=0;i<256;i++)
		{
			if(i<T)
			{
				pixel_B[i]=pixel[i];
			}
			else
			{
				pixel_N[i]=pixel[i];
			}
		}

		for(int i=0;i<256;i++)
		{
			if(pixel_B[i]>0)
			{
				sum_B+=i*pixel_B[i];
				cnt_B+=pixel_B[i];
			}
			if(pixel_N[i]>0)
			{
				sum_N+=i*pixel_N[i];
				cnt_N+=pixel_N[i];
			}
		}
		avg_B=sum_B/cnt_B;
		avg_N=sum_N/cnt_N;
		T2=((avg_B+avg_N)*(size[0]*size[1])/(size[0]*size[1]-L))/2;
		//T2=(avg_B+avg_N)/2;


		while(((T2-T1)>2)||((T1-T2)>2))
		{
			T1=T2;
			for(int i=0;i<256;i++)
			{
				if(i<T)
				{
					pixel_B[i]=pixel[i];
				}
				else
				{
					pixel_N[i]=pixel[i];
				}
			}

			for(int i=0;i<256;i++)
			{
				if(pixel_B[i]>0)
				{
					sum_B+=i*pixel_B[i];
					cnt_B+=pixel_B[i];
				}
				if(pixel_N[i]>0)
				{
					sum_N+=i*pixel_N[i];
					cnt_N+=pixel_N[i];
				}
			}
			avg_B=sum_B/cnt_B;
			avg_N=sum_N/cnt_N;
			T2=((avg_B+avg_N)*(size[0]*size[1])/(size[0]*size[1]-L))/2;
			//T2=(avg_B+avg_N)/2;
		}
	
		T_F=T1;
		//std::cout <<"T_F="<<T_F<<std::endl;


		//�������������Ҫ����ͼ��ָ�����Ҫ���ʵ�ͼ�������С 
		typedef itk::ImageRegionIterator<ImageType> ItType1; 
		ItType1 it1( image, image->GetRequestedRegion() ); 
 
		//���������ƶ����׸�Ԫ�� 
		it1.GoToBegin(); 
		//�������أ�ֱ������ 
		while( !it1.IsAtEnd() ) 
		{ 
			 //��ȡ����ֵ 
			ImageType::PixelType value = it1.Get(); 

			if((int)value>T_F)
			{
				it1.Set(255); 
			}
			else
			{
				it1.Set(0);
			}
   
			//�������ƶ�����һԪ�� 
			++it1; 
		} 

		//image�������ѻҶ���ֵ�ָ���dicmͼ

		//===================================================================
		//==============��image����ȡROI����=================================

		//��ȡ����ͼ��Ĵ�С 
		//ImageType::SizeType size = image->GetLargestPossibleRegion().GetSize(); 
 
		//ѭ�������������� 
		for (int x=0; x<size[0]; x++) 
			for(int y=0; y<size[1]; y++) 
				{ 
					  //������������ 
					  ImageType::IndexType index; 
					  index[0] = x; 
					  index[1] = y; 

					  //��ȡROI
					  if((index[0]>=roi_x1)&&(index[0]<=roi_x2)&&(index[1]>=roi_y1)&&(index[1]<=roi_y2))
					  {}
					  else
					  {
						  //����ROI�����������ֵȫΪ��ɫ
						  image->SetPixel(  index, 0 );  
					  }
				                                      
				}
			//image�����ROI�����dicmͼ

		//===================================================================
		//==========����������Ʒ������=======================================

		typedef   float           InternalPixelType;
		const     unsigned int    InterDimension = 2;
		typedef itk::Image< InternalPixelType, InterDimension >  InternalImageType;

		typedef itk::CastImageFilter< ImageType, InternalImageType > CastingFilterType_image2internal;   //ת��ImageTypeΪInternalImageType         
		//CastingFilterType_image2internal::Pointer caster_image2internal = CastingFilterType_image2internal::New();

		typedef itk::CastImageFilter< InternalImageType, ImageType > CastingFilterType_internal2image;   // //ת��InternalImageTypeΪImageType
		//CastingFilterType_internal2image::Pointer caster_internal2image = CastingFilterType_internal2image::New();

		typedef itk::ConnectedThresholdImageFilter< InternalImageType,
										InternalImageType > ConnectedFilterType;

		int seed_chest_x,seed_chest_y; //Ѱ����ǻ�����ӵ�
		bool flag_loop=false;

		//��ȡ����ͼ��Ĵ�С 
		//ImageType::SizeType size2 = image->GetLargestPossibleRegion().GetSize(); 
			//ѭ�������������� 
		for (int y=roi_y1; y<=roi_y2; y++) 
		{
			int i;
			for(int x=roi_x1; x<=roi_x2; x++) 
				{ 
					for(i=0;i<30;i++)
					{
						//������������ 
					  ImageType::IndexType index; 
					  index[0] = x+i; 
					  index[1] = y; 
					   //��ȡ����ֵ 
					  ImageType::PixelType value = image->GetPixel(index); 
					  if((int)value<100)
					  {
						  break;
					  }
					}
					if(i==30)
					{
						seed_chest_x=x;
						seed_chest_y=y;
						flag_loop=true;
						break;
					}                                     
				}
			if(flag_loop)
			{
				break;
			}
		}


		CastingFilterType_image2internal::Pointer caster_image2internal_chest = CastingFilterType_image2internal::New();

		CastingFilterType_internal2image::Pointer caster_internal2image_chest = CastingFilterType_internal2image::New();

		caster_image2internal_chest->SetInput(image);

		ConnectedFilterType::Pointer connectedThreshold_chest = ConnectedFilterType::New();

		connectedThreshold_chest->SetInput( caster_image2internal_chest->GetOutput() );
		caster_internal2image_chest->SetInput( connectedThreshold_chest->GetOutput() );

		//��ȡͼ�� imageͼ����ǻ����������image_chest
		ImageType::Pointer image_chest =caster_internal2image_chest->GetOutput(); 

		const InternalPixelType lowerThreshold_chest = 200;
		const InternalPixelType upperThreshold_chest = 300;

		connectedThreshold_chest->SetLower(  lowerThreshold_chest  );
		connectedThreshold_chest->SetUpper(  upperThreshold_chest  );


		connectedThreshold_chest->SetReplaceValue( 255 );


			InternalImageType::IndexType  inter_chest_Index;

			inter_chest_Index[0] = seed_chest_x;     
			inter_chest_Index[1] = seed_chest_y;

			connectedThreshold_chest->SetSeed( inter_chest_Index );

			try
			{
				caster_internal2image_chest->Update();
			}
			catch( itk::ExceptionObject & excep )
			{
				std::cerr << "Exception caught !" << std::endl;
				std::cerr << excep << std::endl;
			}

			//image_chest�����imageͼ����ǻ������
			//image�����ROI�����dicmͼ

		//===================================================================
		//=========��image_chest����������������ȡ��Χ����===================

		CastingFilterType_image2internal::Pointer caster_image2internal_outer = CastingFilterType_image2internal::New();

		CastingFilterType_internal2image::Pointer caster_internal2image_outer = CastingFilterType_internal2image::New();
	
		caster_image2internal_outer->SetInput(image_chest);

		ConnectedFilterType::Pointer connectedThreshold_outer = ConnectedFilterType::New();

		connectedThreshold_outer->SetInput( caster_image2internal_outer->GetOutput() );
		caster_internal2image_outer->SetInput( connectedThreshold_outer->GetOutput() );
	
		 //��ȡͼ�� image_chestͼ����Χ������������image_outer
		ImageType::Pointer image_outer =caster_internal2image_outer->GetOutput(); 

		const InternalPixelType lowerThreshold_outer = 0;
		const InternalPixelType upperThreshold_outer = 50;

		connectedThreshold_outer->SetLower(  lowerThreshold_outer  );
		connectedThreshold_outer->SetUpper(  upperThreshold_outer  );

		connectedThreshold_outer->SetReplaceValue( 255 );

		InternalImageType::IndexType  inter_Index_outer;

		inter_Index_outer[0] = 1;     //����ѡȡ���ϽǺ�ɫ���ӵ�
		inter_Index_outer[1] = 1;

		connectedThreshold_outer->SetSeed( inter_Index_outer );

		try
		{
			caster_internal2image_outer->Update();
		}
		catch( itk::ExceptionObject & excep )
		{
			std::cerr << "Exception caught !" << std::endl;
			std::cerr << excep << std::endl;
		}

		//image_outer������������������ָ��image_chestͼ����Χ��������
		//image_chest�����imageͼ����ǻ������
		//image�����ROI�����dicmͼ

		//=========================================================================
		//==========image_chestͼ����image_outerͼ�����=====================
		//�������������Ҫ����ͼ��ָ�����Ҫ���ʵ�ͼ�������С 
		typedef itk::ImageRegionIterator<ImageType> ItType; 
		ItType it_image_chest( image_chest, image_chest->GetRequestedRegion() ); 
		ItType it_image_outer( image_outer, image_outer->GetRequestedRegion() ); 
 
		//���������ƶ����׸�Ԫ�� 
		it_image_chest.GoToBegin(); 
		it_image_outer.GoToBegin(); 

		//�������أ�ֱ������ 
		while( (!it_image_chest.IsAtEnd())&&(!it_image_outer.IsAtEnd()) ) 
		{ 
			 //��ȡ����ֵ 
			ImageType::PixelType value_outer = it_image_outer.Get(); 

			if((int(value_outer))>200)
			{
				it_image_chest.Set(int(value_outer)); 
			}

			//�������ƶ�����һԪ�� 
			++it_image_chest;
			++it_image_outer;
		} 

		//image_chest�����image_chestͼ����image_outerͼ����Ӻ�Ľ��
		//image_outer������������������ָ��image_chestͼ����Χ��������
		//image�����ROI�����dicmͼ

		//===================================================================
		//============================��ͼ��image_chest�Ҷ�ֵ�ߵ�============

		//�������������Ҫ����ͼ��ָ�����Ҫ���ʵ�ͼ�������С 
		typedef itk::ImageRegionIterator<ImageType> ItType; 
		ItType it_invert( image_chest, image_chest->GetRequestedRegion() ); 
		//���������ƶ����׸�Ԫ�� 
		it_invert.GoToBegin(); 
		//�������أ�ֱ������ 
		while( !it_invert.IsAtEnd()) 
		{ 
			 //��ȡ����ֵ 
			ImageType::PixelType value = it_invert.Get(); 

			if((int(value))>200)
			{
				it_invert.Set(0); 
			}

			if((int(value))<50)
			{
				it_invert.Set(255); 
			}
   
			//�������ƶ�����һԪ�� 
			++it_invert;
		} 

		//image_chest�����ͼ��image_chest�Ҷ�ֵ�ߵ���Ľ��
		//image_outer������������������ָ��image_chestͼ����Χ��������
		//image�����ROI�����dicmͼ

		//===================================================================
		//=======��ȡimage_chest����С��Ӿ���===============================

		int bound_rectangle_x1,bound_rectangle_x2,bound_rectangle_y1,bound_rectangle_y2;//������Ӿ��ε��ĸ��߽�

		bool bound_rectangle_x1_flag = false,bound_rectangle_x2_flag = false,bound_rectangle_y1_flag = false,bound_rectangle_y2_flag = false;

		//����߽�bound_rectangle_x1
		for (int x=roi_x1; x<=roi_x2; x++) 
		{
			for(int y=roi_y1; y<=roi_y2; y++) 
				{ 
					  //������������ 
					  ImageType::IndexType index; 
					  index[0] = x; 
					  index[1] = y; 
 
					  //��ȡ����ֵ 
					  ImageType::PixelType value = image_chest->GetPixel(index); 

					  if ((int(value))>200)
					  { 
						  bound_rectangle_x1 = x;
						  bound_rectangle_x1_flag=true;
						  break;
					  } 
				                                      
				}
			if(bound_rectangle_x1_flag)
			{
				break;
			}
		}

		//���ұ߽�bound_rectangle_x2
		for (int x=roi_x2; x>=roi_x1; x--) 
		{
			for(int y=roi_y1; y<=roi_y2; y++) 
				{ 
					  //������������ 
					  ImageType::IndexType index; 
					  index[0] = x; 
					  index[1] = y; 
 
					  //��ȡ����ֵ 
					  ImageType::PixelType value = image_chest->GetPixel(index); 

					  if ((int(value))>200)
					  { 
						  bound_rectangle_x2 = x;
						  bound_rectangle_x2_flag=true;
						  break;
					  } 
				                                      
				}
			if(bound_rectangle_x2_flag)
			{
				break;
			}
		}

		//���ϱ߽�bound_rectangle_y1
		for (int y=roi_y1; y<=roi_y2; y++) 
		{
			for(int x=roi_x1; x<=roi_x2; x++) 
				{ 
					  //������������ 
					  ImageType::IndexType index; 
					  index[0] = x; 
					  index[1] = y; 
 
					  //��ȡ����ֵ 
					  ImageType::PixelType value = image_chest->GetPixel(index); 

					  if ((int(value))>200)
					  { 
						  bound_rectangle_y1 = y;
						  bound_rectangle_y1_flag=true;
						  break;
					  } 
				                                      
				}
			if(bound_rectangle_y1_flag)
			{
				break;
			}
		}

		//���±߽�bound_rectangle_y2
		for (int y=roi_y2; y>=roi_y1; y--) 
		{
			for(int x=roi_x1; x<=roi_x2; x++) 
				{ 
					  //������������ 
					  ImageType::IndexType index; 
					  index[0] = x; 
					  index[1] = y; 
 
					  //��ȡ����ֵ 
					  ImageType::PixelType value = image_chest->GetPixel(index); 

					  if ((int(value))>200)
					  { 
						  bound_rectangle_y2 = y;
						  bound_rectangle_y2_flag=true;
						  break;
					  } 
				                                      
				}
			if(bound_rectangle_y2_flag)
			{
				break;
			}
		}
		//image_chest�����ͼ��image_chest�Ҷ�ֵ�ߵ���Ľ��
		//image_outer������������������ָ��image_chestͼ����Χ��������
		//image�����ROI�����dicmͼ

		//===================================================================

		/********************************************************************
		 *����һ����image_chest����[��bound_rectangle_y2 - bound_rectangle_y1��/2 + 1]
		 *�ĳ������δ����ϡ����¡����ϡ������ĸ�������ֱɨ���
		 *����������image_chest����������������ɨ��
		 *����������image_chest�����ĸ�����תɨ�裨�ҳ�����õķ�����
		 ********************************************************************/
		//====================================================================
	
		for (int x=roi_x1; x<=roi_x2; x++) 
			for(int y=roi_y1; y<=roi_y2; y++) 
			{
				flag[x][y] = false;
			}

		int mid_x = (bound_rectangle_x1+ bound_rectangle_x2)/2;
		int mid_y = (bound_rectangle_y1+ bound_rectangle_y2)/2;
		int four_direction_seed[4][2];

		if(i<=(int)(numberOfFilenames/10))  //���÷�����
		{
			//Ѱ��������ӵ�
			int left_down_seed_x = -1,left_down_seed_y = -1;
			bool flag_loop_left=false;
			for(int x = bound_rectangle_x1;x<=mid_x;x++)
			{
				for(int y=bound_rectangle_y2;y>=bound_rectangle_y1;y--)
				{
					//������������ 
					  ImageType::IndexType index,index2,index3; 
					  index[0] = x; 
					  index[1] = y; 

					  index2[0] = x;
					  index2[1] = y-1;

					  index3[0] = x;
					  index3[1] = y-2;
 
					  //��ȡ����ֵ 
					  ImageType::PixelType value = image_chest->GetPixel(index); 
					  ImageType::PixelType value2 = image_chest->GetPixel(index2); 
					  ImageType::PixelType value3 = image_chest->GetPixel(index3); 
					  if (((int(value))>200)&&(((int)value2)>200)&&(((int)value3)>200)) 
					  { 
						  left_down_seed_x=x;
						  left_down_seed_y=y;
						  flag_loop_left=true;
						  break;
					  } 
				}
				if(flag_loop_left)
				{
					break;
				}
			}


			//Ѱ���Ҳ����ӵ�
			int right_down_seed_x = -1,right_down_seed_y = -1;
			bool flag_loop_right=false;
			for(int x = bound_rectangle_x2;x>=mid_x;x--)
			{
				for(int y=bound_rectangle_y2;y>=bound_rectangle_y1;y--)
				{
					//������������ 
					  ImageType::IndexType index,index2,index3; 
					  index[0] = x; 
					  index[1] = y; 

					  index2[0] = x;
					  index2[1] = y-1;

					  index3[0] = x;
					  index3[1] = y-2;
 
					  //��ȡ����ֵ 
					  ImageType::PixelType value = image_chest->GetPixel(index); 
					  ImageType::PixelType value2 = image_chest->GetPixel(index2); 
					  ImageType::PixelType value3 = image_chest->GetPixel(index3); 
					  if (((int(value))>200)&&(((int)value2)>200)&&(((int)value3)>200)) 
					  { 
						  right_down_seed_x=x;
						  right_down_seed_y=y;
						  flag_loop_right=true;
						  break;
					  } 
				}
				if(flag_loop_right)
				{
					break;
				}
			}

			int left_up_seed_x = -1,left_up_seed_y = -1;

			int right_up_seed_x = -1,right_up_seed_y = -1;

			four_direction_seed[0][0] = left_up_seed_x;
			four_direction_seed[0][1] = left_up_seed_y;

			four_direction_seed[1][0] = left_down_seed_x;
			four_direction_seed[1][1] = left_down_seed_y;

			four_direction_seed[2][0] = right_up_seed_x;
			four_direction_seed[2][1] = right_up_seed_y;

			four_direction_seed[3][0] = right_down_seed_x;
			four_direction_seed[3][1] = right_down_seed_y;

		}
		else   //���÷�����
		{
		double PI =  3.14159265;

		//����ɨ�� Ѱ�����ӵ�
		int left_up_angle = 0;
		int left_up_seed_x=-1,left_up_seed_y=-1;
		int left_up_min_dis = 512;
		while(left_up_angle<90)
		{
			double rad = (left_up_angle*PI)/180; 
			int x = bound_rectangle_x1;
			int y;
			y =(int)(bound_rectangle_y1 + tan(rad)*(x-bound_rectangle_x1));
			while((x<=mid_x)&&(y<=mid_y))
			{
				//������������ 
				ImageType::IndexType index,index2,index3; 
				index[0] = x; 
				index[1] = y; 

				index2[0] = x+1;
				index2[1] = (int)(bound_rectangle_y1 + tan(rad)*(x+1-bound_rectangle_x1));

				index3[0] = x+2;
				index3[1] = (int)(bound_rectangle_y1 + tan(rad)*(x+2-bound_rectangle_x1));

				 //��ȡ����ֵ 
				 ImageType::PixelType value = image_chest->GetPixel(index); 
				 ImageType::PixelType value2 = image_chest->GetPixel(index2); 
				 ImageType::PixelType value3 = image_chest->GetPixel(index3); 

				 if (((int(value))>200)&&((int(value2))>200)&&((int(value3))>200)&&(!flag[x][y]))
				 {
					 int dis;
					 dis = (int)(sqrt((double)((x-bound_rectangle_x1)*(x-bound_rectangle_x1)+(y-bound_rectangle_y1)*(y-bound_rectangle_y1))));
					 if(dis<left_up_min_dis)
					 {
						 left_up_min_dis = dis;
						 left_up_seed_x = x;
						 left_up_seed_y = y;
					 }
					 break;
				 }
				 x++;
				 y =(int)(bound_rectangle_y1 + tan(rad)*(x-bound_rectangle_x1));
			}//while((x<=mid_x)&&(y<=mid_y))
			left_up_angle = left_up_angle+5;
		}//while((x<=mid_x)&&(y<=mid_y))
	

		//����ɨ�� Ѱ�����ӵ�
		int left_down_angle = 275;
		int left_down_seed_x=-1,left_down_seed_y=-1;
		int left_down_min_dis = 512;
		while(left_down_angle<=360)
		{
			double rad = (left_down_angle*PI)/180; 
			int x = bound_rectangle_x1;
			int y;
			y =(int)(bound_rectangle_y2 + tan(rad)*(x-bound_rectangle_x1));
			while((x<=mid_x)&&(y>=mid_y))
			{
				//������������ 
				ImageType::IndexType index,index2,index3; 
				index[0] = x; 
				index[1] = y; 

				index2[0] = x+1;
				index2[1] = (int)(bound_rectangle_y2 + tan(rad)*(x+1-bound_rectangle_x1));

				index3[0] = x+2;
				index3[1] = (int)(bound_rectangle_y2 + tan(rad)*(x+2-bound_rectangle_x1));

				 //��ȡ����ֵ 
				 ImageType::PixelType value = image_chest->GetPixel(index); 
				 ImageType::PixelType value2 = image_chest->GetPixel(index2); 
				 ImageType::PixelType value3 = image_chest->GetPixel(index3); 

				 if (((int(value))>200)&&((int(value2))>200)&&((int(value3))>200)&&(!flag[x][y]))
				 {
					 int dis;
					 dis = (int)(sqrt((double)((x-bound_rectangle_x1)*(x-bound_rectangle_x1)+(bound_rectangle_y2-y)*(bound_rectangle_y2-y))));
					 if(dis<left_down_min_dis)
					 {
						 left_down_min_dis = dis;
						 left_down_seed_x = x;
						 left_down_seed_y = y;
					 }
					 break;
				 }
				 x++;
				 y =(int)(bound_rectangle_y2 + tan(rad)*(x-bound_rectangle_x1));
			}
			left_down_angle = left_down_angle+5;
		}


		//����ɨ�� Ѱ�����ӵ�
		int right_up_angle = 95;
		int right_up_seed_x=-1,right_up_seed_y=-1;
		int right_up_min_dis = 512;
		while(right_up_angle<=180)
		{
			double rad = (right_up_angle*PI)/180; 
			int x = bound_rectangle_x2;
			int y;
			y =(int)(bound_rectangle_y1 + tan(rad)*(x-bound_rectangle_x2));
			while((x>=mid_x)&&(y<=mid_y))
			{
				//������������ 
				ImageType::IndexType index,index2,index3; 
				index[0] = x; 
				index[1] = y; 

				index2[0] = x+1;
				index2[1] = (int)(bound_rectangle_y1 + tan(rad)*(x+1-bound_rectangle_x2));

				index3[0] = x+2;
				index3[1] = (int)(bound_rectangle_y1 + tan(rad)*(x+2-bound_rectangle_x2));


				 //��ȡ����ֵ 
				 ImageType::PixelType value = image_chest->GetPixel(index); 
				 ImageType::PixelType value2 = image_chest->GetPixel(index2); 
				 ImageType::PixelType value3 = image_chest->GetPixel(index3); 

				 if (((int(value))>200)&&((int(value2))>200)&&((int(value3))>200)&&(!flag[x][y]))
				 {
					 int dis;
					 dis = (int)(sqrt((double)((x-bound_rectangle_x2)*(x-bound_rectangle_x2)+(y-bound_rectangle_y1)*(y-bound_rectangle_y1))));
					 if(dis<right_up_min_dis)
					 {
						 right_up_min_dis = dis;
						 right_up_seed_x = x;
						 right_up_seed_y = y;
					 }
				 
					 break;
				 }
				 x--;
				 y =(int)(bound_rectangle_y1 + tan(rad)*(x-bound_rectangle_x2));
			}
			right_up_angle = right_up_angle+5;
		}


		//����ɨ�� Ѱ�����ӵ�
		int right_down_angle = 180;
		int right_down_seed_x=-1,right_down_seed_y=-1;
		int right_down_min_dis = 512;
		while(right_down_angle<270)
		{
			double rad = (right_down_angle*PI)/180; 
			int x = bound_rectangle_x2;
			int y;
			y =(int)(bound_rectangle_y2 + tan(rad)*(x-bound_rectangle_x2));
			while((x>=mid_x)&&(y>=mid_y))
			{
				//������������ 
				ImageType::IndexType index,index2,index3; 
				index[0] = x; 
				index[1] = y; 

				index2[0] = x+1;
				index2[1] = (int)(bound_rectangle_y2 + tan(rad)*(x+1-bound_rectangle_x2));

				index3[0] = x+2;
				index3[1] = (int)(bound_rectangle_y2 + tan(rad)*(x+2-bound_rectangle_x2));

				 //��ȡ����ֵ 
				 ImageType::PixelType value = image_chest->GetPixel(index); 
				 ImageType::PixelType value2 = image_chest->GetPixel(index2); 
				 ImageType::PixelType value3 = image_chest->GetPixel(index3); 
				 if (((int(value))>200)&&((int(value2))>200)&&((int(value3))>200)&&(!flag[x][y]))
				 {
					 int dis;
					 dis = (int)(sqrt((double)((x-bound_rectangle_x2)*(x-bound_rectangle_x2)+(y-bound_rectangle_y2)*(y-bound_rectangle_y2))));
					 if(dis<right_down_min_dis)
					 {
						 right_down_min_dis = dis;
						 right_down_seed_x = x;
						 right_down_seed_y = y;
					 }
				 
					 break;
				 }
				 x--;
				 y =(int)(bound_rectangle_y2 + tan(rad)*(x-bound_rectangle_x2));
			}//while((x<=mid_x)&&(y<=mid_y))
			right_down_angle = right_down_angle+5;
		}//while((x<=mid_x)&&(y<=mid_y))*/

	

		four_direction_seed[0][0] = left_up_seed_x;
		four_direction_seed[0][1] = left_up_seed_y;

		four_direction_seed[1][0] = left_down_seed_x;
		four_direction_seed[1][1] = left_down_seed_y;

		four_direction_seed[2][0] = right_up_seed_x;
		four_direction_seed[2][1] = right_up_seed_y;

		four_direction_seed[3][0] = right_down_seed_x;
		four_direction_seed[3][1] = right_down_seed_y;
		}//else


		/*std::cout<<"left_up_seed_x="<<left_up_seed_x<<std::endl;
			std::cout<<"left_up_seed_y="<<left_up_seed_y<<std::endl;

			std::cout<<"left_down_seed_x="<<left_down_seed_x<<std::endl;
			std::cout<<"left_down_seed_y="<<left_down_seed_y<<std::endl;

			std::cout<<"right_up_seed_x="<<right_up_seed_x<<std::endl;
			std::cout<<"right_up_seed_y="<<right_up_seed_y<<std::endl;

			std::cout<<"right_down_seed_x="<<right_down_seed_x<<std::endl;
			std::cout<<"right_down_seed_y="<<right_down_seed_y<<std::endl;*/


		for(int k=0;k<4;k++)
			{
				if(four_direction_seed[k][0]>0)
				{
						flag[four_direction_seed[k][0]][four_direction_seed[k][1]] = true;
						LinkQueue Q,L;
						InitQueue(Q);
						InitQueue(L);
						EnQueue(Q,four_direction_seed[k][0],four_direction_seed[k][1]);
						while(!IsEmpty(Q))//�����п�
						{
							int area_x,area_y;
							if(DeQueue(Q,area_x,area_y))
							{
								EnQueue(L,area_x,area_y);
								//seed_area_num++;
								if((area_x-1>=bound_rectangle_x1)&&(area_y>=bound_rectangle_y1)&&(area_x-1<=bound_rectangle_x2)&&(area_y<=bound_rectangle_y2)&&!flag[area_x-1][area_y])//��
								{
									//������������ 
									ImageType::IndexType index_west; 
									index_west[0] = area_x-1; 
									index_west[1] = area_y; 
 
									//��ȡ����ֵ 
									ImageType::PixelType value_west = image_chest->GetPixel(index_west); 
									if((int)value_west>100)
									{
										EnQueue(Q,area_x-1,area_y);
										flag[area_x-1][area_y] = true;
									}
								}

								if((area_x-1>=bound_rectangle_x1)&&(area_y-1>=bound_rectangle_y1)&&(area_x-1<=bound_rectangle_x2)&&(area_y-1<=bound_rectangle_y2)&&!flag[area_x-1][area_y-1])//����
								{
									//������������ 
									ImageType::IndexType index_west_north; 
									index_west_north[0] = area_x-1; 
									index_west_north[1] = area_y-1; 
 
									//��ȡ����ֵ 
									ImageType::PixelType value_west_north = image_chest->GetPixel(index_west_north); 
									if((int)value_west_north>100)
									{
										EnQueue(Q,area_x-1,area_y-1);
										flag[area_x-1][area_y-1] = true;
									}
								}

								if((area_x>=bound_rectangle_x1)&&(area_y-1>=bound_rectangle_y1)&&(area_x<=bound_rectangle_x2)&&(area_y-1<=bound_rectangle_y2)&&!flag[area_x][area_y-1])//��
								{
									//������������ 
									ImageType::IndexType index_north; 
									index_north[0] = area_x; 
									index_north[1] = area_y-1; 
 
									//��ȡ����ֵ 
									ImageType::PixelType value_north = image_chest->GetPixel(index_north); 
									if((int)value_north>100)
									{
										EnQueue(Q,area_x,area_y-1);
										flag[area_x][area_y-1] = true;
									}
								}

								if((area_x+1>=bound_rectangle_x1)&&(area_y-1>=bound_rectangle_y1)&&(area_x+1<=bound_rectangle_x2)&&(area_y-1<=bound_rectangle_y2)&&!flag[area_x+1][area_y-1])//����
								{
									//������������ 
									ImageType::IndexType index_east_north; 
									index_east_north[0] = area_x+1; 
									index_east_north[1] = area_y-1; 
 
									//��ȡ����ֵ 
									ImageType::PixelType value_east_north = image_chest->GetPixel(index_east_north); 
									if((int)value_east_north>100)
									{
										EnQueue(Q,area_x+1,area_y-1);
										flag[area_x+1][area_y-1] = true;
									}
								}

								if((area_x+1>=bound_rectangle_x1)&&(area_y>=bound_rectangle_y1)&&(area_x+1<=bound_rectangle_x2)&&(area_y<=bound_rectangle_y2)&&!flag[area_x+1][area_y])//��
								{
									//������������ 
									ImageType::IndexType index_east; 
									index_east[0] = area_x+1; 
									index_east[1] = area_y; 
 
									//��ȡ����ֵ 
									ImageType::PixelType value_east = image_chest->GetPixel(index_east); 
									if((int)value_east>100)
									{
										EnQueue(Q,area_x+1,area_y);
										flag[area_x+1][area_y] = true;
									}
								}

								if((area_x+1>=bound_rectangle_x1)&&(area_y+1>=bound_rectangle_y1)&&(area_x+1<=bound_rectangle_x2)&&(area_y+1<=bound_rectangle_y2)&&!flag[area_x+1][area_y+1])//����
								{
									//������������ 
									ImageType::IndexType index_north_south; 
									index_north_south[0] = area_x+1; 
									index_north_south[1] = area_y+1; 
 
									//��ȡ����ֵ 
									ImageType::PixelType value_north_south = image_chest->GetPixel(index_north_south); 
									if((int)value_north_south>100)
									{
										EnQueue(Q,area_x+1,area_y+1);
										flag[area_x+1][area_y+1] = true;
									}
								}

								if((area_x>=bound_rectangle_x1)&&(area_y+1>=bound_rectangle_y1)&&(area_x<=bound_rectangle_x2)&&(area_y+1<=bound_rectangle_y2)&&!flag[area_x][area_y+1])//��
								{
									//������������ 
									ImageType::IndexType index_south; 
									index_south[0] = area_x; 
									index_south[1] = area_y+1; 
 
									//��ȡ����ֵ 
									ImageType::PixelType value_south = image_chest->GetPixel(index_south); 
									if((int)value_south>100)
									{
										EnQueue(Q,area_x,area_y+1);
										flag[area_x][area_y+1] = true;
									}
								}

								if((area_x-1>=bound_rectangle_x1)&&(area_y+1>=bound_rectangle_y1)&&(area_x-1<=bound_rectangle_x2)&&(area_y+1<=bound_rectangle_y2)&&!flag[area_x-1][area_y+1])//����
								{
									//������������ 
									ImageType::IndexType index_west_south; 
									index_west_south[0] = area_x-1; 
									index_west_south[1] = area_y+1; 
 
									//��ȡ����ֵ 
									ImageType::PixelType value_west_south = image_chest->GetPixel(index_west_south); 
									if((int)value_west_south>100)
									{
										EnQueue(Q,area_x-1,area_y+1);
										flag[area_x-1][area_y+1] = true;
									}
								}


							}//if(DeQueue(Q,area_x,area_y))
						
						}//while(!IsEmpty(Q))�����п�
						free(Q.front);  //�ͷ�ͷ���

							while(!IsEmpty(L))//�����п�
							{
								int L_x,L_y;
								DeQueue(L,L_x,L_y);
							}
							free(L.front);//�ͷ�ͷ���
				}
			}//for(int k=0;k<4;k++)
		

			for (int x=roi_x1; x<=roi_x2; x++) 
			{
				for(int y=roi_y1; y<=roi_y2; y++) 
				{ 
					if(!flag[x][y])
					{
						//������������ 
						ImageType::IndexType index_set; 
						index_set[0] = x; 
						index_set[1] = y; 
 
						image_chest->SetPixel(index_set, 0 );
					}
				}
			}


			//image_chest�����ͼ��image_chest����֧���ܺ�Ľ��
			//image_outer������������������ָ��image_chestͼ����Χ��������
			//image�����ROI�����dicmͼ		

		//====================================================================
		//===========�Էν���ƽ������=========================================
		typedef itk::BinaryBallStructuringElement<
                      PixelType,
                      Dimension  >             StructuringElementType;

		 typedef itk::BinaryErodeImageFilter<
                            ImageType,
                            ImageType,
                            StructuringElementType >  ErodeFilterType;

		 typedef itk::BinaryDilateImageFilter<
                            ImageType,
                            ImageType,
                            StructuringElementType >  DilateFilterType;

		//=========2(�ȽϺã����ҹ���)�ο����㣬�������α�Ե�ľ��״==========
		 ErodeFilterType::Pointer  binaryErode_open[10];
		 DilateFilterType::Pointer binaryDilate_open[10];
		 StructuringElementType  structuringElement_open;

		 structuringElement_open.SetRadius( 1 );  // 3x3 structuring element

		 structuringElement_open.CreateStructuringElement();
		 for(int i=0;i<10;i++)
		 {
			 binaryErode_open[i]  = ErodeFilterType::New();
			 binaryDilate_open[i] = DilateFilterType::New();
			 binaryErode_open[i]->SetKernel(  structuringElement_open );
			 binaryDilate_open[i]->SetKernel( structuringElement_open );
			 binaryErode_open[i]->SetErodeValue( 255 );
			 binaryDilate_open[i]->SetDilateValue( 255 );
		 }

		 int open_it_num;
		 //open_it_num = atoi( argv[10] );                           //�������������
		 open_it_num = 2;                                            //�������������
		 //һ�ο�����
		 binaryErode_open[0]->SetInput( image_chest );
		 binaryDilate_open[0]->SetInput( binaryErode_open[0]->GetOutput());

		 for(int i=1;i<open_it_num;i++)
		 {
			  binaryErode_open[i]->SetInput( binaryDilate_open[i-1]->GetOutput());
			  binaryDilate_open[i]->SetInput( binaryErode_open[i]->GetOutput());
		 }

		 binaryDilate_open[open_it_num-1]->Update();

		 //��ȡͼ�� ��ͼ��image_chest�����㴦������image_chest_open
		ImageType::Pointer image_chest_open = binaryDilate_open[open_it_num-1]->GetOutput();

		//image_chest_open����˶�ͼ��image_chest�����˿������Ľ��

		//====================================================================

		//=========������2���ڸ�ʴ2�����������ڲ�С�ն�=======================
		 ErodeFilterType::Pointer  binaryErode_dilate_erode[10];
		 DilateFilterType::Pointer binaryDilate_dilate_erode[10];
		 StructuringElementType  structuringElement_dilate_erode;

		 structuringElement_dilate_erode.SetRadius( 1 );  // 3x3 structuring element

		 structuringElement_dilate_erode.CreateStructuringElement();
		 for(int i=0;i<10;i++)
		 {
			 binaryErode_dilate_erode[i]  = ErodeFilterType::New();
			 binaryDilate_dilate_erode[i] = DilateFilterType::New();
			 binaryErode_dilate_erode[i]->SetKernel(  structuringElement_dilate_erode );
			 binaryDilate_dilate_erode[i]->SetKernel( structuringElement_dilate_erode );
			 binaryErode_dilate_erode[i]->SetErodeValue( 255 );
			 binaryDilate_dilate_erode[i]->SetDilateValue( 255 );
		 }

		 int dilate_erode_it_num;
		 //dilate_erode_it_num = atoi( argv[13] );                           //���ͺ͸�ʴ�ĵ�������
		 dilate_erode_it_num = 2;                                            //���ͺ͸�ʴ�ĵ�������

		 binaryDilate_dilate_erode[0]->SetInput( image_chest_open );

		 for(int i=1;i<dilate_erode_it_num;i++)
		 {
			 binaryDilate_dilate_erode[i]->SetInput(binaryDilate_dilate_erode[i-1]->GetOutput());
		 }

		 binaryErode_dilate_erode[0]->SetInput( binaryDilate_dilate_erode[dilate_erode_it_num-1]->GetOutput() );

		 for(int i=1;i<dilate_erode_it_num;i++)
		 {
			  binaryErode_dilate_erode[i]->SetInput(binaryErode_dilate_erode[i-1]->GetOutput());
		 }
		 
		 binaryErode_dilate_erode[dilate_erode_it_num-1]->Update();

		 //��ȡͼ�� ��ͼ��image_chest_open���͸�ʴ��������image_chest_open_de
		ImageType::Pointer image_chest_open_de = binaryErode_dilate_erode[dilate_erode_it_num-1]->GetOutput() ;

		//image_chest_open_de����˶�ͼ��image_chest_open���������͸�ʴ�����Ľ��

		//====================================================================

		//====================================================================
		//=========��ͼ��image_chest_open_de���ɳ���ģmask_init===============
		int seed_mask_x,seed_mask_y;
		bool flag_loop_mask=false;
		//��ȡ����ͼ��Ĵ�С 
		ImageType::SizeType size_mask = image_chest_open_de->GetLargestPossibleRegion().GetSize(); 
			//ѭ�������������� 
		for (int y=0; y<size_mask[1]; y++) 
		{
			for(int x=0; x<size_mask[0]; x++) 
				{ 
					  //������������ 
					  ImageType::IndexType index,index2,index3; 
					  index[0] = x; 
					  index[1] = y; 

					  index2[0] = x+1;
					  index2[1] = y;

					  index3[0] = x+2;
					  index3[1] = y;
 
					  //��ȡ����ֵ 
					  ImageType::PixelType value = image_chest_open_de->GetPixel(index); 
					  ImageType::PixelType value2 = image_chest_open_de->GetPixel(index2); 
					  ImageType::PixelType value3 = image_chest_open_de->GetPixel(index3); 
					  if (((int(value))<50)&&(((int)value2)<50)&&(((int)value3)<50)) 
					  { 
						  seed_mask_x=x;
						  seed_mask_y=y;
						  flag_loop_mask=true;
						  break;
					  } 
				                                      
				}
			if(flag_loop_mask)
			{
				break;
			}
		}

		CastingFilterType_image2internal::Pointer caster_image2internal_mask_init = CastingFilterType_image2internal::New();

		CastingFilterType_internal2image::Pointer caster_internal2image_mask_init = CastingFilterType_internal2image::New();

		caster_image2internal_mask_init->SetInput(image_chest_open_de);

		ConnectedFilterType::Pointer connectedThreshold_mask_area = ConnectedFilterType::New();

		connectedThreshold_mask_area->SetInput( caster_image2internal_mask_init->GetOutput() );
	
		caster_internal2image_mask_init->SetInput( connectedThreshold_mask_area->GetOutput() );

		//��ȡͼ�� ��ͼ��image_chest_open_de�еõ�mask_init
		ImageType::Pointer mask_init =caster_internal2image_mask_init->GetOutput();

		const InternalPixelType lowerThreshold_mask_area = 0;
		const InternalPixelType upperThreshold_mask_area = 50;

		connectedThreshold_mask_area->SetLower(  lowerThreshold_mask_area  );
		connectedThreshold_mask_area->SetUpper(  upperThreshold_mask_area  );


		connectedThreshold_mask_area->SetReplaceValue( 255 );


			InternalImageType::IndexType  inter_mask_area_Index;

			inter_mask_area_Index[0] = seed_mask_x;     //ȡ���ӵ�
			inter_mask_area_Index[1] = seed_mask_y;

			connectedThreshold_mask_area->SetSeed( inter_mask_area_Index );

			try
			{
				caster_internal2image_mask_init->Update();
			}
			catch( itk::ExceptionObject & excep )
			{
				std::cerr << "Exception caught !" << std::endl;
				std::cerr << excep << std::endl;
			}

			//�Ժ�һ���ͼ��image_chest_open_de���ɳ���ģmask_init
		//====================================================================

		//======================�Գ���ģmask_init�Ҷ�ֵ�ߵ�������ģmask========

		//�������������Ҫ����ͼ��ָ�����Ҫ���ʵ�ͼ�������С 
		typedef itk::ImageRegionIterator<ImageType> ItType; 
		ItType it_mask_fin( mask_init, mask_init->GetRequestedRegion() ); 
		//���������ƶ����׸�Ԫ�� 
		it_mask_fin.GoToBegin(); 
		//�������أ�ֱ������ 
		while( !it_mask_fin.IsAtEnd()) 
		{ 
			 //��ȡ����ֵ 
			ImageType::PixelType value = it_mask_fin.Get(); 

			if((int(value))>200)
			{
				it_mask_fin.Set(0); 
			}

			if((int(value))<50)
			{
				it_mask_fin.Set(255); 
			}
   
			//�������ƶ�����һԪ�� 
			++it_mask_fin;
		} 

		//��ȡͼ�� ��ͼ��mask_init�еõ�msak
		ImageType::Pointer mask = mask_init;

		//mask���������ģ

		//=================================================================================

		//===============��mask��ģ��image_init�зָ����image_lung========================

		ReaderType::Pointer reader_init = ReaderType::New();
		reader_init->SetFileName( filenames[fni] );                                  //����dicomͼ��filenames[fni]
		ImageIOType::Pointer gdcmImageIO_init = ImageIOType::New();
		reader_init->SetImageIO( gdcmImageIO_init );
		 try
		{
			 reader_init->Update();
		}
		 catch (itk::ExceptionObject & e)
		{
			std::cerr << "exception in file reader " << std::endl;
			std::cerr << e << std::endl;
		 return EXIT_FAILURE;
		}

		 RescaleFilterType::Pointer rescaler_init = RescaleFilterType::New();

		 rescaler_init->SetOutputMinimum(   0 );
		 rescaler_init->SetOutputMaximum( 255 );
		 rescaler_init->SetInput( reader_init->GetOutput() );                      //�Զ����dicmͼƬ����RescaleIntensityImageFilter����
		 rescaler_init->Update();                                             //ִ�йܵ�

		 //��ȡͼ�� 
		ImageType::Pointer image_init = rescaler_init->GetOutput(); 


			//�������������Ҫ����ͼ��ָ�����Ҫ���ʵ�ͼ�������С 
			typedef itk::ImageRegionIterator<ImageType> ItType; 
			ItType it_init_lung( image_init, image_init->GetRequestedRegion() ); 
			ItType it_musk_lung( mask, mask->GetRequestedRegion() ); 
 
			//���������ƶ����׸�Ԫ�� 
			it_init_lung.GoToBegin(); 
			it_musk_lung.GoToBegin(); 


			//�������أ�ֱ������ 
			while( (!it_init_lung.IsAtEnd())&&(!it_musk_lung.IsAtEnd())) 
			{ 
				ImageType::PixelType value_musk_lung = it_musk_lung.Get(); 

				if((int(value_musk_lung))<50)
				{
					it_init_lung.Set(0); 
				}
   
				//�������ƶ�����һԪ�� 
				++it_init_lung;
				++it_musk_lung;
			} 

			//��ȡͼ�� ��mask��ģ��image�зָ����image_lung
			ImageType::Pointer image_lung = image_init;

			CString dicmfilename = outputDirectory +"\\"+"\\"+"lungCT"+ outputimagename[i] +".dcm";

			WriterType::Pointer writer_seg_lung = WriterType::New();
			writer_seg_lung->SetFileName( dicmfilename );                   // ��mask��ģ��image�зָ����image_lung
			writer_seg_lung->SetInput( image_lung);
			writer_seg_lung->UseInputMetaDataDictionaryOff ();
			writer_seg_lung->SetImageIO( gdcmImageIO );
			try
			{
				writer_seg_lung->Update();
			}
			catch( itk::ExceptionObject & excep )
			{
				std::cerr << "Exception caught !" << std::endl;
				std::cerr << excep << std::endl;
			}

			//mask��ģ��image�зָ����image_lung
		//=======================================================================================

		//====================��mask��ģ����4������PET��ģPET_mask===============================
		typedef itk::ResampleImageFilter<
					  ImageType, ImageType >  PETFilterType;

		PETFilterType::Pointer PET_filter = PETFilterType::New();
		typedef itk::Similarity2DTransform< double >  TransformType;
		TransformType::Pointer transform = TransformType::New();

		typedef itk::LinearInterpolateImageFunction<
						   ImageType, double >  InterpolatorType;
		InterpolatorType::Pointer interpolator = InterpolatorType::New();

		PET_filter->SetInterpolator( interpolator );

		PET_filter->SetDefaultPixelValue( 100 );

		const ImageType::SpacingType&
		PET_spacing = mask->GetSpacing();
		const ImageType::PointType&
		PET_origin  = mask->GetOrigin();
		const ImageType::DirectionType&
		PET_direction  = mask->GetDirection();
		InputImageType::SizeType PET_size =
		mask->GetLargestPossibleRegion().GetSize();

		PET_size[0] = PET_size[0]/4;
		PET_size[1] = PET_size[1]/4;

		PET_filter->SetOutputOrigin( PET_origin );
		PET_filter->SetOutputSpacing( PET_spacing );
		PET_filter->SetOutputDirection( PET_direction );
		PET_filter->SetSize( PET_size );

		PET_filter->SetInput( mask ); 

		TransformType::InputPointType rotationCenter;
		rotationCenter[0] = PET_origin[0] + PET_spacing[0] * PET_size[0] / 2.0;
		rotationCenter[1] = PET_origin[1] + PET_spacing[1] * PET_size[1] / 2.0;
		transform->SetCenter( rotationCenter );

		transform->SetAngle( 0.0 );
		transform->SetScale( 4 );//����4��

		TransformType::OutputVectorType translation;

		translation[0] =   192*PET_spacing[0]; //ƽ��
		translation[1] =   192*PET_spacing[1];

		transform->SetTranslation( translation );

		PET_filter->SetTransform( transform );

		PET_filter->Update();
		 //��ȡͼ�� 
		ImageType::Pointer PET_mask = PET_filter->GetOutput();

		//��mask��ģ����4������PET��ģPET_mask
		//=======================================================================================

		//=================��PET_mask��ģ��PET_image�зָ����image_lungPET======================
		ReaderType::Pointer PET_reader = ReaderType::New();
		PET_reader->SetFileName( PET_filenames[PET_fni] );                                  //����PET_dicomͼ��PET_filenames[PET_fni]
		ImageIOType::Pointer PET_gdcmImageIO = ImageIOType::New();
		PET_reader->SetImageIO( PET_gdcmImageIO );
		 try
		{
			 PET_reader->Update();
		}
		 catch (itk::ExceptionObject & e)
		{
			std::cerr << "exception in file reader " << std::endl;
			std::cerr << e << std::endl;
			return EXIT_FAILURE;
		}

		 RescaleFilterType::Pointer PET_rescaler = RescaleFilterType::New();

		 PET_rescaler->SetOutputMinimum(   0 );
		 PET_rescaler->SetOutputMaximum( 255 );
		 PET_rescaler->SetInput( PET_reader->GetOutput() );                      //�Զ����dicmͼƬ����RescaleIntensityImageFilter����
		 PET_rescaler->Update();                                             //ִ�йܵ�

		 //��ȡͼ�� 
		ImageType::Pointer PET_image = PET_rescaler->GetOutput(); 

		//�������������Ҫ����ͼ��ָ�����Ҫ���ʵ�ͼ�������С 
			typedef itk::ImageRegionIterator<ImageType> ItType; 
			ItType it_init_lungPET( PET_image, PET_image->GetRequestedRegion() ); 
			ItType it_musk_lungPET( PET_mask, PET_mask->GetRequestedRegion() ); 
 
			//���������ƶ����׸�Ԫ�� 
			it_init_lungPET.GoToBegin(); 
			it_musk_lungPET.GoToBegin(); 


			//�������أ�ֱ������ 
			while( (!it_init_lungPET.IsAtEnd())&&(!it_musk_lungPET.IsAtEnd())) 
			{ 
				ImageType::PixelType value_musk_lungPET = it_musk_lungPET.Get(); 

				if((int(value_musk_lungPET))<50)
				{
					it_init_lungPET.Set(0); 
				}
   
				//�������ƶ�����һԪ�� 
				++it_init_lungPET;
				++it_musk_lungPET;
			} 

			//��ȡͼ�� ��PET_mask��ģ��PET_image�зָ����image_lungPET
			ImageType::Pointer image_lungPET = PET_image;

			CString PET_dicmfilename = PET_outputDirectory +"\\"+"\\"+"lungPET"+ outputimagename[i] +".dcm";

			WriterType::Pointer writer_seg_lungPET = WriterType::New();
			writer_seg_lungPET->SetFileName( PET_dicmfilename );                   // ��mask��ģ��image�зָ����image_lung
			writer_seg_lungPET->SetInput( image_lungPET);
			writer_seg_lungPET->UseInputMetaDataDictionaryOff ();
			writer_seg_lungPET->SetImageIO( gdcmImageIO );
			try
			{
				writer_seg_lungPET->Update();
			}
			catch( itk::ExceptionObject & excep )
			{
				std::cerr << "Exception caught !" << std::endl;
				std::cerr << excep << std::endl;
			}

			//PET_mask��ģ��PET_image�зָ����image_lungPET

		//=======================================================================================
			PET_fni++;

		}//for

		ReaderType_series::Pointer reader_series = ReaderType_series::New();

		reader_series->SetImageIO( gdcmIO_series );
		reader_series->SetFileNames( filenames );

		try
		{
			reader_series->Update();
		}
		catch (itk::ExceptionObject &excp)
		{
		std::cerr << "Exception thrown while writing the image" << std::endl;
		std::cerr << excp << std::endl;
		return EXIT_FAILURE;
		}

		//==================PET=====================================
		ReaderType_series::Pointer reader_seriesPET = ReaderType_series::New();

		reader_seriesPET->SetImageIO( PET_gdcmIO_series );
		reader_seriesPET->SetFileNames( PET_filenames );

		try
		{
			reader_seriesPET->Update();
		}
		catch (itk::ExceptionObject &excp)
		{
		std::cerr << "Exception thrown while writing the image" << std::endl;
		std::cerr << excp << std::endl;
		return EXIT_FAILURE;
		}
		//==========================================================

		//std::cout<<"�������н�����"<<std::endl;
		strPETCTSeriesSeg +=_T("\r\n�������н�����");
		m_editPETCTSeriesSeg_View.SetWindowText(_T(strPETCTSeriesSeg));

		Finish=clock( );                            //��ʱ����
		time = (double)(Finish-Start)*1000/CLOCKS_PER_SEC;
		//std::cout<<"��ʱ��time = "<<time<<"ms"<<std::endl;


		char strConvertDouble[25];
		gcvt(time,10,strConvertDouble);

		strPETCTSeriesSeg +=_T("\r\n��ʱ��time = ");
		strPETCTSeriesSeg +=_T(strConvertDouble);
		strPETCTSeriesSeg +=_T("ms");
		m_editPETCTSeriesSeg_View.SetWindowText(_T(strPETCTSeriesSeg)); 

		//UpdateData(FALSE);
		return 0;
}
//=======================================================================