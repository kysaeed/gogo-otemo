#ifndef __SCENE_H__
#define __SCENE_H__

#include <SDL2/SDL.h>
#include <list>
#include "GameObject.h"
#include "Sprite.h"
#include "EventReceiver.h"


class GameObject;

class Scene : public GameObject
{
public:
	Scene()
	{
		parent = NULL;
	}

	virtual void clean();

	virtual bool initialize(SDL_Renderer* pRenderer);
	virtual bool render(SDL_Renderer* pRenderer);
	virtual bool onFrame();

	void attach(GameObject* object);
	void detach(GameObject* object);

protected:
private:
	GameObject* parent;
	std::list <GameObject *> children;
	std::list <EventReceiver> eventReceivers[3];
};


#endif
