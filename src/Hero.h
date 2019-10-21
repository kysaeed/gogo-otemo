#ifndef __HERO_H__
#define __HERO_H__

#include "Actor.h"
#include "Scene.h"
#include "ObjectPool.h"

class SceneMain;

class Hero : public Actor
{
public:
	Hero();
	virtual bool initialize(SDL_Renderer* pRenderer);

	virtual bool onFrame();

	void xxx(SDL_Renderer* pRenderer, SceneMain* sceneMain);

	// inline void setMainScene(SceneMain* sm) {
	//   this->sm = sm;
	// }
protected:
	ObjectPool beamPool;
	// SceneMain* sm;
};


#endif
