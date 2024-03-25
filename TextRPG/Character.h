#pragma once
#include "Mecro.h"
#include "MapDraw.h"

enum CHARACTER_TYPE
{
	PLAYER = 0,
	MONSTER
};

class Character
{
protected:
	CHARACTER_TYPE m_type;
	string m_name;
	int m_level;
	int m_exp;
	int m_curHp; //����hp
	int m_maxHp; //�ִ�hp
	int m_gold;
	int m_damager;
	int m_mana;
public:
	Character();
	//���� ������ ���
	virtual void ShowDisplay();
	//�׾����� üũ (���� hp�� 0���ϸ� ���� true)
	bool DeadCheck();
	~Character();
};

//�÷��̾�� ĳ���ʹ� 
class Player : public Character
{

public:
	Player(string name);
	void ShowDisplay();
};

class Monster : public Character
{

public:
	Monster();
	void ShowDisplay();
};
