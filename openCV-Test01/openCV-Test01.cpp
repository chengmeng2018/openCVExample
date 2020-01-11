// openCV-Test01.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<opencv2/opencv.hpp>
using namespace cv;

int main()
{
	String text = "Funny text inside the box";
	text = format("Hello OpenCV %s", CV_VERSION);
	int fontFace = FONT_HERSHEY_COMPLEX;
	double fontScale = 2;
	int thickness = 3;

	Mat img(600, 800, CV_8UC3, Scalar::all(0));

	int baseline = 0;
	Size textSize = getTextSize(text, fontFace,
		fontScale, thickness, &baseline);
	baseline += thickness;

	// center the text
	Point textOrg((img.cols - textSize.width) / 2,
		(img.rows + textSize.height) / 2);

	// draw the box
	rectangle(img, textOrg + Point(0, baseline),
		textOrg + Point(textSize.width, -textSize.height),
		Scalar(0, 0, 255));
	// ... and the baseline first
	line(img, textOrg + Point(0, thickness),
		textOrg + Point(textSize.width, thickness),
		Scalar(0, 0, 255));

	// then put the text itself
	putText(img, text, textOrg, fontFace, fontScale,
		Scalar::all(255), thickness, 8);
	imshow("TestImg", img);
	waitKey();
}