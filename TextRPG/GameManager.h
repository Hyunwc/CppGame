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
	void GameTitle(); //게임 초기 설정
	void NewGame(); //새게임
	void Menu();
	void Colosseum();
	~GameManager();
};