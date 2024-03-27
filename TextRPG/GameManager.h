#pragma once
#include "MapDraw.h"
#include "Character.h"
#include "Player.h"
#include "Monster.h"

class GameManager
{
private:
	Player m_player;
	Monster m_monster;
public:
	GameManager();
	void GameSetting(); //게임 초기 설정
	void GameTitle(); 
	void NewGame(); //새게임
	void Menu(); //메뉴 
	void Colosseum(); //콜로세움
	void GamePlay();
	void ResultBord(int winner); //결과판
	~GameManager();
};