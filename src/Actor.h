#ifndef __ACOTR_H__
#define __ACOTR_H__

#include <string>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_filesystem.h>

#include "GameObject.h"
#include "Sprite.h"
#include "ActorImageCellData.h"
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
	virtual void clean();
	bool load(const std::string &filename);

	virtual Rect *getBoundingBox();


	virtual bool loadAnimationFile(const std::string &filename)
	{
		return false;
	}

	static const int DefaultWidth;
	static const int DefaultHeight;
protected:
	std::vector <ActorImageCellData *> cells;
	AnimationTable animations;
};


#endif
