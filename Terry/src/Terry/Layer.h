#pragma once
#include "Terry/Core.h"
#include "Terry/Events/Event.h"

namespace Terry {
	class TR_API Layer {
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();
		virtual void OnAttach() {};
		virtual void OnDettach() {};
		virtual void OnUpdate() {};
		virtual void OnEvent(Event& event) {};
		inline const std::string& GetName() { return m_DebugName; }
	protected:
		std::string m_DebugName;

	};
}
