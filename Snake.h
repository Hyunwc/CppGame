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

enum SnakeType
{
	SNAKETYPE_HEAD,
	SNAKETYPE_TAIL
};

struct SnakeState
{
	string m_str; //���� ���
	SnakeType s_type; //�Ӹ����� �������� ������
	Position m_curPos; //���� ��ǥx,y
	Position m_lastPos; //������ ��ǥx,y
};

class Snake
{
private:
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
	void SnakeSetting(string str, SnakeType s_type, Position pos);
	void SnakeDraw(); 
	void SnakeErase();
	void Move();
	void SelectDirection();
	Position GetPosition();
	void SpeedUp();
	void AddTail();
	void TailMove();
	Position TestGet(); //�����̳��� ������ǥ�� ��ȯ�ϱ� ���� �Լ�
	~Snake();
};
