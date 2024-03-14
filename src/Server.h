#pragma once
#include<sys/socket.h>
#include<netinet/in.h>
#include<iostream>
#include<unistd.h>
#include"Request.h"
#include"Response.h"
#include<fstream>
namespace http{
	class Server{
		private:
			int socket_fd;
			int current_request;
			int port;
			int hexPort;
			struct sockaddr_in sockaddr;
		public:
			Server();
			void listenAt(int);
			Request* formatRequest(int);
			void handleRequest(int);
			~Server();
	};


}
