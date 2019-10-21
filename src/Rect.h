#ifndef __RECT_H__
#define __RECT_H__

class Rect
{
public:
	Rect();

	inline void setPosition(float x, float y)
	{
		this->x = x;
		this->y = y;
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

	inline void setSize(int w, int h)
	{
		this->width = w;
		this->height = h;
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

protected:
	float x;
	float y;

	int width;
	int height;
};


#endif
