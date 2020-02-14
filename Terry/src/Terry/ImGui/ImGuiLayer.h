#pragma once
#include "Terry/Layer.h"

#include "Terry/Events/KeyEvent.h"
#include "Terry/Events/MouseEvent.h"
#include "Terry/Events/ApplicationEvent.h"

namespace Terry {
	class TR_API ImGuiLayer :public Layer {
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnUpdate() override;
		void OnEvent(Event& event) override;

		virtual void OnAttach() override;
		virtual void OnDettach() override;

	private:
		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
		bool OnMouseMovedEvent(MouseMovedEvent& e);
		bool OnMouseScrolledEvent(MouseScrolledEvent& e);
		bool OnKeyPressedEvent(KeyPressedEvent& e);
		bool OnKeyReleasedEvent(KeyReleasedEvent& e);
		bool OnKeyTypedEvent(KeyTypedEvent& e);
		bool OnWindowResizedEvent(WindowResizedEvent& e);

	private:
		float m_time = 0.0f;
	};
}