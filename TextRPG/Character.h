#pragma once
#include "Mecro.h"
#include "MapDraw.h"
#include "Weapon.h"

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
	int m_curExp;
	int m_maxExp;
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
	//virtual void SetInfo();
	//경험치와 골드를 누적하기위함
	virtual void SetItem(int exp, int gold);
	virtual void LevelUp();
	//현 인스턴스의 hp를 최대치로. 나중에 플레이어 포션 구현할때 써도 될듯
	virtual void MaxHp();

	void Observer();
	virtual void PowerUp(Weapon* weapon);
	void takeDamage(int damage);
	//죽었는지 체크 (현재 hp가 0이하면 리턴 true)
	bool DeadCheck();
	string GetName() { return m_name; }
	int GetCurHP() { return m_curHp; }
	int GetDamage() { return m_power; }
	int GetLevel() { return m_level; }

	~Character();
};


