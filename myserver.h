#ifndef MYSERVER_H
#define MYSERVER_H
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <iostream>

class MyServer : public QObject
{
    Q_OBJECT
public:
    explicit MyServer(QObject *parent = nullptr, quint16 port = 3344);
    ~MyServer();
private slots:
    void NewConnection()
    {
        QTcpSocket *socket = server->nextPendingConnection();
        socket->write("Hello client\r\n");
        socket->flush();
        socket->waitForBytesWritten(3000);
        socket->close();
    }

private:
    QTcpServer *server;
//    QTcpSocket *clients;
};

#endif // MYSERVER_H
