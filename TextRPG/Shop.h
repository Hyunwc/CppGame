#pragma once
#include "Weapon.h"
#include "Player.h"
#include "Mecro.h"

class Shop
{
private:
	Weapon** m_WeaponList;
	int m_WeaponCount;
	vector<Weapon> weaponVec;
public:
	void WeaponDisplay();
	bool BuyWeapon(Player* player, WEAPON TYPE);
	Shop();
	~Shop();
};