#include "ScipioPrecompiledHeader.h"
#include "WindowsInput.h"

#include <GLFW/glfw3.h>
#include "scipio/Application.h"

namespace Scipio {

	Input* Input::s_Instance = new WindowsInput();

	bool WindowsInput::isKeyPressedImpl(int keycode) {
		auto window = static_cast<GLFWwindow*>(Application::get().getWindow().getNativeWindow());
		auto state = glfwGetKey(window, keycode);
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool WindowsInput::isMouseButtonPressedImpl(int button) {
		auto window = static_cast<GLFWwindow*>(Application::get().getWindow().getNativeWindow());
		auto state = glfwGetMouseButton(window, button);
		return state == GLFW_PRESS;
	}

	std::pair<float, float> WindowsInput::getMousePositionImpl() {
		auto window = static_cast<GLFWwindow*>(Application::get().getWindow().getNativeWindow());
		double xPosition, yPosition;
		glfwGetCursorPos(window, &xPosition, &yPosition);
		return { (float)xPosition, (float)yPosition };
	}

	float WindowsInput::getMouseXImpl() {
		auto [x, y] = getMousePositionImpl();
		return x;
	}

	float WindowsInput::getMouseYImpl() {
		auto [x, y] = getMousePositionImpl();
		return y;
	}

}