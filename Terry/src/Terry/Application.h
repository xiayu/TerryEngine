#pragma once
#include "Core.h"
#include "Terry/Events/Event.h"
#include "Terry/Events/ApplicationEvent.h"

#include "Terry/Window.h"
#include "Terry/Layer.h"
#include "Terry/LayerStack.h"

namespace Terry {
	class TR_API Application {
	public:
		Application();
		virtual ~Application();
		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

	private:
		bool OnWindowClose(WindowCloseEvent& e);
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};
	// to be defined in CLIENT
	Application* CreateApplication();
}