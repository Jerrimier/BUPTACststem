#include "CustomerCilent.h"
#include <random>
#include <time.h>
CustomerCilent::CustomerCilent(QWidget *parent)
    : QMainWindow(parent)
{
    QString butname1 = "��һ����ť";
    ui.setupUi(this);
    ui.pushButton->setText(butname1);
    setWindowTitle("�����ؿյ�������");

    socket = new ClientTcpSocket(this);

    socket->abort();
    socket->connectToHost(serverIP, serverPort);

    if (!socket->waitForConnected()) {
        qDebug() << "Connect Failed !";
        return;
    }
    qDebug() << "Connect Successfully!";

    /**********************************
    * ClientTcpSocketʹ��˵���� ��׿
    * 1. �ӷ������յ���Ϣ��
    * �ӷ�������������Ϣ�Ѿ����յ���json��תΪ����Ϣ������Ϣ���ڴ������Ϣ�Ĳۺ����ϼ��ɡ�
    * ʾ����
    *     connect(socket, ClientTcpSocket::turnOnAirConditionerOK, this, [=](float defaultTemp, int defaultFanSpeed) {
    *           //�յ��յ�����OK��Ϣʱ�Ĵ���  
    *     })��
    * 2. ������������Ϣ��
    * ������������Ϣʱֱ�ӵ���socket�ļ���public�������ɡ�
    * ʾ����
    *   ��Ҫ��������˷��Ϳͻ��˿����յ�ʱ�������к������ɣ�
    *       socket->turnOnAirConditioner(roomID);
    **********************************/

    //

    //���Դ���
    std::default_random_engine e;
    e.seed(time(0));
    int roomid = e() % 10;
    socket->turnOnAirConditioner(roomid);
    socket->changeFanSpeed(roomid, 3);
    socket->changeTemp(roomid, 26.5);

    Sleep(10000);

    socket->closeAirConditioner(roomid);
    socket->serviceOnBack(roomid, 28.9, true);
    socket->serviceOnBack(roomid);
    socket->reachTargetTempStopBack(true);
    socket->preemptedStopBack(true);

   /*
    //���Դ���
    connect(socket, &QTcpSocket::readyRead, this, &CustomerCilent::socketReadData);
    connect(socket, &QTcpSocket::disconnected, this, &CustomerCilent::socketDisconnect);
    
    QString msg = "{\"request\":300,\"data\":{\"RoomId\":1, \"FanSpeed\":1}}";

    socket->write(msg.toUtf8().data());*/
}

void CustomerCilent::socketReadData() {
    QByteArray buffer;
    buffer = socket->readAll();
    QString str;
    if (!buffer.isEmpty()) {
        str += tr(buffer);
    }
    qDebug() << str;
    return;
}

void CustomerCilent::socketDisconnect() {
    qDebug() << "Now disconnected.";
    return;
}
