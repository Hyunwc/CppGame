#include "Snake.h"

Snake::Snake()
{
	m_head = "⊙";
	m_speed = 250;
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

void Snake::SelectDirection()
{
	char ch;

	if (kbhit())
	{
		ch = getch();

		switch (ch)
		{
		case DIRECTION_LEFT:
			if (m_snakeDirection != DIRECTION_RIGHT)
				m_snakeDirection = DIRECTION_LEFT;
			break;
		case DIRECTION_RIGHT:
			if (m_snakeDirection != DIRECTION_LEFT)
				m_snakeDirection = DIRECTION_RIGHT;
			break;
		case DIRECTION_UP:
			if (m_snakeDirection != DIRECTION_DOWN)
				m_snakeDirection = DIRECTION_UP;
			break;
		case DIRECTION_DOWN:
			if (m_snakeDirection != DIRECTION_UP)
				m_snakeDirection = DIRECTION_DOWN;
			break;
		}
	}
}

void Snake::Move()
{
	m_curClock = clock();
	if (m_curClock - m_moveClock >= m_speed)
	{
		switch (m_snakeDirection)
		{
		case DIRECTION_LEFT:
			break;
		case DIRECTION_RIGHT:
			break;
		case DIRECTION_UP:
			break;
		case DIRECTION_DOWN:
			break;
		default:
			break;
		}
	}
}

char Snake::getInput()
{
	return 0;
}

Snake::~Snake()
{
}
