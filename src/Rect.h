#ifndef __RECT_H__
#define __RECT_H__

#include <iostream>

class Rect
{
public:
	Rect();

	Rect(float x, float y, int w=0, int h=0);

	inline void setPosition(float x, float y)
	{
		this->x = x;
		this->y = y;
	}

	inline void setSize(float w, float h)
	{
		this->width = w;
		this->height = h;
	}

	inline void setX(float x)
	{
		this->x = x;
	}

	inline void setY(float y)
	{
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

	inline float getTop() const
	{
		return y;
	}

	inline float getLeft() const
	{
		return x;
	}

	inline float getRight() const
	{
		return x + width;
	}

	inline float getBottom() const
	{
		return y + height;
	}

	inline void move(float x, float y)
	{
		this->x += x;
		this->y += y;
	}

	inline void moveX(float x)
	{
		this->x += x;
	}

	inline void moveY(float y)
	{
		this->y += y;
	}

	inline int getWidth() const
	{
		return width;
	}

	inline int getHeight() const
	{
		return height;
	}

	inline void setWidth(int w)
	{
		width = w;
	}

	inline void setHeight(int h)
	{
		height = h;
	}

	virtual bool intersect(Rect* otehr) const;

	Rect getAppleidBodingBoxRect(const Rect* boundingBox);

protected:
	float x;
	float y;

	int width;
	int height;
};


#endif
