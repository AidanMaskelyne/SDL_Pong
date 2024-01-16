#include "Player.h"

Player::Player() {}

Player::~Player() {}

void Player::render(SDL_Renderer* renderer)
{
	if (side == SIDE_LEFT)
	{
		paddle.x = 50;
		paddle.y = 0;
		paddle.w = 10;
		paddle.h = 100;
		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	}
	else if (side == SIDE_RIGHT)
	{
		paddle.x = 640 - 50;
		paddle.y = 50;
		paddle.w = 10;
		paddle.h = 100;
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	}
	
	SDL_RenderFillRect(renderer, &paddle);
}
