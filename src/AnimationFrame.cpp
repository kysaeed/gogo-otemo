#include "AnimationFrame.h"

AnimationFrame::AnimationFrame()
{
	cell = -1;
	frameCount = 1;
	x = 0;
	y = 0;
}

AnimationFrame::AnimationFrame(int cell, int frameCount)
{
	this->cell = cell;
	this->frameCount = frameCount;
	x = 0;
	y = 0;
}
