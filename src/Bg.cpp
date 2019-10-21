#include "Bg.h"

Bg::Bg()
{
	getRect()->setSize(1024, 768);
}

bool Bg::initialize(SDL_Renderer* pRenderer)
{
	loadImageFromFile(pRenderer, "./data/bg.png");

	// pImage = loadImageFromFile(pRenderer, "./data/bg.png");
	// if (pImage == NULL) {
	//   return false;
	// }

	return true;
}

bool Bg::onFrame()
{
	getRect()->move(-2, 0);
	if (getRect()->getX() <= -1024) {
		getRect()->setX(1024);
	}

	return true;
}
