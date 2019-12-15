#ifndef __ANIMATION_H__
#define __ANIMATION_H__

#include <string>
#include <list>

#include "SDL2/SDL.h"
#include "SDL2/SDL_filesystem.h"

#include "AnimationFrame.h"

class Animation
{
public:
	Animation();
	bool load(const std::string &filename);

	inline AnimationFrame getCurrentFrame() const
	{
		return *currentFrameIterator;
	}

	void moveNextFrame();

	inline bool isNull() const
	{
		return frames.size() <= 0;
	}

protected:
	int counter;
	AnimationFrame readFrame(SDL_RWops* file);

	std::list <AnimationFrame> frames;
	std::list <AnimationFrame>::iterator currentFrameIterator;
};


#endif
