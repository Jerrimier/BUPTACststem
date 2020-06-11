#include "Scheduler.h"

Scheduler::Scheduler(QObject *parent)
	: QObject(parent)
{
	return;
}

Scheduler::~Scheduler()
{
}

int Scheduler::createServiceQueue() {
	ACsystemServer::serviceQueue = QVector<int>(); //@ע���ǵøĳ�QVector<ServiceObj*>
	return 0;
}

int Scheduler::createWaitingQueue() {
	ACsystemServer::waitingQueue = QVector<int>(); //@ע���ǵøĳ�QVector<RequestObj*>
	return 0;
}

int Scheduler::ready() {
	this->isReady = true;
	return 0;
}

int Scheduler::setPara(int defaultMode, float tempHighLimit, float tempLowLimit, float defaultTargetTemp, float defaultFeeRate) {
	this->defaultMode = defaultMode;
	this->tempHighLimit = tempHighLimit;
	this->tempLowLimit = tempLowLimit;
	this->defaultTargetTemp = defaultTargetTemp;
	this->defaultFeeRate = defaultFeeRate;
	return 0;
}

QVector<int> Scheduler::getRoomState() {
	QVector<int> roomStates;
	// TODO: ȥDBFacade��roomState����ȫ�������״̬����roomStates��
	return roomStates;
}