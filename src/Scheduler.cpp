#include "spdlog/sinks/daily_file_sink.h"
#include "Scheduler.h"

namespace StreamWatch {

Scheduler::Scheduler()
{

}

Scheduler::~Scheduler()
{
	Uninit();
}

ErrorCode Scheduler::Init(int argc, char* argv[])
{
	// Create a daily logger - a new file is created every day on 2:30am.
	auto dailyLogger = spdlog::daily_logger_mt("daily_logger", "logs/daily.txt", 0, 0);
	spdlog::set_default_logger(dailyLogger);
	spdlog::flush_every(std::chrono::seconds(3));

	// config
	if (m_configManger.Init() != ErrorCode::OK)
	{
		SPDLOG_ERROR("config manger init fail");
		return ErrorCode::CONFIG_ERR;
	}

	return ErrorCode::OK;
}

void Scheduler::Uninit()
{

	m_configManger.Uninit();
}

void Scheduler::DoEvent()
{

}

}