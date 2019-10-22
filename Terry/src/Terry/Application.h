#pragma once
#include "Core.h"
#include "Terry/Window.h"

namespace Terry {
	class TR_API Application {
	public:
		Application();
		virtual ~Application();
		void Run();
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};
	// to be defined in CLIENT
	Application* CreateApplication();
}