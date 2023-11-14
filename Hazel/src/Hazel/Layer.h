#pragma once

#include "Core.h"
#include "Event/Event.h"

namespace Hazel {

	class HAZEL_API Layer
	{
	public:
		Layer(const std::string& name = "Layer") 
			: m_DebugName(name) {}
		virtual ~Layer() {}
		virtual void OnAttach() {}; //当layer添加到layer stack的时候会调用此函数，相当于Init函数
		virtual void OnDetach() {}; //当layer从layer stack移除的时候会调用此函数，相当于Shutdown函数
		virtual void OnEvent(Event&) {};
		virtual void OnUpdate() {};
		//virtual void OnImGuiRender() {};

	protected:
		bool isEnabled{false};	// 值为fasle时，该Layer会被禁用，不会绘制画面，也不会接收事件
		std::string m_DebugName;
	};

}