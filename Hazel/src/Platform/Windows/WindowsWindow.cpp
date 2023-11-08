#include "hzpch.h"

#include "Hazel/Event/ApplicationEvent.h"
#include "Hazel/Event/KeyEvent.h"
#include "Hazel/Event/MouseEvent.h"

#include "Hazel.h"
#include "WindowsWindow.h"

namespace Hazel 
{
	static bool m_initialized = false;

	static void GLFWErrorcallback(int error_code, const char* description)
	{
		HZ_CORE_ERROR("GLFW Error: ({0}), {1}", error_code, description);
	}

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
			glfwSetErrorCallback(GLFWErrorcallback);
		}

		m_Data.title = props.m_title;
		m_Data.width = props.m_width;
		m_Data.height = props.m_height;

		//HZ_CORE_INFO("Creating Window {0} {1} {2}", props.m_title, props.m_width, props.m_height);
		
		m_Window = glfwCreateWindow(m_Data.width, m_Data.height, m_Data.title.c_str(), NULL, NULL);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);

		//set GLFW callback
		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			data.height = height;
			data.width = width;
			WindowResizedEvent event(height, width);
			data.eventCallback(event);
				
		});

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			WindowCloseEvent event;
			data.eventCallback(event);
		});

		glfwSetKeyCallback(m_Window, [] (GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			switch (action)
			{
				case GLFW_PRESS:
				{
					KeyPressedEvent event(key, 0);
					data.eventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyReleasedEvent event(key);
					data.eventCallback(event);
					break;
				}
				case GLFW_REPEAT:
				{
					KeyPressedEvent event(key, 1);
					data.eventCallback(event);
					break;
				}
			}
		});

		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			switch (action)
			{
				case GLFW_PRESS:
				{
					MouseButtonPressedEvent event(button);
					data.eventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseButtonReleasedEvent event(button);
					data.eventCallback(event);
					break;
				}
			}
		});

		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOffset, double yOffset)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			MouseScrolledEvent event((float)xOffset, (float)yOffset);
			data.eventCallback(event);
		});

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xPos, double yPos)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			MouseMovedEvent event((float)xPos, (float)yPos);
			data.eventCallback(event);
		});
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
