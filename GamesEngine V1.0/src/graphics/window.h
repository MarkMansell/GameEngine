#pragma once
#include <iostream>
#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include "../input/input.h"

namespace Engine{
	namespace graphics {

		class Window
		{
		public:
			Window(const char* name, int width, int height);
			~Window();
			bool closed() const;
			void clear() const;
			void update();

			inline int getWidth() const { return m_Width; }
			inline int getHeight() const { return m_Height; }
			
			void getMousePosition(double &x, double &y);

		private:
			bool init();

		private:
			GLFWwindow* m_Window;
			const char* m_Title;
			int m_Width, m_Height;
			//bool m_Closed;
		};

	}
}