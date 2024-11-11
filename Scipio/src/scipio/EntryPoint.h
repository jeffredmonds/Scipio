#pragma once

#ifdef SP_PLATFORM_WINDOWS

extern Scipio::Application* Scipio::createApplication();

int main(int argc, char** argv)
{
	Scipio::Log::Init();

	SP_CORE_INFO("Core logger initialized");
	SP_INFO("Application logger intitialized");

	auto app = Scipio::createApplication();
	app->run();
	delete app;
}
#endif