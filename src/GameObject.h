#ifndef __GAME_OBJECT_H__
#define __GAME_OBJECT_H__

#include <string>
#include <list>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Rect.h"
#include "EventReceiver.h"

class ObjectPool;


class GameObject
{
public:
	GameObject();
	virtual ~GameObject();
	virtual void clean();

	virtual bool initialize(SDL_Renderer* pRenderer)
	{
		return true;
	}

	void addEventListener(int event, GameObject* object, void (GameObject::* eventHandler)(int, GameObject *));

	virtual bool render(SDL_Renderer* pRenderer) = 0;

	virtual bool onFrame()
	{
		return true;
	}

	GameObject *getParent()
	{
		return parent;
	}

	inline ObjectPool *getObjectPool()
	{
		return objectPool;
	}

	void setObjectPool(ObjectPool* pool)
	{
		objectPool = pool;
	}

	inline std::list <EventReceiver>&getEventReceivers(int event)
	{
		return eventReceivers[event];
	}

protected:
	GameObject* parent;
	ObjectPool* objectPool;
	std::list <EventReceiver> eventReceivers[3];
};


#endif
