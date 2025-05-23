#ifndef MAIN_H
# define MAIN_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <SDL2/SDL.h>

typedef struct main
{
	SDL_Window		*win;
	SDL_Renderer	*renderer;
	SDL_Event		e;
}	t_smain;


#endif