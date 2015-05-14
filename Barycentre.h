#pragma once

//#include <Windows.h>
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

#define PANMax 177 // Valeur maximale horizontale de la sc�ne 
#define PANMin 155 // Valeur minimale horizontale de la sc�ne
#define TiltMin 29 // Valeur minimale verticale de la sc�ne
#define TiltMax 65 // Valeur maximale verticale de la sc�ne


using namespace std;
using namespace cv;


typedef struct Donnee
{
	int x;
	int y;
} t_donnee;

class Barycentre
{
private:
	Point barycentre;
	Mat Image;
public:
	Mat getMat();
	void setMat(Mat img);
	Point Calculer(Mat img);
	t_donnee  Conversion(); 
	Barycentre(void);
	~Barycentre(void);
};

