#include "Request.h"

Request::Request(const char* req){
	this->root=nullptr;
	char method[10]={0};
	int i=0;
	while(i<10 && *(req)!='/'){
		method[i++]=*(req++);
	}
	this->method=getMethodFromString(method);
	char rt[128]={0};
	i=0;
	req++;
	while(*req!=' ' && *req!='\0' && i<128){
		*(rt+(i++))=*(req++);
	}
	this->root=new char[length(rt)];
	strcpy(this->root, rt);
}

Request::Request(const Request& req){
	this->method=req.method;
	this->root=new char[length(req.root)];
	strcpy(this->root, req.root);
}
Request::Request(Request&& req){
	this->method=req.method;
	this->root=req.root;
	req.root=nullptr;
}

void Request::operator=(const Request& req){
	this->method=req.method;
	delete[] this->root;
	this->root=new char[length(req.root)];
	strcpy(this->root, req.root);
}
void Request::operator=(Request&& req){
	this->method=req.method;
	delete[] this->root;
	this->root=req.root;
	req.root=nullptr;
}

Method Request::getMethodFromString(const char* str){
	if(strcmp(str, "GET")){
		return GET;
	}else if(strcmp(str, "POST")){
		return POST;
	}else if(strcmp(str, "DELETE")){
		return DELETE;
	}else if(strcmp(str, "PUT")){
		return PUT;
	}
	return BAD_METHOD;
}
Method Request::getMethod(){return this->method;}
char* Request::getRoot(){return this->root;}
Request::~Request(){
	
}
