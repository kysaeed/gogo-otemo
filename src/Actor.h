#ifndef __ACOTR_H__
#define __ACOTR_H__

#include "GameObject.h"
#include "Sprite.h"
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_filesystem.h>

#include "Animation.h"


class Actor : public Sprite
{
public:
	Actor();
	virtual ~Actor();

	virtual bool initialize(SDL_Renderer* pRenderer);
	virtual bool onFrame();
	virtual bool render(SDL_Renderer* pRenderer);

	virtual bool loadAnimationFile(const std::string &filename)
	{
		return false;
	}

	static const int DefaultWidth;
	static const int DefaultHeight;

	enum State {
		none,
		move,
	};

	State state;

	// todo:
protected:
	Animation animation;
};


#endif
