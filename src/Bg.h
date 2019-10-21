#ifndef __BG_H__
#define __BG_H__

#include "Sprite.h"

class Bg : public Sprite {
public:
  Bg();
  virtual bool initialize(SDL_Renderer* pRenderer);
  virtual bool onFrame();

};

#endif
