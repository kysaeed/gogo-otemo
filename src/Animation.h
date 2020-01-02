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

	inline const AnimationFrame&getCurrentFrame() const
	{
		return frames[index];
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
	AnimationFrame readFrame(SDL_RWops* file);

	std::string name;
	std::vector <AnimationFrame> frames;
	int index;
	int counter;
};


#endif
