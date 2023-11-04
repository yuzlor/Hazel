#pragma once

#include "hzpch.h"
#include "Hazel/Core.h"

#define BIT(x) 1 << x

namespace Hazel {

	// 事件的详细类型
	enum class HAZEL_API EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	// 事件的大体种类
	enum EventCategory
	{
		None = 0,
		EventCategoryApplication = BIT(0),
		EventCategoryInput		 = BIT(1),
		EventCategoryKeyboard	 = BIT(2),
		EventCategoryMouse		 = BIT(3),
		EventCategoryMouseButton = BIT(4),
	};

#define EVENT_CLASS_TYPE(type) \
			static EventType GetStaticType() { return EventType::##type; }\
			const EventType GetEventType() const override { return GetStaticType(); }\
			const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) \
			virtual int GetCategoryFlag() const override { return category; }

	class HAZEL_API Event
	{
	public:
		virtual const char* GetName() const = 0;
		virtual const EventType GetEventType() const = 0;
		virtual int GetCategoryFlag() const = 0;
		virtual std::string ToString() const { return GetName(); }
		inline bool IsInCategory(EventCategory type)
		{
			return GetCategoryFlag() & type;
		}

	protected:
		bool m_Handled = false;//用来标记这个事件是否被处理了
	};

	class EventDistpatcher
	{
		template<typename T>
		using Evenfn = std::function<bool(T&)>;
	public:
		EventDistpatcher(Event& event)
			:m_Event(event) {}

		template<typename T>
		bool Dispatch(Evenfn<T> func) 
		{
			if (m_Event.GetEventType == T::GetStaticType) 
			{
				m_Event.m_Handled = func(*(T*)&m_Event);
			}
			return false;
		}

	private:
		Event& m_Event;
	};


}