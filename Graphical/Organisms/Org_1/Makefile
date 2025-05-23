CC = gcc
CFLAGS = -Wall -Wextra -Werror -g `sdl2-config --cflags`
LDFLAGS = `sdl2-config --libs`

SRC = src/main.c
NAME = game

.PHONY: all run clean

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) $(LDFLAGS)

run: all
	./$(NAME)

clean:
	rm -f $(NAME)
