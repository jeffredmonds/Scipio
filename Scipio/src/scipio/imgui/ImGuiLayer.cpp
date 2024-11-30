#include"ScipioPrecompiledHeader.h"
#include "ImGuiLayer.h"

#include "imgui.h"
#include "scipio/platform/opengl/ImGuiOpenGLRenderer.h"
#include "GLFW/glfw3.h"

#include "scipio/Application.h"


namespace Scipio {

	ImGuiLayer::ImGuiLayer() : Layer("ImGuiLayer") {

	}

	ImGuiLayer::~ImGuiLayer() {

	}
	
	void ImGuiLayer::onAttach() {
		ImGui::CreateContext();
		ImGui::StyleColorsDark();

		ImGuiIO& io = ImGui::GetIO();

		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;


		//TODO this is super borked 
		//GLFWwindow* window = (GLFWwindow*)Application::getWindow();

		//// TODO: remove 
		//io.AddKeyEvent(ImGuiKey_Tab, glfwGetKey(window, GLFW_KEY_TAB) == GLFW_PRESS);
		//io.AddKeyEvent(ImGuiKey_LeftArrow, glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS);
		//io.AddKeyEvent(ImGuiKey_RightArrow, glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS);
		//io.AddKeyEvent(ImGuiKey_UpArrow, glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS);
		//io.AddKeyEvent(ImGuiKey_DownArrow, glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS);
		//io.AddKeyEvent(ImGuiKey_PageUp, glfwGetKey(window, GLFW_KEY_PAGE_UP) == GLFW_PRESS);
		//io.AddKeyEvent(ImGuiKey_PageDown, glfwGetKey(window, GLFW_KEY_PAGE_DOWN) == GLFW_PRESS);
		//io.AddKeyEvent(ImGuiKey_Home, glfwGetKey(window, GLFW_KEY_HOME) == GLFW_PRESS);
		//io.AddKeyEvent(ImGuiKey_End, glfwGetKey(window, GLFW_KEY_END) == GLFW_PRESS);
		//io.AddKeyEvent(ImGuiKey_Insert, glfwGetKey(window, GLFW_KEY_INSERT) == GLFW_PRESS);
		//io.AddKeyEvent(ImGuiKey_Delete, glfwGetKey(window, GLFW_KEY_DELETE) == GLFW_PRESS);
		//io.AddKeyEvent(ImGuiKey_Backspace, glfwGetKey(window, GLFW_KEY_BACKSPACE) == GLFW_PRESS);
		//io.AddKeyEvent(ImGuiKey_Space, glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS);
		//io.AddKeyEvent(ImGuiKey_Enter, glfwGetKey(window, GLFW_KEY_ENTER) == GLFW_PRESS);
		//io.AddKeyEvent(ImGuiKey_Escape, glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS);
		//io.AddKeyEvent(ImGuiKey_A, glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS);
		//io.AddKeyEvent(ImGuiKey_C, glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS);
		//io.AddKeyEvent(ImGuiKey_V, glfwGetKey(window, GLFW_KEY_V) == GLFW_PRESS);
		//io.AddKeyEvent(ImGuiKey_X, glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS);
		//io.AddKeyEvent(ImGuiKey_Y, glfwGetKey(window, GLFW_KEY_Y) == GLFW_PRESS);
		//io.AddKeyEvent(ImGuiKey_Z, glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS);

		ImGui_ImplOpenGL3_Init("#version 410");

	}
	void ImGuiLayer::onDetach() {

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
	void ImGuiLayer::onEvent(Event& evnet) {

	}

}