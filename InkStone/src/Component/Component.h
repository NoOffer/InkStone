#pragma once

namespace NXTN {
	class Component
	{
	public:
		virtual ~Component() {}

		virtual void Update() {}
	protected:
		Component() {}
	};
}