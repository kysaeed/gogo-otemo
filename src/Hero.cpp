#include "Hero.h"
#include "Pad.h"

#include "EyeBeam.h"
#include "Core.h"
#include "SceneMain.h"
#include "Vector.h"

#include <iostream>

Hero::Hero()
{
}

bool Hero::initialize(SDL_Renderer* pRenderer)
{
	Actor::initialize(pRenderer);

	bool isInitilied = loadImageFromFile(pRenderer, "./data/otemo.png");
	getRect()->setPosition(70, 400);
	setClipSize(128, 128);

	std::cout << "********** HERO **************" << std::endl;
	animations.load("./data/otemo.oan");

	return isInitilied;
}

void Hero::createEyeBeams(SDL_Renderer* pRenderer, SceneMain* sceneMain)
{
	for (int i = 0; i < 3; i++) {
		EyeBeam* e = new EyeBeam();
		e->initialize(pRenderer);
		e->setObjectPool(&beamPool);
		beamPool.push(e);

		e->addEventListener(0, sceneMain, (EventHnadlerCallback) & SceneMain::onBeamAdded);
		e->addEventListener(1, sceneMain, (EventHnadlerCallback) & SceneMain::onBeamAdded);
	}
}

bool Hero::onFrame()
{
	bool isMoved = false;

	// float sin45 = 0.70710678118;
	// const float step = 4.0;

	Vector v;

	if (Pad::getInstance()->getNormal() & Pad::Left) {
		// getRect()->moveX(-4.0);
		v.setX(-1.0);
		isMoved = true;
	}

	if (Pad::getInstance()->getNormal() & Pad::Right) {
		v.setX(1.0);
		isMoved = true;
	}

	if (Pad::getInstance()->getNormal() & Pad::Up) {
		v.setY(-1.0);
		isMoved = true;
	}
	if (Pad::getInstance()->getNormal() & Pad::Down) {
		v.setY(1.0);
		isMoved = true;
	}

	v.normalize();
	v.scale(4.0);

	getRect()->move(v.getX(), v.getY());


	if (Pad::getInstance()->getTrigger() & Pad::ButtonA) {
		EyeBeam* e = (EyeBeam *) beamPool.pop();
		if (e != NULL) {
			e->getRect()->setPosition(getRect()->getX() + 40, getRect()->getY() + 24);

			Core::getInstance()->gatCurrentScene()->attach(e);
		}
		animations.setCurrentAnimationNumber(0);
		animations.getCurrentAnimation().reset();
	}

	if (Pad::getInstance()->getTrigger() & Pad::ButtonB) {
		animations.setCurrentAnimationNumber(1);
		animations.getCurrentAnimation().reset();
	}
	if (isMoved) {
		state = move;
	} else {
		state = none;
	}

	return Actor::onFrame();
}

void Hero::onAnimationEnd(int animationNumber)
{
	if (animationNumber == 1) {
		animations.setCurrentAnimationNumber(0);
	}
}
