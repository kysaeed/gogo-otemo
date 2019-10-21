#ifndef __LAYER_H__
#define __LAYER_H__

#include "GameObject.h"
#include <list>

class Layer : public GameObject
{
public:
	Layer();
	virtual ~Layer();

	virtual bool initialize(SDL_Renderer* pRenderer);
	virtual bool render(SDL_Renderer* pRenderer);

	virtual bool onFrame();

	inline void setPosition(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	inline int getX()
	{
		return x;
	}

	inline int getY()
	{
		return y;
	}

	inline void setX(int x)
	{
		this->x = x;
	}

	inline void setY(int y)
	{
		this->y = y;
	}

	virtual void clean();

private:
	int x;
	int y;

	std::list <GameObject *> children;
};


#endif
