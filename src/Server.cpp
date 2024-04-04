#include "Server.h"

using namespace http;

Server::Server(){
	this->socket_fd=socket(AF_INET, SOCK_STREAM, 0);
	if(this->socket_fd<0){
		throw "Socket error\n";
	}
}

void Server::listenAt(int _port){
	this->port=_port;
	this->hexPort=toHex(_port);
	this->sockaddr={AF_INET, (unsigned short)this->hexPort, 0};
	if(bind(this->socket_fd, (const struct sockaddr*)&sockaddr, sizeof(sockaddr))<0){
		throw "Bind error\n";
	}
	if(listen(this->socket_fd, 20)<0){throw "Listen error\n";}
	std::cout<<"Succesfully listening at port "<<_port<<'\n';
	for(int i=0; i<5; i++){
		this->current_request=accept(this->socket_fd, NULL, NULL);
		handleRequest(this->current_request);
	}
}

Request* Server::formatRequest(int req){
	char buffer[512]={0};
	recv(req, buffer, 512,0);
	return new Request(buffer);
}
void Server::handleRequest(int req){
	Request* request=formatRequest(req);
	int statusCode=0;
	char* response_body= new char[1024]{};
	char * filePath=new char[128]{};
	strconcat(filePath, "../");
	strconcat(filePath, request->getRoot());
	std::ifstream requestedFile{filePath};
	delete[]filePath;
	char* contentHead=response_body;
	if(!requestedFile){
		statusCode=404;
	}else{
		statusCode=200;
		while(requestedFile.get(*(response_body++))){}
	}
	Response response={statusCode, contentHead, request->getFileType()};
	const char* msg= response.getMessage();
	int bSent=send(req, msg, length(msg), 0);
	delete request;
	delete[]contentHead;
}

Server::~Server(){
	close(this->socket_fd);
	close(this->current_request);
	std::cout<<"\nSuccesfully exiting and closing resources.\n";
}
