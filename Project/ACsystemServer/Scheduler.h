#pragma once

#include <QObject>

class Scheduler : public QObject
{
	Q_OBJECT

public:
	Scheduler(QObject *parent);
	~Scheduler();
	//���ò������ѵ��ȶ���ļ����������ó��봫��һ��
	int setPara(int defaultMode, float tempHighLimit, float tempLowLimit, float defaultTargetTemp, float defaultFeeRate);
	//�����ȶ����״̬����ΪReady
	int ready();
	//��ø����䵱ǰ״̬
	void getRoomState();  //ע������ֵӦΪ������Ϣ�����飬��д����void���ǵ�Ҫ��

private:
	//�����ȴ����У��������ȶ���ʱ����
	int createWaitingQueue();
	//����������У��������ȶ���ʱ����
	int createServiceQueue();

	//�����������ʱʹ�ã�Ĭ��ģʽ
	int defaultMode;
	//�����������ʱʹ�ã�����¶�
	float tempHighLimit;
	//�����������ʱʹ�ã�����¶�
	float tempLowLimit;
	//�����������ʱʹ�ã�Ĭ��Ŀ���¶�
	float defaultTargetTemp;
	//�����������ʱʹ�ã�Ĭ�Ϸ���
	float defaultFeeRate;
	//����ֵ����־���ȶ����Ƿ��Ѿ���
	bool isReady;
};
