/*  
*   File: ball.c
*
*   Author: Popa Vlad (Garnek)
*   
*   Description: Code for the Ball
*/
// SPDX-License-Identifier: MIT

#include <ball.h>
#include <background.h>
#include <collision.h>
#include <paddle.h>

#define BALL_DEFAULT_X_SPEED 3
#define BALL_DEFAULT_Y_SPEED 0

// Size of the "ball's" sides
#define BALL_SIDE 10

ball_t ball;

void ball_init(){
	ball.rect.h = BALL_SIDE;
	ball.rect.w = BALL_SIDE;
	ball.nextPlayerToss = 2;

	ball_toss();
}

void ball_toss(){
	ball.rect.y = 600/2;
	ball.rect.x = 800/2 - (BALL_SIDE/2);

	if(ball.nextPlayerToss == 1){
		ball.speedX = -BALL_DEFAULT_X_SPEED;
		ball.nextPlayerToss = 2;
	} else if(ball.nextPlayerToss == 2){
		ball.speedX = BALL_DEFAULT_X_SPEED;
		ball.nextPlayerToss = 1;
	}

	ball.speedY = BALL_DEFAULT_Y_SPEED;
}

void ball_draw(SDL_Renderer* renderer){
	SDL_RenderFillRect(renderer, &ball.rect);
}

void ball_update(){
	ball.rect.y -= ball.speedY;
	ball.rect.x += ball.speedX;

	if(ball.rect.y < BACKGROUND_EDGE_HEIGHT || ball.rect.y > (600-BACKGROUND_EDGE_HEIGHT-ball.rect.h)){
		ball.speedY = -ball.speedY;
	}
	
	if(ball.rect.x <= 0 || (ball.rect.x + ball.rect.w) >= 800){
		ball_toss();
		return;
	} 

	// This bool is used to make sure the ball doesnt get stuck inside any of the paddles
	static bool alreadyCollided = false;
	// The distance from the center of the paddle
	int distanceFromCenter; 
	if(collision_detect_rect(&paddle1.rect, &ball.rect)){
		if(alreadyCollided) return;
		
		ball.speedX = 3;

		//TODO: Improve the Y speed calculation
		
	        distanceFromCenter = (paddle1.rect.y + (paddle1.rect.h/2)) - (ball.rect.y + (ball.rect.h/2));
		if(distanceFromCenter < 10 && distanceFromCenter > 0) ball.speedY = 1;
		else if(distanceFromCenter < 15 && distanceFromCenter > 0) ball.speedY = 2;
		else if(distanceFromCenter < 20 && distanceFromCenter > 0) ball.speedY = 3;
		else if(distanceFromCenter <= 45 && distanceFromCenter > 0) ball.speedY = 4;
		else if(distanceFromCenter > -10 && distanceFromCenter < 0) ball.speedY = -1;
		else if(distanceFromCenter > -15 && distanceFromCenter < 0) ball.speedY = -2;
		else if(distanceFromCenter > -20 && distanceFromCenter < 0) ball.speedY = -3;
		else if(distanceFromCenter >= -45 && distanceFromCenter < 0) ball.speedY = -4; 
		else ball.speedY = 0;

		alreadyCollided = true;
	} else if(collision_detect_rect(&paddle2.rect, &ball.rect)){
		if(alreadyCollided) return;

		ball.speedX = -3;

	        distanceFromCenter = (paddle2.rect.y + (paddle2.rect.h/2)) - (ball.rect.y + (ball.rect.h/2));
		if(distanceFromCenter < 10 && distanceFromCenter > 0) ball.speedY = 1;
		else if(distanceFromCenter < 15 && distanceFromCenter > 0) ball.speedY = 2;
		else if(distanceFromCenter < 20 && distanceFromCenter > 0) ball.speedY = 3;
		else if(distanceFromCenter <= 45 && distanceFromCenter > 0) ball.speedY = 4;
		else if(distanceFromCenter > -10 && distanceFromCenter < 0) ball.speedY = -1;
		else if(distanceFromCenter > -15 && distanceFromCenter < 0) ball.speedY = -2;
		else if(distanceFromCenter > -20 && distanceFromCenter < 0) ball.speedY = -3;
		else if(distanceFromCenter >= -45 && distanceFromCenter < 0) ball.speedY = -4; 
		else ball.speedY = 0;

		alreadyCollided = true;
	} else {
		alreadyCollided = false;
	}
}
