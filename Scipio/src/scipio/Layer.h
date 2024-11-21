#pragma once

#include "scipio/Core.h"
#include "scipio/events/Event.h"

namespace Scipio {

	class SCIPIO_API Layer {

	public:
		Layer(const std::string& name = "Layer");

		virtual ~Layer();

		virtual void onAttack() {}
		virtual void onDetach() {}
		virtual void onUpdate() {}
		virtual void onEvent(Event& event) {}

		inline const std::string& GetName() const { return m_DebugName; }

	protected:
		std::string m_DebugName;

	};

}