#pragma once

#include "Event.h"

namespace Hazel 
{
	class MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float xoffset, float yoffset)
			:m_xOffset(xoffset), m_yOffset(yoffset) {}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)

		std::string ToString() const override
		{
			std::stringstream ss;
			// Create a string with represents 
			ss << "MouseMovedEvent: xOffset = " << GetXOffset() << ", yOffset = " << GetYOffset();
			return ss.str();
		}

		inline float GetXOffset() const { return m_xOffset; }
		inline float GetYOffset() const { return m_yOffset; }
	private:
		float m_xOffset, m_yOffset;
	};

	class MouseButtonEvent : public Event
	{
	public:
		MouseButtonEvent(int button)
			:m_Button(button) {}
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouseButton)
		virtual ~MouseButtonEvent() {}
		inline int GetMouseButton() const { return m_Button; };

	protected:
		int m_Button;
	};

	class MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int button) :
			MouseButtonEvent(button) {}
		EVENT_CLASS_TYPE(MouseButtonPressed)

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressed";
			return ss.str();
		}

	private:
	};

	class MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int button) :
			MouseButtonEvent(button) {}
		EVENT_CLASS_TYPE(MouseButtonReleased)

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleased";
			return ss.str();
		}

	private:
	};

	class MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float xOffset, float yOffset)
			:m_XOffset(xOffset), m_YOffset(yOffset) {}

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouseButton)

		std::string ToString() const override
		{
			std::stringstream a;
			a << "MouseScrolled: xOffset = " << GetXOffset() << ", yOffset = " << GetYOffset();
			return a.str();
		}

		inline float GetXOffset() const { return m_XOffset; }
		inline float GetYOffset() const { return m_YOffset; }
	private:
		float m_XOffset, m_YOffset;
	};
}