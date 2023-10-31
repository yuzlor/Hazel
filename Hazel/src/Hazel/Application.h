#pragma once

#include "Core.h"

namespace Hazel
{
	class HAZEL_API Application
	{
	public:
		Application();
		virtual ~Application();
		void run();
	};

	//to be defined in CLIENT
	Application* creatApplication();
}



