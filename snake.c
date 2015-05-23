/* TERMINAL SNAKE */
/* BY MARTIN FREDRIKSSON */
/* ##-2015-05-23-## */

#include <stdio.h>
#include <windows.h>

#include "snake.h"


Snake *mySnake = (Snake *)malloc(sizeof(struct Snake));
int score = 0;
int addedParts = 1;
int main(int argc, char const *argv[])
{
	//Create the players snake
	mySnake->snakePos[10][10] = 2;
	struct SnakePart *firstPart = (SnakePart *)malloc(sizeof(struct SnakePart)); 
	firstPart->posX = 10;
	firstPart->posY = 10;

	//Add this first part to list of all snake parts
	mySnake->snakeParts[0] = firstPart;

	mySnake->direction = 1;

	feedSnake();
	feedSnake();
	while(1){
		//unix system("clear");

		//clear screen
		//COORD cursor = {0,0};
		//SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
		system("cls");

		updateGame();
		printGame();
		Sleep(500);  // Sleep for 0.5 seconds (Windows only)
	}


	getchar();
	return 0;
}

void printGame(){

	//Print game title, score etc
	printf("TERMINAL SNAKE by Martin Fredriksson, SCORE: %d\n", score);

	//Print the game frame
	for (int row = 1; row < 23; row++)
	{	
		//Print the horizontal game boundries
		if(row == 1 || row == 22){
			for(int i=0; i < 80; i++){
				printf("#");
			}
			continue;
		}

		for(int col=0; col < 80; col++){
			if (col == 0 || col == 79)
			{
				printf("#");
			}else if (mySnake->snakePos[row][col] == 1 || mySnake->snakePos[row][col] == 2){
				//Print either s for snake or " " for empty spot
				if(mySnake->snakePos[row][col] == 1){
					printf("#");
				}else{
					printf("$");
				}

			}else{
				//Fill empty spots with blank spaces
				printf(" ");
			}
		}
	}

}

void updateGame(){
	//moveSnake(mySnake->direction);
	//feedSnake();

	printf("Parts: %d\n", addedParts);
	//Update table of snake positions
	for(int part = 1; part < addedParts; part++){
		//printf("%d",mySnake->snakeParts[part]->posY);
		mySnake->snakePos[mySnake->snakeParts[part]->posY][mySnake->snakeParts[part]->posX] = 1;
	}
}

void moveSnake(int dir){
	//dir == 1 is right

	/* MASSIVE TODO */
}

void feedSnake(){
	struct SnakePart *feedPart = (SnakePart *)malloc(sizeof(struct SnakePart));
	feedPart->posX = mySnake->snakeParts[addedParts-1]->posX-1;
	feedPart->posY = mySnake->snakeParts[addedParts-1]->posY;
	mySnake->snakeParts[addedParts] = feedPart;

	addedParts++;

	/*
	struct SnakePart *testPart = (SnakePart *)malloc(sizeof(struct SnakePart));
	testPart->posX = 10;
	testPart->posY = 16;
	mySnake->snakeParts[2] = testPart;
	*/

}