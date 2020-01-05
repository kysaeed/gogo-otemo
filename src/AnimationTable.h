#ifndef __ANIMATION_TABLE_H__
#define __ANIMATION_TABLE_H__

#include <vector>
#include <string>

#include "SDL2/SDL.h"
#include "SDL2/SDL_filesystem.h"

#include "Animation.h"

class AnimationTable
{
public:
	AnimationTable();
	void read(SDL_RWops* file);

	inline int getCurrentAnimationNumber() const
	{
		return currentAnimationIndex;
	}

	void setCurrentAnimationNumber(int number);

	Animation&getCurrentAnimation();

	std::vector <Animation> animations;
protected:
	int currentAnimationIndex;
};


#endif
