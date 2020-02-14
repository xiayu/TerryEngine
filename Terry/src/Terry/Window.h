#pragma once
#include "trpch.h"
#include "Terry/Core.h"
#include "Terry/Events/Event.h"

namespace Terry {
	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;
		WindowProps(const std::string &title = "Terry Engine",
			unsigned int width = 1280,
			unsigned int height = 720)
			:Title(title), Width(width), Height(height) {

		}
	};

	// Interface£¨WindowsWindow¡¢MacWindow¡¢LinuxWindow£©
	class TR_API Window {
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window(){}
		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;

		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		virtual void* GetNativeWindow() const = 0;

		static Window *Create(const WindowProps& props = WindowProps());
	};
}