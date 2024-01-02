#include <InkStone.h>

class Sandbox : public NXTN::Application
{
public:
	Sandbox() {}
	~Sandbox() {}
};

NXTN::Application* NXTN::CreateApplication()
{
	return new Sandbox();
}