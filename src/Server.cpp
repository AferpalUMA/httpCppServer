#include "Server.h"

using namespace http;

Server::Server(){
	this->socket_fd=socket(AF_INET, SOCK_STREAM, 0);
	if(this->socket_fd<0){
		throw 0;
	}
}

void Server::listenAt(int _port){
	this->port=_port;
	this->hexPort=toHex(_port);
	this->sockaddr={AF_INET, (unsigned short)this->hexPort, 0};
	if(bind(this->socket_fd, (const struct sockaddr*)&sockaddr, sizeof(sockaddr))<0){
		throw 0;
	}
	if(listen(this->socket_fd, 5)<0){throw 0;}
	std::cout<<"Succesfully listening at port "<<_port<<'\n';
	this->current_request=accept(this->socket_fd, NULL, NULL);
	formatRequest(this->current_request);
}

void Server::formatRequest(int req){
	char buffer[512]={0};
	int i=0;
	recv(req, buffer, 512,0);
	const char* res="HTTP/1.1 200 OK\r\n\r\nCrazy taxi 3\r\n\r\n";
	if(send(req, res, sizeof(res), 0)!=0){
		std::cout<<errno;
	}
}

Server::~Server(){
	close(this->socket_fd);
	close(this->current_request);
	std::cout<<"\nSuccesfully exiting and closing resources.\n";
}
