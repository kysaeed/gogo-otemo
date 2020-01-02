#include "Animation.h"

#include <iostream>


Animation::Animation()
{
	index = 0;
	counter = 0;
}

void Animation::reset()
{
	index = 0;
	counter = 0;
}

void Animation::read(SDL_RWops* file)
{
	const int maxNameLength = 1024;

	int32_t nameByteCount = 0;
	SDL_RWread(file, &nameByteCount, sizeof(nameByteCount), 1);

	std::cout << "name len=" << nameByteCount << std::endl;
	char nameBuffer[maxNameLength];
	if (nameByteCount > (maxNameLength - 1)) {
		nameByteCount = (maxNameLength - 1);
	}

	SDL_RWread(file, nameBuffer, sizeof(char), nameByteCount);
	nameBuffer[nameByteCount + 1] = '\0';

	this->name = std::string(nameBuffer);

	std::cout << "----- " << name << " -----" << std::endl;

	int32_t count = 0;
	SDL_RWread(file, &count, sizeof(count), 1);
	std::cout << "    frame-count: " << count << std::endl;

	frames.clear();
	frames.reserve(count);
	for (int i = 0; i < count; i++) {
		AnimationFrame frame = readFrame(file);
		frames.push_back(frame);
	}
	index = 0;
}

bool Animation::load(const std::string &filename)
{
	SDL_RWops* file = SDL_RWFromFile(filename.c_str(), "r");
	if (file == nullptr) {
		return false;
	}

	read(file);

	SDL_RWclose(file);
	return true;
}

bool Animation::moveNextFrame()
{
	if (frames.size() <= 0) {
		return true;
	}

	counter++;
	if (counter >= frames[index].getFrameCount()) {
		counter = 0;
		index++;
		if (index >= frames.size()) {
			index = 0;
			// currentFrameIterator = frames.begin();
			return true;
		}
	}

	return false;
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
