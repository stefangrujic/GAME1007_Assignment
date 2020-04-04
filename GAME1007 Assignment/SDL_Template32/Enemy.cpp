#include<Enemy.h>
#include<iostream>

 Enemy::Enemy()
{
}


 Enemy() {
	 src = { 0, 0, 182, 248 };
	 dst = { WIDTH, HEIGHT, src.w / 3, src.h / 3 };
		 }