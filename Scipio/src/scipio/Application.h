#pragma once

#include "Core.h"
#include "events/Event.h"

namespace Scipio {

	class SCIPIO_API Application 
	{
		
	public:
		Application();
		void run();
	};

	//To be defined in client
	Application* createApplication();

}

