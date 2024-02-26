#pragma once
#include "Mecro.h"
#include "MapDraw.h"

enum KEY
{
	KEY_LEFT = 'a',
	KEY_RIGHT = 'd',
	KEY_UP = 'w',
	KEY_DOWN = 's',
	KEY_ESC = 27,  
	KEY_ENTER = 13,  
	KEY_CANCEL = 'n' //¹«¸£±â
};

class Player
{
private:
	string stone; //¹ÙµÏµ¹ ¸ð¾ç
	Position stonePos; //¹ÙµÏµ¹ÀÇ x, y ÁÂÇ¥
public:
	void SetPosition(const Size& _mapSize);
	void Move();
};