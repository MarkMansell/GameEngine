#include "src\graphics\window.h"
#include "src\graphics\shader.h"
#include "src\maths\maths.h"

#include "src\graphics\buffers\buffer.h"
#include "src\graphics\buffers\indexbuffer.h"
#include "src\graphics\buffers\vertexarray.h"

#include "src/graphics/renderer2d.h"
#include "src/graphics/simple2drenderer.h"

#include "src/graphics/batchrenderer2d.h"

#include "src\graphics\static_sprite.h"
#include "src\graphics\sprite.h"

#include <time.h>
#include "src\Utilities\timer.h"



int main()
{
	using namespace Engine;
	using namespace graphics;
	using namespace maths;

	Window window("Engine", 960, 540);
	//glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	mat4 ortho = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

	srand(time(NULL));

	std::vector<Renderable2D*> sprites;

	Shader shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	shader.enable();
	shader.setUniformMat4("pr_matrix", ortho);
	//shader.setUniformMat4("ml_matrix", mat4::translation(vec3(4, 3, 0)));
	//shader.setUniformMat4("ml_matrix", mat4::rotation(45.0f, vec3(0, 0, 1)));
	Sprite sprite(5, 5, 4, 4, maths::vec4(1, 0, 1, 1));
	Sprite sprite2(7, 1, 2, 3, maths::vec4(0.2f, 0, 1, 1));
	BatchRenderer2D renderer;


	for (float y = 0; y < 9.0f; y++)
	{
		for (float x = 0; x < 16.0f; x++)
		{
			sprites.push_back(new Sprite(x, y, 0.9f, 0.9f, maths::vec4(rand() % 1000 / 1000.0f, 0, 1, 1)));
		}
	}



	shader.setUniform2f("light_pos", vec2(4.0f, 1.5f));
	shader.setUniform4f("colour", vec4(0.2f, 0.4f, 0.8f, 1.0f));






	Timer time;
	float timer = 0;
	unsigned int frames = 0;

	while (!window.closed())
	{
		mat4 mat = mat4::translation(vec3(5, 5, 5));
		//mat = mat * mat4::rotation(time.elapsed(), vec3(0, 0, 1));
		mat = mat * mat4::translation(vec3(-5, -5, -5));
		shader.setUniformMat4("ml_matrix", mat);

		double x = input::Mouse::GetInstance().GetX();
		double y = input::Mouse::GetInstance().GetY();


		shader.setUniform2f("light_pos", vec2((float)(x * 16.0f / 960.0f), (float)(9.0f - y * 9.0f / 540.0f)));
		window.clear();
			//glDrawArrays(GL_TRIANGLES, 0, 6);
		//double x, y;
		


		renderer.begin();

		for (int j = 0; j < sprites.size(); j++)
		{
			renderer.submit(sprites[j]);
		}

		//renderer.submit(&sprite);
		//renderer.submit(&sprite2);
		renderer.end();
		renderer.flush();
		window.update();
		frames++;
		if (time.elapsed() - timer > 1.0f)
		{
			timer += 1.0f;
			printf("%d FPS \n", frames);
			frames = 0;
		}

	}
	return 0;
}
