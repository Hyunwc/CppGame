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
	int m_curHp; //현재hp
	int m_maxHp; //최대hp
	int m_gold;
	int m_damager;
	int m_mana;
public:
	Character();
	//현재 정보를 출력
	virtual void ShowDisplay();
	//죽었는지 체크 (현재 hp가 0이하면 리턴 true)
	bool DeadCheck();
	~Character();
};

//플레이어는 캐릭터다 
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
