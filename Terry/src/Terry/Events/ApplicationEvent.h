#pragma once
#include "Terry/Core.h"
#include "Terry/Events/Event.h"
namespace Terry {
	class TR_API WindowResizedEvent :public Event {
	public:
		WindowResizedEvent(unsigned int width, unsigned int height) :m_Width(width), m_Height(height) {
		}
		inline int GetWidth() const { return m_Width; }
		inline int GetHeight() const {
			return m_Height;
		}
		std::string ToString() const override {
			std::stringstream ss;
			ss << "WindowResizedEvent:" << m_Width << "," << m_Height;
			return ss.str();
		}
		EVENT_CLASS_TYPE(WindowResized)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	private:
		unsigned int m_Width, m_Height;
	};

	class TR_API WindowCloseEvent :public Event {
	public:
		WindowCloseEvent(){}
		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class TR_API AppTickEvent :public Event {
	public:
		AppTickEvent(){}
		EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class TR_API AppRenderEvent :public Event {
	public:
		AppRenderEvent() {}
		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
}