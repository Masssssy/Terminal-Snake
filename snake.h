void printGame();
void updateGame();
void moveSnake(int);
void feedSnake();
void initSnake(int, int);


struct SnakePart
{
	int posX;
	int posY;
};

struct Snake
{
	struct SnakePart *snakeParts[100];
	int snakePos [30][100];
	int direction;
};

