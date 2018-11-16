#include <stdio.h>
#include "map.h"

#ifndef PLAYER_INFO_H
#define PLAYER_INFO_H

#define INITIAL_HP 10	//�÷��̾��� �ʱ� ü��

#define IC 3			//�� ����� ��, ��� ť�� ũ��

typedef struct location
{
	int x;		//������ ��ġ
	int y;		//������ ��ġ
} loc;

typedef struct playerInfo
{
	loc* consoleLocation;	//�ܼ� ��ǥ
	loc* matrixLocation;	//��� ��ǥ
	int hp;					//�÷��̾��� HP
	int damage;
	int defenceState;		//�÷��̾��� ��� Ŀ�ǵ� ���� ����
	char Instructions[IC];	//��� Ŀ�ǵ� �迭
	char symbol;			//�÷��̾��� ���
	int surrender;			//�÷��̾��� �׺� ����
} playerInfo;

playerInfo* createPlayer(char symbol);						//�÷��̾�� ���� �Ҵ�, �ʱ�ȭ
void destroyPlayer(playerInfo* p);							//�÷��̾�� �Ҵ�� ���� ����
void setLocation(playerInfo* p, int x, int y);				//
void copyPlayer(playerInfo* resorce, playerInfo* table);	//

#endif