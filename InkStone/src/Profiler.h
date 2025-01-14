#pragma once

#include "Log.h"

namespace NXTN {
	class Profiler
	{
	public:
		Profiler();
		~Profiler();

		void NewFrame(const char* name);
		void EndFrame(const char* name);
		
		std::chrono::nanoseconds* GetRecord(const char* name);
		float GetRecordMS(const char* name);

	private:
		struct ProfileRecord
		{
			std::chrono::steady_clock::time_point timeStamp;
			std::chrono::nanoseconds timeRecord;
		};

		std::unordered_map<const char*, ProfileRecord> m_Result;
	};
}
