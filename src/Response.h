#pragma once
#include "Utilities.h"
class Response{
	private:
		int statusCode;
		int contentLength;
		char* contentType;
		char* message;
		char* body;
	public:
		Response(int sCode, const char* body, const char* _contentType);
		Response(const Response&);
		Response(Response&&);
		void generateMessage();
		char* getMessage();
		~Response();
};
