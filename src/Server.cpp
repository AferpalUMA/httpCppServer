#include "Server.h"

using namespace http;

Server::Server(){
	this->socket_fd=socket(AF_INET, SOCK_STREAM, 0);
	if(this->socket_fd<0){
		throw 0;
	}
}

void Server::listen(int _port){
	this->port=_port;
	this->hexPort=toHex(_port);
	this->sockaddr={AF_INET, hexport, 0};
	if(bind(this->socket_fd, &sockaddr, size(sockaddr))<0){
		throw 0;
	}
	if(listen(this->socket_fd, 5)<0){throw 0;}
	this->current_request=accept(this->socket_fd, NULL, NULL);
	char buffer[256]={0};
	recv(this->current_request, buffer, 256, 0);


}
