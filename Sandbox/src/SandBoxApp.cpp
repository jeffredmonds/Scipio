#include <Scipio.h>


class TestLayer : public Scipio::Layer {
public:
	
	TestLayer() : Layer("test") {}

	void onUpdate() override {
		SP_INFO("TestLayer::Update");
	}

	void onEvent(Scipio::Event& event) override {
		SP_TRACE("{0}", event.toString());
	}
};


class Sandbox : public Scipio::Application {
public:
	Sandbox() {
		pushLayer(new TestLayer());
		pushOverlay(new Scipio::ImGuiLayer());
	}

	~Sandbox() {

	}
};

Scipio::Application* Scipio::createApplication()
{
	return new Sandbox();
}