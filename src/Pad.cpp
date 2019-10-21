#include "Pad.h"

Pad * Pad::instance = NULL;

const unsigned int Pad::Up = (1 << 0);
const unsigned int Pad::Down = (1 << 1);
const unsigned int Pad::Left = (1 << 2);
const unsigned int Pad::Right = (1 << 3);

const unsigned int Pad::ButtonA = (1 << 5);
const unsigned int Pad::ButtonB = (1 << 6);

Pad::Pad()
{
	normal = 0;
	old = 0;
	trigger = 0;
	changed = 0;
	released = 0;
	isDiagonalDirectionBlocked = true;
}

void Pad::onFrame()
{
	old = normal;
	normal = 0;

	const Uint8* keyStates = SDL_GetKeyboardState(NULL);

	if ((!isDiagonalDirectionBlocked) || !(keyStates[SDL_SCANCODE_UP] && keyStates[SDL_SCANCODE_DOWN])) {
		if (keyStates[SDL_SCANCODE_UP]) {
			normal |= Up;
		}
		if (keyStates[SDL_SCANCODE_DOWN]) {
			normal |= Down;
		}
	}

	if ((!isDiagonalDirectionBlocked) || !(keyStates[SDL_SCANCODE_LEFT] && keyStates[SDL_SCANCODE_RIGHT])) {
		if (keyStates[SDL_SCANCODE_LEFT]) {
			normal |= Left;
		}
		if (keyStates[SDL_SCANCODE_RIGHT]) {
			normal |= Right;
		}
	}

	if (keyStates[SDL_SCANCODE_Z]) {
		normal |= ButtonA;
	}
	if (keyStates[SDL_SCANCODE_X]) {
		normal |= ButtonB;
	}

	changed = normal ^ old;
	trigger = normal & changed;
	released = (!normal) & changed;
}

Pad *Pad::getInstance()
{
	if (instance == NULL) {
		instance = new Pad();
	}
	return instance;
}
