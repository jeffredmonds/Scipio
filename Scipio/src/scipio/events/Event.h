#pragma once

#include "scipio/Core.h"

#include <string>
#include <functional>

namespace Scipio {

	enum class EventType
	{
		NONE = 0,
		WINDOW_CLOSED, 
		WINDOW_RESIZED, 
		WINDOW_FOCUS,
		WINDOW_LOST_FOCUS,
		WINDOW_MOVED,
		APP_TICK,
		APP_UPDATE,
		APP_RENDER, 
		KEY_PRESSED,
		KEY_RELEASED, 
		MOUSE_BUTTON_PRESSED,
		MOUSE_BUTTON_RELEASED,
		MOUSE_MOVED,
		MOUSE_SCROLLED
	};

	enum EventCategory
	{
		NONE = 0,
		EVENT_CATEGORY_APPLICATION = BIT(0),
		EVENT_CATEGORY_INPUT = BIT(1),
		EVENT_CATEGORY_KEYBOARD = BIT(2),
		EVENT_CATEGORY_MOUSE = BIT(3),
		EVENT_CATEGORY_MOUSE_BUTTON = BIT(4)
	};

#define EVENT_CLASS_TYPE(type) static EventType getStaticType() { return EventType::##type; }\
																virtual EventType getEventType() const override { return getStaticType(); }\
																virtual const char* getName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int getCategoryFlags() const override { return category; }

	class SCIPIO_API Event {
		friend class EventDispatcher;

	public:
		virtual EventType getEventType() const = 0;
		virtual const char* getName() const = 0;
		virtual int getCategoryFlags() const = 0;
		virtual std::string toString() const { return getName(); }

		inline bool isInCategory(EventCategory category) {
			return getCategoryFlags() & category;
		}
	protected:
		bool m_Handled = false;
	};

	class EventDispatcher {

		//T == event type
		template<typename T> using EventFn = std::function<bool(T&)>;

	public:

		//create instance of this class with the event recieved
		EventDispatcher(Event& event) : m_Event(event) {}

		template<typename T> bool dispatch(EventFn<T> func) {
			if (m_Event.getEventType() == T::getStaticType()) {
				//call function with passed in event for specific event type
				m_Event.m_Handled = func(*(T*)&m_Event);
				return true;
			}
			return false;
		}

	private:
		Event& m_Event;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e) {
		return os << e.toString();
	}
}