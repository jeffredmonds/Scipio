#pragma once

#include "scipio/Layer.h"

#include "scipio/platform/opengl/imgui_impl_glfw.h"

#include "scipio/events/ApplicationEvent.h"
#include "scipio/events/KeyEvent.h"
#include "scipio/events/MouseEvent.h"

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
		bool onMouseButtonPressedEvent(MouseButtonPressedEvent& event);
		bool onMouseButtonReleasedEvent(MouseButtonReleasedEvent& event);
		bool onMouseMovedEvent(MouseMovedEvent& event);
		bool onMouseScrolledEvent(MouseScrolledEvent& event);
		bool onKeyPressedEvent(KeyPressedEvent& event);
		bool onKeyReleasedEvent(KeyReleasedEvent& event);
		bool onKeyTypedEvent(KeyTypedEvent& event);
		bool onWindowResizedEvent(WindowResizedEvent& event);

		static ImGuiKey mapGLFWKeyToImGuiKey(int key);

	private:
		float m_Time = 0.0f;
	};
}