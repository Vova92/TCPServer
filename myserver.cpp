#include "myserver.h"

MyServer::MyServer(QObject *parent, quint16 port) : QObject(parent)
{
    server = new QTcpServer();
    connect(server, &QTcpServer::newConnection, this, &MyServer::NewConnection);
    if (server->listen(QHostAddress::Any, port))
        std::cout << "Server started" << std::endl;
    else
        std::cout << "Server could not start" << std::endl;

}

MyServer::~MyServer()
{
    server->close();
}
