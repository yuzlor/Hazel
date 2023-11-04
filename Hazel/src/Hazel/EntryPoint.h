#pragma once

#ifdef HZ_PLATFORM_WINDOWS

extern Hazel::Application* Hazel::creatApplication();

int main(int* argc, char** argv)
{
	Hazel::Log::Init();
	HZ_CORE_WARN("Initialied Log!");
	int a = 1;
	HZ_INFO("Hello! var={0}", a);
	auto app = Hazel::creatApplication();
	app->run();
	delete app;
}

#endif