#ifndef MAIN_H
# define MAIN_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <time.h>
# include <SDL2/SDL.h>

# define WIN_W 640
# define WIN_H 480
# define GRID_COLS 64
# define GRID_ROWS 48
# define CELL_WIDTH (WIN_W / GRID_COLS)
# define CELL_HEIGHT (WIN_H / GRID_ROWS)

typedef struct s_app
{
	SDL_Window		*win;
	SDL_Renderer	*renderer;
	SDL_Event		e;
	int				grid[GRID_ROWS][GRID_COLS];
}	t_app;

int		init_SDL(t_app *app);
void	init_grid(t_app *app);
void	draw_grid(t_app *app);

#endif