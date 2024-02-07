#include "Map.h"

Map::Map()
{
	srand((unsigned int)time(0));
	m_mapSize.m_iWidth = WIDTH;
	m_mapSize.m_iHeight = HEIGHT;
	ObstacleCount = 50;
	HeartCount = 10;
}

void Map::MapDraw()
{
	MapDraw::WallDraw(m_mapSize.m_iWidth, m_mapSize.m_iHeight);
	MapDraw::ObstacleDraw(Obsvec);
	MapDraw::HeartDraw(Heartvec);
}

void Map::RandObstacle()
{
	//int x, y = 0;
	for (int i = 0; i < ObstacleCount; i++)
	{
		ObsPos.m_ix = (rand() % (m_mapSize.m_iWidth - 2) * 2) + 2;
		ObsPos.m_iy = (rand() % (m_mapSize.m_iHeight - 2)) + 1;
		
		Obsvec.push_back(ObsPos);
	}
}

void Map::RandHeart()
{
	for (int i = 0; i < HeartCount; i++)
	{
		HeartPos.m_ix = (rand() % (m_mapSize.m_iWidth - 2) * 2) + 2;
		HeartPos.m_iy = (rand() % (m_mapSize.m_iHeight - 2)) + 1;
		//장애물과 좌표가 똑같으면 i-- 되게
		//if(ObsPos.m_ix == HeartPos.m_ix && ObsPos.m_iy == HeartPos.m_iy)
		//장애물과 좌표가 똑같으면 i--
		if (ObsPos == HeartPos)
			i--;
		else
			Heartvec.push_back(HeartPos);
	}
}

Size Map::GetSize()
{
	return m_mapSize;
}

Map::~Map()
{
}