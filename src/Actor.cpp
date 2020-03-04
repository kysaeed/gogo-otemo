#include "Actor.h"

const int Actor::DefaultWidth = 128;
const int Actor::DefaultHeight = 128;

#include <iostream>

Actor::Actor()
{
	// x = 128;
	// y = 128;

	setClipSize(DefaultWidth, DefaultHeight);
}

Actor::~Actor()
{
	clean();
}

bool Actor::initialize(SDL_Renderer* pRenderer)
{
	return true;
}

bool Actor::onFrame()
{
	if (animations.getCurrentAnimation().isNull()) {
		onAnimationEnd(animations.getCurrentAnimationNumber());
		return true;
	}

	AnimationFrame frame = animations.getCurrentAnimation().getCurrentFrame();
	setClipIndex(frame.getCell());
	// std::cout << "cell:" << frame.getCell() << " frameCount:" << frame.getFrameCount() << std::endl;
	if (animations.getCurrentAnimation().moveNextFrame()) {
		onAnimationEnd(animations.getCurrentAnimationNumber());
	}

	return true;
}

void Actor::onAnimationEnd(int animationNumber)
{
	// std::cout << "onAnimationEnd : " << animationNumber << std::endl;
}

bool Actor::render(SDL_Renderer* pRenderer)
{
	if (!animations.getCurrentAnimation().isNull()) {
		AnimationFrame frame = animations.getCurrentAnimation().getCurrentFrame();
		return paint(pRenderer, rect.getX() + frame.getX(), rect.getY() + frame.getY());
	}

	return paint(pRenderer, rect.getX(), rect.getY());
}

void Actor::clean()
{
	for (std::vector <ActorImageCellData *>::iterator it = cells.begin(); it != cells.end(); it++) {
		if ((*it) != nullptr) {
			delete (*it);
			(*it) = nullptr;
		}
	}
	Sprite::clean();
}

bool Actor::load(const std::string &filename)
{
	SDL_RWops* file = SDL_RWFromFile(filename.c_str(), "r");
	if (file == nullptr) {
		return false;
	}

	int32_t r[4];
	SDL_RWread(file, r, sizeof(int32_t), 4);
	boundingBox = Rect(r[0], r[1], r[2], r[3]);

	std::cout << "bouding-box : (" << boundingBox.getX() << ", " << boundingBox.getY() << ") " <<
		boundingBox.getWidth() << "x" << boundingBox.getHeight() << std::endl;

	int32_t cellCount = 1;
	SDL_RWread(file, &cellCount, sizeof(int32_t), 1);

	std::cout << "cell-count : " << cellCount << std::endl;

	cells.resize(cellCount);
	for (int i =  0; i < cellCount; i++) {
		ActorImageCellData* cell = new ActorImageCellData();
		cell->read(file);
		cells[i] = cell;
	}

	animations.read(file);

	return true;
}

ActorImageCellMountPoint *Actor::getMoutPoint(int id)
{
	ActorImageCellData* cell = getCellData();
	std::cout << "cell : " << cell << std::endl;
	if (cell == nullptr) {
		return nullptr;
	}
	return cell->getMoutPoint(id);
}

Rect *Actor::getBoundingBox()
{
	ActorImageCellData* cell = getCellData();
	if (cell == nullptr) {
		return Sprite::getBoundingBox();
	}
	if (cell->getBoundingBox()->isEmpty()) {
		return Sprite::getBoundingBox();
	}
	return cell->getBoundingBox();
}
