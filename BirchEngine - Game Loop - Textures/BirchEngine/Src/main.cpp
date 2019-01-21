#include "Game.h"

Game *game = nullptr;

int main(int argc, char *argv[])
{
	// Frames per second.
	const int FPS = 60;
	// Time in ms divided by frames per second. This will give us the amount of delay between frames.
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;

	game = new Game();
	game->init("GameWindow", 800, 600, false);

	while (game->running())
	{
		// Set this to how many ms its been since we first initialized SDL.
		frameStart = SDL_GetTicks();

		game->handleEvents();
		game->update();
		game->render();

		// Gives us in ms how long it's taken to go through handling our events, updating objects, rendering it.
		frameTime = SDL_GetTicks() - frameStart;

		// Check to see if we need to delay running the next frame.
		if (frameDelay > frameTime)
		{
			// Delays by the difference between frameDelay and frameTime.
			SDL_Delay(frameDelay - frameTime);
		}
	}

	game->clean();
	return 0;
}