#ifndef __CAT_H__
#define __CAT_H__

#include "Actor.h"

class Cat : public Actor
{
public:
	Cat();
	virtual bool initialize(SDL_Renderer* pRenderer);
	virtual bool onFrame();

	void kill();

	bool isDead() const
	{
		return isDeadState;
	}

	void setDead(bool isDead)
	{
		isDeadState = isDead;
	}

protected:
	int direction;
	int frameCount;

	bool isDeadState;
};


#endif
