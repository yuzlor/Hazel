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
		virtual void OnAttach() {}; //��layer��ӵ�layer stack��ʱ�����ô˺������൱��Init����
		virtual void OnDetach() {}; //��layer��layer stack�Ƴ���ʱ�����ô˺������൱��Shutdown����
		virtual void OnEvent(Event&) {};
		virtual void OnUpdate() {};
		//virtual void OnImGuiRender() {};

	protected:
		bool isEnabled{false};	// ֵΪfasleʱ����Layer�ᱻ���ã�������ƻ��棬Ҳ��������¼�
		std::string m_DebugName;
	};

}