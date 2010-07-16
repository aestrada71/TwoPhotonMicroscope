/*	Name: Server.cpp
	Description: Server implementation TCP/IP configuration of TCSPC hardware. Based on Qt toolkit documentation
	for QtNetwork module, by Nokia Corporation.

	Written by: Alex Greis
	
	Functional Optical Imaging Laboratory
	Department of Biomedical Engineering
	University of Texas at Austin
	Austin, TX 78712
	
	Created:	12/3/09
	Updated:	
*/ 
#include <QtNetwork>

#include <stdlib.h>
#include "server.h"

//Function: Server
//Type: Default Constructor
Server::Server()
{
}

//Function: init()
//Type: Member Function
//Description: Initializes server
void Server::init()
{
	 tcpServer = new QTcpServer(this);
     if (!tcpServer->listen()) 
	 {
		//QMessageBox::about(0,"TCSPC Server",tr("Unable to start the server: %1.")
       //                       .arg(tcpServer->errorString()));
         //close();
         return;
     }
	 
	 emit sendPort((int)tcpServer->serverPort());
  
     configData << tr("NULL DATA");

     //Connect signal to slot - when a new connection occurs, send data
     this->connect(tcpServer, SIGNAL(newConnection()), this, SLOT(sendData()));
}
//Function: setData
//Type: Member Function
//Description: Sets data to be transmitted to TCSPC client
void Server::setData(char *data)
{
	QString str = tr(data);
	configData.clear();
	configData << str;
}
 //Function: sendData
 //Type: Slot
 //Description: Encodes and sends data to client after connection attempt
 void Server::sendData()
 {
     QByteArray block;
     QDataStream out(&block, QIODevice::WriteOnly);
     out.setVersion(QDataStream::Qt_4_0);
     
	 //reserve space for a 16-bit integer
	 //this space will be used to indicate to clients how much data is sent in a transmission
	 out << (quint16)0;
     out << configData.at(qrand() % configData.size());
     out.device()->seek(0);
     out << (quint16)(block.size() - sizeof(quint16));

	 //Connect socket destructor - ensure socket is deleted after disconnecting
     QTcpSocket *clientConnection = tcpServer->nextPendingConnection();
     this->connect(clientConnection, SIGNAL(disconnected()),clientConnection, SLOT(deleteLater()));

	 //Write data and close
     clientConnection->write(block);
     clientConnection->disconnectFromHost();
 }