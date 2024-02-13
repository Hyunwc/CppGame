#include "Map.h"

Map::Map()
{
	srand((unsigned int)time(0));
	m_mapSize.m_iWidth = WIDTH;
	m_mapSize.m_iHeight = HEIGHT;
	ObstacleCount = 50;
	HeartCount = 0;
}

void Map::MapDraw()
{
	MapDraw::WallDraw(m_mapSize.m_iWidth, m_mapSize.m_iHeight);
	//MapDraw::WallDraw(WallVec);
	MapDraw::ObstacleDraw(ObsSet);
	//MapDraw::HeartDraw(HeartSet);
}


void Map::WallSetting()
{
	for (int y = 0; y < m_mapSize.m_iHeight; y++)
	{
		for (int x = 0; x < m_mapSize.m_iWidth; x++)
		{
			if ((y == 0 || y == m_mapSize.m_iHeight - 1) && (x > 0 && x < m_mapSize.m_iWidth))
			{
				WallPos.m_ix = x;
				WallPos.m_iy = y;
				WallVec.push_back(WallPos);
			}
			else if (y > 1 && y < 29 && (x == 0 || x == 50))
			{
				WallPos.m_ix = x;
				WallPos.m_iy = y;
				WallVec.push_back(WallPos);
			}
		}
	}
}


void Map::RandObstacle()
{
	
	int i = 0;
	while (i < ObstacleCount)
	{
		ObsPos.m_ix = (rand() % (m_mapSize.m_iWidth - 2) * 2) + 2;
		ObsPos.m_iy = (rand() % (m_mapSize.m_iHeight - 2)) + 1;

		ObsSet.insert(ObsPos);
		i++;
	}
}

void Map::RandHeart()
{
	
	int i = 0;
	while (i < 10)
	{
		HeartPos.m_ix = (rand() % (m_mapSize.m_iWidth - 2) * 2) + 2;
		HeartPos.m_iy = (rand() % (m_mapSize.m_iHeight - 2)) + 1;

		HeartSet.insert(HeartPos);
		i++;
	}
}

Size Map::GetSize()
{
	return m_mapSize;
}

set<Position> Map::GetObstaclePos()
{
	return ObsSet;
}

set<Position> Map::GetHeartPos()
{
	return HeartSet;
}

void Map::HeartDraw()
{
	m_CurClock = clock();
	if (HeartCount <= 10 && m_CurClock - m_HeartClock > 1000)
	{
		m_HeartClock = m_CurClock;
		MapDraw::HeartDraw(HeartSet);
		HeartCount++;
	}
}

Map::~Map()
{
}