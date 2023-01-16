#include <InkStone.h>

class Sandbox : public InkStone::Application
{
public:
	Sandbox() {
	}

	~Sandbox() {
	}
};

InkStone::Application* InkStone::CreateApplication() {
	return new Sandbox();
}