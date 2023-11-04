#include "hzpch.h"
#include "Application.h"
#include "Hazel/Event/ApplicationEvent.h"
#include "Hazel/Log.h"

namespace Hazel {

	Application::Application()
	{

	}
	Application::~Application()
	{

	}
	void Application::run()
	{
		WindowResizedEvent we(1200, 700);
		HZ_TRACE(we.ToString());

		while (true);
	}
}