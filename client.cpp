#include "Client.h"

Client::Client()
{
	WSADATA WSAData;
	WSAStartup(MAKEWORD(2,0), & WSAData);
	SOCKET sock;
	SOCKADDR_IN sin;
	sin.sin_addr.s_addr	= inet_addr("127.0.0.1");
	sin.sin_family		= AF_INET;
	sin.sin_port		= htons(4148);
	sock = socket(AF_INET,SOCK_STREAM,0);
	bind(sock, (SOCKADDR *)&sin, sizeof(sin));
	connect(sock, (SOCKADDR *)&sin, sizeof(sin));
	this->sock = sock;
}

Client::Client(char *ip, int port)
{
	WSADATA WSAData;
	WSAStartup(MAKEWORD(2,0), & WSAData);
	SOCKET sock;
	SOCKADDR_IN sin;
	sin.sin_addr.s_addr	= inet_addr(ip);
	sin.sin_family		= AF_INET;
	sin.sin_port		= htons(port);
	sock = socket(AF_INET,SOCK_STREAM,0);
	bind(sock, (SOCKADDR *)&sin, sizeof(sin));
	connect(sock, (SOCKADDR *)&sin, sizeof(sin));
	this->sock = sock;
}

void	Client::SendCoord(t_donnee data)
{
	send(this->sock, (const char *)&data, sizeof(data), 0);
}

Client::~Client()
{
	WSACleanup();
}