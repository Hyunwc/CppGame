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
	set<Position> ObsSet; //��ֹ� ��ǥ ��Ƶ� �����̳�
	set<Position> HeartSet; //��Ʈ ��ǥ ��Ƶ� �����̳�
	Position WallPos; //�� x,y ��ǥ ����ü
	Position ObsPos; //��ֹ� x,y ��ǥ ����ü
	Position HeartPos; //��Ʈ x,y ��ǥ ����ü
	int m_CurClock;
	int m_HeartClock;
	int ObstacleCount = 0;
	int HeartCount = 0;
public:
	Map();
	void MapDraw();
	//void WallSetting();
	void RandObstacle(); //�������� ��ֹ���ǥ ���ϱ�
	void RandHeart(); //�������� ��Ʈ��ǥ ���ϱ�
	Size GetSize(); //�� ���� ���� ��ȯ
	set<Position> GetObstaclePos();
	set<Position> GetHeartPos();
	bool ObsCheck(set<Position> obs, Position heartPos);
	void HeartDraw();
	void AllClear();

	int isCollide(Position s_curPos);
	~Map();
};