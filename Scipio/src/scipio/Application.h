#pragma once

#include "Core.h"
#include "events/Event.h"
#include "Window.h"

namespace Scipio {

	class SCIPIO_API Application 
	{
		
	public:
		Application();
		void run();

	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	//To be defined in client
	Application* createApplication();

}

