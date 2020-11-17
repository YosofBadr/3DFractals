#include <iostream>
#include <GL/glew.h>
#include "display.h"
#include "shader.h"

int main(int argc, char* argv[])
{	
	Display display(800, 600, "Hello World");

	Shader shader("./res/basicShader");


	while (!display.isClosed()) {

		display.Clear(0.15f, 0.0f, 0.4f, 1.0f);
		shader.Bind();

		display.Update();

	}
	return 0;
}