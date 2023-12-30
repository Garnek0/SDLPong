/*  
*   File: ball.h
*
*   Author: Popa Vlad (Garnek)
*   
*   Description: Pong Background (centerline and other)
*/
// SPDX-License-Identifier: MIT

#ifndef BALL_H
#define BALL_H

#include <types.h>

typedef struct {
	SDL_Rect rect;
	// This holds the number (1 or 2) of the next player on which's side
	// the ball will be tossed. Starting value is 1. (First toss is on p2's side)
	int nextPlayerToss;
	int speedX;
	int speedY;
} ball_t;

extern ball_t ball;

void ball_init();
void ball_draw(SDL_Renderer* renderer);
void ball_toss();

void ball_update();

#endif //BALL_H
