/**
 * Author:    Jens Heukers
 * Created:   13.02.2024
 *
 **/

#include "core.h"
#include "debug.h"

Core::Core() {
	Debug::Print("QuantumSpark loading...");

	m_bShouldQuit = false;

	//Create renderer
	m_oRenderer = new Renderer();
}

Core::~Core() {
	Debug::Print("Exiting QuantumSpark...");

	delete m_oRenderer;
}

void Core::Update() {
	if (!m_oRenderer)
		return;

	m_oRenderer->Draw();

	if (m_oRenderer->ShouldClose())
		m_bShouldQuit = true;

	float deltaTime = m_oRenderer->GetDeltaTime();


}