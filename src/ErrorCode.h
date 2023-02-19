#pragma once
#include <stdint.h>

namespace StreamWatch {
using ErrorCode = enum class ErrorCodeEnum : int32_t {
	OK = 0,
	ERR = -10000,
	PARAM,
	CONFIG_ERR,
	FILE,
};

}