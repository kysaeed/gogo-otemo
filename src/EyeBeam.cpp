#include "EyeBeam.h"
#include "Core.h"
#include "ObjectPool.h"

#include <iostream>

EyeBeam::EyeBeam()
{
}

bool EyeBeam::initialize(SDL_Renderer* pRenderer)
{
	if (!loadImageFromFile(pRenderer, "./data/eye_beam.png")) {
		return false;
	}

	SDL_SetTextureBlendMode(image, SDL_BLENDMODE_ADD);
	SDL_SetTextureAlphaMod(image, 0xE0);

	boundingBox = Rect(3, 27, 57, 10);

	return true;
}

bool EyeBeam::onFrame()
{
	getRect()->moveX(8);

	if (getRect()->getX() >= 1024) {
		return false;
	}

	return true;
}
