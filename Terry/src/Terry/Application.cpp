#include "Application.h"
#include "Terry/Events/ApplicationEvent.h"
#include "Terry/Log.h"

namespace Terry {
	Application::Application() {

	}
	Application::~Application() {

	}

	void Application::Run() {
		WindowResizedEvent e(800, 600);
		TR_TRACE(e);
		while (true);
	}
}