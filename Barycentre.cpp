#include "Barycentre.h"

using namespace std;
using namespace cv;

Barycentre::Barycentre(void)
{
}


Barycentre::~Barycentre(void)
{
}

Point	Barycentre::Calculer(Mat img)
{
	float x = 0;
	float y = 0;
    int cpt = 0;

	for(int i = 0; i < img.cols; i++) {   // la boucle qui permet de parcourir tout les pixels de l'image
		for(int j = 0; j < img.rows; j++) {
			if(img.at<uchar>(j, i) == 255) // Calcul des pixels différents de la couleur noir (noir = 0)
				{	
					x += i;						
					y += j;
					cpt++;
                }		          
        }
	}
	if (cpt == 0) // Si ne rentre pas dans la condition au dessus alors retourne les anciens points sauvegardés dans la classe
		return (this->barycentre);
	else
	{
			Point b((x /cpt), (y /cpt)); // retourne les coordonnées du barycentre
			this->barycentre = b;
	}
	return this->barycentre;
}

Mat		Barycentre::getMat()
{
	return this->Image; // retourne l'attribut "Image" se trouvant dans la classe
}

void	Barycentre::setMat(Mat img)
{
	this->Image = img; // permet d'assigner l'attribut Image à la valeur de img 
}


t_donnee	Barycentre::Conversion()
{
	Point p(this->barycentre);
	t_donnee data;

	data.x = PANMax - (p.x/(640/(PANMax - PANMin)));
	data.y = TiltMax - (p.y/(480/(TiltMax - TiltMin)));

	return (data);
}
