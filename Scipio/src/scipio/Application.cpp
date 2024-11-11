#include "Application.h"

#include "scipio/events/ApplicationEvent.h"
#include "scipio/Log.h"

namespace Scipio {

	Application::Application() {

	}

	void Application::run() {

		WindowResizedEvent e(1280, 720);

		SP_TRACE("heck_ehck_theck");

		if (e.isInCategory(EVENT_CATEGORY_APPLICATION))
		{
			SP_TRACE(e.toString());
		}
		if (e.isInCategory(EVENT_CATEGORY_INPUT))
		{
			SP_TRACE(e.toString());
		}


		while (true);
	}
}