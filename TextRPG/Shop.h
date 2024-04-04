#pragma once
#include "Weapon.h"
#include "Player.h"
#include "Mecro.h"
//#include "GameManager.h"

class Shop
{
private:
	vector<Weapon> weaponVec;
public:
	void WeaponDisplay(Player* player);
	void WeaponLoad();
	//void BuyWeapon(Player* player, WEAPON TYPE);
	Shop();
	~Shop();
};