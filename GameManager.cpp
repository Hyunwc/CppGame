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
		cout << "게임이 시작되었습니다~" << endl;
		break;
	case 2:
		return;
	}
}

void GameManager::GameStart()
{
}

void GameManager::TextScore()
{
	string str = "Score : ";

}

GameManager::~GameManager()
{
}