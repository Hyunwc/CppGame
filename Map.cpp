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
	//MapDraw::WallDraw(m_mapSize.m_iWidth, m_mapSize.m_iHeight);
	MapDraw::WallDraw(WallVec);
	MapDraw::ObstacleDraw(ObsSet);
	//MapDraw::HeartDraw(HeartSet);
}

void Map::WallSetting()
{
	for (int y = 0; y < m_mapSize.m_iHeight; y++)
	{
		for (int x = 0; x < m_mapSize.m_iWidth; x++)
		{
			if (y == 0 || y == m_mapSize.m_iHeight - 1 || x == 0 || x == m_mapSize.m_iWidth - 1)
				WallVec.insert({ x, y });
		}
	}
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
	while (1)
	{
		HeartPos.m_ix = (rand() % (m_mapSize.m_iWidth - 2)) + 1;
		HeartPos.m_iy = (rand() % (m_mapSize.m_iHeight - 2)) + 1;

		if (ObsCheck(ObsSet, HeartPos))
			continue;

		HeartSet.insert(HeartPos);
		break;
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
//장애물과 겹치는지 
bool Map::ObsCheck(set<Position> obs, Position heartPos)
{
	for (auto itr = obs.begin(); itr != obs.end(); itr++)
	{
		//만약 장애물과 겹친다면 리턴true
		if (itr->m_ix == heartPos.m_ix && itr->m_iy == heartPos.m_iy)
			return true;
	}
	return false;
}

void Map::HeartDraw()
{
	m_CurClock = clock();
	if (HeartCount < 10 && m_CurClock - m_HeartClock > 1000)
	{
		RandHeart();
		m_HeartClock = m_CurClock;
		MapDraw::HeartDraw(HeartSet);
		HeartCount++;
	}
}

void Map::AllClear()
{
	HeartCount = 0;
	ObsSet.clear();
	HeartSet.clear();
}

int Map::isCollide(Position s_curPos)
{
	auto wall = WallVec.find(s_curPos);
	auto obj = ObsSet.find(s_curPos);
	auto ht = HeartSet.find(s_curPos);

	if (obj != ObsSet.end())
	{
		ObsSet.erase(obj); //해당좌표 삭제
		return MAP_OBSTACLE;
	}
	
	if (ht != HeartSet.end())
	{
		HeartSet.erase(ht);
		HeartCount--;
		return MAP_HEART;
	}
	
	if (wall != WallVec.end())
	{
		return MAP_WALL;
	}

	return MAP_EMPTY;
}

Map::~Map()
{
}