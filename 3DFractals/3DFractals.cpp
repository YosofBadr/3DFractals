#include <iostream>
#include <GL/glew.h>
#include "display.h"
#include "shader.h"
#include "mesh.h"
#include "texture.h"
#include "transform.h"
#include "camera.h"

#define WIDTH 800
#define HEIGHT 600

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
	Camera camera(glm::vec3(0, 0, -3), 70.0f, (float)WIDTH / (float)HEIGHT, 0.01f, 1000.0f);
	Transform transform;

	float counter = 0.0f;


	while (!display.isClosed()) {

		display.Clear(0.15f, 0.0f, 0.4f, 1.0f);
		float cosCounter = cosf(counter);
		float sinCounter = sinf(counter);


		transform.GetPos().x = sinCounter;
		transform.GetPos().z = cosCounter;
		transform.GetRot().x = counter;
		transform.GetRot().y = counter;
		transform.GetRot().z = counter;

		//transform.SetScale(glm::vec3(cosCounter, cosCounter, cosCounter));


		shader.Bind();
		texture.Bind(0);
		shader.Update(transform, camera);
		mesh.Draw();

		display.Update();
		counter += 0.03f;

	}
	return 0;
}