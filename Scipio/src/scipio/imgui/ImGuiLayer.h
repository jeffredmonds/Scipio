#pragma once

#include "scipio/Layer.h"

#include "scipio/events/ApplicationEvent.h"
#include "scipio/events/KeyEvent.h"
#include "scipio/events/MouseEvent.h"

namespace Scipio {

	class SCIPIO_API ImGuiLayer : public Layer {

	public: 
		ImGuiLayer();
		~ImGuiLayer();

	
		virtual void onAttach() override;
		virtual void onDetach() override;
		virtual void onImGuiRender() override;
		
		void begin();
		void end();

	private:
		float m_Time = 0.0f;
	};
}