#pragma once

#include "Core.h"
#include "Window.h"
#include "LayerStack.h"
#include "Hazel/Event/ApplicationEvent.h"

namespace Hazel
{
	class HAZEL_API Application
	{
	public:
		Application();
		virtual ~Application();
		inline static Application& Get() { return *s_Instance; }

		void OnEvent(Event& event);
		void Run();
		bool OnWindowClose(WindowCloseEvent& e);
		void PushLayer(std::shared_ptr<Layer> layer);
		std::shared_ptr<Layer> PopLayer();
		Window& GetWindow()const { return *m_Window; }

	protected:
		std::unique_ptr<Window> m_Window;
		LayerStack m_LayerStack;
		bool m_Running = true;

	private:
		static Application* s_Instance;
	};

	//to be defined in CLIENT
	Application* creatApplication();
}



