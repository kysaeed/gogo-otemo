#ifndef __CAT_H__
#define __CAT_H__

#include "Actor.h"

class Cat : public Actor
{
public:
	Cat();
	virtual bool initialize(SDL_Renderer* pRenderer);
	virtual bool onFrame();

	bool isDead()
	{
		return isDeadState;
	}

	void setDead(bool isDead)
	{
		isDeadState = isDead;
	}

protected:
	int hp;
	int direction;
	int frameCount;

	bool isDeadState;
};


#endif
