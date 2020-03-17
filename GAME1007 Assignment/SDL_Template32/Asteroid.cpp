#include "Asteroid.h"

SDL_Rect Asteroid::getRect()
{
	return dst;
}

Asteroid::Asteroid()
{
}

Asteroid::~Asteroid()
{
}

void Asteroid::draw(SDL_Renderer* renderer)
{
	SDL_RenderCopy(renderer, pAsteroidTex, &src, &dst);
}

void Asteroid::cleanup()
{
}

Asteroid::Asteroid(SDL_Renderer* renderer)
{
	pAsteroidTex = IMG_LoadTexture(renderer, "asteroid.png");

	SDL_QueryTexture(pAsteroidTex, NULL, NULL, &src.w, &src.h);

	src.x = 0;
	src.y = 0;

	dst.x = 290;
	dst.y = 100;
	dst.w = 100;
	dst.h = 100;
}

