#include "trpch.h"
#include "Terry.h"

class ExampleLayer :public Terry::Layer {
public:
	ExampleLayer() :
		Layer("Example") {

	}

	void OnUpdate() override {
		if (Terry::Input::IsKeyPressed(TR_KEY_TAB))
			TR_INFO("Tab key pressed!");
	}

	void OnEvent(Terry::Event& event) override {
		//TR_INFO("{0}", event);
	}
};


class SanBox :public Terry::Application
{
public:
	SanBox() {
		PushLayer(new ExampleLayer()); 
		PushOverlay(new Terry::ImGuiLayer());
	}

	~SanBox() {

	}

};
Terry::Application *Terry::CreateApplication() {
	return new SanBox();
}