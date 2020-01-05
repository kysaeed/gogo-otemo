#ifndef __ACOTR_H__
#define __ACOTR_H__

#include <string>
// #include <list>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_filesystem.h>

#include "GameObject.h"
#include "Sprite.h"
#include "Animation.h"
#include "AnimationTable.h"


class Actor : public Sprite
{
public:
	Actor();
	virtual ~Actor();

	virtual bool initialize(SDL_Renderer* pRenderer);
	virtual bool onFrame();
	virtual void onAnimationEnd(int animationNumber);
	virtual bool render(SDL_Renderer* pRenderer);
	bool load(const std::string &filename);

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
	// Animation animation;
	AnimationTable animations;
};


#endif
