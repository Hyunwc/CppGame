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
	vector<Position> Obsvec; //장애물 좌표 담아둘 컨테이너
	vector<Position> Heartvec; //하트 좌표 담아둘 컨테이너
	Position ObsPos; //장애물 x,y 좌표 구조체
	Position HeartPos; //하트 x,y 좌표 구조체
	int ObstacleCount = 0;
	int HeartCount = 0;
public:
	Map();
	void MapDraw();
	void RandObstacle(); //랜덤으로 장애물좌표 정하기
	void RandHeart(); //랜덤으로 하트좌표 정하기
	Size GetSize(); //맵 가로 세로 반환
	~Map();
};