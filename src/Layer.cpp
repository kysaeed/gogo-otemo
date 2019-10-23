#include "Layer.h"

Layer::Layer()
{
	x = 0;
	y = 0;
}

Layer::~Layer()
{
	clean();
}

bool Layer::initialize(SDL_Renderer* pRenderer)
{
	return true;
}

bool Layer::render(SDL_Renderer* pRenderer)
{
	for (std::list <GameObject *>::iterator it = children.begin(); it != children.end(); it++) {
		(*it)->render(pRenderer);
	}
	return true;
}

bool Layer::onFrame()
{
	for (std::list <GameObject *>::iterator it = children.begin(); it != children.end(); it++) {
		(*it)->onFrame();
	}
	return true;
}

void Layer::clean()
{
	while (children.size() > 0) {
		GameObject* object = children.front();
		children.pop_front();
		delete object;
	}
}
