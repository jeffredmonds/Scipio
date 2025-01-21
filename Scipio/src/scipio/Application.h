#pragma once

#include "Core.h"
#include "Window.h"
#include "scipio/LayerStack.h"
#include "scipio/imgui/ImGuiLayer.h"
#include "scipio/events/Event.h"
#include "scipio/events/ApplicationEvent.h"


namespace Scipio {

	class SCIPIO_API Application 
	{
		
	public:
		Application();
		void run();
		void onEvent(Event& event);

		void pushLayer(Layer* layer);
		void pushOverlay(Layer* layer);

		inline static Application& get() { return *s_Instance; }
		inline Window& getWindow() { return *m_Window; }

	private:
		bool OnWindowClose(WindowCloseEvent& event);
		ImGuiLayer* m_ImGuiLayer;
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;

	private:
		static Application* s_Instance;
	};

	//To be defined in client
	Application* createApplication();

}

