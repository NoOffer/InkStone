#pragma once

#include "Core.h"

namespace NXTN {
	class Input
	{
	public:
		static inline bool IsKeyPressed(int keycode) { return s_Instance->IsKeyPressedImpl(keycode); }

	protected:
		virtual bool IsKeyPressedImpl(int keycode) = 0;

	private:
		static Input* s_Instance;
	};
}
