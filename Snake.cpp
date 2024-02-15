#include "Snake.h"

Snake::Snake()
{
	m_head = "⊙";
	m_speed = 1000;
	m_curClock = 0;
	m_moveClock = 0;
}

void Snake::SetPosition(Size _mapSize)
{
	//현재 시작 0,0 가로50 세로30
	m_position.m_ix = _mapSize.m_iWidth - 1;
	m_position.m_iy = _mapSize.m_iHeight / 2;

	//m_snake.clear();
}

void Snake::SnakeSetting(string str, SnakeType s_type, Position pos)
{
	SnakeState Snake_Head;
	Snake_Head = { str, s_type, pos.m_ix / 2, pos.m_iy, 0, 0 };
	SnakeVec.push_back(Snake_Head);
}

void Snake::SnakeDraw()
{
	for (auto itr = SnakeVec.begin(); itr != SnakeVec.end(); itr++)
		MapDraw::TextDraw(itr->m_str, itr->m_curPos.m_ix * 2, itr->m_curPos.m_iy);
	//MapDraw::TextDraw(m_head, m_position.m_ix, m_position.m_iy);
}

void Snake::SnakeErase()
{
	for (auto itr = SnakeVec.begin(); itr != SnakeVec.end(); itr++)
		MapDraw::TextErase(itr->m_str, itr->m_curPos.m_ix * 2, itr->m_curPos.m_iy);
	//MapDraw::TextErase(m_position.m_ix, m_position.m_iy);
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
	auto itr = SnakeVec.begin(); //머리

	m_curClock = clock();

	if (m_curClock - m_moveClock >= m_speed)
	{
		//모든뱀을 지움
		SnakeErase();
		//현재좌표를 마지막좌표에 저장한 후에 좌표이동이 진행
		itr->m_lastPos.m_ix = itr->m_curPos.m_ix;
		itr->m_lastPos.m_iy = itr->m_curPos.m_iy;

		switch (m_snakeDirection)
		{
		case DIRECTION_DEFAULT:
			break;
		case DIRECTION_LEFT:
			itr->m_curPos.m_ix--;
			break;
		case DIRECTION_RIGHT:
			itr->m_curPos.m_ix++;
			break;
		case DIRECTION_UP:
			itr->m_curPos.m_iy--;
			break;
		case DIRECTION_DOWN:
			itr->m_curPos.m_iy++;
			break;
		default:
			break;
		}
		//다시그림
		TailMove();
		SnakeDraw();

		m_moveClock = m_curClock;
		
	}
}


void Snake::SpeedUp()
{
	m_speed -= 100;
}

void Snake::AddTail()
{
	SnakeState Snake_Tail;
	auto itr = SnakeVec.begin();
	Snake_Tail = { "○", SNAKETYPE_TAIL, itr->m_lastPos.m_ix, itr->m_lastPos.m_iy, 0, 0 };
	SnakeVec.push_back(Snake_Tail);
}

void Snake::TailMove()
{
	Position saveTail, saveLast = { 0, 0 };
	for (auto itr = SnakeVec.begin(); itr != SnakeVec.end(); itr++)
	{
		if (itr->s_type == SNAKETYPE_HEAD)
		{
			//머리의 마지막 위치를 저장
			saveLast.m_ix = itr->m_lastPos.m_ix;
			saveLast.m_iy = itr->m_lastPos.m_iy;
		}
		else if (itr->s_type == SNAKETYPE_TAIL)
		{
			//꼬리의 마지막좌표를 현재위치로 저장
			itr->m_lastPos.m_ix = itr->m_curPos.m_ix;
			itr->m_lastPos.m_iy = itr->m_curPos.m_iy;
			//꼬리의 현재 위치를 따로 저장
			saveTail.m_ix = itr->m_curPos.m_ix;
			saveTail.m_iy = itr->m_curPos.m_iy;
			//현재위치를 앞 객체의 좌표로 업데이트
			itr->m_curPos.m_ix = saveLast.m_ix;
			itr->m_curPos.m_iy = saveLast.m_iy;
			//다음 객체가 업데이트할 좌표를 이전 객체의 좌표로 미리 업데이트
			saveLast.m_ix = saveTail.m_ix;
			saveLast.m_iy = saveTail.m_iy;
		}
	}
}

void Snake::SnakeClear()
{
	SnakeVec.clear();
	m_speed = 1000;
	m_snakeDirection = DIRECTION_DEFAULT;
}

Position Snake::TestGet()
{
	auto itr = SnakeVec.begin();
	return itr->m_curPos;
}

Snake::~Snake()
{
}
