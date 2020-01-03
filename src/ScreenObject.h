#ifndef __SCREEN_OBJECT_H__
#define __SCREEN_OBJECT_H__

#include "GameObject.h"

class ScreenObject : public GameObject
{
public:
	ScreenObject();
	virtual bool intersect(ScreenObject* other);

	virtual Rect *getRect()
	{
		return NULL;
	}

	virtual Rect *getBoundingBox()
	{
		return NULL;
	}
};


#endif
