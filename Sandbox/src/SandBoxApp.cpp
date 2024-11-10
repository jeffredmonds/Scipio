#include <Scipio.h>


class Sandbox : public Scipio::Application {
public:
	Sandbox() {

	}

	~Sandbox() {

	}
};

Scipio::Application* Scipio::createApplication()
{
	return new Sandbox();
}