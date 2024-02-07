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
	vector<Position> Obsvec; //��ֹ� ��ǥ ��Ƶ� �����̳�
	vector<Position> Heartvec; //��Ʈ ��ǥ ��Ƶ� �����̳�
	Position ObsPos; //��ֹ� x,y ��ǥ ����ü
	Position HeartPos; //��Ʈ x,y ��ǥ ����ü
	int ObstacleCount = 0;
	int HeartCount = 0;
public:
	Map();
	void MapDraw();
	void RandObstacle(); //�������� ��ֹ���ǥ ���ϱ�
	void RandHeart(); //�������� ��Ʈ��ǥ ���ϱ�
	Size GetSize(); //�� ���� ���� ��ȯ
	~Map();
};