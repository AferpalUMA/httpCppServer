#include"Server.h"
int main(){
	http::Server server;
	server.get("/home", [](Request* req, Response* res){
		res->send("Hello world");
	});
	server.get("/", [](Request* req, Response* res){
		res->send("Wassup");
	});
	server.get("/ivanchu", [](Request* req, Response* res){
		res->send("Ivanchu_12 como mola!!");
	});
	server.listenAt(3000);
	return 0;
}
