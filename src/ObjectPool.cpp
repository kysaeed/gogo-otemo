#include "ObjectPool.h"

ObjectPool::ObjectPool()
{
}

ObjectPool::~ObjectPool()
{
	clean();
}

void ObjectPool::push(GameObject* object)
{
	if (object->getObjectPool() != this) {
		object->getObjectPool()->remove(object);
		object->setObjectPool(this);
	}

	objectList.push_back(object);
}

GameObject *ObjectPool::pop()
{
	if (objectList.size() < 1) {
		return NULL;
	}

	GameObject* object = objectList.front();
	objectList.pop_front();
	return object;
}

void ObjectPool::remove(GameObject* object)
{
	objectList.remove(object);
	object->setObjectPool(NULL);
}

void ObjectPool::clean()
{
	do {
		GameObject* object = objectList.front();
		objectList.pop_front();
		object->clean();
		delete object;
	} while (objectList.size() > 0);
}
