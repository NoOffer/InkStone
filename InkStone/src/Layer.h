#pragma once

#include "Core.h"
#include "Event/Event.h"

namespace NXTN {

	class NXTN_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void Update() {}
		virtual void Dispatch(Event& event) {}

		inline const std::string& GetName() const { return m_Name; }
	protected:
		std::string m_Name;
	};
}

