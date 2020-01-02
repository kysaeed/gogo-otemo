#ifndef __SCENE_MAIN_H__
#define __SCENE_MAIN_H__

#include "Scene.h"
#include <list>

#include "Hero.h"
#include "Cat.h"
#include "EyeBeam.h"

class SceneMain : public Scene
{
public:
	SceneMain();
	virtual bool initialize(SDL_Renderer* pRenderer);
	virtual bool onFrame();

	void onBeamAdded(int event, GameObject* object);
	void onBeamRemvoed(int event, GameObject* object);

protected:
	Hero* hero;
	std::list <Cat *> cats;
	std::list <EyeBeam *> eyeBeams;
	Sprite* pFarBg[2];
};


#endif
