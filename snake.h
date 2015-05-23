void printGame();
void updateGame();
void moveSnake(int);
void feedSnake();

struct SnakePart
{
	int posX;
	int posY;
};

struct Snake
{
	struct SnakePart *snakeParts[100];
	int snakePos [24][80];
	int direction;
};

