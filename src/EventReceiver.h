#ifndef __EVENT_RECEIVER_H__
#define __EVENT_RECEIVER_H__

class GameObject;
typedef void (GameObject::* EventHnadlerCallback)(int ev, GameObject* object);

class EventReceiver
{
public:
	EventReceiver(GameObject* object, void(GameObject::* eventHandler)(int, GameObject *));
	void callEventHandler(GameObject* object);

protected:
	GameObject* object;
	EventHnadlerCallback handler;
};


#endif
