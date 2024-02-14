/**
 * Author:    Jens Heukers
 * Created:   13.02.2024
 *
 **/
#include "renderer.h"
#include "debug.h"

Renderer::Renderer() {
	m_iDeltaTime = 0;
	m_pWindow = nullptr;

	if (!glfwInit())
		return;

	Debug::Print("GLFW Initialized");
}

Renderer::~Renderer() {
	glfwTerminate();

	Debug::Print("GLFW Teriminated");
}

void Renderer::CreateWindow(int pWidth, int pHeight, const char* pWindowTitle) {
	m_pWindow = glfwCreateWindow(pWidth, pHeight, pWindowTitle, NULL, NULL);
	glfwMakeContextCurrent(m_pWindow);
}

void Renderer::Draw() {
	if (!m_pWindow)
		return;

	glClear(GL_COLOR_BUFFER_BIT);

	glfwSwapBuffers(m_pWindow);
	glfwPollEvents();

	//Calculate delta time
	static float lastTime = (float)glfwGetTime();
	float currentTime = (float)glfwGetTime();

	m_iDeltaTime = currentTime - lastTime;
	lastTime = currentTime;
}

bool Renderer::ShouldClose() {
	if (!m_pWindow)
		return false;
	return glfwWindowShouldClose(m_pWindow);
}

float Renderer::GetDeltaTime() {
	return m_iDeltaTime;
}