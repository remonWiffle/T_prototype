#include "playerInfo.h"
#include "T_prototype_H.h"

/*
�÷��̾��� Ű���� �Է°��� playerInfo->Instruction�� �־��ش�.
*/

char getInstructions(void)
{
	char c = 0;

	while (1)
	{
		rewind(stdin);  //�Է� ���� �ʱ�ȭ
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
