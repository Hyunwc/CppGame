#pragma once
#include "Mecro.h"
#include "MapDraw.h"
#include "Player.h"

class GameManager
{
private:
	Player player;
	Size m_mapSize; //�� ������ ����ü
	/*const int width = 20;
	const int height = 20;*/
public:
	GameManager();
	void GameSetting();
	void MenuDraw();
	void GameStart();
	void GamePlay();
	void MenualDraw();
};