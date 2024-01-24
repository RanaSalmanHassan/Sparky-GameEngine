#include <gl\glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "Src/Graphics/Window.h"

int main() {

	using namespace Sparky;
	using namespace Graphics;


	Window window("Test Window", 500, 1000);
	glClearColor(0.2f, 0.6f, 0.6f, 1.0f);

	std::cout << glGetString(GL_VERSION) << std::endl;

	while (!window.Closed())
	{
		//std::cout << "Widht : " << window.getWidht() << " , " << "Height : " << window.getHeight() << std::endl;
		window.Clear();
		if (window.IsKeyPressed(GLFW_KEY_A))
		{
			std::cout << "PRESSED!!!!" << std::endl;
		}
		if (window.IsMouseButtonPressed(GLFW_MOUSE_BUTTON_LEFT))
		{
			std::cout << "PRESSED!!!!" << std::endl;
		}
		double x, y;
		window.GetMousePosition(x, y);
		std::cout << x << " , " << y << std::endl;

		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(0.0f, 0.5f);
		glVertex2f(0.5f, -0.5f);
		glEnd();
		window.Update();
	}
}