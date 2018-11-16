#include "T_prototype_H.h"
#include "playerInfo.h"
#include "map.h"

//branch test

/*
플레이어의 액션 함수(무빙, 공격, 방어)
*/

void goForward(playerInfo *p)
{
	if(p->consoleLocation->y > TOP)
	{
		p->consoleLocation->y = p->consoleLocation->y - COLUMN_RANGE;
		p->matrixLocation->y = p->matrixLocation->y - 1;
	}
}

void goBackward(playerInfo *p)
{
	if(p->consoleLocation->y < BOTTOM)
	{
		p->consoleLocation->y = p->consoleLocation->y + COLUMN_RANGE;
		p->matrixLocation->y = p->matrixLocation->y + 1;
	}
}

void goLeft(playerInfo *p)
{
	if(p->consoleLocation->x > LEFT)
	{
		p->consoleLocation->x = p->consoleLocation->x - ROW_RANGE;
		p->matrixLocation->x = p->matrixLocation->x - 1;
	}
}

void goRight(playerInfo *p)
{
	if(p->consoleLocation->x < RIGHT)
	{
		p->consoleLocation->x = p->consoleLocation->x + ROW_RANGE;
		p->matrixLocation->x = p->matrixLocation->x + 1;
	}
}

void strongMeleeAttack(playerInfo* attacker, playerInfo* defender)
{
	int attX = attacker->matrixLocation->x;
	int attY = attacker->matrixLocation->y;
	int defX = defender->matrixLocation->x;
	int defY = defender->matrixLocation->y;

	if((defX == attX) && (defY <= attY+1 && defY >= attY-1))
	{
		defender->hp = defender->hp - 5;
	}
	else if((defY == attY) && (defX <= attX+1 && defX >= attX-1))
	{
		defender->hp = defender->hp - 5;
	}
}

void roundMeleeAttack(playerInfo* attacker, playerInfo* defender)
{
	int attX = attacker->matrixLocation->x;
	int attY = attacker->matrixLocation->y;
	int defX = defender->matrixLocation->x;
	int defY = defender->matrixLocation->y;

	if((defX <= attX+1 && defX >= attX-1) && (defY <= attY+1 && defY >= attY-1))
	{
		defender->hp = defender->hp - 3;
	}
}

void rangedAttack(playerInfo* attacker, playerInfo* defender)
{
	int attX = attacker->matrixLocation->x;
	int attY = attacker->matrixLocation->y;
	int defX = defender->matrixLocation->x;
	int defY = defender->matrixLocation->y;

	if((defX == attX) || (defY == attY))
	{
		defender->hp = defender->hp - 2;
	}
}


void defense(playerInfo* p)
{
	p->defenceState = 1;
}

void surrender(playerInfo* p)
{
	p->surrender = 1;
}