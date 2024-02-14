#pragma once
#include "GameManager.h"


GameManager::GameManager()
{

}

void GameManager::SetPosition(Size _mapSize)
{
	m_mapSize.m_iWidth = _mapSize.m_iWidth;
	m_mapSize.m_iHeight = _mapSize.m_iHeight;
}

void GameManager::GameSetting()
{
	map.MapDraw();
	SetPosition(map.GetSize());
	snake.SetPosition(map.GetSize());
	MenuDraw();
}

void GameManager::MenuDraw()
{
	int Select;
	MapDraw::gotoxy(m_mapSize.m_iWidth * 0.8, m_mapSize.m_iHeight * 0.3);
	cout << "S n a k e  G a m e" << endl;
	MapDraw::gotoxy(m_mapSize.m_iWidth * 0.9, m_mapSize.m_iHeight * 0.4);
	cout << "1. Start" << endl;
	MapDraw::gotoxy(m_mapSize.m_iWidth * 0.9, m_mapSize.m_iHeight * 0.5);
	cout << "2. Exit" << endl;
	MapDraw::gotoxy(m_mapSize.m_iWidth * 0.9, m_mapSize.m_iHeight * 0.7);
	cout << "Select : ";
	cin >> Select;
	switch (Select)
	{
	case 1:
		//GameStart함수 완성시 작성예정.
		GameStart();
		break;
	case 2:
		return;
	}
}

void GameManager::GameStart()
{
	system("cls");
	//map.WallSetting();
	map.RandObstacle();
	map.RandHeart();
	map.MapDraw();
	snake.SnakeSetting("⊙", SNAKETYPE_HEAD, snake.GetPosition());
	snake.SnakeDraw();
	GamePlay();
}

void GameManager::GamePlay()
{
	while (1)
	{
		snake.SelectDirection();
		snake.Move();
		map.HeartDraw();

		Position curSnaksPos = snake.TestGet();
		int CollisionResult = map.isCollide(curSnaksPos);
		if (CollisionResult == MAP_OBSTACLE)
		{
			snake.AddTail();
		}
	}
}



void GameManager::TextScore()
{
	
}

//bool GameManager::CheckCollision()
//{
//	Position testPos = snake.TestGet();
//
//	set<Position> obsPosition = map.GetObstaclePos();
//	set<Position> heartPosition = map.GetHeartPos();
//	
//	auto obj = obsPosition.find(testPos);
//	if (obj != obsPosition.end())
//	{
//		obsPosition.erase(obj);
//		return MAP_OBSTACLE;
//	}
//	else if (heartPosition.find(testPos) != heartPosition.end())
//	{
//		return MAP_HEART;
//	}
//
//	return false;
//}

GameManager::~GameManager()
{
}