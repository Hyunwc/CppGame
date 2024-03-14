#pragma once
#include "Mecro.h"
#include "MapDraw.h"
#include "Player.h"

class GameManager
{
private:
	Player player;
	Size m_mapSize; //맵 사이즈 구조체
public:
	GameManager();
	void GameSetting(); //초기셋팅
	void MenuDraw(); //메뉴 그려주는 함수 1선택하면 게임시작, 2선택하면 종료
	void GameStart(); 
	void GamePlay();
	void EndGame();
};