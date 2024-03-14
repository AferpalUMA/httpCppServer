#include"Server.h"
int main(){
	http::Server server;
	server.listenAt(3000);
	return 0;
}
