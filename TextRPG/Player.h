#pragma once
#include "Character.h"

//플레이어는 캐릭터다 
class Player : public Character
{

public:
	Player();
	//Player(string name);
	//void SetInfo(string name);
	void SetName(string name);
	void SetItem(int exp, int gold);
	void LevelUp();
	void PowerUp(Weapon* weapon);
	void ShowDisplay();
	void ShowInfo();
};

