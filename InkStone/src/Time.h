#pragma once

#include <chrono>

namespace NXTN {
	class Time
	{
	public:
		static void InitTime();
		static void UpdateTime();

		static inline float GetDeltaTime() { return m_DeltaTime; }

	private:
		static std::chrono::time_point<std::chrono::steady_clock> m_LastTimePoint;
		static float m_DeltaTime;
	};
}

