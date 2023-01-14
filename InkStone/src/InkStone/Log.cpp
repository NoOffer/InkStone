#include "Log.h"

namespace InkStone
{
	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
	}
}
