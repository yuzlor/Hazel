#include "hzpch.h"
#include "Application.h"
#include "Hazel/Event/ApplicationEvent.h"
#include "Hazel/Log.h"

namespace Hazel {

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}
	Application::~Application()
	{

	}
	void Application::run()
	{
		/*WindowResizedEvent we(1200, 700);
		HZ_TRACE(we.ToString());*/

		while (m_Running)
		{
			m_Window->OnUpdate();
		}
	}
}