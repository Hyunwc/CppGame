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

void Map::RandObstacle()
{
	int i = 0;
	while (i < ObstacleCount)
	{
		ObsPos.m_ix = (rand() % (m_mapSize.m_iWidth - 2)) + 1;
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
		HeartPos.m_ix = (rand() % (m_mapSize.m_iWidth - 2)) + 1;
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
		MapDraw::HeartDraw(HeartSet);
		m_HeartClock = m_CurClock;
		HeartCount++;
	}
	/*int CountClock, CurClock;
	CountClock = clock();
	while (1)
	{
		CurClock = clock();
		if (HeartCount <= 10 && CurClock - CountClock > 1000)
		{
			MapDraw::HeartDraw(HeartSet);
			
			CountClock = CurClock;
			HeartCount++;
		}
		
	}*/
}

void Map::AllClear()
{
	ObsSet.clear();
	HeartSet.clear();
}

int Map::isCollide(Position s_curPos)
{
	auto obj = ObsSet.find(s_curPos);
	auto ht = HeartSet.find(s_curPos);

	if (obj != ObsSet.end())
	{
		ObsSet.erase(obj); //해당좌표 삭제
		return MAP_OBSTACLE;
	}
	else if (ht != HeartSet.end())
	{
		HeartSet.erase(ht);
		return MAP_HEART;
	}
	return MAP_EMPTY;
}

Map::~Map()
{
}