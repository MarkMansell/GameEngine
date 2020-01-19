#include "input.h"

namespace Engine{
	namespace input{

		Mouse Mouse::m_Instance;

		Mouse& Mouse::GetInstance()
		{
			return Mouse::m_Instance;
		}

		Keyboard Keyboard::m_Instance;

		Keyboard& Keyboard::GetInstance()
		{
			return Keyboard::m_Instance;
		}

	}
}