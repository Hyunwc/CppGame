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
	Weapon* GetWeapon(string name);
	//
	//void BuyWeapon(Player* player, WEAPON TYPE);
	Shop();
	~Shop();
};