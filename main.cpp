#include "Barycentre.h"
#include "CheckConnect.h"
#include "Client.h"
#include <Windows.h>
#include "ConnectVideoIP.h"

int main()
{

 system("pause");
    CheckConnect img; // initialisation de la classe CheckConnect 
	ConnectVideoIp c("http://admin:@192.168.0.50/videostream.cgi?.mjpg"); // r�cup�rer l�adresse de la camera ip
	Barycentre	   b; // initialisation de la classe Barycentre
	Client client("127.0.0.1", 42);
    Mat image, image2 , image_fin;
	int x = 0, y = 0;

	if(!c.getCap()) { // R�cuperation du flux vid�o
        cout << "Erreur dans l'ouverture du flux vid�o" << endl;
        return -1;
    }
  
      cout << "Resolution : 640x480"<<endl;
    while(1) {  
		image = img.getImg(c.getFlux()); // On r�cup�re une image du flux de la camera ip
       imshow("Scene depart", image); // affiche l'image
	   image2 = img.getImg(c.getFlux()); // On r�cup�re une autre image de la camera ip
        absdiff(image,image2,image2); // On compare image et image2 
		threshold(image2,image2,50,255,CV_THRESH_BINARY);   // traitement de l'image2
		cvtColor(image2,image2,CV_RGB2GRAY);
		b.setMat(image2); // On pr�pare l�image 2 au calcul du Barycentre
		Point p = b.Calculer(image2); // On calcule le barycentre de la diff�rence de l�image 2
		client.SendCoord(b.Conversion());
		circle(image2, p, 30, Scalar(255, 0, 255)); // On place un cercle blanc sur le barycentre
		imshow("Comparaison images", b.getMat()); // et on l�affiche
		if(waitKey(1) >= 0) break; // attente de l'appuie d'une touche pour quitter
        }
		cvDestroyWindow("Comparaison images2"); // destruction de la f�netre
    return 0;
}