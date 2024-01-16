#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>

#include "Pong.h"
#include "Player.cpp"

const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;

Pong::Pong()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		printf("SDL_Init() error: %s\n", SDL_GetError());
		return;
	}

	window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
	if (window == NULL)
	{
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "SDL_CreateWindow() error: %s", SDL_GetError());
		return;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == NULL)
	{
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "SDL_CreateRenderer() error: %s\n", SDL_GetError());
		return;
	}

	player1.setSide(SIDE_LEFT);
	player2.setSide(SIDE_RIGHT);
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
	lastUpdate = SDL_GetTicks();
	while (!windowShouldClose)
	{
		while (SDL_PollEvent(&event) > 0)
		{
			processEvents();
			update();
			draw();
		}
	}
}

void Pong::processEvents()
{
	switch (event.type)
	{
		case SDL_QUIT:
			SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "SDL_QUIT event recieved");
			windowShouldClose = true;
			break;
		case SDL_KEYDOWN:
			handleKeyboardEvent(event.key);
	}
}

void Pong::handleKeyboardEvent(SDL_KeyboardEvent e)
{
	SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "SDL_KeyboardEvent received: %s", SDL_GetKeyName(e.keysym.sym));
	switch (e.keysym.sym)
	{
		case SDLK_ESCAPE:
			sendQuitEvent();
			break;
	}
}

void Pong::sendQuitEvent()
{
	SDL_Event quitEvent;
	quitEvent.type = SDL_QUIT;
	SDL_PushEvent(&quitEvent);
}

void Pong::update()
{
	Uint32 currentUpdate = SDL_GetTicks();
	float deltaTime = (currentUpdate - lastUpdate) / 1000.0f;


	lastUpdate = SDL_GetTicks();
}
void Pong::draw()
{
	/* Render a default black background */
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	player1.render(renderer);
	player2.render(renderer);

	/* Render the current contents of the renderer */
	SDL_RenderPresent(renderer);
}
