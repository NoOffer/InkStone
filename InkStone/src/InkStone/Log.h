#pragma once

#include "Core.h"

#include "spdlog/spdlog.h"

namespace InkStone
{
	class INKS_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetLogger() { return s_Logger; }
	private:
		static std::shared_ptr<spdlog::logger> s_Logger;
	};
}

#define INKS_CRITICAL(...) InkStone::Log::GetLogger()->critical(__VA_ARGS__)
#define INKS_ERROR(...) InkStone::Log::GetLogger()->error(__VA_ARGS__)
#define INKS_WARNING(...) InkStone::Log::GetLogger()->warn(__VA_ARGS__)
#define INKS_INFO(...) InkStone::Log::GetLogger()->info(__VA_ARGS__)
