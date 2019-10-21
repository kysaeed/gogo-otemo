#include <iostream>

#include "Core.h"
#include "GameObject.h"

int main(int argc, char** argv)
{
	Core* g = Core::getInstance();
	if (!g->initialize()) {
		Core::exit();
		return -1;
	}

	int result = g->run();

	Core::exit();

	return result;
}
