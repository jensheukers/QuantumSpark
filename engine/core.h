/**
 * Author:    Jens Heukers
 * Created:   13.02.2024
 *
 **/

#ifndef QUANTUMSPARK_CORE_H
#define QUANTUMSPARK_CORE_H
#include "graphics/renderer.h"

class Core {
private:
	bool m_bShouldQuit;

	Renderer* m_oRenderer;
public:
	//Getters
	Renderer* GetRenderer() { return m_oRenderer;  }

	Core();
	~Core();

	void Update();
	bool ShouldQuit() { return m_bShouldQuit; }
};

#endif // !QUANTUMSPARK_CORE_H