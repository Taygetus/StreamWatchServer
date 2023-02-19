#pragma once
#include "index.h"

namespace StreamWatch {

class Scheduler {
public:
	static Scheduler* Instance() {
		static Scheduler _scheduler;
		return &_scheduler;
	}

private:
	Scheduler();
	virtual ~Scheduler();

public:
	ErrorCode Init(int argc, char* argv[]);
	void Uninit();

	void DoEvent();

public:
	ConfigManger m_configManger;
};

}