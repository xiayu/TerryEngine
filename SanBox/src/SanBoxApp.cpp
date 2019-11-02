#include "trpch.h"
#include "Terry.h"
class ExampleLayer :public Terry::Layer {
public:
	ExampleLayer() :
		Layer("Example") {

	}
	void OnUpdate() override {
		TR_INFO("ExampleLayer update");
	}

	void OnEvent(Terry::Event& event) override {
		TR_INFO("{0}", event);
	}
};
class SanBox :public Terry::Application
{
public:
	SanBox() {
		PushLayer(new ExampleLayer());
	}

	~SanBox() {

	}

};
Terry::Application *Terry::CreateApplication() {
	return new SanBox();
}