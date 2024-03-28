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
	//플레이어랑 몬스터 클래스가 이 멤버들을 사용해야 하기 때문에 protected
protected:
	CHARACTER_TYPE m_type;
	string m_name;
	int m_level;
	int m_exp;
	int m_curHp; //현재hp
	int m_maxHp; //최대hp
	int m_gold;
	int m_power; //공격력
	int m_mana;
public:
	Character();
	//현재 정보를 출력
	virtual void ShowDisplay();
	virtual void ShowInfo();
	//정보를 전달 받는 함수
	virtual void SetInfo();
	void Observer();
	//죽었는지 체크 (현재 hp가 0이하면 리턴 true)
	void takeDamage(int damage);
	bool DeadCheck();
	string GetName() { return m_name; }
	int GetCurHP() { return m_curHp; }
	int GetDamage() { return m_power; }
	int GetLevel() { return m_level; }

	~Character();
};


