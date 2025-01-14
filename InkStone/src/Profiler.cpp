#include "pch.h"

#include "Profiler.h"

namespace NXTN {
	Profiler::Profiler()
	{

	}

	Profiler::~Profiler()
	{

	}

	void Profiler::NewFrame(const char* name)
	{
		m_Result[name];

		m_Result[name].timeStamp = std::chrono::steady_clock::now();
	}

	void Profiler::EndFrame(const char* name)
	{
		m_Result[name];

		m_Result[name].timeRecord = std::chrono::steady_clock::now() - m_Result[name].timeStamp;
	}

	std::chrono::nanoseconds* Profiler::GetRecord(const char* name)
	{
		if (m_Result.find(name) == m_Result.end())
		{
			Log::Warning("Invalid record name");
			return nullptr;
		}
		else
		{
			return &(m_Result[name].timeRecord);
		}
	}

	float Profiler::GetRecordMS(const char* name)
	{
		if (m_Result.find(name) == m_Result.end())
		{
			Log::Warning("Invalid record name");
			return -1;
		}
		else
		{
			return std::chrono::duration_cast<std::chrono::microseconds>(m_Result[name].timeRecord).count() / 1000.0f;
		}
	}
}
