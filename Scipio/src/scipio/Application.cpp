#include "ScipioPrecompiledHeader.h" 
#include "Application.h"

#include "scipio/Log.h"

#include <GLFW/glfw3.h>

namespace Scipio {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application::Application() {
		m_Window = std::unique_ptr<Window>(Window::create());
		m_Window->setEventCallback(BIND_EVENT_FN(onEvent));
	}


	void Application::run() {
	
		while (m_Running) {
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : m_LayerStack) {
				layer->onUpdate();
			}

			m_Window->onUpdate();
		}
	}

	void Application::onEvent(Event& event) {

		EventDispatcher dispatcher(event);
		dispatcher.dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();) {
			(*--it)->onEvent(event);
			if (event.handled) {
				break;
			}
		}
	}

	void Application::pushLayer(Layer* layer) {
		m_LayerStack.pushLayer(layer);
	}

	void Application::pushOverlay(Layer* overlay) {
		m_LayerStack.pushOverlay(overlay);
	}

	bool Application::OnWindowClose(WindowCloseEvent& event) {

		m_Running = false;
		return true;
	}
}