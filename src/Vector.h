#ifndef __VECTOR_H__
#define __VECTOR_H__

class Vector
{
public:
	Vector()
	{
		x = 0;
		y = 0;
	}

	Vector(float x, float y)
	{
		this->x = x;
		this->y = y;
	}

	inline float getX() const
	{
		return x;
	}

	inline float getY() const
	{
		return y;
	}

	inline void setX(float x)
	{
		this->x = x;
	}

	inline void setY(float y)
	{
		this->y = y;
	}

	void normalize();
	void scale(float scale);

protected:
	float x;
	float y;
};


#endif
