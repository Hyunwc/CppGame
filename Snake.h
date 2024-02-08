#pragma once
#include "Mecro.h"
#include "MapDraw.h"

enum DIRECTION
{
	DIRECTION_LEFT = 'a',
	DIRECTION_RIGHT = 'd',
	DIRECTION_UP = 'w',
	DIRECTION_DOWN = 's'
};

class Snake
{
private:
	string m_head;
	Position m_position;
	Size m_mapSize;
	char input;
	char direction;
public:
	Snake();

	void SetPosition(Size _mapSize);
	void SnakeDraw();
	void Move();
	char getInput();
	~Snake();
};
