#pragma once
#include "Mecro.h"
#include "MapDraw.h"
#define WIDTH 50
#define HEIGHT 30

class Map
{
private:
	Size m_mapSize;
	//int m_wallWidth;
	//int m_wallHeight;
public:
	Map();
	void MapDraw();
	void RandObstacle(); //랜덤으로 장애물좌표 정하기
	Size GetSize(); //맵 가로 세로 반환
	~Map();
};