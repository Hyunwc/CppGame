#pragma once
#include "Mecro.h"
#include "MapDraw.h"
#include "Map.h"

enum DIRECTION
{
	DIRECTION_LEFT = 'a',
	DIRECTION_RIGHT = 'd',
	DIRECTION_UP = 'w',
	DIRECTION_DOWN = 's'
};

struct SnakeState
{
	string m_str; //¹ìÀÇ ¸ð¾ç
	Position m_curPos; //ÇöÀç ÁÂÇ¥x,y
	Position m_lastPos; //¸¶Áö¸· ÁÂÇ¥x,y
};

class Snake
{
private:
	Map map;
	string m_head;
	Position m_position;
	Position m_LastPosition;
	Size m_mapSize;
	SnakeState m_state;
	DIRECTION m_snakeDirection;
	vector<SnakeState> SnakeVec;
	int m_curClock;
	int m_moveClock;
	int m_speed;
public:
	Snake();

	void SetPosition(Size _mapSize);
	void SnakeSetting(string str, Position pos);
	void SnakeDraw(); 
	void SnakeErase();
	void Move();
	void SelectDirection();
	Position GetPosition();
	void SpeedUp();
	void AddTail();
	~Snake();
};
