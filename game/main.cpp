/**
 * Author:    Jens Heukers
 * Created:   13.02.2024
 *
 * Main entry point
 *
 **/
#include <core.h>

int main(int argc, char* argv[]) {
	Core* core = new Core();

	while (!core->ShouldQuit()) {
		core->Update();
	}

	delete core;

	return 0;
}