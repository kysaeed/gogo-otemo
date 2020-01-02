#include "SceneMain.h"

#include "Bg.h"
#include <iostream>

SceneMain::SceneMain()
{
	hero = NULL;
}

bool SceneMain::initialize(SDL_Renderer* pRenderer)
{
	Scene::initialize(pRenderer);

	for (int i = 0; i < 2; i++) {
		pFarBg[i] = new Sprite();
		pFarBg[i]->initialize(pRenderer);
		pFarBg[i]->loadImageFromFile(pRenderer, "./data/far_bg.png");
		attach(pFarBg[i]);
	}
	pFarBg[0]->getRect()->setPosition(0, 4);
	pFarBg[1]->getRect()->setPosition(1024, 4);


	Sprite* sun = new Sprite();
	sun->loadImageFromFile(pRenderer, "./data/sun.png");
	sun->getRect()->setPosition(80, 24);
	attach(sun);



	Bg* pBg = new Bg();
	pBg->initialize(pRenderer);
	attach(pBg);

	Bg* pBg2 = new Bg();
	pBg2->initialize(pRenderer);
	pBg2->getRect()->setPosition(1024, 0);
	attach(pBg2);


	hero = new Hero();
	hero->initialize(pRenderer);
	hero->createEyeBeams(pRenderer, this);
	attach(hero);



	{
		Cat* cat = new Cat();
		cat->initialize(pRenderer);
		cat->getRect()->setPosition(820, 320);
		cat->setDead(false);
		cats.push_back(cat);


		attach(cat);
	}

	{
		Cat* cat = new Cat();
		cat->initialize(pRenderer);
		cat->getRect()->setPosition(730, 480);
		cat->setDead(false);
		cats.push_back(cat);

		attach(cat);
	}


	return true;
}

bool SceneMain::onFrame()
{
	if (!Scene::onFrame()) {
		return false;
	}

	for (std::list <EyeBeam *>::iterator b = eyeBeams.begin(); b != eyeBeams.end(); b++) {
		for (std::list <Cat *>::iterator c = cats.begin(); c != cats.end(); c++) {
			if ((*b)->getRect()->intersect((*c)->getRect())) {
				// std::cout << "HIT!" << std::endl;
				this->detach(*c);
				c = cats.erase(c);
			} else {
				// std::cout << std::endl;
			}
		}
	}

	for (int i = 0; i < 2; i++) {
		int x = pFarBg[i]->getRect()->getX();
		x--;
		if (x <= -1024) {
			x = 1024;
		}
		pFarBg[i]->getRect()->setPosition(x, 4);
	}

	return true;
}

void SceneMain::onBeamAdded(int event, GameObject* object)
{
	EyeBeam* e = dynamic_cast <EyeBeam *>(object);
	if (e == NULL) {
		return;
	}

	eyeBeams.push_back(e);
}

void SceneMain::onBeamRemvoed(int event, GameObject* object)
{
	EyeBeam* e = dynamic_cast <EyeBeam *>(object);
	if (e == NULL) {
		return;
	}

	eyeBeams.remove(e);
}
