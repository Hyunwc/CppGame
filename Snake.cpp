#include "Snake.h"

Snake::Snake()
{
	m_head = "⊙";
}

void Snake::SetPosition(Size _mapSize)
{
	//현재 시작 0,0 가로50 세로30
	m_position.m_ix = _mapSize.m_iWidth - 1;
	m_position.m_iy = _mapSize.m_iHeight / 2;
}

void Snake::SnakeDraw()
{
	MapDraw::TextDraw(m_head, m_position.m_ix, m_position.m_iy);
}

void Snake::Move()
{
}

char Snake::getInput()
{
	return 0;
}

Snake::~Snake()
{
}
