#ifndef HEADER
#define HEADER
#include<iostream>
#include<opencv2\opencv.hpp>

#define ASCII_HEIGHT 80

cv::Mat preProcess(const cv::Mat src);
void img2ascii(const cv::Mat src);

#endif // !HEADER

