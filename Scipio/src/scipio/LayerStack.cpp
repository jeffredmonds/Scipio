#include "ScipioPrecompiledHeader.h"
#include "LayerStack.h"

namespace Scipio {

	LayerStack::LayerStack() {
	}

	LayerStack::~LayerStack() {
		for (Layer* layer : m_Layers) {
			delete layer;
		}
	}

	void LayerStack::pushLayer(Layer* layer) {
		 m_Layers.emplace(m_Layers.begin() + m_LayerInsertIndex, layer);
		 m_LayerInsertIndex++;
	}

	void LayerStack::pushOverlay(Layer* overlay) {
		m_Layers.emplace_back(overlay);
	}

	void LayerStack::popLayer(Layer* layer) {
		auto foundLayer = std::find(m_Layers.begin(), m_Layers.end(), layer);
		if (foundLayer != m_Layers.end()) {
			m_Layers.erase(foundLayer);
			m_LayerInsertIndex--;
		}
	}

	void LayerStack::popOverlay(Layer* overlay) {
		auto foundLayer = std::find(m_Layers.begin(), m_Layers.end(), overlay);
		if (foundLayer != m_Layers.end()) {
			m_Layers.erase(foundLayer);
		}
	}
}