#pragma once
#include <gl/glew.h>
#include <GLFW/glfw3.h>

namespace Sparky {
	namespace Graphics {

#define MAX_KEYS 1024
#define MAX_BUTTONS 32

		class Window {
		private:
			const char* m_Name;
			int m_Width, m_Height;
			GLFWwindow* m_window;
			bool m_Closed;

			bool m_keys[MAX_KEYS];
			bool m_MouseButtons[MAX_BUTTONS];
			double mouse_x, mouse_y;

		public:
			Window(const char* name, int widht, int height);
			~Window();
			void Update();
			bool Closed() const;
			void Clear() const;


			inline int getWidht() { return m_Width; };
			inline int getHeight() { return m_Height; };

			bool IsKeyPressed(unsigned int keycode) const;
			bool IsMouseButtonPressed(unsigned int button_code) const;
			void GetMousePosition(double& x, double& y) const;

		private:
			bool Init();

			// These are functions which will be called when a user presses a key,or presses mouse button, or moves cursor
			// They are used in GLFW Functions : glfwSetKeyCallback(m_window, key_callback);
			//									 glfwSetMouseButtonCallback(m_window, mouse_button_callback)

			friend static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
			friend static void mouse_button_callback(GLFWwindow* window, int button, int action, int mode);
			friend static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
		};


	}
}