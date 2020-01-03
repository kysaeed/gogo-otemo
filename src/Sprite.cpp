#include "Sprite.h"

Sprite::Sprite()
{
	// x = 0;
	// y = 0;

	rect.setPosition(0, 0);

	imageWidth = 0;
	imageHeight = 0;

	clipIndex = 0;

	// width = 0;
	// height = 0;
	rect.setSize(0, 0);

	image = NULL;
}

Sprite::~Sprite()
{
	clean();
}

bool Sprite::loadImageFromFile(SDL_Renderer* pRenderer, const std::string &filename)
{
	clean();

	SDL_Surface* loadedSurface = IMG_Load(filename.c_str());
	if (loadedSurface == NULL) {
		return false;
	}

	SDL_Texture* newImage = SDL_CreateTextureFromSurface(pRenderer, loadedSurface);
	if (newImage == NULL) {
		return false;
	}

	image = newImage;
	imageWidth = loadedSurface->w;
	imageHeight = loadedSurface->h;

	setClipSize(imageWidth, imageHeight);

	clipIndex = 0;
	rect.setSize(imageWidth, imageHeight);
	boudingBox.setSize(imageWidth, imageHeight);

	SDL_FreeSurface(loadedSurface);

	return true;
}

bool Sprite::render(SDL_Renderer* pRenderer)
{
	return paint(pRenderer, rect.getX(), rect.getY());
}

bool Sprite::paint(SDL_Renderer* pRenderer, int x, int y)
{
	if (image == NULL) {
		return true;
	}
	if ((imageWidth == 0) || (imageHeight == 0)) {
		return true;
	}

	// Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, rect.getWidth(), rect.getHeight() };

	// SDL_Rect* clip = NULL;
	SDL_Rect clip = { 0 };
	clip.x = rect.getWidth() * (clipIndex % clipCountW);
	clip.y = rect.getHeight() * static_cast <int>(clipIndex / clipCountW);
	clip.w = rect.getWidth();
	clip.h = rect.getHeight();
	SDL_RenderCopy(pRenderer, image, &clip, &renderQuad);

	return true;
}

void Sprite::clean()
{
	if (image == NULL) {
		return;
	}

	SDL_DestroyTexture(image);
	image = NULL;
	imageWidth = 0;
	imageHeight = 0;

	clipIndex = 0;

	rect.setSize(imageWidth, imageHeight);
	// width = imageWidth;
	// height = imageHeight;
}

void Sprite::setClipSize(int w, int h)
{
	clipIndex = 0;

	if (w < 1) {
		rect.setWidth(imageWidth);
	} else {
		rect.setWidth(w);
	}

	if (h < 1) {
		rect.setHeight(imageHeight);
	} else {
		rect.setHeight(h);
	}

	if ((rect.getWidth() < 1) || (rect.getHeight() < 1)) {
		clipCountW = 1;
		clipCountH = 1;
	} else {
		clipCountW = (imageWidth / rect.getWidth());
		clipCountH = (imageHeight / rect.getHeight());
	}
	boudingBox.setSize(rect.getWidth(), rect.getHeight());
}
