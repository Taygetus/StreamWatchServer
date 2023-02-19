#pragma once
#include "index.h"

namespace StreamWatch {

class ConfigManger {
public:
	explicit ConfigManger();
	virtual ~ConfigManger();

public:
	ErrorCode Init();
	void Uninit();

public:
	ErrorCode SetConfig(const std::string& key, const json& value);
	json GetConfig(const std::string& key);

private:
	ErrorCode SaveConfigToFile();

private:
	std::string m_configPath;
	json m_configJson;
};

}