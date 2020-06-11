#pragma once

#include <QObject>
#include "ACsystemServer.h"

class ACController : public QObject
{
	Q_OBJECT

public:
	ACController(QObject *parent);
	~ACController();
	//�ۺ��������������ť���ߴ򿪳���ʱ����
	void powerOn();
	//�ۺ���������Ա�����������ʱ���ã����Ͳ��������ȶ���
	void sendPara(int defaultMode, float tempHighLimit, float tempLowLimit, float defaultTargetTemp, float defaultFeeRate);
	//�ۺ���������Ա�����ʼ����ʱ����
	void startUp();
	//ÿ��һ��ʱ�����һ�Σ���ȡ���䵱ǰ״̬��չʾ�ڽ�����
	QVector<int> checkRoomState();  //@ע��Ӧ��ΪQVector<RoomBean>����Room����֮����һ���洢�з�����Ϣ�Ķ���

private:
	//��powerOn()�������ã��������ȶ���
	int createScheduler();
};
