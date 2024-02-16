#pragma once
#include "Mecro.h"
#include "MapDraw.h"
#include "Snake.h"
#define WIDTH 50
#define HEIGHT 30

enum MAP
{
	MAP_EMPTY,
	MAP_WALL,
	MAP_OBSTACLE,
	MAP_HEART
};

class Map
{
private:
	Size m_mapSize;
	vector<Position> WallVec;
	set<Position> ObsSet; //장애물 좌표 담아둘 컨테이너
	set<Position> HeartSet; //하트 좌표 담아둘 컨테이너
	Position WallPos; //벽 x,y 좌표 구조체
	Position ObsPos; //장애물 x,y 좌표 구조체
	Position HeartPos; //하트 x,y 좌표 구조체
	int m_CurClock;
	int m_HeartClock;
	int ObstacleCount = 0;
	int HeartCount = 0;
public:
	Map();
	void MapDraw();
	//void WallSetting();
	void RandObstacle(); //랜덤으로 장애물좌표 정하기
	void RandHeart(); //랜덤으로 하트좌표 정하기
	Size GetSize(); //맵 가로 세로 반환
	set<Position> GetObstaclePos();
	set<Position> GetHeartPos();
	bool ObsCheck(set<Position> obs, Position heartPos);
	void HeartDraw();
	void AllClear();

	int isCollide(Position s_curPos);
	~Map();
};