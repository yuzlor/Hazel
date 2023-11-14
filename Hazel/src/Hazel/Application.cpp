#include "hzpch.h"
#include "Application.h"
#include "Hazel/Event/ApplicationEvent.h"
#include "Hazel/Event/Event.h"
//#include "Hazel.h"

namespace Hazel {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Hazel::Application* Hazel::Application::s_Instance = nullptr;

	Application::Application()
	{
		HAZEL_ASSERT(!s_Instance, "Already Exists an application instance");
		s_Instance = this;
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}

	Application::~Application()
	{

	}

	void Application::PushLayer(std::shared_ptr<Layer>  layer)
	{
		m_LayerStack.PushLayer(layer);
	}

	std::shared_ptr<Hazel::Layer> Application::PopLayer()
	{
		return m_LayerStack.PopLayer();
	}

	void Application::OnEvent(Event& event)
	{
		//HZ_CORE_INFO("{0}", event);
		EventDistpatcher dispatcher(event);
		dispatcher.Dispatch<WindowCloseEvent>(
			std::bind(&Application::OnWindowClose, this, std::placeholders::_1));
		/*dispatcher.Dispatch<WindowResizedEvent>(
			std::bind(&Application::OnWindowResized, this, std::placeholders::_1));*/
		HZ_CORE_INFO("{0}", event.ToString());

		for (auto layer : m_LayerStack) {
			layer->OnEvent(event);
		}
	}

	void Application::Run()
	{
		/*WindowResizedEvent we(1200, 700);
		HZ_TRACE(we.ToString());*/

		while (m_Running)
		{
			for (auto layer : m_LayerStack) {
				layer->OnUpdate();
			}
			m_Window->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

	/*bool Application::OnWindowResized(WindowResizedEvent& e)
	{
		m_Window->OnResized(e.GetWindowWidth(), e.GetWindowHeight());
		return true;
	}*/
}