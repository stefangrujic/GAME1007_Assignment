#include "Game.h"
#include <SDL.h>

//Create our Game object
Game* g_game = 0;

/*
	   Initialize
			|
	 |--Get Input
	 |		|
	 |	Physics
	 |		|
	 |--Rendering
			|
		  Exit
*/


int main(int argc, char* args[])
{
	g_game = new Game();

	g_game->init("Assignment_v0.1", 100,100,640,480,false);

	g_game->prepare();

	while (g_game->running())
	{
		g_game->handleEvents();
		g_game->update();
		g_game->render();
		g_game->waitForNextFrame();
	}

	g_game->cleanup();

	return 0;
}






