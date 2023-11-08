#include "hzpch.h"
#include "Application.h"
#include "Hazel/Event/ApplicationEvent.h"
#include "Hazel/Log.h"

namespace Hazel {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}

	Application::~Application()
	{

	}

	void Application::OnEvent(Event& event)
	{
		HZ_CORE_INFO("{0}", event);
	}

	void Application::Run()
	{
		/*WindowResizedEvent we(1200, 700);
		HZ_TRACE(we.ToString());*/

		while (m_Running)
		{
			m_Window->OnUpdate();
		}
	}
}