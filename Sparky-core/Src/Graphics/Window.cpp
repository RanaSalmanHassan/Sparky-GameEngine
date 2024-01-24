#include "Window.h"
#include <iostream>

namespace Sparky {
	namespace Graphics {

		Window::Window(const char* name, int widht, int height) {
			m_Name = name;
			m_Width = widht;
			m_Height = height;
			if (!Init())
			{
				glfwTerminate();
			}

			for (int i = 0; i < MAX_KEYS; i++)
			{
				m_keys[i] = false;
			}
			
			for (int i = 0; i < MAX_BUTTONS; i++)
			{
				m_MouseButtons[i] = false;
			}
		}

		void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode) {

			Window* win = (Window*)glfwGetWindowUserPointer(window);
			if (action != GLFW_RELEASE)
			{
				win->m_keys[key] = true;
			}
		}

		void mouse_button_callback(GLFWwindow* window, int button, int action, int mode) {
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			if (action != GLFW_RELEASE)
			{
				win->m_MouseButtons[button] = true;
			}
		}

		void cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win->mouse_x = xpos;
			win->mouse_y = ypos;
		}

		bool Window::Init() {

			if (!glfwInit())
			{
				std::cout << "Failed to initialize GLFW!" << std::endl;
				return false;
			}


			m_window = glfwCreateWindow(m_Height, m_Width, m_Name, NULL, NULL);
			if (!m_window)
			{
				glfwTerminate();
				std::cout << "Failed to creat a GLFW Window" << std::endl;
				return false;
			}
			glfwMakeContextCurrent(m_window);
			glfwSetWindowUserPointer(m_window, this);
			glfwSetKeyCallback(m_window, key_callback);
			glfwSetMouseButtonCallback(m_window, mouse_button_callback);
			glfwSetCursorPosCallback(m_window, cursor_position_callback);

			if (glewInit() != GLEW_OK)
			{
				std::cout << "Unable to initialize GLEW!" << std::endl;
				return false;
			}

			std::cout << glGetString(GL_VERSION) << std::endl;
			return true;

		}

		Window::~Window() {
			glfwTerminate();
		};

		void Window::Clear() const {
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		void Window::Update(){

			glfwPollEvents();
			glfwGetFramebufferSize(m_window, &m_Width, &m_Height);
			glViewport(0, 0, m_Width, m_Height);
			glfwSwapBuffers(m_window);
		};

		bool Window::Closed() const {
			return glfwWindowShouldClose(m_window) == 1;
		}

		bool Window::IsKeyPressed(unsigned int keycode) const{

			if (keycode >= MAX_KEYS)
			{
				return false;
			}

			return m_keys[keycode];
		}
		
		bool Window::IsMouseButtonPressed(unsigned int button_code) const{

			if (button_code >= MAX_BUTTONS)
			{
				return false;
			}

			return m_MouseButtons[button_code];
		}

		void Window::GetMousePosition(double& x, double& y) const{
			x = mouse_x;
			y = mouse_y;
		}

		

	}
}