#pragma once

#include "Core.h"
#include "events/Event.h"
#include "events/ApplicationEvent.h"
#include "Window.h"

namespace Scipio {

	class SCIPIO_API Application 
	{
		
	public:
		Application();
		void run();
		void onEvent(Event& event);


	private:
		bool OnWindowClose(WindowCloseEvent& event);
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	//To be defined in client
	Application* createApplication();

}

