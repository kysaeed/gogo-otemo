#ifndef __OBJECT_POOL_H__
#define __OBJECT_POOL_H__

#include <list>
#include "GameObject.h"

class ObjectPool
{
public:
	ObjectPool();
	~ObjectPool();

	void push(GameObject* object);
	GameObject *pop();

	template <typename T> void pop2(T a)
	{
	}

	void remove(GameObject* object);

	void clean();

protected:
	std::list <GameObject *> objectList;
};


#endif
