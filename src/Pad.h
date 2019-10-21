#ifndef __PAD_H__
#define __PAD_H__

#include <SDL2/SDL.h>

class Pad
{
public:
	static Pad *getInstance();

	void onFrame();

	static const unsigned int Up;
	static const unsigned int Down;
	static const unsigned int Left;
	static const unsigned int Right;

	static const unsigned int ButtonA;
	static const unsigned int ButtonB;


	inline unsigned int getNormal() const
	{
		return normal;
	}

	inline unsigned int getOld() const
	{
		return old;
	}

	inline unsigned int getTrigger() const
	{
		return trigger;
	}

	inline unsigned int getReleased() const
	{
		return released;
	}

protected:
	unsigned int normal;
	unsigned int old;
	unsigned int trigger;
	unsigned int changed;
	unsigned int released;

	bool isDiagonalDirectionBlocked;
private:
	Pad();
	static Pad* instance;
};


#endif
