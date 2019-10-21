#include "ScreenObject.h"

ScreenObject::ScreenObject()
{
}

bool ScreenObject::intersect(ScreenObject* other)
{
	if (getRect() == NULL) {
		return false;
	}

	if (other->getRect() == NULL) {
		return false;
	}

	if (getRect()->intersect(other->getRect())) {
		return true;
	}
	return false;
}
