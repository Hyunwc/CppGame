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
	void GameSetting(); //���� �ʱ� ����
	void GameTitle(); 
	void NewGame(); //������
	void Menu(); //�޴� 
	void Colosseum(); //�ݷμ���
	void GamePlay();
	void ResultBord(int winner); //�����
	~GameManager();
};