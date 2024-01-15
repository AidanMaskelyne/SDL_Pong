#include <SDL2/SDL.h>
#include "Player.h"

class Pong {
public:
	Pong();
	~Pong();

	void run();
	void handleEvent();
	void update();
	void draw();
	void quit(int exitCode);

	bool windowShouldClose = false;

private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event event;

	Player player1, player2;
};
