#include "Rect.h"

Rect::Rect()
{
	x = 0;
	y = 0;

	width = 0;
	height = 0;
}

Rect::Rect(float x, float y, int w, int h)
{
	this->x = x;
	this->y = y;
	this->width = w;
	this->height = h;
}

Rect Rect::getAppleidBodingBoxRect(const Rect* boundingBox)
{
	if (boundingBox == NULL) {
		return *this;
	}

	return Rect(
		x + boundingBox->getX(),
		y + boundingBox->getY(),
		boundingBox->getWidth(),
		boundingBox->getHeight());
}

bool Rect::intersect(Rect* other) const
{
	if (x > other->getRight()) {
		return false;
	}

	if (getRight() < other->getX()) {
		return false;
	}

	if (y > other->getBottom()) {
		return false;
	}

	if (getBottom() < other->getY()) {
		return false;
	}

	return true;
}
