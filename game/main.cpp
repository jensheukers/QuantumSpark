/**
 * Author:    Jens Heukers
 * Created:   13.02.2024
 *
 * Main entry point
 *
 **/
#include <core.h>
#include <debug.h>
#include <entity.h>

#include "math/vector3.h"

int main(int argc, char* argv[]) {
	vector3 vector = vector3(10, 0, 0);
	vector = vector + 2;

	Debug::Print(vector);
	
	Entity* entity = new Entity();
	Component* component = new Component();
	entity->AddComponent(component);

	Core* core = new Core();
	core->GetRenderer()->CreateWindow(1080, 720, "QuantumSpark");

	while (!core->ShouldQuit()) {
		core->Update();
	}

	delete core;

	return 0;
}