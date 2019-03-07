#include "window.h"

int main(int argc, char** args)
{
	Window window("SDL test", 800, 600);

	while (!window.isClosed())
	{
		//window.pollEvents();
		window.clear();
	}
	return 0;
}