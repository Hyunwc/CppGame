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
	TextScore();
	while (1)
	{
		snake.SelectDirection();
		snake.Move();
		map.HeartDraw();
		

		Position curSnaksPos = snake.TestGet();
		int CollisionResult = map.isCollide(curSnaksPos);
		if (CollisionResult == MAP_OBSTACLE)
		{
			//게임오버 완성되면 수정할예정
			exit(0);
		}
		else if (CollisionResult == MAP_HEART)
		{
			snake.AddTail();
			snake.SpeedUp();
		}
	}
}

void GameManager::GameOver()
{
}



void GameManager::TextScore()
{
	
	MapDraw::gotoxy(40, 32);
	cout << "Score : " << score << endl;
}



GameManager::~GameManager()
{
}