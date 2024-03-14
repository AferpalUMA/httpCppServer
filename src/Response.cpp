#include "Response.h"

Response::Response(int _statusCode, const char* body, const char* _contentType){
	this->statusCode=_statusCode;
	this->contentLength=length(body);
	this->body= new char[this->contentLength];
	this->message=nullptr;
	strcpy(this->body, body);
	this->contentType= new char[length(_contentType)];
	strcpy(this->contentType, _contentType);
}

Response::Response(const Response& otherResponse){
	this->statusCode=otherResponse.statusCode;
	this->contentLength=otherResponse.contentLength;
	this->body= new char[this->contentLength];
	strcpy(this->body, otherResponse.body);
	this->message=new char[length(otherResponse.message)];
	strcpy(this->message, otherResponse.message);
	this->contentType= new char[length(otherResponse.contentType)];
	strcpy(this->contentType, otherResponse.contentType);
}

Response::Response(Response&& otherResponse){
	this->statusCode=otherResponse.statusCode;
	this->contentLength=otherResponse.contentLength;
	this->body=otherResponse.body;
	otherResponse.body=nullptr;
	this->message=otherResponse.message;
	otherResponse.message=nullptr;
	this->contentType=otherResponse.contentType;
	otherResponse.contentType=nullptr;
}
void Response::generateMessage(){
	if(this->message!=nullptr){delete[] this->message;}
	this->message=new char[this->contentLength+100];
	strconcat(this->message, "HTTP/1.1 ");
	char number[4]={(char)(((this->statusCode/100)%10)+'0'), (char)(((this->statusCode/10)%10)+'0'), (char)((this->statusCode%10)+'0'), '\0'};
	strconcat(this->message, number);
	if(number[0]=='4'){
		strconcat(this->message, " Not found\nContent-Type: text/");
		strconcat(this->message, this->contentType);
		strconcat(this->message, "\nContent-Length: 78\nConnection: Closed\n\n<html>\n<body>\n<h1 style=\"color: red\">Error, page not found</h1>\n</body>\n<html>\r\n\r\n");return;
	}else if(number[0]=='2'){
		strconcat(this->message, " OK\nContent-Type: text/");
		strconcat(this->message, this->contentType);
		strconcat(this->message, "\nContent-Length: ");
	}
	int l=this->contentLength;
	char size[32]={0};
	int i=0;
	while(l>0){
		size[i++]=char(l%10+'0');
		l/=10;
	}
	strreverse(size);
	strconcat(this->message, size);
	strconcat(this->message, "\nConnection: Closed\n\n");
	strconcat(this->message, this->body);
	strconcat(this->message, "\r\n\r\n");
}
char* Response::getMessage(){
	generateMessage();
	return this->message;
}

Response::~Response(){
	if(this->body){delete[] this->body;}
	if(this->message){delete[] this->message;}
}
