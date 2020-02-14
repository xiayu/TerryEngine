#pragma once
#include "Terry/Core.h"
#include "Terry/Events/Event.h"

namespace Terry {
	class TR_API KeyEvent :public Event {
	public:
		inline int GetKeyCode() {
			return m_KeyCode;
		}
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryKeyboard)
	protected:
		KeyEvent(int keycode):m_KeyCode(keycode){
		} 
		int m_KeyCode;
	};

	class TR_API KeyPressedEvent :public KeyEvent {
	public:
		KeyPressedEvent(int keycode, int repeatcount) :KeyEvent(keycode), m_RepeatCount(repeatcount) {

		}
		inline int GetRepeatCount() { return m_RepeatCount; }
		std::string ToString() const override {
			std::stringstream ss;
			ss << "KeyPressedEvent:" << m_KeyCode << "(" << m_RepeatCount << " repeats)";
			return ss.str();
		}
		EVENT_CLASS_TYPE(KeyPressed)
	private:
		int m_RepeatCount;
	};
	
	class TR_API KeyReleasedEvent :public KeyEvent {
	public:
		KeyReleasedEvent(int keycode) :KeyEvent(keycode) {

		}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "KeyReleasedEvent:" << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};

	class TR_API KeyTypedEvent :public KeyEvent {
	public:
		KeyTypedEvent(int keycode) :KeyEvent(keycode) {

		}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "KeyTypedEvent:" << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyTyped)
	};

}