#include"ScipioPrecompiledHeader.h"
#include "ImGuiLayer.h"

#include "imgui.h"
#include "scipio/platform/opengl/ImGuiOpenGLRenderer.h"
#include "GLFW/glfw3.h"

#include "scipio/Application.h"
#include "scipio/events/Event.h"

#include "scipio/platform/opengl/imgui_impl_glfw.h"
namespace Scipio {

	ImGuiLayer::ImGuiLayer() : Layer("ImGuiLayer") {

	}

	ImGuiLayer::~ImGuiLayer() {

	}
	
	void ImGuiLayer::onAttach() {

		//This works with the newest version of imgui, however this bypasses our event layer system 
		// will need to figure out how to pipe this into the layer system because this will probably
		// cause issues in the future 
		ImGui::CreateContext();

		ImGuiIO& io = ImGui::GetIO();
		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

		ImGui::StyleColorsDark();

		ImGui_ImplGlfw_InitForOpenGL(glfwGetCurrentContext(), true);
		ImGui_ImplOpenGL3_Init("#version 410");

		GLFWwindow* window = glfwGetCurrentContext(); 

		glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
			ImGuiIO& io = ImGui::GetIO();
			ImGuiKey imguiKey = mapGLFWKeyToImGuiKey(key);

			if (imguiKey != ImGuiKey_None) {
				bool isPressed = (action == GLFW_PRESS || action == GLFW_REPEAT);
				io.AddKeyEvent(imguiKey, isPressed);
			}
			io.AddKeyEvent(ImGuiMod_Ctrl, (mods & GLFW_MOD_CONTROL) != 0);
			io.AddKeyEvent(ImGuiMod_Shift, (mods & GLFW_MOD_SHIFT) != 0);
			io.AddKeyEvent(ImGuiMod_Alt, (mods & GLFW_MOD_ALT) != 0);
			io.AddKeyEvent(ImGuiMod_Super, (mods & GLFW_MOD_SUPER) != 0);
			});

		glfwSetMouseButtonCallback(window, [](GLFWwindow* window, int button, int action, int mods) {
			ImGuiIO& io = ImGui::GetIO();
			io.AddMouseButtonEvent(button, action == GLFW_PRESS);
			});

		glfwSetCursorPosCallback(window, [](GLFWwindow* window, double xpos, double ypos) {
			ImGuiIO& io = ImGui::GetIO();
			io.AddMousePosEvent((float)xpos, (float)ypos);
			});

		glfwSetScrollCallback(window, [](GLFWwindow* window, double xoffset, double yoffset) {
			ImGuiIO& io = ImGui::GetIO();
			io.AddMouseWheelEvent((float)xoffset, (float)yoffset);
			});

		glfwSetCharCallback(window, [](GLFWwindow* window, unsigned int c) {
			ImGuiIO& io = ImGui::GetIO();
			io.AddInputCharacter(c);
			});
	}
	void ImGuiLayer::onDetach() {
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();

	}

	void ImGuiLayer::onUpdate() {

		ImGuiIO& io = ImGui::GetIO();
		Application& app = Application::get();
		io.DisplaySize = ImVec2(app.getWindow().getWidth(), app.getWindow().getHeight());

		float time = (float)glfwGetTime();
		io.DeltaTime = m_Time > 0.0f ? (time - m_Time) : (1.0f / 60.0f);
		m_Time = time;

		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();

		static bool show = true;
		ImGui::ShowDemoWindow(&show);

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

	}

	//this code uses the event dispatcher currently not being used.  
	void ImGuiLayer::onEvent(Event& event) {
		//EventDispatcher dispatcher(event);
		//dispatcher.dispatch<MouseButtonPressedEvent>(SP_BIND_EVENT_FN(ImGuiLayer::onMouseButtonPressedEvent));
		//dispatcher.dispatch<MouseButtonReleasedEvent>(SP_BIND_EVENT_FN(ImGuiLayer::onMouseButtonReleasedEvent));
		//dispatcher.dispatch<MouseMovedEvent>(SP_BIND_EVENT_FN(ImGuiLayer::onMouseMovedEvent));
		//dispatcher.dispatch<MouseScrolledEvent>(SP_BIND_EVENT_FN(ImGuiLayer::onMouseScrolledEvent));
		//dispatcher.dispatch<KeyPressedEvent>(SP_BIND_EVENT_FN(ImGuiLayer::onKeyPressedEvent));
		//dispatcher.dispatch<KeyReleasedEvent>(SP_BIND_EVENT_FN(ImGuiLayer::onKeyReleasedEvent));
		//dispatcher.dispatch<KeyTypedEvent>(SP_BIND_EVENT_FN(ImGuiLayer::onKeyTypedEvent));
		//dispatcher.dispatch<WindowResizedEvent>(SP_BIND_EVENT_FN(ImGuiLayer::onWindowResizedEvent));
	}

	bool ImGuiLayer::onMouseButtonPressedEvent(MouseButtonPressedEvent& event) {
		ImGuiIO& io = ImGui::GetIO();
		io.MouseDown[event.GetMouseButton()] = true;

		return false;
	}
	bool ImGuiLayer::onMouseButtonReleasedEvent(MouseButtonReleasedEvent& event) {
		ImGuiIO& io = ImGui::GetIO();
		io.MouseDown[event.GetMouseButton()] = false;

		return false; 
	}
	bool ImGuiLayer::onMouseMovedEvent(MouseMovedEvent& event) {
		ImGuiIO& io = ImGui::GetIO();
		io.MousePos = ImVec2(event.getX(), event.getY());

		return false;
	}
	bool ImGuiLayer::onMouseScrolledEvent(MouseScrolledEvent& event) {
		ImGuiIO& io = ImGui::GetIO();
		io.MouseWheelH += event.GetXOffset();
		io.MouseWheel += event.GetYOffset();

		return false;
	}
	bool ImGuiLayer::onKeyPressedEvent(KeyPressedEvent& event) {
		ImGuiIO& io = ImGui::GetIO();

		return true;
	}

	bool ImGuiLayer::onKeyReleasedEvent(KeyReleasedEvent& event) {
		ImGuiIO& io = ImGui::GetIO();
		return false;
	}
	bool ImGuiLayer::onKeyTypedEvent(KeyTypedEvent& event) {
		ImGuiIO& io = ImGui::GetIO();
		return false;
	}
	bool ImGuiLayer::onWindowResizedEvent(WindowResizedEvent& event) {
		//ImGuiIO& io = ImGui::GetIO();
		//io.DisplaySize = ImVec2(event.getWidth(), event.getHeight());
		//io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);
		//glViewport(0, 0, event.getWidth(), event.getHeight());

		return false;
	}

	ImGuiKey ImGuiLayer::mapGLFWKeyToImGuiKey(int key) {
		switch (key) {
		case GLFW_KEY_TAB: return ImGuiKey_Tab;
		case GLFW_KEY_LEFT: return ImGuiKey_LeftArrow;
		case GLFW_KEY_RIGHT: return ImGuiKey_RightArrow;
		case GLFW_KEY_UP: return ImGuiKey_UpArrow;
		case GLFW_KEY_DOWN: return ImGuiKey_DownArrow;
		case GLFW_KEY_PAGE_UP: return ImGuiKey_PageUp;
		case GLFW_KEY_PAGE_DOWN: return ImGuiKey_PageDown;
		case GLFW_KEY_HOME: return ImGuiKey_Home;
		case GLFW_KEY_END: return ImGuiKey_End;
		case GLFW_KEY_INSERT: return ImGuiKey_Insert;
		case GLFW_KEY_DELETE: return ImGuiKey_Delete;
		case GLFW_KEY_BACKSPACE: return ImGuiKey_Backspace;
		case GLFW_KEY_SPACE: return ImGuiKey_Space;
		case GLFW_KEY_ENTER: return ImGuiKey_Enter;
		case GLFW_KEY_ESCAPE: return ImGuiKey_Escape;
		case GLFW_KEY_A: return ImGuiKey_A;
		case GLFW_KEY_B: return ImGuiKey_B;
		case GLFW_KEY_C: return ImGuiKey_C;
		case GLFW_KEY_V: return ImGuiKey_V;
		case GLFW_KEY_X: return ImGuiKey_X;
		case GLFW_KEY_Y: return ImGuiKey_Y;
		case GLFW_KEY_Z: return ImGuiKey_Z;
		default: return ImGuiKey_None; // Ignore unrecognized keys
		}
	}

}