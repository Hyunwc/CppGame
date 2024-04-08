#pragma once
#include "Character.h"

//플레이어는 캐릭터다 
class Player : public Character
{
private:
	Weapon* weapon;
public:
	Player();
	//Player(string name);
	//void SetInfo(string name);
	void SetName(string name);
	void SetItem(int exp, int gold);
	void LevelUp();
	void PowerUp();
	void MaxHp();
	void ShowDisplay();
	void ShowInfo();
	void Respone();
	void DataSave(int slot);
	void DataLoad(int slot, class Shop* shop);
	void PowerUpdate();
	void BuyShop(Weapon* weapon);
	bool SetWeapon(Weapon* weapon);
	void Reset();
};

