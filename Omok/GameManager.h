#pragma once
#include "Mecro.h"
#include "MapDraw.h"
#include "Player.h"

class GameManager
{
private:
	Player player;
	Size m_mapSize; //�� ������ ����ü
public:
	GameManager();
	void GameSetting(); //�ʱ����
	void MenuDraw(); //�޴� �׷��ִ� �Լ� 1�����ϸ� ���ӽ���, 2�����ϸ� ����
	void GameStart(); 
	void GamePlay();
	void EndGame();
};