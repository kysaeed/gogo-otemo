#include "AnimationTable.h"

#include <iostream>

AnimationTable::AnimationTable()
{
	currentAnimationIndex = 0;
}

Animation &AnimationTable::getCurrentAnimation()
{
	// std::cout << "anm-index = " << currentAnimationIndex << std::endl;
	return animations[currentAnimationIndex];
}

bool AnimationTable::load(const std::string &filename)
{
	SDL_RWops* file = SDL_RWFromFile(filename.c_str(), "r");

	if (file == nullptr) {
		return false;
	}

	animations.clear();

	int32_t count = 0;
	SDL_RWread(file, &count, 4, 1);

	std::cout << "---------------" << std::endl;
	std::cout << "ani-set count = " << count << std::endl;

	for (int i = 0; i < count; i++) {
		Animation animation;
		animation.read(file);
		animations.push_back(animation);
		std::cout << "      -> read-frame=" << animation.frames.size() << std::endl;
	}
	SDL_RWclose(file);

	std::cout << "---------------" << std::endl;
	for (int i = 0; i < count; i++) {
		setCurrentAnimationNumber(i);
		std::cout << i << " : f-count = " << getCurrentAnimation().frames.size() << std::endl;
		getCurrentAnimation().reset();
	}
	setCurrentAnimationNumber(0);

	return true;
}

void AnimationTable::setCurrentAnimationNumber(int number)
{
	// if (number >= animations.size()) {
	// 	number = (animations.size() - 1);
	// }
	if (number < 0) {
		number = 0;
	}

	currentAnimationIndex = number;
}
