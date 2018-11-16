#include "playerInfo.h"
#include "T_prototype_H.h"

/*
플레이어의 키보드 입력값을 playerInfo->Instruction에 넣어준다.
*/

char getInstructions(void)
{
	char c = 0;

	while (1)
	{
		rewind(stdin);  //입력 버퍼 초기화
		c = getch();

		if (c == '\r')
			break;
		else if (c > 'z' || c < '0')
		{
			continue;
		}
		
		break;
	}
	
	return c;
}
