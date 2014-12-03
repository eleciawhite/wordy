/*

This code is based on MicroPong by Shane Lynch
https://github.com/iequalshane/MicroPong/blob/master/MicroPong.ino

Copyright (c) 2014 Shane Lynch

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

Video: https://www.youtube.com/watch?v=UitQD64Nw2o

Changes to the code by Elecia White are beerware: use at your own risk, 
if you find it useful and we ever meet up, buy me a beer. 

*/

#include <MicroView.h>

const int renderDelay = 16; // About 60hz
const int startDelay = 4000;
const int gameOverDelay = 6000;

const int scoreToWin = 3;
int playerScore = 0;
int enemyScore = 0;

const float paddleWidth = LCDWIDTH/16.0;
const float paddleHeight = LCDHEIGHT/3.0;
const float halfPaddleWidth = paddleWidth/2.0;
const float halfPaddleHeight = paddleHeight/2.0;

float playerPosX = 1.0 + halfPaddleWidth;
float playerPosY = 0.0;
float enemyPosX = LCDWIDTH - 1.0 - halfPaddleWidth;
float enemyPosY = 0.0;
float enemyVelY = 0.5;

const float ballRadius = 2.0;
const float ballSpeedX = 1.0;
float ballPosX = LCDWIDTH/2.0;
float ballPosY = LCDHEIGHT/2.0;
float ballVelX = -1.0 * ballSpeedX;
float ballVelY = 0;


void resetGame()
{
	enemyScore = 0;
	playerScore = 0;
	enemyPosY = 0.0;
	ballPosX = LCDWIDTH/2.0;
	ballPosY = LCDHEIGHT/2.0;
	ballVelX = -1.0 * ballSpeedX;
	ballVelY = 0.0;
}

void initializeGraphics()
{
	uView.begin();
	uView.setFontType(1);
}
void renderString(int x, int y, String string)
{
	uView.setCursor(x,y);
	uView.print(string);
}

void renderPaddle(int x, int y, bool filled)
{
	if (filled) {
		uView.rectFill(
			x - halfPaddleWidth, 
			y - halfPaddleHeight, 
			paddleWidth, 
			paddleHeight);
	} else {
		uView.rect(
			x - halfPaddleWidth, 
			y - halfPaddleHeight, 
			paddleWidth, 
			paddleHeight);
	}
}

void renderBall(int x, int y)
{
	uView.circle(x, y, 2);	
}

void renderScores(int firstScore, int secondScore)
{
	renderString(10, 0, String(firstScore));
	renderString(LCDWIDTH - 14, 0, String(secondScore));
}
void renderGame()
{
	uView.clear(PAGE);
	
	renderScores(playerScore, enemyScore);
	renderPaddle(playerPosX, playerPosY, true);
	renderPaddle(enemyPosX, enemyPosY, false);
	renderBall(ballPosX, ballPosY);

	uView.display();
	delay(renderDelay);
}
void displayGameStart()
{
	uView.clear(PAGE);
	renderString(0,0, "Get");
	renderString(5,12, "ready");
	renderString(12,24, "for ");
	renderString(17,36, "PONG!");
	uView.display();
	delay(startDelay);
}
float clampPaddlePosY(float paddlePosY)
{
	float newPaddlePosY = paddlePosY;
	
	if (paddlePosY - halfPaddleHeight < 0)
	{
		newPaddlePosY = halfPaddleHeight;
	}
	else if (paddlePosY + halfPaddleHeight > LCDHEIGHT)
	{
		newPaddlePosY = LCDHEIGHT - halfPaddleHeight;
	}
	
	return newPaddlePosY;
}

void updatePlayer(int playerPosYIn )
{
	playerPosY = clampPaddlePosY((playerPosYIn * LCDHEIGHT)/100);
}

void updateEnemy()
{
	// Follow the ball at a set speed
	if (enemyPosY < ballPosY)
	{
		enemyPosY += enemyVelY;
	}
	else if(enemyPosY > ballPosY)
	{
		enemyPosY -= enemyVelY;
	}
	
	enemyPosY = clampPaddlePosY(enemyPosY);
}

void updateBall()
{
	ballPosY += ballVelY;
	ballPosX += ballVelX;
	
	// Top and bottom wall collisions
	if (ballPosY < ballRadius)
	{
		ballPosY = ballRadius;
		ballVelY *= -1.0;
	}
	else if (ballPosY > LCDHEIGHT - ballRadius)
	{
		ballPosY = LCDHEIGHT - ballRadius;
		ballVelY *= -1.0;
	}
	
	// Left and right wall collisions
	if (ballPosX < ballRadius)
	{
		ballPosX = ballRadius;
		ballVelX = ballSpeedX;
		enemyScore++;
	}
	else if (ballPosX > LCDWIDTH - ballRadius)
	{
		ballPosX = LCDWIDTH - ballRadius;
		ballVelX *= -1.0 * ballSpeedX;
		playerScore++;
	}
	
	// Paddle collisions
	if (ballPosX < playerPosX + ballRadius + halfPaddleWidth)
	{
		if (ballPosY > playerPosY - halfPaddleHeight - ballRadius && 
			ballPosY < playerPosY + halfPaddleHeight + ballRadius)
		{
			ballVelX = ballSpeedX;
			ballVelY = 2.0 * (ballPosY - playerPosY) / halfPaddleHeight;
		}
	}
	else if (ballPosX > enemyPosX - ballRadius - halfPaddleWidth)
	{
		if (ballPosY > enemyPosY - halfPaddleHeight - ballRadius && 
			ballPosY < enemyPosY + halfPaddleHeight + ballRadius)
		{
			ballVelX = -1.0 * ballSpeedX;
			ballVelY = 2.0 * (ballPosY - enemyPosY) / halfPaddleHeight;
		}
	}
}
void updateGame(int playerPos)
{
	updatePlayer(playerPos);
	updateEnemy();
	updateBall();
}

void gameOver(bool didWin)
{
	if (didWin)
	{
		renderString(20,10, "You");
		renderString(20,30, "Win!");
	}
	else
	{
		renderString(20,10, "You");
		renderString(15,30, "Lose!");
	}
	
	uView.display();
	delay(gameOverDelay);
}
void setupPong()
{
	initializeGraphics();
    resetGame();
	displayGameStart();
}
bool loopPong(int playerPos)
{
	updateGame(playerPos);
	renderGame();
	
	if (playerScore >= scoreToWin)
	{
		gameOver(true);
		return false;
	}
	else if (enemyScore >= scoreToWin)
	{
		gameOver(false);
		return false;
	}
	return true;
}
