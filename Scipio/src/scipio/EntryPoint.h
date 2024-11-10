#pragma once

#ifdef SP_PLATFORM_WINDOWS

extern Scipio::Application* Scipio::createApplication();

int main(int argc, char** argv)
{
	auto app = Scipio::createApplication();
	app->run();
	delete app;
}
#endif