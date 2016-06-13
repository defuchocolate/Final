#include "opencv2/opencv.hpp"
#include <vector>
#include <iostream>
#include <time.h>

/*
Program Outline
---------------------------------------------------
1. Capture video from camera(0).
2. Retrive height and width of the frame resolution.
3. Convert from BGR to HSV color space
---------------------------------------------------
*/

using namespace cv;
using namespace std;

int main(int argc, char* argv[]) {
	VideoCapture cap(0);

	//Check wether the camera available or not
	if (!cap.isOpened()) {
		cout << "Cannot open video cam" << endl;
		return -1;
	}

	while (1) {
		Mat frame, mHsv;
		bool bSuccess = cap.read(frame);
		if (!bSuccess) {
			cout << "Cannot read a frame from video stream" << endl;
			break;
		}
		imshow("videoWindow", frame);

		//convert to HSV
		cvtColor(frame, mHsv, CV_BGR2HSV);
		imshow("HSV", mHsv);
		if (waitKey(1) == 27) {
			break;
		}
	}
	return 0;
}