#pragma once
#include "Terry/Layer.h"

namespace Terry {
	class ImGuiLayer :public Layer {
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnUpdate() override;
		void OnEvent(Event& event) override;
		virtual void OnAttach() override;
		virtual void OnDettach() override;

	private:

	};
}