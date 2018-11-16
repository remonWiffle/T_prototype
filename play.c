#include "T_prototype_H.h"
#include "playerInfo.h"
#include "map.h"

void doAction(playerInfo* p1, playerInfo* p2, char instruction)
{
	if(instruction == 'w') //moving
	{
		goForward(p1);
	}
	else if(instruction == 's')
	{
		goBackward(p1);
	}
	else if(instruction == 'a')
	{
		goLeft(p1);
	}
	else if(instruction == 'd')
	{
		goRight(p1);
	}
	else if(instruction == 'p')
	{
		surrender(p1);
	}
	else if(instruction == '1') // strong attack
	{
		strongMeleeAttack(p1, p2);
	}
	else if(instruction == '2') // round attack
	{
		roundMeleeAttack(p1, p2);
	}
	else if(instruction == '3') // ranged attack
	{
		rangedAttack(p1, p2);
	}
	
}

int isMoving(playerInfo* p, int index)
{
	int instruction = p->Instructions[index];

	if(instruction <= 'w' && instruction >= 'a')
		return 1;
	return 0;
}

void Action(playerInfo* p1, playerInfo* p2, int index)
{
	if(isMoving(p2, index))
	{
		doAction(p2, p1, p2->Instructions[index]);
		doAction(p1, p2, p1->Instructions[index]);
		return;
	}
	doAction(p1, p2, p1->Instructions[index]);
	doAction(p2, p1, p2->Instructions[index]);
}

int isFinished(playerInfo* p1, playerInfo* p2)
{
	int p1HP = p1->hp;
	int p2HP = p2->hp;
	int p1Surr = p1->surrender;
	int p2Surr = p2->surrender;

	if(p1HP <= 0 && p2HP <= 0)
	{
		printf("Draw\n");
		return 1;
	}
	else if(p1HP <= 0)
	{
		printf("p2 WIN\n");
		return 1;
	}
	else if(p2HP <= 0)
	{
		printf("p1 WIN\n");
		return 1;
	}
	else if(p1Surr == 1 && p2Surr == 1)
	{
		printf("Draw\n");
		return 1;
	}
	else if(p1Surr == 1)
	{
		printf("p2 WIN\n");
		return 1;
	}
	else if(p2Surr == 1)
	{
		printf("p1 WIN\n");
		return 1;
	}
	
	return 0;
}

void play(playerInfo* p1, playerInfo* p2)
{
	int i=0;
	int j=0;
	int flag = 1;
	char instruction[2];
	
	playerInfo* p1Demo = createPlayer('D');
	playerInfo* p2Demo = createPlayer('D');
	playerInfo* beforeDemo1 = createPlayer('D');
	playerInfo* beforeDemo2 = createPlayer('D');

	//copy to demo
	copyPlayer(p1, p1Demo);
	copyPlayer(p2, p2Demo);

	instruction[0] = 0;	// real instruction
	instruction[1] = 0; // enter checker


	////////////////////input
	while(flag)
	{
		//input p1
		displayMap(p1, p2);
		gotoxy(0, BOTTOM + COLUMN_RANGE);
		printf("player 1 turn\n");
		system("pause");

		for (i = 0; i < IC; i++)
		{
			while (1)
			{
				instruction[1] = getInstructions();
				if (instruction[1] == '\r')	//enter key
				{
					break;
				}
				instruction[0] = instruction[1];
				p1Demo->Instructions[i] = instruction[0];
				copyPlayer(p1Demo, beforeDemo1);	//store p1Demo to before ( for restore )
				copyPlayer(p2Demo, beforeDemo2);
				doAction(p1Demo, p2Demo, instruction[0]);

				//update display (show expecting result)
				system("cls");
				displayMap(p1Demo, p2Demo);
				showAttack(p1Demo->consoleLocation->x, p1Demo->consoleLocation->y, instruction[0]);
				gotoxy(0, BOTTOM + COLUMN_RANGE);
				showTurn(i + 1);
				showInstructionQueue(p1Demo, i);
				showStatus(p1Demo);
				showStatus(p2Demo);

				//p1Demo restore
				copyPlayer(beforeDemo1, p1Demo);
				copyPlayer(beforeDemo2, p2Demo);
			}
			p1->Instructions[i] = instruction[0];
			doAction(p1Demo, p2Demo, instruction[0]); //do it
		}

		copyPlayer(p1, p1Demo); //p1Demo initialize
		copyPlayer(p2, p2Demo);

		//input p2
		system("cls");
		displayMap(p1, p2);
		gotoxy(0, BOTTOM + COLUMN_RANGE);
		printf("player 2 turn\n");
		system("pause");


		for (i = 0; i < IC; i++)
		{
			while (1)
			{
				instruction[1] = getInstructions();
				if (instruction[1] == '\r')	//enter key
				{
					break;
				}
				instruction[0] = instruction[1];
				p2Demo->Instructions[i] = instruction[0];
				copyPlayer(p1Demo, beforeDemo1);
				copyPlayer(p2Demo, beforeDemo2);	//store p2Demo to before ( for restore )
				doAction(p2Demo, p1Demo, instruction[0]);

				//update display (show expecting result)
				system("cls");
				displayMap(p1Demo, p2Demo);
				showAttack(p2Demo->consoleLocation->x, p2Demo->consoleLocation->y, instruction[0]);
				gotoxy(0, BOTTOM + COLUMN_RANGE);
				showTurn(i + 1);
				showInstructionQueue(p2Demo, i);
				showStatus(p2Demo);
				showStatus(p1Demo);

				//p1Demo restore
				copyPlayer(beforeDemo1, p1Demo);
				copyPlayer(beforeDemo2, p2Demo);
			}
			p2->Instructions[i] = instruction[0];
			doAction(p2Demo, p1Demo, instruction[0]); //do it
		}

		copyPlayer(p1, p1Demo);
		copyPlayer(p2, p2Demo);  //p2Demo initialize
		////////////////////////////////////////////////////

		//actions
		system("cls");
		displayMap(p1, p2);
		gotoxy(0, BOTTOM + COLUMN_RANGE);
		printf("actions\n");
		system("pause");

		for (i = 0; i < IC; i++)
		{
			Action(p1, p2, i);
			system("cls");
			displayMap(p1, p2);
			gotoxy(0, BOTTOM + COLUMN_RANGE);

			showStatus(p1);
			showInstructionQueue(p1, i);

			showStatus(p2);
			showInstructionQueue(p2, i);

			//check end
			if (isFinished(p1, p2))
			{
				flag = 0;
				destroyPlayer(p1Demo);
				destroyPlayer(p2Demo);
				destroyPlayer(beforeDemo1);
				destroyPlayer(beforeDemo2);
				return;
			}

			system("pause");
		}
		
		//copy p1, p2 to demos ( p1, p2 were changed )
		copyPlayer(p1, p1Demo);
		copyPlayer(p2, p2Demo);

		system("cls");
		
	}
}