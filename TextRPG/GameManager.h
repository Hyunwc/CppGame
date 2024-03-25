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
	void GameTitle(); //게임 초기 설정
	void GamePlay();
	~GameManager();
};