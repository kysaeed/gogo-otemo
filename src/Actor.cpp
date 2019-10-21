#include "Actor.h"

const int Actor::DefaultWidth = 128;
const int Actor::DefaultHeight = 128;


Actor::Actor()
{
	// x = 128;
	// y = 128;


	frameCount = 0;
	animationCount = 0;

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
	return true;
}

// bool Actor::render(SDL_Renderer* pRenderer)
// {
//   sprite->setPosition(x, y);
//   sprite->render(pRenderer);
//
//   return true;
// }

// void Actor::clean()
// {
//   sprite->clean();
// }
