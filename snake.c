/* TERMINAL SNAKE */
/* BY MARTIN FREDRIKSSON */
/* ##-2015-05-23-## */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <ncurses.h>

#include "snake.h"

typedef struct Snake Snake;
typedef struct SnakePart SnakePart;

struct Snake *theSnake;
int score = 0;
int addedParts = 1;
int main(int argc, char const *argv[])
{	
	WINDOW *snake_box;
    int offsetx, offsety;
    initscr();
    noecho();
	keypad (stdscr, TRUE); //Enable keypad/keyb constants
    curs_set(0); //Disable cursor
    addstr( "Terminal Snake by Martin Fredriksson" );
    addstr("    SCORE:  ");

    //Center window
    offsetx = (COLS - 100) / 2;
    offsety = (LINES - 30) / 2;
 	
 	//Actually create window
    snake_box = newwin(30,
                           100,
                           offsety,
                           offsetx);
    box(snake_box, 0 , 0);


    initSnake(10,10);
    //Add snake at start position
    mvwaddch(snake_box, theSnake->snakeParts[0]->posY, theSnake->snakeParts[0]->posX, '$');

    int c;
    while(c != 'q'){

    	updateGame();
		printGame();
    	refresh();
    	wrefresh(snake_box);

    	//sleep(500);  // Sleep for 0.5 seconds

    	c = getch();
		switch(c)
		{	case KEY_UP:
				addstr("up");
				break;
			case KEY_DOWN:
				addstr("down");
				break;
			case KEY_LEFT:
				addstr("left");
				break;
			case KEY_RIGHT:
				addstr("right");
				break;
		}
    }

 
    delwin(snake_box);
 
    endwin();

	/*
	theSnake = malloc(sizeof(struct Snake));
	//Create the players snake
	theSnake->snakePos[10][10] = 2;
	struct SnakePart *firstPart = malloc(sizeof(struct SnakePart)); 
	firstPart->posX = 10;
	firstPart->posY = 10;

	//Add this first part to list of all snake parts
	theSnake->snakeParts[0] = firstPart;

	theSnake->direction = 1;

	feedSnake();	//temp feed
	feedSnake();	//temp feed
	while(1){


		//unix system("clear");
		//clear screen
		//COORD cursor = {0,0};
		//SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
		//system("cls");

	}


	getchar();
	return 0;*/
}

void initSnake(int x, int y){
    theSnake = malloc(sizeof(struct Snake));
	//Create the players snake
	theSnake->snakePos[10][10] = 2;
	struct SnakePart *firstPart = malloc(sizeof(struct SnakePart)); 
	firstPart->posX = x;
	firstPart->posY = y;

	//Add this first part to list of all snake parts
	theSnake->snakeParts[0] = firstPart;

	theSnake->direction = 1;

	feedSnake();	//temp feed
	feedSnake();	//temp feed

}

void printGame(){

}

/*
void printGame(){

	//Print game title, score etc
	printf("TERMINAL SNAKE by Martin Fredriksson, SCORE: %d\n", score);

	//Print the game frame
	for (int row = 1; row < 30; row++)
	{	
		//Print the horizontal game boundries
		if(row == 1 || row == 29){
			for(int i=0; i < 100; i++){
				printf("#");
			}
			continue;
		}

		for(int col=0; col < 100; col++){
			if (col == 0 || col == 99)
			{
				printf("#");
			}else if (theSnake->snakePos[row][col] == 1 || theSnake->snakePos[row][col] == 2){
				//Print either s for snake or " " for empty spot
				if(theSnake->snakePos[row][col] == 1){
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

	fflush(stdout);
}*/

void updateGame(){

}

/*
void updateGame(){
	//moveSnake(theSnake->direction);
	//feedSnake();

	printf("Parts: %d\n", addedParts);
	//Update table of snake positions
	for(int part = 1; part < addedParts; part++){
		//printf("%d",theSnake->snakeParts[part]->posY);
		theSnake->snakePos[theSnake->snakeParts[part]->posY][theSnake->snakeParts[part]->posX] = 1;
	}
}*/

void moveSnake(int dir){
	//dir == 1 is right

	/* MASSIVE TODO */
}

void feedSnake(){
	struct SnakePart *feedPart = (SnakePart *)malloc(sizeof(struct SnakePart));
	feedPart->posX = theSnake->snakeParts[addedParts-1]->posX-1;
	feedPart->posY = theSnake->snakeParts[addedParts-1]->posY;
	theSnake->snakeParts[addedParts] = feedPart;

	addedParts++;

	/*
	struct SnakePart *testPart = (SnakePart *)malloc(sizeof(struct SnakePart));
	testPart->posX = 10;
	testPart->posY = 16;
	theSnake->snakeParts[2] = testPart;
	*/

}