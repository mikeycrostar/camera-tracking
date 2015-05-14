#pragma once

#include <winsock2.h>
#include <WS2tcpip.h>
#include <iostream>
#include <string>
#include "Barycentre.h"
#include <cstdio>
  
class Client {
public:
	Client();
	Client(char *ip, int port);
	~Client();
	void deco();
	void SendCoord(t_donnee coord);
private:
	SOCKET sock;
};
 