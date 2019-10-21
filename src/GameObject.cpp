// #include <iostream>
#include "GameObject.h"
#include "ObjectPool.h"
#include "Pad.h"


GameObject::GameObject()
{
	objectPool = NULL;
}

GameObject::~GameObject()
{
	clean();
}

void GameObject::addEventListener(int event, GameObject* object, void (GameObject::* eventHandler)(int, GameObject *))
{
	eventReceivers[event].push_back(EventReceiver(object, eventHandler));
}

void GameObject::clean()
{
}
