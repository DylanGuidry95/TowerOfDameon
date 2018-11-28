#include "Application2D.h"
#include "TowerofDameonApp.h"
int main() {
	
	// allocation
	auto app = new TowerofDameonApp();

	// initialise and loop
	app->run("AIE", 1280, 720, false);

	// deallocation
	delete app;

	return 0;
}