#include <iostream>
#include <GL/glew.h>
#include "display.h"
#include "shader.h"
#include "mesh.h"
#include "texture.h"
#include "transform.h"

int main(int argc, char* argv[])
{	
	Display display(800, 600, "Hello World");

	Vertex vertices[] = {
				Vertex(glm::vec3(-0.5, -0.5, 0), glm::vec2(0.0, 0.0)),
				Vertex(glm::vec3(0, 0.5, 0), glm::vec2(0.5, 1.0)),
				Vertex(glm::vec3(0.5, -0.5, 0), glm::vec2(1.0, 0.0)),
	};

	Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]));
	Shader shader("./res/basicShader");
	Texture texture("./res/bricks.jpg");
	Transform transform;

	float counter = 0.0f;


	while (!display.isClosed()) {

		display.Clear(0.15f, 0.0f, 0.4f, 1.0f);
		float cosCounter = cosf(counter);

		transform.GetPos().x = sinf(counter);
		transform.GetRot().z = counter;
		transform.SetScale(glm::vec3(cosCounter, cosCounter, cosCounter));


		shader.Bind();
		texture.Bind(0);
		shader.Update(transform);
		mesh.Draw();

		display.Update();
		counter += 0.03f;

	}
	return 0;
}