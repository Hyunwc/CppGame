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
	WEAPON m_Type; //���� Ÿ��
	string m_strName; //���� �̸�
	int m_damage; //���ݷ�
	int m_gold; //����
};