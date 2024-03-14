#pragma once
#include "Utilities.h"
class Response{
	private:
		int statusCode;
		int contentLength;
		int contentType;
		char* message;
		char* body;
	public:
		Response(int sCode, const char* body);
		Response(const Response&);
		Response(Response&&);
		void generateMessage();
		char* getMessage();
		~Response();
};
