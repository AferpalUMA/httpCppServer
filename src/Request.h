#pragma once
#include "Utilities.h"
enum Method{GET, POST, DELETE, PUT, BAD_METHOD};

class Request{
	private:
		Method method;
		char* root;
		char* fileType;
	public:
		Request(const char* req);
		Request(const Request& req);
		Request(Request&& req);
		void operator=(const Request& req);
		void operator=(Request&& req);
		char* getRoot() const;
		char* getFileType() const;
		Method getMethod() const;
		Method getMethodFromString(const char*);
		~Request();

};
