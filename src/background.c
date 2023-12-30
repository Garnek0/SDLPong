/*  
*   File: background.c
*
*   Author: Popa Vlad (Garnek)
*   
*   Description: Pong Background (centerline and other)
*/
// SPDX-License-Identifier: MIT

#include <background.h>

#define BACKGROUND_CENTERLINE_SPACING 40
#define BACKGROUND_CENTERLINE_WIDTH 6
#define BACKGROUND_CENTERLINE_LINE_LENGTH 20

void background_draw(SDL_Renderer* renderer){
	SDL_Rect rect;
	rect.x = 0;
	rect.y = 0;
	rect.h = BACKGROUND_EDGE_HEIGHT;
	rect.w = 800;

	SDL_RenderFillRect(renderer, &rect);

	rect.y = 600 - rect.h;

	SDL_RenderFillRect(renderer, &rect);

	// Draw the centerline, but use the same rect struct

	rect.x = 800/2  - (BACKGROUND_CENTERLINE_WIDTH/2);
	rect.w = BACKGROUND_CENTERLINE_WIDTH;
	rect.h = BACKGROUND_CENTERLINE_LINE_LENGTH;

	for(int i = 0; i < 600; i+=BACKGROUND_CENTERLINE_SPACING){
		rect.y = i;

		SDL_RenderFillRect(renderer, &rect);
	}
}
