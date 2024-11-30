#pragma once

#include "scipio/Layer.h"

namespace Scipio {

	class SCIPIO_API ImGuiLayer : public Layer {

	public: 
		ImGuiLayer();
		~ImGuiLayer();

	
		void onAttach();
		void onDetach();
		void onUpdate();
		void onEvent(Event& event);

	private:
		float m_Time = 0.0f;
	};
}