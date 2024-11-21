#include "ScipioPrecompiledHeader.h"
#pragma once

#include "scipio/Core.h"

namespace Scipio {

	enum class EventType
	{
		None = 0,
		WindowClose, 
		WindowResized, 
		WindowFocus,
		WindowLostFocus,
		WindowMoved,
		AppTick,
		AppUpdate,
		AppRender, 
		KeyPressed,
		KeyReleased, 
		MouseButtonPressed,
		MouseButtonReleased,
		MouseMoved,
		MouseScrolled
	};

	enum EventCategory
	{
		NONE = 0,
		EventCategoryApplication = BIT(0),
		EventCategoryInput = BIT(1),
		EventCategoryKeyboard = BIT(2),
		EventCategoryMouse = BIT(3),
		EventCategoryMouseButton = BIT(4)
	};

#define EVENT_CLASS_TYPE(type) static EventType getStaticType() { return EventType::##type; }\
																virtual EventType getEventType() const override { return getStaticType(); }\
																virtual const char* getName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int getCategoryFlags() const override { return category; }

	class SCIPIO_API Event {
		friend class EventDispatcher;

	public:

		bool handled = false;

		virtual EventType getEventType() const = 0;
		virtual const char* getName() const = 0;
		virtual int getCategoryFlags() const = 0;
		virtual std::string toString() const { return getName(); }

		inline bool isInCategory(EventCategory category) {
			return getCategoryFlags() & category;
		}

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
				m_Event.handled = func(*(T*)&m_Event);
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