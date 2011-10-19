/*	Name: Server.h
	Description: Server implementation TCP/IP configuration of TCSPC hardware. Based on Qt toolkit documentation
	for QtNetwork module, by Nokia Corporation.

	Written by: Alex Greis
	
	Functional Optical Imaging Laboratory
	Department of Biomedical Engineering
	University of Texas at Austin
	Austin, TX 78712
	
	Created:	12/3/09
	Updated:	3/24/2010	-Added to Two Photon main app
*/ 

#ifndef SERVER_H
#define SERVER_H

#include <QtNetwork>
//#include <QtGui>
//#include <QDialog>

class QTcpServer;

class Server : public QObject
{
     Q_OBJECT

 public:
	 Server();
	 void init();
	 void setData(char *data);

 private slots:
     void sendData();

signals:
	 void sendPort(int port);

 private:

     QTcpServer *tcpServer;
     QStringList configData;
 };

 #endif