#include "T_prototype_H.h"
#include "playerInfo.h"
#include "map.h"

int main(void)
{
	
	playerInfo* p1 = createPlayer('0');		//�÷��̾�1�� 'O'�� ����
	setOgre(p1);
	playerInfo* p2 = createPlayer('X');		//�÷��̾�2�� 'X'�� ����

	setLocation(p1, MIDDLE_COLUMN, BOTTOM);	//�÷��̾�1�� ���� �߾��ϴܿ� ��ġ��Ŵ
	setLocation(p2, MIDDLE_COLUMN, TOP);	//�÷��̾�2�� ���� �߾ӻ�ܿ� ��ġ��Ŵ

	play(p1, p2);		//���� ����

	system("pause");

	return 0;			//���� ���α׷� ����
}