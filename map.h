#ifndef MAP_H
#define MAP_H

#define X_LENGTH 5		//맵의 세로 길이
#define Y_LENGTH 5		//맵의 가로 길이

#define COLUMN_RANGE	2	//매트릭스로 변환시 
#define ROW_RANGE		6	//
#define LEFT	3			//
#define TOP		1			//
#define RIGHT	LEFT + (X_LENGTH-1)*ROW_RANGE
#define BOTTOM	TOP + (Y_LENGTH-1)*COLUMN_RANGE

#define MIDDLE_COLUMN LEFT + (RIGHT-LEFT)/2
#endif