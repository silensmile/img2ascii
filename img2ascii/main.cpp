#include"header.h"

using cv::Mat;
using cv::imread;
using cv::waitKey;

int main(int argc,char* argv[]) {
	system("title=img2ascii By silensmile");
	if (argc == 1) {
		std :: cout << "Please input the path of the image to be converted and run in the cmd" << std :: endl;
		std::cout << "Example: img2ascii.exe ./image.png" << std::endl;
		system("pause");
		return 0;
	}
	const Mat src = imread(argv[1]);
	Mat temp = preProcess(src);
	img2ascii(temp);
	std::cout << "Please use monospace fonts in notepad" << std::endl;
	system("ascii.txt");
	system("pause");
	return 0;
}