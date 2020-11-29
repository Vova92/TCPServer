#include <QCoreApplication>
#include <QTcpServer>
#include <QTcpSocket>
#include <iostream>

#include "myserver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyServer server;
    std::cout << "134123123" << endl;

    return a.exec();
}

