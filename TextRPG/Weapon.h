#pragma once
#include "MapDraw.h"
#include "Mecro.h"

enum WEAPON
{
	WEAPON_START,
	WEAPON_GONE = 0,
	WEAPON_SWORD,
	WEAPON_AXE,
	WEAPON_HAMMER
};

class Chararcter;
struct Weapon
{
	WEAPON m_Type; //무기 타입
	string m_strName; //무기 이름
	int m_damage; //공격력
	int m_gold; //가격

	int GetDamage() { return m_damage; }
	int GetGold() { return m_gold; }
};