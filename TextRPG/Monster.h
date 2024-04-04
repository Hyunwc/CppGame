#pragma once
#include "Character.h"

class Monster : public Character
{

public:
	Monster();
	Monster(string name, int level, int hp, int power);
	void SetData(string name, int level, int hp, int power);
	void ShowInfo();
	void ShowDisplay();
	void MaxHp();
};
