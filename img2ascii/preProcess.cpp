#include"header.h"
using namespace cv;

//对比度拉伸
Mat ContrastStretch(Mat const SourceImage, double min)
{
	Mat hist;
	int histSize = 256;
	calcHist(&SourceImage, 1, 0, Mat(), hist, 1, &histSize, 0);
	//cout << hist << endl;

	int data_min = 0, data_max = 255;
	int accumulate = 0, minValue = static_cast<int>(SourceImage.rows * SourceImage.cols * min);
	for (accumulate = 0; data_min < histSize; data_min++) {
		accumulate += (hist.at<float>(data_min));
		if (accumulate > minValue)
			break;
	}

	for (accumulate = 0; data_max >= 0; data_max--)
	{
		accumulate += hist.at<float>(data_max);
		if (accumulate > minValue)
			break;
	}

	//cout << data_min << " " << data_max << endl;

	Mat lookUp(1, 256, CV_8U);
	int len = data_max - data_min;

	if (len < 1) return SourceImage;
	//剔除直方图两边并将中间拉伸
	for (int i = 0; i < 256; i++)
	{
		if (i < data_min) lookUp.at<uchar>(i) = 0;
		else if (i > data_max) lookUp.at<uchar>(i) = 255;
		else lookUp.at<uchar>(i) = static_cast<uchar>(255.0*(i - data_min) / len);
	}

	Mat resultImage;
	//查找表，灰度值映射
	LUT(SourceImage, lookUp, resultImage);
	return resultImage;
}

Mat preProcess(const Mat src) {
	Mat temp;
	cvtColor(src, temp, CV_RGB2GRAY);
	//GaussianBlur(temp, temp, Size(temp.rows / 72 * 2 + 1, temp.rows / 72 * 2 + 1), 0, 0);
	double ratio = static_cast<double>(temp.cols) / temp.rows;
	resize(temp, temp, Size(ASCII_HEIGHT * ratio * 17 / 8, ASCII_HEIGHT));
	temp = ContrastStretch(temp, 0.05);
	return temp;
}