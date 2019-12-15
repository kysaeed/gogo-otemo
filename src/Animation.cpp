#include "Animation.h"

#include <iostream>


Animation::Animation()
{
	counter = 0;
	currentFrameIterator = frames.begin();
}

bool Animation::load(const std::string &filename)
{
	SDL_RWops* file = SDL_RWFromFile(filename.c_str(), "r");
	if (file == nullptr) {
		return false;
	}

	int32_t count = 0;
	SDL_RWread(file, &count, 4, 1);
	// std::cout << count << std::endl;

	for (int i = 0; i < count; i++) {
		AnimationFrame frame = readFrame(file);
		frames.push_back(frame);
	}

	currentFrameIterator = frames.begin();

	SDL_RWclose(file);
	return true;
}

void Animation::moveNextFrame()
{
	if (frames.size() <= 1) {
		return;
	}

	counter++;
	if (counter >= (*currentFrameIterator).getFrameCount()) {
		counter = 0;
		currentFrameIterator++;
		if (currentFrameIterator == frames.end()) {
			currentFrameIterator = frames.begin();
		}
	}
}

AnimationFrame Animation::readFrame(SDL_RWops* file)
{
	int32_t cell = -1;
	int32_t frameCount = 1;

	SDL_RWread(file, &cell, sizeof(cell), 1);
	SDL_RWread(file, &frameCount, sizeof(frameCount), 1);

	AnimationFrame frame(cell, frameCount);

	int32_t x = 0;
	int32_t y = 0;
	SDL_RWread(file, &x, sizeof(x), 1);
	SDL_RWread(file, &y, sizeof(y), 1);

	frame.setPosition(x, y);

	int32_t eventCount = 0;
	SDL_RWread(file, &eventCount, 4, 1);

	return frame;
}
