#pragma once

#include "Layer.h"

namespace Hazel {

	class HAZEL_API LayerStack
	{
	public:
		using LayerIter = std::vector<std::shared_ptr<Layer>>::iterator;
		LayerStack();
		~LayerStack();
		
		void PushLayer(std::shared_ptr<Layer> layer);// lay代表普通的layer, Overlay代表离屏幕最近的layer
		void PushOverlay(std::shared_ptr<Layer> overlay);
		std::shared_ptr<Layer> PopLayer();
		void PopOverlay(std::shared_ptr<Layer> overlay);
		std::shared_ptr<Layer> GetLayer(uint32_t id) { return m_Stack[id]; }
		uint32_t GetLayerCnt() { return static_cast<uint32_t>(m_Stack.size()); }


		LayerIter begin() { return m_Stack.begin(); }
		LayerIter end() { return m_Stack.end(); }

	private:
		std::vector<std::shared_ptr<Layer>> m_Stack;
		LayerIter curStackIter;
	};

}
