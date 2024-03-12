#pragma once
#include<sys/socket.h>
#include<netinet/in.h>
#include<iostream>
#include<unistd.h>
#include"Utilities.h"
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
			void formatRequest(int);
			~Server();
	};


}
