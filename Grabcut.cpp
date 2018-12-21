#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/video/background_segm.hpp>
#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <iostream>
#include <sstream>

using namespace cv;
using namespace std;

/* GrabCut algorithm in a very simple way using opencv implementations*/

Point point1, point2;
int drag = 0;
Rect rect; 
Mat img, roiImg; 
bool select_flag = true;
Mat rectimg;
vector<Point>Pf,Pb;


void mouseHandler(int event, int x, int y, int flags, void* param)
{
	if (event == EVENT_LBUTTONDOWN && !drag)
	{
		point1 = Point(x, y);
		drag = 1;
	}

	else if (event == EVENT_MOUSEMOVE && drag)
	{
		
		Mat img1 = img.clone();
		point2 = Point(x, y);
		rectangle(img1, point1, point2, CV_RGB(255, 0, 0), 3, 8, 0);
		imshow("image", img1);
			
	}

	else if (event == EVENT_LBUTTONUP && drag)
	{
		point2 = Point(x, y);
		rect = Rect(point1.x,point1.y,x-point1.x,y-point1.y);
		drag = 0;
		roiImg = img(rect);
			
	}

	else if (event == EVENT_RBUTTONDOWN)
	{
		
		select_flag = false;
		drag = 0;
		imshow("ROI", roiImg);
		
	}
}

int main(int argc, char** argv)
{	
	
	img= imread(argv[1]);
	Mat img2=img.clone();
	cv::Mat foreground(img.size(),CV_8UC3,cv::Scalar(255,255,255));
	Mat result(img.size(),CV_8UC1);
	Mat fg,bg;
	namedWindow("image",1);
	imshow("image", img);
	int i;
	setMouseCallback("image", mouseHandler, NULL);
	cout<<"Enter number of iteration"<<endl;
	cin>>i;

	while((select_flag==true)&&(waitKey(0)!=27))
	{
		
		grabCut(img,result,rect,bg,fg,i,GC_INIT_WITH_RECT);
		cv::compare(result,cv::GC_PR_FGD,result,cv::CMP_EQ);
		img.copyTo(foreground,result); 
		imshow("image3",foreground);
		
	}
		
	waitKey(0);
	return 0;
}


