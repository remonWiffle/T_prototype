#include "T_prototype_H.h"
#include "playerInfo.h"
#include "map.h"

playerInfo* createPlayer(char symbol)
{
	int i=0, j=0;
	playerInfo* p = (playerInfo*)malloc(sizeof(playerInfo));
	p->consoleLocation = (loc*)malloc(sizeof(loc));
	p->matrixLocation = (loc*)malloc(sizeof(loc));

	p->hp = INITIAL_HP;
	p->damage = 0;
	p->defenceState = 0;
	p->consoleLocation->x = 0;
	p->consoleLocation->y = 0;
	p->symbol = symbol;
	p->surrender = 0;

	return p;
}

void destroyPlayer(playerInfo* p)
{
	int i = 0;

	free(p->consoleLocation);
	free(p->matrixLocation);
	free(p);
}

void destroyMap(int** map)
{
	int i=0;

	for(i=0; i<Y_LENGTH; i++)
		free(map[i]);
	free(map);
}
void setLocation(playerInfo* p, int x, int y)
{
	p->matrixLocation->x = (x-LEFT)/ROW_RANGE;
	p->matrixLocation->y = (y-TOP)/COLUMN_RANGE;
	p->consoleLocation->x = x;
	p->consoleLocation->y = y;
}

void copyPlayer(playerInfo* resorce, playerInfo* table)
{
	int i = 0;

	table->consoleLocation->x = resorce->consoleLocation->x;
	table->consoleLocation->y = resorce->consoleLocation->y;

	table->matrixLocation->x = resorce->matrixLocation->x;
	table->matrixLocation->y = resorce->matrixLocation->y;

	table->defenceState = resorce->defenceState;
	table->hp = resorce->hp;
	
	for (i = 0; i < IC; i++)
		table->Instructions[i] = resorce->Instructions[i];

	table->surrender = resorce->surrender;
	table->symbol = resorce->symbol;
}

/*
플레이어 생성, 삭제
초기화함수
*/