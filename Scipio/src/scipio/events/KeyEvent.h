#pragma once

#include "Event.h"

namespace Scipio {
	class SCIPIO_API KeyEvent : public Event {

	public: 
		inline int getKeyCode() const {
			return m_KeyCode;
		}

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard| EventCategoryInput);
		
	protected:
		KeyEvent(int keycode) : m_KeyCode(keycode) {}

		int m_KeyCode;
	};

	class SCIPIO_API KeyPressedEvent : public KeyEvent {
		
	public:
		KeyPressedEvent(int keycode, int repeatCount) : KeyEvent(keycode), m_RepeatCount(repeatCount) {}

		inline int getRepeatedCount() const {
			return m_RepeatCount;
		}

		std::string toString() const override {
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KEY_PRESSED)

	private:
		int m_RepeatCount;
	};

	class SCIPIO_API KeyReleasedEvent : public KeyEvent {
		
	public:
		KeyReleasedEvent(int keycode) : KeyEvent(keycode) {}

		std::string toString() const override {
			std::stringstream ss;
			ss << "KeyReleaseEvent " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KEY_RELEASED)
	};
}