#pragma once
#include "MapDraw.h"
#include "Character.h"

class GameManager
{
private:
	//Character m_player;
public:
	GameManager();
	void GameSetting();
	void GameTitle(); //���� �ʱ� ����
	void GamePlay();
	~GameManager();
};