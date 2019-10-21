#ifndef __EYE_BEAM_H__
#define __EYE_BEAM_H__

#include "Sprite.h"

class EyeBeam : public Sprite
{
public:
	EyeBeam();
	virtual bool initialize(SDL_Renderer* pRenderer);

	virtual bool onFrame();
};


#endif
