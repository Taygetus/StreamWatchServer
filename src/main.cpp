#include <thread>
#include "Scheduler.h"

int main(int argc, char* argv[])
{
	auto scheduler = StreamWatch::Scheduler::Instance();

	if (scheduler->Init(argc, argv) != StreamWatch::ErrorCode::OK)
	{
		SPDLOG_ERROR("init fail");
		return -1;
	}
	SPDLOG_INFO("start");

	while (1)
	{
		scheduler->DoEvent();
		std::this_thread::sleep_for(std::chrono::microseconds(1));
	}

	scheduler->Uninit();
	return 0;
}