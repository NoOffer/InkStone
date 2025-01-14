#pragma once

#include "Event/ApplicationEvent.h"
#include "Event/KeyEvent.h"
#include "Event/MouseEvent.h"

namespace NXTN {

	class Layer
	{
	public:
		virtual ~Layer() {}

		virtual void Update() {}
		virtual void UIUpdate() {}
		virtual inline bool OnEvent(Event& event) { return false; }

		inline const char* GetName() const { return m_Name; }

	protected:
		Layer(const char* name = "Layer");

		const char* m_Name;
	};
}

