/*  
*   File: collision.c
*
*   Author: Popa Vlad (Garnek)
*   
*   Description: Collision Detection
*/
// SPDX-License-Identifier: MIT

#include <collision.h>

bool collision_detect_rect(SDL_Rect* rect1, SDL_Rect* rect2){
	if(((rect1->y + rect1->h) <= rect2->y) ||
	   (rect1->y >= (rect2->y + rect2->h)) ||
	   ((rect1->x + rect1->w) <= rect2->x) ||
	   (rect1->x >= (rect2->x + rect2->w))) return false;

	return true;
}
