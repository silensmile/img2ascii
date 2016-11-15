#include"header.h"
#include<vector>
#include<fstream>
using namespace std;
void img2ascii(const cv::Mat src) {
	char index[8] = { ' ','.',',',';','~','*','#','@' };
	int pixal = 0;
	int pixalLevel = 0;
	vector<char> ascii;
	for (int i = 0; i < src.rows; i++) {
		for (int j = 0; j < src.cols; j++) {
			pixal = 255-src.at<uchar>(i, j);
			if (0 <= pixal && pixal < 32)
				pixalLevel = 0;
			if (32 < pixal && pixal < 64)
				pixalLevel = 1;
			if (64 < pixal && pixal < 96)
				pixalLevel = 2;
			if (96 < pixal && pixal < 128)
				pixalLevel = 3;
			if (128 < pixal && pixal < 160)
				pixalLevel = 4;
			if (160 < pixal && pixal < 192)
				pixalLevel = 5;
			if (192 < pixal && pixal < 224)
				pixalLevel = 6;
			if (224 < pixal && pixal < 256)
				pixalLevel = 7;
			ascii.push_back(index[pixalLevel]);
		}
	}
	double ratio = static_cast<double>(src.cols) / src.rows;
	ofstream outFile("ascii.txt");
	for (int i = 0; i < ascii.size(); i++) {
		if (i % src.cols == 0)
			outFile << endl;
		outFile << ascii[i];
	}
}