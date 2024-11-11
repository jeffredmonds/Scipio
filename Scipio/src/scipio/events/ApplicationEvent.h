#pragma once

#include "Event.h"

#include <sstream>

namespace Scipio {

	class SCIPIO_API WindowResizedEvent : public Event {

	public:
		WindowResizedEvent(unsigned int width, unsigned int height) : m_Width(width), m_Height(height) {}

		inline unsigned int getWidth() const { 
			return m_Width; 
		}

		inline unsigned int getHeight() const {
			return m_Height;
		}

		std::string toString() const override {
			std::stringstream ss;
			ss << "WindowResizeEvent: " << m_Width << ", " << m_Height;
			return ss.str();
		}

		EVENT_CLASS_TYPE(WINDOW_RESIZED)
		EVENT_CLASS_CATEGORY(EVENT_CATEGORY_APPLICATION)

	private:
		unsigned int m_Width, m_Height;
	};

	class SCIPIO_API WindowClosedEvent : public Event {

	public:
		WindowClosedEvent() {}

		EVENT_CLASS_TYPE(WINDOW_CLOSED)
		EVENT_CLASS_CATEGORY(EVENT_CATEGORY_APPLICATION)

	};

	class SCIPIO_API AppTickEvent : public Event {

	public:
		AppTickEvent() {}

		EVENT_CLASS_TYPE(APP_TICK)
		EVENT_CLASS_CATEGORY(EVENT_CATEGORY_APPLICATION)

	};

	class SCIPIO_API AppUpdateEvent : public Event{

	public:
		AppUpdateEvent() {}

		EVENT_CLASS_TYPE(APP_UPDATE)
		EVENT_CLASS_CATEGORY(EVENT_CATEGORY_APPLICATION)

	};

	class SCIPIO_API AppRenderEvent : public Event{

	public:
		AppRenderEvent() {}

		EVENT_CLASS_TYPE(APP_RENDER)
		EVENT_CLASS_CATEGORY(EVENT_CATEGORY_APPLICATION)

	};
}