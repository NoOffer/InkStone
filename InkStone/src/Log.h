#pragma once

#include "Core.h"

namespace NXTN {
	class NXTN_API Log
	{
	public:
		template <typename... Args>
		static void Info(const char* msg, Args... args)
		{
			time_t tt = time(0);
			tm ltm;
			localtime_s(&ltm, &tt);

			mtx.lock();
			printf("%02d:%02d:%02d [Info]  ", ltm.tm_hour, ltm.tm_min, ltm.tm_sec);
			printf(msg, args...);
			printf("\n");
			mtx.unlock();
		}

		template <typename... Args>
		static void Warning(const char* msg, Args... args)
		{
			time_t tt = time(0);
			tm ltm;
			localtime_s(&ltm, &tt);

			mtx.try_lock();  // Non-blocking
			printf("%02d:%02d:%02d [Warn]  ", ltm.tm_hour, ltm.tm_min, ltm.tm_sec);
			printf(msg, args...);
			printf("\n");
			mtx.unlock();
		}

		template <typename... Args>
		static void Error(const char* msg, Args... args)
		{
			time_t tt = time(0);
			tm ltm;
			localtime_s(&ltm, &tt);

			mtx.lock();
			printf("%02d:%02d:%02d [Error] ", ltm.tm_hour, ltm.tm_min, ltm.tm_sec);
			printf(msg, args...);
			printf("\n");
			mtx.unlock();
		}

	private:
		static std::mutex mtx;
	};
}

