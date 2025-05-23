#include "../include/main.h"

int	init_SDL(t_smain *sm)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		fprintf(stderr, "SDL_Init Error: %s\n", SDL_GetError());
		return (1);
	}
	sm->win = SDL_CreateWindow("SDL2 macOS Test",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		640, 480,
		SDL_WINDOW_SHOWN | SDL_WINDOW_ALLOW_HIGHDPI);
	if (!sm->win)
	{
		fprintf(stderr, "Window Error: %s\n", SDL_GetError());
		SDL_Quit();
		return (1);
	}
	sm->renderer = SDL_CreateRenderer(sm->win, -1, \
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!sm->renderer)
	{
		fprintf(stderr, "Renderer Error: %s\n", SDL_GetError());
		SDL_DestroyWindow(sm->win);
		SDL_Quit();
		return (1);
	}
	return (0);
}

int main(void)
{
	t_smain	sm;

	if (init_SDL(&sm))
		return (1);
	SDL_SetRenderDrawColor(sm.renderer, 0, 128, 255, 255);
	SDL_RenderClear(sm.renderer);
	SDL_RenderPresent(sm.renderer);
	int running = 1;
	while (running)
	{
		while (SDL_PollEvent(&sm.e))
		{
			if (sm.e.type == SDL_QUIT)
				running = 0;
		}
		SDL_Delay(16);
	}
	SDL_DestroyRenderer(sm.renderer);
	SDL_DestroyWindow(sm.win);
	SDL_Quit();
	return (0);
}
