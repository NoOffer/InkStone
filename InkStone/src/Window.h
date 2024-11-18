#pragma once

//#include "Core.h"

#include "src/Log.h"
#include "src/System.h"

namespace NXTN {
	class Window
	{
	public:
		virtual ~Window() {}

		virtual void Update() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		virtual void* GetNativeWindow() const = 0;

		static Window* Create(unsigned int width = 500, unsigned int height = 500, std::string title = "InkStone");
	};
}
