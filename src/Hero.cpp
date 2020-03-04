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
	load("./data/otemo.oan");

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
	Vector v;

	if (Pad::getInstance()->getNormal() & Pad::Left) {
		v.setX(-1.0);
	}

	if (Pad::getInstance()->getNormal() & Pad::Right) {
		v.setX(1.0);
	}

	if (Pad::getInstance()->getNormal() & Pad::Up) {
		v.setY(-1.0);
	}
	if (Pad::getInstance()->getNormal() & Pad::Down) {
		v.setY(1.0);
	}

	v.normalize();
	v.scale(4.0);

	getRect()->move(v.getX(), v.getY());


	if (Pad::getInstance()->getTrigger() & Pad::ButtonA) {
		EyeBeam* e = (EyeBeam *) beamPool.pop();
		if (e != NULL) {
			Vector v(40, 24);

			ActorImageCellMountPoint* p = getMoutPoint(1);
			std::cout << "point addr : " << p << std::endl;
			if (p != nullptr) {
				std::cout << "  pos: " << p->getOffset().getX() << ", " << p->getOffset().getY() << std::endl;
				v = p->getOffset();
			}
			e->getRect()->setPosition(getRect()->getX() + v.getX(), getRect()->getY() + v.getY());

			Core::getInstance()->gatCurrentScene()->attach(e);
		}
	}

	if (Pad::getInstance()->getTrigger() & Pad::ButtonB) {
		animations.setCurrentAnimationNumber(1);
		animations.getCurrentAnimation().reset();
	}

	return Actor::onFrame();
}

void Hero::onAnimationEnd(int animationNumber)
{
	if (animationNumber == 1) {
		animations.setCurrentAnimationNumber(0);
	}
}
