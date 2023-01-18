#include "inks_pch.h"
#include "Log.h"

//#include "spdlog/sinks/stdout_color_sinks.h"

namespace InkStone
{
	std::shared_ptr<spdlog::logger> Log::s_Logger;

	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] %v%$");

		Log::s_Logger = spdlog::default_logger();
		//Log::s_Logger = spdlog::stdout_color_mt("InkStone Engine");
		Log::s_Logger->set_level(spdlog::level::trace);
	}
}
