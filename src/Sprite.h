#ifndef __SPRITE_H__
#define __SPRITE_H__

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "ScreenObject.h"
#include "Rect.h"

class Sprite : public ScreenObject
{
public:
	Sprite();
	virtual ~Sprite();

	virtual bool initialize(SDL_Renderer* pRenderer)
	{
		return true;
	}

	bool loadImageFromFile(SDL_Renderer* pRenderer, const std::string &filename);
	virtual bool render(SDL_Renderer* pRenderer);

	inline int getImageWidth()
	{
		return imageWidth;
	}

	inline int getImageHeight()
	{
		return imageHeight;
	}

	void setClipSize(int w, int h);

	inline int getClipIndex()
	{
		return clipIndex;
	}

	inline void setClipIndex(int index)
	{
		clipIndex = index;
		clipIndex %= (clipCountW * clipCountH);
	}

	inline int getClipCountW()
	{
		return clipCountW;
	}

	inline int getClipCountH()
	{
		return clipCountH;
	}

	virtual void clean();

	virtual Rect *getRect()
	{
		return &rect;
	}

	virtual Rect *getBoundingBox()
	{
		return &boundingBox;
	}

protected:
	bool paint(SDL_Renderer* pRenderer, int x, int y);

	Rect rect;
	Rect boundingBox;

	// int x;
	// int y;
	//
	int imageWidth;
	int imageHeight;

	int clipIndex;
	// int width;
	// int height;

	int clipCountW;
	int clipCountH;

	SDL_Texture* image;
};


#endif
