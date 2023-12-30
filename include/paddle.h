/*  
*   File: paddle.h
*
*   Author: Popa Vlad (Garnek)
*/
// SPDX-License-Identifier: MIT

#ifndef PADDLE_H
#define PADDLE_H

#define PADDLE_EDGE_OFFSET 10

#include <types.h>

typedef struct {
	SDL_Rect rect;
} paddle_t;

extern paddle_t paddle1;
extern paddle_t paddle2;

void paddle_init();
void paddle_draw(SDL_Renderer* renderer);

void paddle_up(paddle_t* paddle);
void paddle_down(paddle_t* paddle);

void paddle_state();

#endif //PADDLE_H
