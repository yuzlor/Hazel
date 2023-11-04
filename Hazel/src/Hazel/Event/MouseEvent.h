#pragma once

#include "Event.h"

namespace Hazel {
	class MouseMovedEvent : public Event
	{
	public:
		static EventType GetStaticType() { return EventType::MouseMoved; }
		const EventType GetEventType() const override { return GetStaticType(); }
		const char* GetName() const override { return "MouseMoved"; }
		std::string ToString()
		{
			// Create a string with represents 
			std::string a = "MouseMovedEvent: xOffset = " + GetXOffset() + ", yOffset = " + GetYOffset();
			return a;
		}

		inline float GetXOffset() const { return m_xOffset; }
		inline float GetYOffset() const { return m_yOffset; }
	private:
		float m_xOffset, m_yOffset;
	};

}