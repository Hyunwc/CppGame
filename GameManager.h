#pragma once
#include "Mecro.h"
#include "MapDraw.h"
#include "Map.h"
#include "Snake.h"


class GameManager
{
private:
	Size m_mapSize;
	Map map;
	Snake snake;
	//int heartCount = 0; //��Ʈ ����
	int score;  //���ھ�
public:
	GameManager(); //������
	void SetPosition(Size _mapSize);
	void GameSetting();
	void MenuDraw(); //���Ӽ��ø޴� 
	void GameStart();
	void GamePlay();
	void GameOver();
	void TextScore(); //���ھ� ����
	~GameManager();
};