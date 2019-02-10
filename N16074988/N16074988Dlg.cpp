
// N16074988Dlg.cpp : 實作檔
//伍錫志

#include "stdafx.h"
#include "N16074988.h"
#include "N16074988Dlg.h"
#include "afxdialogex.h"
#include <cstdio>
#include <opencv2\highgui\highgui.hpp>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <typeinfo>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include "opencv2/imgcodecs.hpp"
#include <opencv2/ml.hpp>
# include <vector> 
#include<atlstr.h>
using namespace cv;
using namespace std;
using namespace cv::ml;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 對 App About 使用 CAboutDlg 對話方塊

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 對話方塊資料
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援

														// 程式碼實作
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CN16074988Dlg 對話方塊



CN16074988Dlg::CN16074988Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_N16074988_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CN16074988Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CN16074988Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CN16074988Dlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CN16074988Dlg::OnBnClickedButton1)
//	ON_EN_UPDATE(m_editCtrl, &CN16074988Dlg::OnUpdateMEditctrl)
//	ON_STN_ENABLE(m_strTextCtrl, &CN16074988Dlg::OnEnableMStrtextctrl)
ON_EN_CHANGE(m_editCtrl, &CN16074988Dlg::OnEnChangeeditctrl)
ON_STN_CLICKED(m_strTextCtrl, &CN16074988Dlg::OnStnClickedstrtextctrl)
//ON_EN_CHANGE(IDC_EDIT1, &CN16074988Dlg::OnEnChangeEdit1)
ON_EN_CHANGE(IDC_EDIT2, &CN16074988Dlg::OnEnChangeEdit2)
ON_EN_CHANGE(IDC_EDIT3, &CN16074988Dlg::OnEnChangeEdit3)
END_MESSAGE_MAP()


// CN16074988Dlg 訊息處理常式

BOOL CN16074988Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 將 [關於...] 功能表加入系統功能表。

	// IDM_ABOUTBOX 必須在系統命令範圍之中。
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

	// 設定此對話方塊的圖示。當應用程式的主視窗不是對話方塊時，
	// 框架會自動從事此作業
	SetIcon(m_hIcon, TRUE);			// 設定大圖示
	SetIcon(m_hIcon, FALSE);		// 設定小圖示

									// TODO: 在此加入額外的初始設定
	AllocConsole();
	freopen("CONOUT$", "w", stdout);


	CStatic * m_MyStaticControl;
	m_MyStaticControl = (CStatic *)GetDlgItem(IDC_STATIC2);
	CString aCString = CString(_T("Train image: data01/image/image0121 \n Label image: data01/label/image0121"));
	m_MyStaticControl->SetWindowText(aCString);

	return TRUE;  // 傳回 TRUE，除非您對控制項設定焦點
}

void CN16074988Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果將最小化按鈕加入您的對話方塊，您需要下列的程式碼，
// 以便繪製圖示。對於使用文件/檢視模式的 MFC 應用程式，
// 框架會自動完成此作業。

void CN16074988Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 繪製的裝置內容

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 將圖示置中於用戶端矩形
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 描繪圖示
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 當使用者拖曳最小化視窗時，
// 系統呼叫這個功能取得游標顯示。
HCURSOR CN16074988Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);

}
void writeMatToFile(cv::Mat& m, const char* filename)
{
	ofstream fout(filename);

	if (!fout)
	{
		cout << "File Not Opened" << endl;  return;
	}

	for (int i = 0; i<m.rows; i++)
	{
		for (int j = 0; j<m.cols; j++)
		{
			fout << m.at<float>(i, j) << "\t";
		}
		fout << endl;
	}

	fout.close();
}

template <typename T> string tostr(const T& t) {
	ostringstream os;
	os << t;
	return os.str();
}
void CN16074988Dlg::OnBnClickedOk()
{
	//Mat train_1 = imread("image0131.png");
	//Mat test_image = imread("./Data/data01/image/image0132.png");
	//Mat train_image = imread("./Data/data01/label/image0132.png");

	string head = "./Data/data";
	string test_middle = "/image/image";
	string ground_middle = "/label/image";
	string end = ".png";

	CString data_num_string;
	CEdit *data_num;
	data_num = (CEdit*)GetDlgItem(IDC_EDIT2);

	data_num->GetWindowText(data_num_string); //讀取
	CT2CA pszConvertedAnsiString(data_num_string);
	string yee1(pszConvertedAnsiString);
	if (yee1 == "")
	{
		yee1 = "02";
	}
	cout << yee1 << endl;

	CString image_num_string;
	CEdit *image_num;
	image_num = (CEdit*)GetDlgItem(IDC_EDIT3);
	image_num->GetWindowText(image_num_string); //讀取
	CT2CA pszConvertedAnsiString2(image_num_string);
	string yee3(pszConvertedAnsiString2);
	if (yee3 == "")
	{
		yee3= "0202";
	}
	cout << yee3 << endl;
	cout << head + yee1 + test_middle + yee3 + end << endl;
	cout << head + yee1 + ground_middle + yee3 + end << endl;

	Mat test_image_1 = imread(head + yee1 + test_middle + yee3 + end);
	Mat ground_truth = imread(head + yee1 + ground_middle + yee3 + end);

//	Mat test_image_1 = imread("./Data/data01/image/image0080.png");
//	Mat ground_truth = imread("./Data/data01/label/image0080.png");

	Mat train_image_1 = imread("./Data/data01/image/image0121.png");
	Mat train_label_1 = imread("./Data/data01/label/image0121.png");

//	Mat train_image_2 = imread("./Data/data02/image/image0113.png");
//	Mat train_label_2 = imread("./Data/data02/label/image0113.png");

	// CV_8UC3 use at.<Vec3b>
	Mat color_img(512, 512, CV_8UC3, Scalar(200, 100, 0));

	//cout << train_image_1;
	imshow("Testing Image", test_image_1);
	//imshow("Training image", train_image_1);
	imshow("Ground Truth", ground_truth);

	cout << "rows: " << train_image_1.rows << " " << endl;

	/*
	Vec3b  bgrPixel = train_image_1.at<Vec3b>(200, 200);
	cout << "3 channel value on point (200, 200): " << bgrPixel << endl;
	float blue = bgrPixel.val[0];
	cout << "Blue channel value on point (200, 200): " << blue << endl;
	cout << "type of bgrPixel.val[0]:  " << typeid(bgrPixel.val[0]).name() << endl;
	*/

	// CV_32FC1 use .at<float>
	Mat trainingDataMat_to_float_1(train_image_1.rows, train_image_1.cols, CV_32FC1);
	Mat training_label_to_float_1(train_label_1.rows, train_label_1.cols, CV_32FC1);

//	Mat trainingDataMat_to_float_2(train_image_2.rows, train_image_2.cols, CV_32FC1);
//	Mat training_label_to_float_2(train_label_2.rows, train_label_2.cols, CV_32FC1);

	Mat testingDataMat_to_float(test_image_1.rows, test_image_1.cols, CV_32FC1);
	Mat grouod_truth_to_float(ground_truth.rows, ground_truth.cols, CV_32FC1);


	for (int j = 0; j < train_image_1.rows; j++)
	{
		for (int i = 0; i < train_image_1.cols; i++)
		{
			float data = train_image_1.at<Vec3b>(j, i).val[0];
			trainingDataMat_to_float_1.at<float>(j, i) = data;
		}
	}

	for (int j = 0; j < train_label_1.rows; j++)
	{
		for (int i = 0; i < train_label_1.cols; i++)
		{
			float data = train_label_1.at<Vec3b>(j, i).val[0];
			training_label_to_float_1.at<float>(j, i) = data;
		}
	}

	/*
	for (int j = 0; j < train_image_2.rows; j++)
	{
		for (int i = 0; i < train_image_2.cols; i++)
		{
			float data = train_image_2.at<Vec3b>(j, i).val[0];
			trainingDataMat_to_float_2.at<float>(j, i) = data;
		}
	}

	for (int j = 0; j < train_label_2.rows; j++)
	{
		for (int i = 0; i < train_label_2.cols; i++)
		{
			float data = train_label_2.at<Vec3b>(j, i).val[0];
			training_label_to_float_2.at<float>(j, i) = data;
		}
	}
	*/
	for (int j = 0; j < test_image_1.rows; j++)
	{
		for (int i = 0; i < test_image_1.cols; i++)
		{
			float data = test_image_1.at<Vec3b>(j, i).val[0];
			testingDataMat_to_float.at<float>(j, i) = data;
		}
	}

	for (int j = 0; j < ground_truth.rows; j++)
	{
		for (int i = 0; i < ground_truth.cols; i++)
		{
			float data = ground_truth.at<Vec3b>(j, i).val[0];
			grouod_truth_to_float.at<float>(j, i) = data;
		}
	}

	Mat trainingDataMat_1 = trainingDataMat_to_float_1.clone().reshape(0, trainingDataMat_to_float_1.cols*trainingDataMat_to_float_1.rows);
	Mat trainlabelDataMat_1 = training_label_to_float_1.clone().reshape(0, training_label_to_float_1.cols*training_label_to_float_1.rows);
//	Mat trainingDataMat_2 = trainingDataMat_to_float_2.clone().reshape(0, trainingDataMat_to_float_2.cols*trainingDataMat_to_float_2.rows);
//	Mat trainlabelDataMat_2 = training_label_to_float_2.clone().reshape(0, training_label_to_float_2.cols*training_label_to_float_2.rows);

	Mat testingDataMat = testingDataMat_to_float.clone().reshape(0, testingDataMat_to_float.cols*testingDataMat_to_float.rows);
	Mat groundDataMat = grouod_truth_to_float.clone().reshape(0, grouod_truth_to_float.cols*grouod_truth_to_float.rows);

	cout << "trainingDataMat_to_float_1.rows: " << trainingDataMat_to_float_1.rows << " ," << "trainingDataMat_to_float_1.cols: " << trainingDataMat_to_float_1.cols << endl;
//	cout << "trainingDataMat_to_float_2.rows: " << trainingDataMat_to_float_2.rows << " ," << "trainingDataMat_to_float_2.cols: " << trainingDataMat_to_float_2.cols << endl;

	cout << "testingDataMat_to_float.rows: " << testingDataMat_to_float.rows << " ," << "testingDataMat_to_float.cols: " << testingDataMat_to_float.cols << endl;
	cout << "trainingDataMat_to_float_1  size: " << trainingDataMat_to_float_1.size() << endl;
//	cout << "trainingDataMat_to_float_2  size: " << trainingDataMat_to_float_2.size() << endl;
	cout << "testingDataMat_to_float  size: " << testingDataMat_to_float.size() << endl;

	cout << "trainingDataMat_1.rows: " << trainingDataMat_1.rows << " ," << "trainingDataMat_1.cols: " << trainingDataMat_1.cols << endl;
//	cout << "trainingDataMat_2.rows: " << trainingDataMat_2.rows << " ," << "trainingDataMat_2.cols: " << trainingDataMat_2.cols << endl;
	cout << "testingDataMat.rows: " << testingDataMat.rows << " ," << "testingDataMat.cols: " << testingDataMat.cols << endl;
	cout << "trainingDataMat_1  size: " << trainingDataMat_1.size() << endl;
	cout << "testingDataMat  size: " << testingDataMat.size() << endl;
	cout << "trainlabelDataMat_1  size:  " << trainlabelDataMat_1.size()<<endl;
	cout << "grouod_truth_to_float size" << grouod_truth_to_float.size() << endl;

	// 使用OpenCV里面的机器学习算法时，要保证给的labelData的数据格式为”有符号的整型数”，
	// ”CV_32FC1”就是错误的一种形式，应该使用”CV_32SC1

	Mat labels_1 = Mat(512 * 512, 1, CV_32SC1);
	Mat labels_2 = Mat(512 * 512, 1, CV_32SC1);

	cout << "label matrix size: " << labels_1.size() << endl;
	cout << "label matrix row number: " << labels_1.rows << endl;

	for (int i = 0; i < labels_1.rows; i++)
	{
		labels_1.at<float>(i, 0) = -1.0;
	}

	for (int i = 0; i < labels_2.rows; i++)
	{
		labels_2.at<float>(i, 0) = -1;
	}

	float count_label_1 = 0;
	float count_label_2 = 0;

	/*
	float count_training_label_DataMat_1 = 0;
	for (int j = 0; j < trainingDataMat_1.rows; j++)
	{
		if (trainingDataMat_1.at<float>(j, 0) >220)
		{
			count_training_label_DataMat_1++;

			labels_1.at<float>(j, 0) = 1.0;
		}
	}
	*/

	
	float count_training_label_DataMat_1 = 0;
	for (int j = 0; j < trainlabelDataMat_1.rows; j++)
	{
		if (trainlabelDataMat_1.at<float>(j, 0) !=0)
		{
			count_training_label_DataMat_1++;
			labels_1.at<float>(j, 0) = 1.0;
		}
	}
	
	
	const char* filename_2 = "trainlabelDataMat_1.txt";
	writeMatToFile(trainlabelDataMat_1, filename_2);

	const char* filename_3 = "labels_1.txt";
	writeMatToFile(labels_1, filename_3);

	/*
	float count_training_label_DataMat_2 = 0;
	for (int j = 0; j < trainlabelDataMat_2.rows; j++)
	{
		if (trainlabelDataMat_2.at<float>(j, 0) != 0)
		{
			count_training_label_DataMat_2++;
			labels_2.at<float>(j, 0) = 1.0;
		}
	}
	*/

	for (int j = 0; j < labels_1.rows; j++)
	{
		if (labels_1.at<float>(j, 0) == 1)
		{
			count_label_1++;
		}
	}

	/*
	for (int j = 0; j < labels_2.rows; j++)
	{
		if (labels_2.at<float>(j, 0) == 1)
		{
			count_label_2++;
		}
	}
	*/

	float count_neg_label_1 = 0;
	for (int j = 0; j < labels_1.rows; j++)
	{
		if (labels_1.at<float>(j, 0) == -1)
		{
			count_neg_label_1++;
		}
	}

	float testing_data_white = 0;
	for (int j = 0; j < testingDataMat.rows; j++)
	{
		if (testingDataMat.at<float>(j, 0) != 0)
		{
			testing_data_white++;
		}
	}

	float ground_truth_white = 0;
	for (int j = 0; j < groundDataMat.rows; j++)
	{
		if (groundDataMat.at<float>(j, 0) != 0)
		{
			ground_truth_white++;
		}
	}

	cout << "train label_1 white: " <<  count_training_label_DataMat_1 << ", " << count_label_1 << endl;
//	cout << "train label_2 white: " << count_label_2 << endl;
	cout << "train data black: " << count_neg_label_1 << endl;
//	cout << "test data white: " << testing_data_white << endl;
	cout << "ground truth white: " << ground_truth_white << endl;

	//cout << "White Pixels in ground truth image: " << count << endl;
	//cout << "Value 1 in label list: " << count_2 << endl;
	//cout << labels;

	const char* filename1 = "original.txt";
	writeMatToFile(trainingDataMat_1, filename1);

	Ptr<SVM> svm = SVM::create();
	svm->setType(SVM::C_SVC);
	svm->setKernel(SVM::RBF);
	svm->setC(1);
	double c = svm->getC();
	cout << "C=" << c << endl;
	//svm->setTermCriteria(TermCriteria(TermCriteria::MAX_ITER, (int)1e5, 1e-6));
	svm->setTermCriteria(TermCriteria(TermCriteria::MAX_ITER, 2000, -0.1));

//	trainingDataMat_1.push_back(trainingDataMat_2);
//	cout << "a.rows: " << trainingDataMat_1.rows << " ," << "a.cols: " << trainingDataMat_1.cols << endl;

//	labels_1.push_back(labels_2);
//	cout << "a.rows: " << labels_1.rows << " ," << "a.cols: " << labels_1.cols << endl;

	svm->train(trainingDataMat_1, ROW_SAMPLE, labels_1);

	//	svm->train(trainingDataMat_2, ROW_SAMPLE, labels_2);
	//svm->train(trainingDataMat, ROW_SAMPLE, labels);
	cout << "Finished training process" << endl;
	Mat ppp;
	ppp = svm->getSupportVectors();
	//	cout << "Support Vectors: "<<ppp << endl;

	//float response = svm->predict(testingDataMat);

	int result_white_count_in_ploting = 0;

	Vec3b black(0, 0, 0), white(255, 255, 255), yellow(30, 255, 255);
	for (int j = 0; j < testingDataMat_to_float.rows; j++)
	{
		for (int i = 0; i < testingDataMat_to_float.cols; i++)
		{
			Mat sampleMat(1, 1, CV_32FC1);

			sampleMat.at<float>(0, 0) = testingDataMat_to_float.at<float>(j, i);

			float response = svm->predict(sampleMat);

			//cout << sampleMat;
			//cout << "reponse: " << response << endl;

			if (response > 0)
			{
				color_img.at<Vec3b>(j, i) = white;
				result_white_count_in_ploting++;
			}
			else if (response < 0)
			{
				color_img.at<Vec3b>(j, i) = black;
			}

			else
			{
				color_img.at<Vec3b>(j, i) = yellow;
			}
		}
	}

	Mat output;
	svm->predict(testingDataMat, output);
	//cout << "output : " << output << endl;	

	const char* filename = "output.txt";
	writeMatToFile(output, filename);

	cout << "Result white count from loop: " << result_white_count_in_ploting << endl;

	Mat Result_to_float(color_img.rows, color_img.cols, CV_32FC1);

	for (int j = 0; j < color_img.rows; j++)
	{
		for (int i = 0; i < color_img.cols; i++)
		{
			float data = color_img.at<Vec3b>(j, i).val[0];
			Result_to_float.at<float>(j, i) = data;
		}
	}

	float ground_white_from_Mat = 0;
	float result_white_from_Mat = 0;
	float Interscetion = 0;
	for (int j = 0; j < Result_to_float.rows; j++)
	{
		for (int i = 0; i < Result_to_float.cols; i++)
		{
			if (Result_to_float.at<float>(j, i) != 0)
			{
				result_white_from_Mat++;
			}

			if (grouod_truth_to_float.at<float>(j, i) != 0)
			{
				ground_white_from_Mat++;
			}

			if (Result_to_float.at<float>(j, i) != 0 && grouod_truth_to_float.at<float>(j, i) != 0)
			{
				Interscetion++;
			}
		}
	}

	/*
	Mat ResultDataMat = Result_to_float.clone().reshape(0, Result_to_float.cols*Result_to_float.rows);

	float Interscetion = 0;

	float result_white_from_Mat = 0;
	for (int j = 0; j < ResultDataMat.rows; j++)
	{
	if (ResultDataMat.at<float>(j, 0) != 0  && groundDataMat.at<float>(j, 0) != 0)
	{
	Interscetion++;
	}
	if (ResultDataMat.at<float>(j, 0) != 0)
	{
	result_white_from_Mat++;
	}
	}
	*/

	cout << "Interscetion: " << Interscetion << endl;
	cout << "ground_white_from_Mat: " << ground_white_from_Mat << endl;
	cout << "result_white_from_Mat:  " << result_white_from_Mat << endl;
	float dice = ((2 * (Interscetion)) / (result_white_count_in_ploting + ground_truth_white)) * 100;
	cout << "Dice Coefficient: " << dice << "%" << endl;

	imshow("SVM Result.jpg", color_img);


	string sy = tostr(dice);
	CStatic * m_MyStaticControl;
	m_MyStaticControl = (CStatic *)GetDlgItem(IDC_STATIC5);
	CString cstr(  sy.c_str() );
	CString per = CString(_T("%"));
	m_MyStaticControl->SetWindowText(cstr+ per);

	string sy2 = tostr(result_white_from_Mat);
	CStatic * m_MyStaticControl2;
	m_MyStaticControl2 = (CStatic *)GetDlgItem(IDC_STATIC6);
	CString cstr2(sy2.c_str());	
	m_MyStaticControl2->SetWindowText(cstr2);

	string sy3 = tostr(ground_white_from_Mat);
	CStatic * m_MyStaticControl3;
	m_MyStaticControl3 = (CStatic *)GetDlgItem(IDC_STATIC7);
	CString cstr3(sy3.c_str());
	m_MyStaticControl3->SetWindowText(cstr3);

	string sy4 = tostr(Interscetion);
	CStatic * m_MyStaticControl4;
	m_MyStaticControl4 = (CStatic *)GetDlgItem(IDC_STATIC8);
	CString cstr4(sy4.c_str());	
	m_MyStaticControl4->SetWindowText(cstr4);


}



void CN16074988Dlg::OnBnClickedButton1()
{
	// Set text in Static Text box
	/*
	CStatic * m_MyStaticControl;
	m_MyStaticControl=(CStatic *)GetDlgItem(IDC_STATIC2);
	CString aCString = CString(_T("A string"));
	m_MyStaticControl->SetWindowText(aCString);
	*/
}

void CN16074988Dlg::OnEnChangeeditctrl()
{
	// TODO:  如果這是 RICHEDIT 控制項，控制項將不會
	// 傳送此告知，除非您覆寫 CDialogEx::OnInitDialog()
	// 函式和呼叫 CRichEditCtrl().SetEventMask()
	// 讓具有 ENM_CHANGE 旗標 ORed 加入遮罩。

	// TODO:  在此加入控制項告知處理常式程式碼
}


void CN16074988Dlg::OnStnClickedstrtextctrl()
{
	// TODO: 在此加入控制項告知處理常式程式碼
}


void CN16074988Dlg::OnEnChangeEdit1()
{
	// TODO:  如果這是 RICHEDIT 控制項，控制項將不會
	// 傳送此告知，除非您覆寫 CDialogEx::OnInitDialog()
	// 函式和呼叫 CRichEditCtrl().SetEventMask()
	// 讓具有 ENM_CHANGE 旗標 ORed 加入遮罩。

	// TODO:  在此加入控制項告知處理常式程式碼
}


void CN16074988Dlg::OnEnChangeEdit2()
{
	// TODO:  如果這是 RICHEDIT 控制項，控制項將不會
	// 傳送此告知，除非您覆寫 CDialogEx::OnInitDialog()
	// 函式和呼叫 CRichEditCtrl().SetEventMask()
	// 讓具有 ENM_CHANGE 旗標 ORed 加入遮罩。

	// TODO:  在此加入控制項告知處理常式程式碼
}


void CN16074988Dlg::OnEnChangeEdit3()
{
	// TODO:  如果這是 RICHEDIT 控制項，控制項將不會
	// 傳送此告知，除非您覆寫 CDialogEx::OnInitDialog()
	// 函式和呼叫 CRichEditCtrl().SetEventMask()
	// 讓具有 ENM_CHANGE 旗標 ORed 加入遮罩。

	// TODO:  在此加入控制項告知處理常式程式碼
}
