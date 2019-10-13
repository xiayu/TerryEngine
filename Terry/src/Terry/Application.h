#pragma once
#include "Core.h"

namespace Terry {
	class TR_API Application {
	public:
		Application();
		virtual ~Application();
		void Run();
	};
	// to be defined in CLIENT
	Application* CreateApplication();
}