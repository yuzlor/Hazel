#include <Hazel.h>


class Sandbox : public Hazel::Application
{
public:
	Sandbox() {}
	~Sandbox() {}
};

Hazel::Application* Hazel::creatApplication()
{
	return new Sandbox();
}