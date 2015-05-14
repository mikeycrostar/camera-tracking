#include "ConnectVideoIP.h"


ConnectVideoIp::ConnectVideoIp() : videoStreamAddress("http://admin:@192.168.0.50/videostream.cgi?.mjpg")
{
	// constructeurs par défauts sans paramètres
}

ConnectVideoIp::ConnectVideoIp(String url)
{
	this->videoStreamAddress = url; // constructeurs avec un paramètre pour choisir la source du flux vidéo
}

ConnectVideoIp::~ConnectVideoIp()
{
		// destructeurs
}

void		ConnectVideoIp::setFlux(VideoCapture xp)
{
	this->video = xp; // setter du Flux video permettant d'assigner le flux à la variable "vidéo" la valeur de XP 
}
VideoCapture ConnectVideoIp::getFlux()
{
	return this->video;
}

bool		ConnectVideoIp::getCap(void)
{
	VideoCapture vcap;
	if (!vcap.open(this->videoStreamAddress)) // getter pour récupérer le flux vidéo
		return false;
	setFlux(vcap);
	return true;
}
