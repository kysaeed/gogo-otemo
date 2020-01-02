#include "Core.h"

#include "Pad.h"
#include "GameObject.h"
#include "SceneMain.h"
#include "EventReceiver.h"

int Core::initializeCount = 0;
SDL_Renderer * Core::pRenderer = NULL;
SDL_Window * Core::pWindow = NULL;
Core * Core::game = NULL;

Core::Core()
{
	currentScene = NULL;
}

Core::~Core()
{
	clean();
}

Core *Core::getInstance()
{
	if (game == NULL) {
		game = new Core();
	}
	return game;
}

bool Core::initialize()
{
	if (initializeCount > 0) {
		initializeCount++;
		return true;
	}

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		return false;
	}



	int windowMode = SDL_WINDOW_SHOWN;
	// int windowMode = SDL_WINDOW_FULLSCREEN;
	// int windowMode = SDL_WINDOW_FULLSCREEN_DESKTOP;
	pWindow = SDL_CreateWindow("Go Go", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1024, 768, windowMode);
	if (pWindow == NULL) {
		return false;
	}

	pRenderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (pRenderer == NULL) {
		return false;
	}

	SDL_SetRenderDrawColor(pRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
		return false;
	}

	initializeCount++;
	return true;
}

void Core::clean()
{
	if (currentScene != NULL) {
		currentScene->clean();
		delete currentScene;
		currentScene = NULL;
	}

	if (initializeCount <= 0) {
		return;
	}

	initializeCount--;
	if (initializeCount > 0) {
		return;
	}

	if (pRenderer != NULL) {
		SDL_DestroyRenderer(pRenderer);
		pRenderer = NULL;
	}

	if (pWindow != NULL) {
		SDL_DestroyWindow(pWindow);
		pWindow = NULL;
	}

	IMG_Quit();
	SDL_Quit();
}

void Core::setCurrentScene(Scene* scene)
{
	currentScene = scene;
}

int Core::run()
{
	SDL_Event event = { 0 };

	Pad* pad = Pad::getInstance();

	Scene* scene = new SceneMain();
	scene->initialize(pRenderer);
	setCurrentScene(scene);

	bool quit = false;
	while (1) {
		while (SDL_PollEvent(&event) != 0) {
			if (event.type == SDL_QUIT) {
				quit = true;
			}
		}
		if (quit) {
			break;
		}

		pad->onFrame();

		SDL_SetRenderDrawColor(pRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(pRenderer);

		if (currentScene != NULL) {
			currentScene->onFrame();
			currentScene->render(pRenderer);
		}

		SDL_RenderPresent(pRenderer);
	}

	return 0;
}

void Core::exit()
{
	if (game != NULL) {
		game->clean();
		delete game;
		game = NULL;
	}
}
