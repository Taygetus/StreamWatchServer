#pragma once

#include "index.h"

namespace StreamWatch {

class File {
public:
	static ErrorCode ReadFromFile(const std::string& path, std::string& out);
	static ErrorCode WriteToFile(const std::string& path, const std::string& data);
	static size_t GetFileSize(const std::string& path);
};

}