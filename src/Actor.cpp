#include "Actor.h"

const int Actor::DefaultWidth = 128;
const int Actor::DefaultHeight = 128;


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
	return true;
}

bool Actor::render(SDL_Renderer* pRenderer)
{
	if (!animation.isNull()) {
		AnimationFrame frame = animation.getCurrentFrame();
		return paint(pRenderer, rect.getX() + frame.getX(), rect.getY() + frame.getY());
	}

	return paint(pRenderer, rect.getX(), rect.getY());
}

// void Actor::clean()
// {
//   sprite->clean();
// }
