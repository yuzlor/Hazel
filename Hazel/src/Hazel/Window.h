#include "hzpch.h"

#include "Event/Event.h"
#include "Core.h"

namespace Hazel {

	struct HAZEL_API WindowProps 
	{
	public:
		std::string m_title;
		unsigned int m_width;
		unsigned int m_height;

		WindowProps(const std::string& title = "Hazel Engine", unsigned int width = 1280, unsigned int height = 720)
			:m_title(title), m_width(width), m_height(height) 
		{

		}

	};

	class HAZEL_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;//error: callback undeclared identifier
		virtual ~Window() {};
		virtual int const GetWindowWidth() const = 0;
		virtual int const GetWindowHeight() const = 0;
		virtual bool IsVSync() const = 0;
		virtual void SetVSync(bool) = 0;
		virtual void OnUpdate() = 0;
		virtual void OnResized(unsigned int width, unsigned int height) = 0;
		//virtual void* GetNaiveWindow() = 0;
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};
}