#pragma once
#include "MapDraw.h"
#include "Character.h"
#include "Player.h"
#include "Monster.h"
#include "Weapon.h"
#include "Shop.h"

class GameManager
{
private:
	Player m_player;
	Monster m_monster;
	Shop m_shop;
	vector<Monster> monsterVec;
public:
	GameManager();
	void GameSetting(); //게임 초기 설정
	void LoadMonster();
	void GameTitle();
	void NewGame(); //새게임
	void Menu(); //메뉴 
	void Colosseum(); //콜로세움
	void GamePlay();
	void MonsterInfo(); //몬스터 출력
	void ResultBord(int winner, int level); //결과판
	~GameManager();
};