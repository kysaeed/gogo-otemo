#include "Actor.h"

const int Actor::DefaultWidth = 128;
const int Actor::DefaultHeight = 128;

#include <iostream>

Actor::Actor()
{
	// x = 128;
	// y = 128;


	state = none;

	setClipSize(DefaultWidth, DefaultHeight);
}

Actor::~Actor()
{
	clean();
}

bool Actor::initialize(SDL_Renderer* pRenderer)
{
	return true;
}

bool Actor::onFrame()
{
	if (animations.getCurrentAnimation().isNull()) {
		onAnimationEnd(animations.getCurrentAnimationNumber());
		return true;
	}

	AnimationFrame frame = animations.getCurrentAnimation().getCurrentFrame();
	setClipIndex(frame.getCell());
	// std::cout << "cell:" << frame.getCell() << " frameCount:" << frame.getFrameCount() << std::endl;
	if (animations.getCurrentAnimation().moveNextFrame()) {
		onAnimationEnd(animations.getCurrentAnimationNumber());
	}

	return true;
}

void Actor::onAnimationEnd(int animationNumber)
{
	// std::cout << "onAnimationEnd : " << animationNumber << std::endl;
}

bool Actor::render(SDL_Renderer* pRenderer)
{
	if (!animations.getCurrentAnimation().isNull()) {
		AnimationFrame frame = animations.getCurrentAnimation().getCurrentFrame();
		return paint(pRenderer, rect.getX() + frame.getX(), rect.getY() + frame.getY());
	}

	return paint(pRenderer, rect.getX(), rect.getY());
}

bool Actor::load(const std::string &filename)
{
	SDL_RWops* file = SDL_RWFromFile(filename.c_str(), "r");
	if (file == nullptr) {
		return false;
	}

	int32_t r[4];
	SDL_RWread(file, r, sizeof(int32_t), 4);
	boudingBox = Rect(r[0], r[1], r[2], r[3]);

	std::cout << "bouding-box : (" << boudingBox.getX() << ", " << boudingBox.getY() << ") " <<
		boudingBox.getWidth() << "x" << boudingBox.getHeight() << std::endl;

	int32_t cellCount = 1;
	SDL_RWread(file, &cellCount, sizeof(int32_t), 1);

	std::cout << "cell-count : " << cellCount << std::endl;

	for (int i =  0; i < cellCount; i++) {
		SDL_RWread(file, r, sizeof(int32_t), 4);

		int32_t c = 0;
		SDL_RWread(file, &c, sizeof(int32_t), 1);
		std::cout << "\tpoint-count = " << c << std::endl;

		for (int j = 0; j < c; j++) {
			int32_t filler[3] = { 0 };
			SDL_RWread(file, filler, sizeof(int32_t), 3);
		}
	}

	animations.read(file);

	return true;
}

// void Actor::clean()
// {
//   sprite->clean();
// }
