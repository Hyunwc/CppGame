#pragma once
#include "MapDraw.h"
#include "Character.h"
#include "Player.h"

class GameManager
{
private:
	Player m_player;
public:
	GameManager();
	void GameSetting();
	void GameTitle(); //���� �ʱ� ����
	void NewGame(); //������
	void Menu();
	void Colosseum();
	~GameManager();
};