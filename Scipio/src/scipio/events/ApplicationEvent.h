#pragma once

#include "Event.h"

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

		EVENT_CLASS_TYPE(WindowResized)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)

	private:
		unsigned int m_Width, m_Height;
	};

	class SCIPIO_API WindowCloseEvent : public Event {

	public:
		WindowCloseEvent() {}

		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class SCIPIO_API AppTickEvent : public Event {

	public:
		AppTickEvent() {}

		EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class SCIPIO_API AppUpdateEvent : public Event{

	public:
		AppUpdateEvent() {}

		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class SCIPIO_API AppRenderEvent : public Event{

	public:
		AppRenderEvent() {}

		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
}