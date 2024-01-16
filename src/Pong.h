#include <SDL2/SDL.h>
#include "Player.h"

class Pong {
public:
	Pong();
	~Pong();

	void run();
	void processEvents();
	void handleKeyboardEvent(SDL_KeyboardEvent e);
	void update();
	void draw();
	void sendQuitEvent();

	bool windowShouldClose = false;

private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event event;
	Player player1, player2;

	Uint32 lastUpdate;
};
