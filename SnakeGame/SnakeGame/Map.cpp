#include "Map.h"

Map::Map()
{
	m_mapSize.m_iWidth = WIDTH;
	m_mapSize.m_iHeight = HEIGHT;
}

void Map::MapDraw()
{
	//벽그리는 함수
	MapDraw::WallDraw(m_mapSize.m_iWidth, m_mapSize.m_iHeight);
}

void Map::RandObstacle()
{
	//srand((unsigned int)time(0)); //난수 생성
	
}

Size Map::GetSize()
{
	return m_mapSize;
}

Map::~Map()
{
}
