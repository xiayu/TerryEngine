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
		//layer
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		inline std::unique_ptr<Window>& GetWindow() { return m_Window; }

		inline static Application& Get() { return *m_Instance; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		// layer stack
		LayerStack m_LayerStack;
		static Application* m_Instance;
	};
	// to be defined in CLIENT
	Application* CreateApplication();
}