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
	void RandObstacle(); //�������� ��ֹ���ǥ ���ϱ�
	Size GetSize(); //�� ���� ���� ��ȯ
	~Map();
};