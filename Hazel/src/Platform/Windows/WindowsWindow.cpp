#include "hzpch.h"
#include "WindowsWindow.h"

namespace Hazel 
{
	static bool m_initialized = false;

	Window* Window::Create(const WindowProps& props)
	{
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		Init(props);
	}

	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}

	void WindowsWindow::Init(const WindowProps& props)
	{
		if (!m_initialized)
		{
			m_initialized = true;
			int r = glfwInit();
			//HAZEL_ASSERT(r, "Failed to init glfw!")
		}

		m_Data.title = props.m_title;
		m_Data.width = props.m_width;
		m_Data.height = props.m_height;

		//HZ_CORE_INFO("Creating Window {0} {1} {2}", props.m_title, props.m_width, props.m_height);
		
		m_Window = glfwCreateWindow(m_Data.width, m_Data.height, m_Data.title.c_str(), NULL, NULL);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);

	}

	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(m_Window);
	}

	void WindowsWindow::SetVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		m_Data.isVSync = enabled;
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void WindowsWindow::OnResized(unsigned int width, unsigned int height)
	{
		return;
	}

	/*void* WindowsWindow::GetNaiveWindow()
	{
		return;
	}*/
}
