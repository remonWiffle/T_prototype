#include "T_prototype_H.h"
#include "playerInfo.h"
#include "map.h"

int main(void)
{
	
	playerInfo* p1 = createPlayer('0');		//플레이어1을 'O'로 설정
	setOgre(p1);
	playerInfo* p2 = createPlayer('X');		//플레이어2를 'X'로 설정

	setLocation(p1, MIDDLE_COLUMN, BOTTOM);	//플레이어1을 맵의 중앙하단에 위치시킴
	setLocation(p2, MIDDLE_COLUMN, TOP);	//플레이어2를 맵의 중앙상단에 위치시킴

	play(p1, p2);		//게임 시작

	system("pause");

	return 0;			//게임 프로그램 종료
}