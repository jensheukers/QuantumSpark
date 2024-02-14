/**
 * Author:    Jens Heukers
 * Created:   13.02.2024
 *
 **/
#ifndef QUANTUMSPARK_RENDERER_H
#define QUANTUMSPARK_RENDERER_H
#include <GLFW/glfw3.h>
#include <vector>

class Renderer {
protected:
	float m_iDeltaTime;
	GLFWwindow* m_pWindow;
public:
	Renderer();
	~Renderer();

	void CreateWindow(int pWidth, int pHeight, const char* pWindowTitle);
	void Draw();
	bool ShouldClose();
	float GetDeltaTime();
};

#endif // !QUANTUMSPARK_RENDERER_H