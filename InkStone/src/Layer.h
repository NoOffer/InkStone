#pragma once

#include "Event/Event.h"

namespace NXTN {

	class Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer() {}

		virtual void Update() {}
		virtual void Dispatch(Event& event) {}

		inline const std::string& GetName() const { return m_Name; }

	protected:
		std::string m_Name;
	};
}

