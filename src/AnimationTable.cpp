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

void AnimationTable::read(SDL_RWops* file)
{
	animations.clear();

	int32_t count = 0;
	SDL_RWread(file, &count, 4, 1);

	std::cout << "---------------" << std::endl;
	std::cout << "ani-set count = " << count << std::endl;

	for (int i = 0; i < count; i++) {
		Animation animation;
		animation.read(file);
		animations.push_back(animation);
	}
	SDL_RWclose(file);

	std::cout << "---------------" << std::endl;
	for (int i = 0; i < count; i++) {
		setCurrentAnimationNumber(i);
		getCurrentAnimation().reset();
	}
	setCurrentAnimationNumber(0);
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
