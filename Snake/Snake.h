#pragma once
#include "Mecro.h"
#include "MapDraw.h"
#include "Map.h"

enum DIRECTION
{
	DIRECTION_DEFAULT,
	DIRECTION_LEFT = 'a',
	DIRECTION_RIGHT = 'd',
	DIRECTION_UP = 'w',
	DIRECTION_DOWN = 's'
};

enum SnakeType
{
	SNAKETYPE_HEAD,
	SNAKETYPE_TAIL
};

struct SnakeState
{
	string m_str; //뱀의 모양
	SnakeType s_type; //머리인지 꼬리인지 구분할
	Position m_curPos; //현재 좌표x,y
	Position m_lastPos; //마지막 좌표x,y
};

class Snake
{
private:
	SnakeState m_state;//m_head
	vector<SnakeState> SnakeVec;

	const string m_head;
	Position m_position;
	//Position m_LastPosition;

	Size m_mapSize;
	DIRECTION m_snakeDirection;


	int m_curClock;
	int m_moveClock;
	int m_speed;

public:
	Snake();

	void SetPosition(const Size& _mapSize);
	void SnakeSetting(string str, SnakeType s_type, Position pos);
	void SnakeDraw(); 
	void SnakeErase();
	void Move();
	void SelectDirection();
	Position GetPosition();
	void SpeedUp();
	void AddTail();
	void TailMove();
	void SnakeClear();
	bool TailCollide();
	Position TestGet(); //컨테이너의 현재좌표만 반환하기 위한 함수
	~Snake();
};
