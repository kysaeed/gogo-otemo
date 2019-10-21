#include "Scene.h"

// #include <iostream>
#include "GameObject.h"
#include "ObjectPool.h"


bool Scene::initialize(SDL_Renderer* pRenderer)
{
	return true;
}

void Scene::clean()
{
	do {
		GameObject* object = children.front();
		children.pop_front();
		object->clean();
		delete object;
	} while (children.size() > 0);
}

// void Scene::addEventListener(int event, GameObject* object, void (GameObject::*eventHandler)(int, GameObject*))
// {
//     eventReceivers[event].push_back(EventReceiver(object, eventHandler));
// }

void Scene::attach(GameObject* object)
{
	children.push_back(object);
	for (std::list <EventReceiver>::iterator it = object->getEventReceivers(0).begin(); it != object->getEventReceivers(
			 0).end(); it++) {
		it->callEventHandler(object);
	}
}

void Scene::detach(GameObject* object)
{
	children.remove(object);
	for (std::list <EventReceiver>::iterator it = object->getEventReceivers(1).begin(); it != object->getEventReceivers(
			 1).end(); it++) {
		it->callEventHandler(object);
	}
}

bool Scene::onFrame()
{
	for (std::list <GameObject *>::iterator it = children.begin(); it != children.end(); it++) {
		if (!(*it)->onFrame()) {
			if ((*it)->getObjectPool() != NULL) {
				(*it)->getObjectPool()->push(*it);
			}
			it = children.erase(it);
		}
	}
	return true;
}

bool Scene::render(SDL_Renderer* pRenderer)
{
	for (std::list <GameObject *>::iterator it = children.begin(); it != children.end(); it++) {
		(*it)->render(pRenderer);
	}

	return true;
}
