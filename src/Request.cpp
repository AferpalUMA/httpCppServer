#include "Request.h"

Request::Request(const char* req){
	this->root=nullptr;
	char method[10]={0};
	int i=0;
	while(i<10 && *(req)!='/'){
		if(*(req)!=' '){
			method[i++]=*(req);
		}
		req++;
	}
	this->method=getMethodFromString(method);
	char* rt=new char[128]{};
	char* rt2=rt;
	i=0;
	req++;
	while(*req!=' ' && *req!='\0' && i<128){
		*(rt+(i++))=*(req++);
	}
	this->root=new char[length(rt)];
	strcpy(this->root, rt);
	while (*rt!='.'){rt++;}
	rt++;
	this->fileType=new char[length(rt)+1]{};
	strcpy(this->fileType, rt);
	delete[] rt2;
}

Request::Request(const Request& req){
	this->method=req.method;
	this->root=new char[length(req.root)]{};
	strcpy(this->root, req.root);
	this->fileType= new char[length(req.fileType)]{};
	strcpy(this->fileType, req.fileType);
}
Request::Request(Request&& req){
	this->method=req.method;
	this->root=req.root;
	req.root=nullptr;
	this->fileType=req.fileType;
	req.fileType=nullptr;
}

void Request::operator=(const Request& req){
	this->method=req.method;
	delete[] this->root;
	this->root=new char[length(req.root)]{};
	strcpy(this->root, req.root);
	delete[] this->fileType;
	strcpy(this->fileType, req.fileType);
}
void Request::operator=(Request&& req){
	this->method=req.method;
	delete[] this->root;
	this->root=req.root;
	req.root=nullptr;
	delete[] this->fileType;
	this->fileType=req.fileType;
	req.fileType=nullptr;
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
Method Request::getMethod()const{return this->method;}
char* Request::getRoot()const{return this->root;}
char* Request::getFileType()const{return this->fileType;}
Request::~Request(){
	if(this->root){
		delete[] this->root;
	}
	if(this->fileType){
		delete[] this->fileType;
	}
}
