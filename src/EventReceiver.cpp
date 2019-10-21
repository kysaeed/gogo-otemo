#include "EventReceiver.h"

EventReceiver::EventReceiver(GameObject* object, void(GameObject::* eventHandler)(int, GameObject *))
{
	this->object = object;
	this->handler = eventHandler;
}

void EventReceiver::callEventHandler(GameObject* sender)
{
	(this->object->*(this->handler))(0, sender);
}
