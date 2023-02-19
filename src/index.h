#pragma once

#include <string>
#include <list>
#include <map>
#include <vector>
#include <stdint.h>

#include "spdlog/spdlog.h"
#include "nlohmann/json.hpp"
using json = nlohmann::json;

#include "ErrorCode.h"
#include "ConfigManger.h"

// vs2017 not have `not`
#ifndef not
#define not !
#endif
