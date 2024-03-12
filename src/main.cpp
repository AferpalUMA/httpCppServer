#include"Server.h"

int main(){
	http::Server server;
	server.listenAt(8080);
	return 0;
}
