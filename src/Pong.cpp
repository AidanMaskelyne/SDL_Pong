#include <SDL2/SDL.h>

#include "Pong.h"

Pong::Pong()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		printf("SDL_Init() error: %s\n", SDL_GetError());
		return;
	}

	window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);
	if (window == NULL)
	{
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "SDL_CreateWindow() error: %s", SDL_GetError());
		return;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL)
	{
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "SDL_CreateRenderer() error: %s\n", SDL_GetError());
		return;
	}
}

Pong::~Pong()
{
	SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "Cleaning up...");

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Pong::run()
{
	while (!windowShouldClose)
	{
		while (SDL_PollEvent(&event) > 0)
		{
			handleEvent();
			update();
			draw();
		}
	}
}

void Pong::handleEvent()
{
	switch (event.type)
	{
		case SDL_QUIT:
			SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "SDL_QUIT event recieved");
			windowShouldClose = true;
			break;

	}
}

void Pong::update()
{
	/* Update */
}
void Pong::draw()
{
	/* Black background */
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
}
