#include <iostream>
#include <GL/glew.h>
#include "display.h"
#include "shader.h"
#include "mesh.h"

int main(int argc, char* argv[])
{	
	Display display(800, 600, "Hello World");

	Vertex vertices[] = {
		Vertex(glm::vec3(-0.5, -0.5, 0)),
				Vertex(glm::vec3(0, 0.5, 0)),
				Vertex(glm::vec3(0.5, -0.5, 0)),
	};

	Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]));
	Shader shader("./res/basicShader");


	while (!display.isClosed()) {

		display.Clear(0.15f, 0.0f, 0.4f, 1.0f);
		shader.Bind();
		mesh.Draw();

		display.Update();

	}
	return 0;
}