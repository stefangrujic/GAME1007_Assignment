#pragma once
#include <SDL_image.h>
#include <math.h>

class Enemy
{
public:
	bool is_active = true;
	bool is_hit = false;
	SDL_Rect src, dst;
	static const int speed = 3;
	bool spawns_blt = false;
	int blt_frame_count = 0;
	static const int kEnmBltSpawnFrame = 60;

	void SetDstY(int in_y) {
		dst.y = in_y;
	}
	void Update()
	{
		dst.x -= speed;
		blt_frame_count++;
		spawns_blt = false;
		if (blt_frame_count == kEnmBltSpawnFrame) {
			blt_frame_count = 0;
			spawns_blt = true;
		}

		if (dst.x + dst.w < 0) {
			is_active = false;
		}
	}