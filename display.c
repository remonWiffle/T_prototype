#include "T_prototype_H.h"
#include "playerInfo.h"
#include "map.h"

void gotoxy(int x, int y)
{
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void printDot(int x, int y)
{
	if ((x >= LEFT && x <= RIGHT) && (y >= TOP && y <= BOTTOM))
	{
		gotoxy(x, y);
		printf("%c", '*');
	}
}

void showMap(void)
{
	int i = 0;
	int j = 0;

	for(j=0; j<Y_LENGTH; j++)
	{
		for(i=0; i<X_LENGTH; i++)
			printf("式式式式式式");
		printf("\n");
		for(i=0; i<X_LENGTH+1; i++)
			printf("|     ");
		printf("\n");
	}
	for(i=0; i<X_LENGTH; i++)
		printf("式式式式式式");
	printf("\n");
}

int areThemSameLocation(playerInfo* p1, playerInfo* p2)
{
	if((p1->consoleLocation->x == p2->consoleLocation->x) 
		&& (p1->consoleLocation->y == p2->consoleLocation->y))
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}

void showPlayerLocation(playerInfo* p)
{
	gotoxy(p->consoleLocation->x, p->consoleLocation->y);
	printf("%c", p->symbol);

	gotoxy(0,24);
}

void showSameLocation(playerInfo* p1, playerInfo* p2)
{
	gotoxy(p1->consoleLocation->x - 1, p1->consoleLocation->y);
	printf("%c%c", p1->symbol, p2->symbol);
}

void showInstructionQueue(playerInfo* p, int index)
{
	int i=0;

	for (i = 0; i <= index; i++)
		showInstruction(p, i);
	printf("\n");
}

void displayMap(playerInfo* p1, playerInfo* p2)
{
	showMap();
	showPlayerLocation(p1);
	showPlayerLocation(p2);
	if(areThemSameLocation(p1, p2))
		showSameLocation(p1, p2);
}

void showStatus(playerInfo* p)
{
	printf(" %c  hp: %d\n", p->symbol, p->hp);
}

void showTurn(int turn)
{
	printf("turn %d", turn);
}

void showInstruction(playerInfo* p, int index)
{
	printf(" %c  ", p->Instructions[index]);
}

void showAttack(int x, int y, char type)
{
	int X = x;
	int Y = y;
	if (type == '1')
	{
		printDot(x + ROW_RANGE, y);
		printDot(x - ROW_RANGE, y);
		printDot(x, y + COLUMN_RANGE);
		printDot(x, y - COLUMN_RANGE);
	}
	else if (type == '2')
	{
		printDot(x + ROW_RANGE, y);
		printDot(x - ROW_RANGE, y);
		printDot(x, y + COLUMN_RANGE);
		printDot(x, y - COLUMN_RANGE);
		printDot(x + ROW_RANGE, y + COLUMN_RANGE);
		printDot(x + ROW_RANGE, y - COLUMN_RANGE);
		printDot(x - ROW_RANGE, y + COLUMN_RANGE);
		printDot(x - ROW_RANGE, y - COLUMN_RANGE);
	}
	else if (type == '3')
	{
		while (Y < BOTTOM)
		{
			Y = Y + COLUMN_RANGE;
			printDot(X, Y);
		}
		X = x;	//initialize
		Y = y;
		while (Y > TOP)
		{
			Y = Y - COLUMN_RANGE;
			printDot(X, Y);
		}
		X = x;	//initialize
		Y = y;
		while (X < RIGHT)
		{
			X = X + ROW_RANGE;
			printDot(X, Y);
		}
		X = x;	//initialize
		Y = y;
		while (X > LEFT)
		{
			X = X - ROW_RANGE;
			printDot(X, Y);
		}
		X = x;	//initialize
		Y = y;
	}
} // show attack range