#include "myudp.h"
#include <stdio.h>

MyUDP::MyUDP(QObject *parent) :QObject(parent){
    socket = new QUdpSocket(this);
    socket->bind(QHostAddress("172.16.18.120"),43);
    connect(socket,SIGNAL(readyRead()),this,SLOT(readReady()));
    qDebug() << "ready!";
}

void MyUDP::WriteData() {
    QByteArray msg;
    msg.append("Hello!!!");
    qDebug() << "writing!";
    socket->writeDatagram(msg,QHostAddress("172.16.18.121"),33);
}

void MyUDP::readReady() {
    QString tmp;
    QByteArray buffer;
    int size_buffer = socket->pendingDatagramSize();
    buffer.resize( size_buffer );
    QHostAddress sender;
    quint16 port;
    socket->readDatagram(buffer.data(),buffer.size(),&sender,&port);
//    qDebug() << "sender: " << sender.toString();
//    qDebug() << "sender port:" << port;
//    qDebug() << "length: " << size_buffer;
//    unsigned int y, y1;
    unsigned int w = 0, w2 = 0, wt = 0;
    for (int i = 0; i < size_buffer; i+=2) {
//        y = (tmp.number( (unsigned char)buffer[i], 10) ).toInt();

//        y = y * 2;
//        y = (tmp.number( (unsigned char)buffer[i], 10) ).toInt();
//        y = (tmp.number( w, 10) ).toInt();

        w = (unsigned char)buffer[i];
        w2 = (unsigned char)buffer[i+1];
        wt = w | (w2<<8);
        tmp.append( tmp.number(wt, 10) );
//        tmp.append("=");
//        tmp.append( tmp.number( w, 16) );
//        tmp.append( tmp.number( w2, 16) );
        tmp.append(" ");
    }
    qDebug() << tmp;
}
