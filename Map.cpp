#include "Map.h"

Map::Map()
{
	m_mapSize.m_iWidth = WIDTH;
	m_mapSize.m_iHeight = HEIGHT;
}

void Map::MapDraw()
{
	//º®±×¸®´Â ÇÔ¼ö
	MapDraw::WallDraw(m_mapSize.m_iWidth, m_mapSize.m_iHeight);
}

void Map::RandObstacle()
{
	//srand((unsigned int)time(0)); //³­¼ö »ý¼º
	int ObsCount = 30;
	int x, y = 0;
	for (int i = 0; i < ObsCount; i++)
	{
		x = (rand() % (m_mapSize.m_iWidth - 2)) + 1;
		y = (rand() % (m_mapSize.m_iHeight - 2)) + 1;
		MapDraw::ObstacleDraw(x, y);
	}

}

Size Map::GetSize()
{
	return m_mapSize;
}

Map::~Map()
{
}