#include "Rect.h"

Rect::Rect()
{
	x = 0;
	y = 0;

	width = 0;
	height = 0;
}

bool Rect::intersect(Rect* other) const
{
	if (x > (other->getX() + other->getWidth())) {
		return false;
	}

	if ((x + width) < other->getX()) {
		return false;
	}

	if (y > (other->getY() + other->getHeight())) {
		return false;
	}

	if ((y + height) < other->getY()) {
		return false;
	}

	return true;
}
