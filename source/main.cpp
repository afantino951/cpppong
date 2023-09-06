#include<SDL.h>
#include<stdio.h>
#include<iostream>
#include<string>
#include<sstream>

#include "ball.h"
#include "utils.h"


int sdl_init_gui(SDL_Window* &window, SDL_Surface* &screenSurface, SDL_Renderer* &renderer) {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    return -1;
  } 
 
  //Set texture filtering to linear
  if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
  {
    printf( "Warning: Linear texture filtering not enabled!" );
    return -1;
  }

  // Create window
  window = SDL_CreateWindow("Pong CPP", SDL_WINDOWPOS_UNDEFINED,
                            SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                            SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
  if (window == NULL) {
    printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
    return -1;
  } 

  //Create renderer for window
  renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
  if( renderer == NULL )
  {
    printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
    return -1;
  }

  //Initialize renderer color
  SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );

  return 0;
}

void sdl_cleanup_gui(SDL_Window* &window, SDL_Renderer* &renderer) {
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);

  window = NULL;
  renderer = NULL;

  // Quit SDL subsystems
  SDL_Quit();
}

int sdl_main(int argc, char *args[]) {
  SDL_Window *window = NULL;
  SDL_Surface *screenSurface = NULL;
  SDL_Renderer* renderer = NULL;

  if (sdl_init_gui(window, screenSurface, renderer) < 0) {
    return -1;
  }

  Ball myBall = Ball(320, 240);

  // Hack to get window to stay up
  SDL_Event e;
  bool quit = false;
  while (!quit) {
    while (SDL_PollEvent(&e)) {

      // User request to quit
      if (e.type == SDL_QUIT) {
        quit = true;
      }
    
      myBall.handleEvent(e);
    }
    myBall.move();

    //Clear screen
    SDL_SetRenderDrawColor( renderer, 0x00, 0x00, 0x00, 0x00 );
    SDL_RenderClear( renderer );

    //Draw blue horizontal line
    SDL_SetRenderDrawColor( renderer, 0x00, 0x00, 0xFF, 0xFF );		
    SDL_RenderDrawLine( renderer, 0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2 );

    //Draw vertical line of yellow dots
    SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0x00, 0xFF );
    for( int i = 0; i < SCREEN_HEIGHT; i += 4 )
    {
      SDL_RenderDrawPoint( renderer, SCREEN_WIDTH / 2, i );
    }

    myBall.render( renderer );

    //Update screen
    SDL_RenderPresent( renderer );
  }

  sdl_cleanup_gui(window, renderer);

  return 0;
}


int main(int argc, char *args[]) {
    return sdl_main(argc, args);
}