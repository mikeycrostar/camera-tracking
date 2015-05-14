#include "ConnectVideoIP.h"


ConnectVideoIp::ConnectVideoIp() : videoStreamAddress("http://admin:@192.168.0.50/videostream.cgi?.mjpg")
{
	// constructeurs par d�fauts sans param�tres
}

ConnectVideoIp::ConnectVideoIp(String url)
{
	this->videoStreamAddress = url; // constructeurs avec un param�tre pour choisir la source du flux vid�o
}

ConnectVideoIp::~ConnectVideoIp()
{
		// destructeurs
}

void		ConnectVideoIp::setFlux(VideoCapture xp)
{
	this->video = xp; // setter du Flux video permettant d'assigner le flux � la variable "vid�o" la valeur de XP 
}
VideoCapture ConnectVideoIp::getFlux()
{
	return this->video;
}

bool		ConnectVideoIp::getCap(void)
{
	VideoCapture vcap;
	if (!vcap.open(this->videoStreamAddress)) // getter pour r�cup�rer le flux vid�o
		return false;
	setFlux(vcap);
	return true;
}
