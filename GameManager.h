#pragma once
#include "Mecro.h"
#include "MapDraw.h"
#include "Map.h"
#include "Snake.h"

enum MAP
{
	MAP_WALL,
	MAP_OBSTACLE,
	MAP_HEART
};

class GameManager
{
private:
	Size m_mapSize;
	Map map;
	Snake snake;
	//int heartCount = 0; //��Ʈ ����
	int score = 0;  //���ھ�
public:
	GameManager(); //������
	void SetPosition(Size _mapSize);
	void GameSetting();
	void MenuDraw(); //���Ӽ��ø޴� 
	void GameStart();
	void GamePlay();
	void GameOver();
	void TextScore(); //���ھ� ����
	bool CheckCollision();
	~GameManager();
};