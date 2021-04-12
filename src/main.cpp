#include "./../platforms/platforms.hpp"
#include <SDL.h>

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;

SDL_Rect fillRect = { SCREEN_WIDTH / 4,
                      SCREEN_HEIGHT / 4,
                      SCREEN_WIDTH / 2,
                      SCREEN_HEIGHT / 2 };

int
main(int argc, char* args[])
{
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
    return -1;

  if ((gWindow = SDL_CreateWindow("RedRectangle",
                                  SDL_WINDOWPOS_UNDEFINED,
                                  SDL_WINDOWPOS_UNDEFINED,
                                  SCREEN_WIDTH,
                                  SCREEN_HEIGHT,
                                  SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE)) ==
      NULL)
    return -1;

  if ((gRenderer = SDL_CreateRenderer(gWindow, -1, 0)) == NULL)
    return -1;

  SDL_SetRenderDrawColor(gRenderer, 255, 0, 0, 255);
  SDL_RenderFillRect(gRenderer, &fillRect);
  SDL_RenderPresent(gRenderer);
  SDL_Event e;
  bool quit = false;

  while (!quit) {
    while (SDL_PollEvent(&e)) {
      if (e.type == SDL_QUIT) {
        quit = true;
      }
      // if (e.type == SDL_KEYDOWN){
      //     quit = true;
      // }
      // if (e.type == SDL_MOUSEBUTTONDOWN){
      //     quit = true;
      // }
    }
  }

  SDL_DestroyRenderer(gRenderer);
  SDL_DestroyWindow(gWindow);
  gWindow = NULL;
  gRenderer = NULL;

  SDL_Quit();
  return 0;
}