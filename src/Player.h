#pragma once

#include <SDL2/SDL.h>

enum ScreenSide {
	SIDE_LEFT,
	SIDE_RIGHT,
};

class Player {
public:
	Player();
	~Player();

	void setSide(ScreenSide newSide) { side = newSide; }
	void render(SDL_Renderer* renderer);

private:
	const float speedMult = 1.0;
	ScreenSide side;
	SDL_Rect paddle;
};
