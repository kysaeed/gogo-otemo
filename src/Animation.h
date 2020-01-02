#ifndef __ANIMATION_H__
#define __ANIMATION_H__

#include <string>
#include <vector>

#include "SDL2/SDL.h"
#include "SDL2/SDL_filesystem.h"

#include "AnimationFrame.h"

class Animation
{
public:
	Animation();
	bool load(const std::string &filename);
	void read(SDL_RWops* file);

	void reset();

	inline AnimationFrame getCurrentFrame() const
	{
		return *currentFrameIterator;
	}

	bool moveNextFrame();

	inline bool isNull() const
	{
		return frames.size() <= 0;
	}

	inline int getFrameDataCount() const
	{
		return frames.size();
	}

protected:
	std::string name;
	int counter;
	AnimationFrame readFrame(SDL_RWops* file);

	std::vector <AnimationFrame> frames;
	std::vector <AnimationFrame>::iterator currentFrameIterator;
};


#endif
