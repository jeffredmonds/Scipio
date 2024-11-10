#pragma once

#include "Core.h"

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

