#pragma once
#include "Mecro.h"
#include "MapDraw.h"

class Map
{
private:
	Position m_position; //맵의 좌표
	Size m_mapSize; //맵의 크기
public:
	Map(); //생성자
	void MapDraw(); //단순 맵 그리기
	Position GetPosition(); //맵의 시작좌표 반환
	Size GetSize(); // 맵 가로 세로 반환
	~Map(); //소멸자
};