#pragma once

#include "Event.h"

#include <sstream>

namespace Scipio {

	class SCIPIO_API MouseMoveEvent : public Event {

	public:
		MouseMoveEvent(float x, float y) : m_MouseX(x), m_MouseY(y) {}


		inline float getX() const {
			return m_MouseX;
		}

		inline float getY() const {
			return m_MouseY;
		}

		std::string toString() const override {
			std::stringstream ss;
			ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MOUSE_MOVED)
		EVENT_CLASS_CATEGORY(EVENT_CATEGORY_MOUSE | EVENT_CATEGORY_INPUT)

	private:
		float m_MouseX, m_MouseY;
	};

	class SCIPIO_API MouseButtonEvent : public Event {

	public:
		inline int GetMouseButton() const { return m_Button; }

		EVENT_CLASS_CATEGORY(EVENT_CATEGORY_MOUSE | EVENT_CATEGORY_INPUT)

	protected:

		MouseButtonEvent(int button) : m_Button(button) {}

		int m_Button;
	};

	class SCIPIO_API MouseButtonPressedEvent : public MouseButtonEvent {
		
	public:
		MouseButtonPressedEvent(int button) : MouseButtonEvent(button) {}

		std::string toString() const override {
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MOUSE_BUTTON_PRESSED)
	};

	class SCIPIO_API MouseButtonReleasedEvent : MouseButtonEvent {

	public:
		MouseButtonReleasedEvent(int button) : MouseButtonEvent(button) {}

		std::string toString() const override {
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MOUSE_BUTTON_RELEASED)

	};
}