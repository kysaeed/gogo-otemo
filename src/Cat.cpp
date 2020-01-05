#include "Cat.h"

#include <iostream>

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

	std::cout << "********** CAT **************" << std::endl;


	setClipSize(128, 128);
	// boudingBox = Rect(44, 20, 37, 64);
	load("./data/koneko.oan");

	isDeadState = false;


	return true;
}

void Cat::kill()
{
	animations.setCurrentAnimationNumber(1);
	setDead(true);
	// setDead(true);
}

bool Cat::onFrame()
{
	// if (++frameCount > 4) {
	// 	frameCount = 0;
	// 	setClipIndex((getClipIndex() + 1) % 2);
	// }

	int s = animations.getCurrentAnimationNumber();

	if (s == 0) {
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
	}

	if (s == 1) {
		getRect()->move(3, 8);
	}

	return Actor::onFrame();
}
