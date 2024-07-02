#pragma once

#include "Log.h"

namespace NXTN {
	class NXTN_API Window
	{
	public:
		virtual ~Window() {}

		virtual void Update() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual void SetVSync(bool enabled) = 0;
		inline bool IsVSync() const { return m_VSync; }

		virtual void* GetNativeWindow() const = 0;

		static Window* Create(unsigned int width = 1280, unsigned int height = 720, std::string title = "InkStone");

	protected:
		bool m_VSync = false;
	};
}
