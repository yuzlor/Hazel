#pragma once

#ifdef HZ_PLATFORM_WINDOWS

extern Hazel::Application* Hazel::creatApplication();

int main(int* argc, char** argv)
{
	auto app = Hazel::creatApplication();
	app->run();
	delete app;
}

#endif