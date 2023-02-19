#include "ConfigManger.h"
#include "GeneralAbility.h"

namespace StreamWatch {

ConfigManger::ConfigManger()
{
	m_configPath = "./conf/config.json";
}

ConfigManger::~ConfigManger()
{

}

ErrorCode ConfigManger::Init()
{
	std::string data;
	if (ErrorCode::OK != File::ReadFromFile(m_configPath, data))
	{
		SPDLOG_ERROR("not read file:{}", m_configPath);
		return ErrorCode::FILE;
	}

	if (!data.empty())
	{
		m_configJson = json::parse(data);
	}

	return ErrorCode::OK;
}

void ConfigManger::Uninit()
{

}

ErrorCode ConfigManger::SetConfig(const std::string& key, const json& value)
{
	m_configJson[key] = value;

	return SaveConfigToFile();
}

json ConfigManger::GetConfig(const std::string& key)
{
	if (key.empty())
	{
		SPDLOG_ERROR("get config key empty");
		return json();
	}

	if (m_configJson.find(key) != m_configJson.end())
	{
		return m_configJson[key];
	}

	return json();
}

ErrorCode ConfigManger::SaveConfigToFile()
{
	auto data = m_configJson.dump(2);

	auto err = File::WriteToFile(m_configPath, data);
	if (err != ErrorCode::OK)
	{
		SPDLOG_ERROR("not write file:{}", m_configPath);
		return ErrorCode::FILE;
	}

	return ErrorCode::OK;
}

}