#ifndef __CORE_H__
#define __CORE_H__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Scene.h"


class Core
{
public:
	virtual ~Core();
	bool initialize();

	int run();
	void clean();

	// inline SDL_Renderer* getRenderer() {
	//   return pRenderer;
	// }

	void setCurrentScene(Scene* scene);

	inline Scene *gatCurrentScene()
	{
		return currentScene;
	}

	static Core *getInstance();
	static void exit();

private:
	Core();

	static SDL_Renderer* pRenderer;
	static SDL_Window* pWindow;

	Scene* currentScene;

	static int initializeCount;
	static Core* game;
};


#endif
