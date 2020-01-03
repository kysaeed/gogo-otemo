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

	Rect rect = getRect()->getAppleidBodingBoxRect(getBoundingBox());
	Rect otherRect = other->getRect()->getAppleidBodingBoxRect(other->getBoundingBox());

	if (rect.intersect(&otherRect)) {
		return true;
	}
	return false;
}
