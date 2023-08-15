#include <stdio.h>
#include <SDL.h>

#define SIZE 200

int main(int argc, char *argv[])
{

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s", SDL_GetError());
    }
    else {

        SDL_CreateWindow(
            "SDL2 Demo",
            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            SIZE, SIZE,
            SDL_WINDOW_SHOWN
        );

        SDL_Delay(2000);
    }

	return 0;
}
