#include <stdio.h>
#include "map.h"

#ifndef PLAYER_INFO_H
#define PLAYER_INFO_H

#define INITIAL_HP 10	//플레이어의 초기 체력

#define IC 3			//총 명령의 수, 명령 큐의 크기

typedef struct location
{
	int x;		//세로축 위치
	int y;		//가로축 위치
} loc;

typedef struct playerInfo
{
	loc* consoleLocation;	//콘솔 좌표
	loc* matrixLocation;	//행렬 좌표
	int hp;					//플레이어의 HP
	int damage;
	int defenceState;		//플레이어의 방어 커맨드 선택 여부
	char Instructions[IC];	//명령 커맨드 배열
	char symbol;			//플레이어의 모양
	int surrender;			//플레이어의 항복 여부
} playerInfo;

playerInfo* createPlayer(char symbol);						//플레이어에게 공간 할당, 초기화
void destroyPlayer(playerInfo* p);							//플레이어에게 할당된 공간 삭제
void setLocation(playerInfo* p, int x, int y);				//
void copyPlayer(playerInfo* resorce, playerInfo* table);	//

#endif