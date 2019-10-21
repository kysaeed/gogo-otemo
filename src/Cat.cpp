#include "Cat.h"

Cat::Cat()
{
	direction = -1;
	frameCount = 0;
}

bool Cat::initialize(SDL_Renderer* pRenderer)
{
	if (!loadImageFromFile(pRenderer, "./data/sprite_koneko.png")) {
		return false;
	}

	setClipSize(128, 128);
	isDeadState = false;

	return true;
}

bool Cat::onFrame()
{
	if (++frameCount > 4) {
		frameCount = 0;
		setClipIndex((getClipIndex() + 1) % 2);
	}

	int x = getRect()->getX();

	x += (direction * 3);
	if (x < 500) {
		x = 500;
		direction = -direction;
	} else if (x > 990) {
		x = 990;
		direction = -direction;
	}

	getRect()->setX(x);

	return true;
}