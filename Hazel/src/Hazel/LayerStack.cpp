#include "hzpch.h"
#include "LayerStack.h"

namespace Hazel {

	LayerStack::LayerStack()
	{
		curStackIter = m_Stack.begin();
	}

	LayerStack::~LayerStack()
	{
		for (auto layer : m_Stack) {
			layer->OnDetach();
		}
	}

	void LayerStack::PushLayer(std::shared_ptr<Layer> layer)
	{
		m_Stack.emplace(m_Stack.begin(), layer);
		layer->OnAttach();
		
	}

	void LayerStack::PushOverlay(std::shared_ptr<Layer> overlay)
	{
		m_Stack.emplace_back(overlay);
		overlay->OnAttach();
	}

	std::shared_ptr<Layer> LayerStack::PopLayer()
	{
		if (m_Stack.size() > 0)
		{
			auto top = m_Stack[0];
			m_Stack.erase(m_Stack.begin(), m_Stack.begin() + 1);
			return top;
		}
		else
		{
			return nullptr;
		}
	}

	void LayerStack::PopOverlay(std::shared_ptr<Layer> overlay)
	{
		auto it = std::find(m_Stack.begin(), m_Stack.end(), overlay);
		if (it != m_Stack.end())
			m_Stack.erase(it);
	}

}