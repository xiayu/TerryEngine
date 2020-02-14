#pragma once
#include "Terry/Input.h"

namespace Terry {
	class WindowsInput :public Input {
	public:
	protected:
		virtual bool IsKeyPressedImpl(int keycode) override;
		virtual bool IsMouseButtonPressedImpl(int button) override;
		virtual float GetMouseXImpl() override;
		virtual float GetMouseYImpl() override;
		virtual std::pair<float, float> GetMousePositionImpl() override;

	private:
	};
}
