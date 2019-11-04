#include "trpch.h"
#include "ImGuiLayer.h"
#include "Platform/OpenGL/ImGuiOpenGLRenderer.h"

namespace Terry {
	
	ImGuiLayer::ImGuiLayer()
		:Layer("imgui layer")
	{

	}

	ImGuiLayer::~ImGuiLayer()
	{

	}

	void ImGuiLayer::OnUpdate()
	{

	}

	void ImGuiLayer::OnEvent(Event& event)
	{

	}
	
	void ImGuiLayer::OnAttach()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	void ImGuiLayer::OnDettach()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

}