/*  
*   File: main.c
*
*   Author: Popa Vlad (Garnek)
*   
*   Description: SDL Initialisation and event loop.
*/
// SPDX-License-Identifier: MIT

#include <types.h>
#include <paddle.h>
#include <background.h>
#include <ball.h>

#define TICK_INTERVAL 10

static unsigned int nextTime;
unsigned int time_left(){
	unsigned int now;
	now = SDL_GetTicks();

	if(nextTime <= now) return 0;
	else return (nextTime - now);
}

int main(int argc, char** argv){
	SDL_Window* window;
	SDL_Renderer* renderer;

	if(SDL_Init(SDL_INIT_EVERYTHING) != 0){
		fprintf(stderr, "Failed to initialise SDL: %s\n", SDL_GetError());
		return -1;
	}

	window = SDL_CreateWindow("SDL Pong", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, 0);
	if(window == NULL){
		fprintf(stderr, "Failed to initialise SDL window: %s\n", SDL_GetError());
		return -1;
	}

	renderer = SDL_CreateRenderer(window, -1, 0);
	if(renderer == NULL){
		fprintf(stderr, "Failed to initialise SDL renderer: %s\n", SDL_GetError());
		return -1;
	}
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	paddle_init();
	ball_init();

	bool exit = false;
	SDL_Event event;

	while((!exit)){
		while(SDL_PollEvent(&event)){
			switch(event.type){
				case SDL_QUIT:
					exit = true;
					break;
				default:
					break;
			}
		}
		paddle_state();
		ball_update();
 
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

		background_draw(renderer);
		paddle_draw(renderer);
		ball_draw(renderer);

		SDL_RenderPresent(renderer);

		SDL_Delay(time_left());
		nextTime += TICK_INTERVAL;
	}

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);

	SDL_Quit();

	return 0;
}
