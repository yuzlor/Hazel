#pragma once

#include "Core.h"
#include "Window.h"
#include "Hazel/Event/ApplicationEvent.h"

namespace Hazel
{
	class HAZEL_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();

		void OnEvent(Event& event);
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResized(WindowResizedEvent& e);

	protected:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	//to be defined in CLIENT
	Application* creatApplication();
}



