#include "ScipioPrecompiledHeader.h" 
#include "Application.h"

#include "scipio/events/ApplicationEvent.h"
#include "scipio/Log.h"

namespace Scipio {

	Application::Application() {

	}

	void Application::run() {

		WindowResizedEvent e(1280, 720);

		SP_TRACE("heck_ehck_theck");

		if (e.isInCategory(EventCategoryApplication))
		{
			SP_TRACE(e.toString());
		}
		if (e.isInCategory(EventCategoryInput))
		{
			SP_TRACE(e.toString());
		}


		while (true);
	}
}