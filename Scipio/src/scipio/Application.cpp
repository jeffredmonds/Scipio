#include "ScipioPrecompiledHeader.h" 
#include "Application.h"

#include "scipio/events/ApplicationEvent.h"
#include "scipio/Log.h"

#include <GLFW/glfw3.h>

namespace Scipio {

	Application::Application() {
		m_Window = std::unique_ptr<Window>(Window::create());
	}

	void Application::run() {
	
		while (m_Running) {
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->onUpdate();
		}


		while (true);
	}
}