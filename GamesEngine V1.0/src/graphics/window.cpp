#include "window.h"

namespace Engine{
	namespace graphics {

		void windowResize(GLFWwindow* window, int width, int height);
		void onKeyChange(GLFWwindow* window, int key, int scancode, int action, int mods);
		void onMouseMove(GLFWwindow* window, double mx, double my);
		void onMouseChange(GLFWwindow* window, int button, int action, int mods);

		Window::Window(const char* title, int width, int height)
		{
			m_Title = title;
			m_Width = width;
			m_Height = height;

			if (!init())
			{
				glfwTerminate();
			}
		}

		Window::~Window()
		{
			glfwTerminate();
		}

		bool Window::init()
		{
			if (!glfwInit())
			{
				return false;
			}

			m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);

			if (!m_Window)
			{
				glfwTerminate();
				std::cout << "Failed to create the window" << std::endl;
				return false;
			}
			glfwMakeContextCurrent(m_Window);
			glfwSetWindowUserPointer(m_Window, this);
			glfwSetWindowSizeCallback(m_Window, windowResize);
			glfwSetKeyCallback(m_Window, onKeyChange);
			glfwSetMouseButtonCallback(m_Window, onMouseChange);
			glfwSetCursorPosCallback(m_Window, onMouseMove);
			glfwSwapInterval(0.0f);

			if (glewInit() != GLEW_OK)
			{
				std::cout << "GLEW Failed Initialize" << std::endl;
				return false;
			}
			std::cout << "OpenGL: " << glGetString(GL_VERSION) << std::endl;
			return true;
		}



		void Window::clear() const
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		void Window::update()
		{
			GLenum error = glGetError();
			if (error != GL_NO_ERROR)
				std::cout << "OpenGL Error: " << error << std::endl;
			glfwPollEvents();
			glfwSwapBuffers(m_Window);
		}

		bool Window::closed() const
		{
			return glfwWindowShouldClose(m_Window) == 1;
		}

		void windowResize(GLFWwindow* window, int width, int height)
		{
			glViewport(0, 0, width, height);
		}

		void onKeyChange(GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			input::Keyboard::GetInstance().SetKeyState(key, action != GLFW_RELEASE);
		}

		void onMouseMove(GLFWwindow* window, double mx, double my)
		{
			input::Mouse& mouse = input::Mouse::GetInstance();
			mouse.SetX(mx);
			mouse.SetY(my);
		}

		void onMouseChange(GLFWwindow* window, int button, int action, int mods)
		{
			input::Mouse::GetInstance().SetButtonState(button, action != GLFW_RELEASE);
		}
	}
}