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
	void DataSave(int slot);
	void BuyShop(Weapon* weapon);
	void Reset();
};

