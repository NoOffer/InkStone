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
		virtual inline bool OnEvent(Event& event) { return false; }

		inline const std::string& GetName() const { return m_Name; }

	protected:
		Layer(const std::string& name = "Layer");

		std::string m_Name;
	};
}

