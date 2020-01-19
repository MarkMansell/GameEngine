#pragma once

#define MAX_KEYS 1024
#define MAX_BUTTONS 32

namespace Engine{
	namespace input{

		class Keyboard
		{
		public:
			static Keyboard& GetInstance();

			inline void SetKeyState(unsigned int key, bool state)
			{
				m_keys[key] = state;
			}

			inline bool isPressed(unsigned int key) const
			{
				return m_keys[key];
			}

		private:
			Keyboard()
			{
				for (int i = 0; i < MAX_KEYS; i++)
				{
					m_keys[i] = false;
				}
			}
		private:
			static Keyboard m_Instance;
			bool m_keys[MAX_KEYS];
		};

		class Mouse
		{
		public:
			static Mouse& GetInstance();

			inline double GetX() { return m_mx; }
			inline double GetY() { return m_my; }

			inline void SetX(double x) { m_mx = x; }
			inline void SetY(double y) { m_my = y; }

			inline void SetButtonState(unsigned int button, bool state)
			{
				m_Buttons[button] = state;
			}

			inline bool isPressed(unsigned int button)
			{
				return m_Buttons[button];
			}
		private:
			Mouse()
			{
				for (int i = 0; i < MAX_BUTTONS; i++)
				{
					m_Buttons[i] = false;
				}
			}

		private:
			static Mouse m_Instance;
			bool m_Buttons[MAX_BUTTONS];
			double m_mx;
			double m_my;
		};



	}
}