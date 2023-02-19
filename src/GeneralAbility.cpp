#include "GeneralAbility.h"

#include "third/tfile/tfile.h"

namespace StreamWatch {

ErrorCode File::ReadFromFile(const std::string& path, std::string& out)
{
	out.clear();
	if (path.empty())
	{
		SPDLOG_ERROR("path empty");
		return ErrorCode::PARAM;
	}

	if (0 >= GetFileSize(path))
	{
		tfile::read(path.c_str(), out);
	}

	return ErrorCode::OK;
}

ErrorCode File::WriteToFile(const std::string& path, const std::string& data)
{
	if (path.empty())
	{
		SPDLOG_ERROR("path empty");
		return ErrorCode::PARAM;
	}

	auto size = tfile::write(path.c_str(), data);
	if (size != data.size())
	{
		SPDLOG_ERROR("write file size not same");
		return ErrorCode::FILE;
	}

	SPDLOG_DEBUG("write file, size:{}, path:{}", size, path);
	return ErrorCode::OK;
}

size_t File::GetFileSize(const std::string& path)
{
	return tfile::size(path.c_str());
}

}