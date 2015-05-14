#pragma once

//#include <Windows.h>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace cv;

class ConnectVideoIp
{
public:
	void setFlux(VideoCapture xp);
	VideoCapture getFlux();
	ConnectVideoIp();
	ConnectVideoIp(String url);
	~ConnectVideoIp();
	bool getCap();
private:
	VideoCapture video;
	String videoStreamAddress;
};

