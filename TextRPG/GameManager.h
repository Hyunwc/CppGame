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
	//Shop shop;
public:
	GameManager();
	void GameSetting(); //���� �ʱ� ����
	void GameTitle();
	void NewGame(); //������
	void Menu(); //�޴� 
	void Colosseum(); //�ݷμ���
	void GamePlay();
	void MonsterInfo(); //���� ���
	void ResultBord(int winner, int level); //�����
	~GameManager();
};