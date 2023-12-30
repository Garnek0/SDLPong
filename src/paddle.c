/*  
*   File: paddle.c
*
*   Author: Popa Vlad (Garnek)
*   
*   Description: Code for the paddles.
*/
// SPDX-License-Identifier: MIT

#include <paddle.h>

#define PADDLE_HEIGHT 70
#define PADDLE_WIDTH 10

#define PADDLE_POS_INCREMENT 5

paddle_t paddle1; // Left paddle
paddle_t paddle2; // Right paddle

void paddle_init() {
	paddle1.rect.y = 600/2 - (PADDLE_HEIGHT/2);
	paddle1.rect.x = PADDLE_EDGE_OFFSET;
	paddle1.rect.h = PADDLE_HEIGHT;
	paddle1.rect.w = PADDLE_WIDTH;

	paddle2.rect.y = 600/2 - (PADDLE_HEIGHT/2);
	paddle2.rect.x = 800 - PADDLE_EDGE_OFFSET;
	paddle2.rect.h = PADDLE_HEIGHT;
	paddle2.rect.w = PADDLE_WIDTH;

	paddle2.rect.x -= paddle2.rect.w;
}

void paddle_up(paddle_t* paddle){
	if(paddle->rect.y <= PADDLE_EDGE_OFFSET) return;

	paddle->rect.y -= PADDLE_POS_INCREMENT;
}

void paddle_down(paddle_t* paddle){
	if(paddle->rect.y >= (600 - (PADDLE_EDGE_OFFSET+paddle->rect.h))) return;

	paddle->rect.y += PADDLE_POS_INCREMENT;
}

inline void paddle_draw(SDL_Renderer* renderer){
	SDL_RenderFillRect(renderer, &paddle1.rect);
	SDL_RenderFillRect(renderer, &paddle2.rect);
}

void paddle_state(){
	const uint8_t* keystates = SDL_GetKeyboardState(NULL);
	if(keystates[SDL_SCANCODE_W]) paddle_up(&paddle1);
	else if(keystates[SDL_SCANCODE_S]) paddle_down(&paddle1);

	if(keystates[SDL_SCANCODE_UP]) paddle_up(&paddle2);
	else if(keystates[SDL_SCANCODE_DOWN]) paddle_down(&paddle2);
}
