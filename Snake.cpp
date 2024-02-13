#include "Snake.h"

Snake::Snake()
{
	m_head = "⊙";
	m_speed = 1000;
}

void Snake::SetPosition(Size _mapSize)
{
	//현재 시작 0,0 가로50 세로30
	m_position.m_ix = _mapSize.m_iWidth - 1;
	m_position.m_iy = _mapSize.m_iHeight / 2;

	//m_snake.clear();
}

void Snake::SnakeDraw()
{
	MapDraw::TextDraw(m_head, m_position.m_ix, m_position.m_iy);
}

void Snake::SnakeErase()
{
	MapDraw::TextErase(m_position.m_ix, m_position.m_iy);
}

void Snake::SelectDirection()
{
	char ch;

	if (_kbhit())
	{
		ch = _getch();

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

Position Snake::GetPosition()
{
	return m_position;
}



void Snake::Move()
{
	m_curClock = clock();
	if (m_curClock - m_moveClock >= m_speed)
	{
		SnakeErase();

		Position prevHeadPosition = m_position;

		switch (m_snakeDirection)
		{
		case DIRECTION_LEFT:
			m_position.m_ix--;
			break;
		case DIRECTION_RIGHT:
			m_position.m_ix++;
			break;
		case DIRECTION_UP:
			m_position.m_iy--;
			break;
		case DIRECTION_DOWN:
			m_position.m_iy++;
			break;
		default:
			break;
		}

		if (!m_tail.empty())
		{
			// 꼬리의 마지막 위치를 가져와서 꼬리를 지우고 머리 위치에 추가
			Position tailEnd = m_tail.back();
			MapDraw::TextErase(tailEnd.m_ix, tailEnd.m_iy);
			m_tail.pop_back();
			m_tail.insert(m_tail.begin(), prevHeadPosition);
		}

		SnakeDraw();

		m_moveClock = m_curClock;
	}
}


void Snake::SpeedUp()
{
}

void Snake::AddTail()
{
	m_tail.push_back(m_position);
}

Snake::~Snake()
{
}
