#include <Hazel.h>

class ExampleLayer : public Hazel::Layer
{
	void OnAttach() override
	{
		LOG("Init Layer");
	}

	void OnDetach() override
	{
		LOG("Close Layer");
	}

	void OnEvent(Hazel::Event& e) override
	{
		std::string s = e.ToString();
		//LOG("{0}", s);
		//LOG("{0}", "SampleLayer: ");//, e.ToString());
	}
	void OnUpdate() override
	{
		LOG("Example Layer: On Update");
	}

};

class Sandbox : public Hazel::Application
{
public:
	Sandbox() 
	{
		m_LayerStack.PushLayer(std::make_shared<ExampleLayer>());
		m_LayerStack.PushOverlay(std::make_shared<Hazel::ImGuiLayer>());
		//m_LayerStack.PushLayer(new ExampleLayer());
		//m_LayerStack.PushOverlay(new Hazel::ImGuiLayer());
	}
	~Sandbox() {}
};

Hazel::Application* Hazel::creatApplication()
{
	Sandbox* s = new Sandbox();
	return s;
}