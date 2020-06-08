#include "ACsystemServer.h"
#include <QDebug.h>

ACsystemServer::ACsystemServer(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    server = new TcpServer(this, 23333);


    /**********************************
    * TcpServerʹ��˵���� ��׿
    * 1. �ӿͻ����յ���Ϣ��
    * �ӿͻ��˷����İ��Ѿ����յ���json��תΪ����Ϣ������Ϣ���ڴ������Ϣ�Ĳۺ����ϼ��ɡ�
    * ʾ����  
    *   connect(server, TcpServer::turnOnAirConditioner, this, [=](int roomID) {
    *      //�յ������յ�����Ĵ���
    *   });
    * 2. ���ͻ��˷���Ϣ��
    * ���ͻ��˷���Ϣʱֱ�ӵ���server�ļ���public�������ɡ�
    * ʾ����
    *   ��Ҫ��ͻ��˷����ѵ���ָ���¶�ʱ�������к������ɣ�
    *       server->reachTargetTempStop(roomID);
    **********************************/

    ////�������Խ����Ƿ�ɹ�
    //connect(server, &TcpServer::changeFanSpeed, this, [=](int roomID, int fanSpeed) {
    //    qDebug() << "roomID: " << roomID << "\nfanspeed" << fanSpeed;
    //});

    ////������Ϣ�Ƿ񴥷�
    //connect(server, &TcpServer::turnOnAirConditioner, this, [=](int roomID) {
    //    qDebug() << "Turn on conditioner Successful";
    //    server->turnOnAirConditionerBack(roomID, 24, 3);
    //    server->changeTempBack(roomID, true);
    //    server->changeFanSpeedBack(roomID, true);

    //    Sleep(10000);

    //    server->turnOffAirConditionerBack(roomID, true);
    //    server->serviceOn(roomID, 111);
    //    server->reachTargetTempStop(roomID);
    //    server->preemptedStop(roomID, 111, 222);
    //});
}

void ACsystemServer::receiveData(QByteArray data) {
    QString str;
    if (!data.isEmpty()) {
        str += tr(data);
    }
    qDebug() << str;
}

////���Ե���demo
//void ACsystemServer::serverNewConnect() {
//    TcpSocket* newClient = new TcpSocket(this);
//    QTcpSocket* socket;
//    socket = server->nextPendingConnection();
//    connect(socket, &QTcpSocket::readyRead, this, &ACsystemServer::socketReadData);
//    connect(socket, &QTcpSocket::disconnected, this, &ACsystemServer::socketDisconnected);
//
//    qDebug() << "Client connected";
//
//    socket->write("Hi");
//}
//
//void ACsystemServer::socketReadData() {
//
//    QByteArray buffer;
//
//    buffer = socket->readAll();
//    QString str;
//    if (!buffer.isEmpty()) {
//        str += tr(buffer);
//    }
//    qDebug() << "buffer: " << str;
//}
//
//void ACsystemServer::socketDisconnected() {
//    qDebug() << "Client disconnected";
//}
