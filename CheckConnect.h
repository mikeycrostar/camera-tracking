#pragma once

//#include <Windows.h>
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/video/background_segm.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <vector>
#include <string>

using namespace std;
using namespace cv;

class CheckConnect
{
	Mat image, image2;
public:
	CheckConnect(void);
	~CheckConnect(void);
	Mat getImg(VideoCapture xp);
};

