#pragma once

#include "Core.h"
#include "Window.h"

namespace Hazel
{
	class HAZEL_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();

		void OnEvent(Event& event);

	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	//to be defined in CLIENT
	Application* creatApplication();
}



