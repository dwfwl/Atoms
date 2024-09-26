#include <iostream>
#include <Atoms/atoms.h>
#include <memory>
#include <opengl/Shaders/shader.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <periodicTable.h>

#include <chrono>

float calculateFPS() {
	static int frameCount = 0;
	static auto startTime = std::chrono::high_resolution_clock::now();
	frameCount++;

	auto currentTime = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::seconds>(currentTime - startTime).count();

	if (duration >= 1) {
		float fps = frameCount / static_cast<float>(duration);
		std::cout << "FPS: " << fps << std::endl;
		frameCount = 0; 
		startTime = currentTime; 
		return fps;
	}


	return 0.0f;
}

glm::mat4 setupProj(int windowWidth, int windowHeight)
{
	float aspectRatio = (float)windowWidth / (float)windowHeight;
	std::cout << aspectRatio << std::endl;
	return glm::ortho(-aspectRatio, aspectRatio, -1.0f, 1.0f, -1.0f, 1.0f);;
}

int main()
{
	glfwInit();

	GLFWwindow* window = glfwCreateWindow(1800, 980, "Atoms", nullptr, nullptr);
	glfwMakeContextCurrent(window);

	glfwSwapInterval(0);
	gladLoadGL();

	glViewport(0, 0, 1800, 980);

	std::unique_ptr<Shader> shader = std::make_unique<Shader>();
	shader_create(shader.get(), "../Element/inc/opengl/Shaders/default/default.vert", "../Element/inc/opengl/Shaders/default/default.frag");
	
	glm::mat4 projection = setupProj(1800, 980);
	u_mat4f(shader, "proj", projection);

	std::unique_ptr<PeriodicTable> periodicTable = std::make_unique<PeriodicTable>();

	while (!glfwWindowShouldClose(window))
	{
		calculateFPS();
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

		periodicTable->draw(*shader.get());
		

		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
} 