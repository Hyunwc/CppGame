#pragma once
#include "Character.h"

//�÷��̾�� ĳ���ʹ� 
class Player : public Character
{

public:
	Player();
	//Player(string name);
	void SetInfo(string name);
	void ShowDisplay();
	void ShowInfo();
};

