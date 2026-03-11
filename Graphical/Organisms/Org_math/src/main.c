#include "../include/main.h"

int	init_SDL(t_app *app)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		fprintf(stderr, "SDL_Init Error: %s\n", SDL_GetError());
		return (1);
	}
	app->win = SDL_CreateWindow("Game of Life",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		WIN_W, WIN_H, SDL_WINDOW_SHOWN | SDL_WINDOW_ALLOW_HIGHDPI);
	if (!app->win)
	{
		fprintf(stderr, "Window Error: %s\n", SDL_GetError());
		SDL_Quit();
		return (1);
	}
	app->renderer = SDL_CreateRenderer(app->win, -1, \
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!app->renderer)
	{
		fprintf(stderr, "Renderer Error: %s\n", SDL_GetError());
		SDL_DestroyWindow(app->win);
		SDL_Quit();
		return (1);
	}
	return (0);
}

void	init_grid(t_app *app)
{
	int	y;
	int	x;

	srand(time(NULL));
	y = 0;
	while (y < GRID_ROWS)
	{
		x = 0;
		while (x < GRID_COLS)
		{
			app->grid[y][x] = rand() % 2;
			x++;
		}
		y++;
	}
}

void	draw_grid(t_app *app)
{
	int	y;
	int	x;
	SDL_Rect cell;

	y = 0;
	while (y < GRID_ROWS)
	{
		x = 0;
		while (x < GRID_COLS)
		{
			cell.x = x * CELL_WIDTH;
			cell.y = y * CELL_HEIGHT;
			cell.w = CELL_WIDTH;
			cell.h = CELL_HEIGHT;
			if (app->grid[y][x])
				SDL_SetRenderDrawColor(app->renderer, 255, 255, 255, 255);
			else
				SDL_SetRenderDrawColor(app->renderer, 0, 0, 0, 255);
			SDL_RenderFillRect(app->renderer, &cell);
			x++;
		}
		y++;
	}
}

int	main(void)
{
	t_app	app;
	int		running;

	if (init_SDL(&app))
		return (1);
	init_grid(&app);
	running = 1;
	while (running)
	{
		while (SDL_PollEvent(&app.e))
		{
			if (app.e.type == SDL_QUIT)
				running = 0;
		}
		SDL_SetRenderDrawColor(app.renderer, 0, 0, 0, 255);
		SDL_RenderClear(app.renderer);
		draw_grid(&app);
		SDL_RenderPresent(app.renderer);
		SDL_Delay(100);
	}
	SDL_DestroyRenderer(app.renderer);
	SDL_DestroyWindow(app.win);
	SDL_Quit();
	return (0);
}
