#include "Vector.h"

#include <cmath>

void Vector::normalize()
{
	float a = sqrt((x * x) + (y * y));
	if (!a) {
		return;
	}

	x /= a;
	y /= a;
}

void Vector::scale(float scale)
{
	x *= scale;
	y *= scale;
}
