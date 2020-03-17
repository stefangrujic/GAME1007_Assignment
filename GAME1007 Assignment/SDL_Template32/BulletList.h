#include "Bullet.h"
#include "Asteroid.h"
#include <vector>


class BulletList {
	std::vector<Bullet> bulletArray;

public:

	BulletList();
	~BulletList();

	void AddBullet(SDL_Renderer* renderer, int x, int y);
	void UpdateBullets(SDL_Renderer* renderer, Asteroid obstacle);
};