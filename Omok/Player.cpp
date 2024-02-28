#include "Player.h"

Player::Player() : stone("○"), isBlackTurn(true)
{
}

void Player::SetPosition(const Size& _mapSize)
{
	//맵 중앙에 바둑돌을 그리기 위함
	stonePos.m_ix = _mapSize.m_iWidth / 2;
	stonePos.m_iy = _mapSize.m_iHeight / 2;
	
}

void Player::StoneDraw()
{
	MapDraw::FieldDraw(20, 20); //지워진 맵을 다시 그리기 위함
	MapDraw::DrawPoint(stone, stonePos.m_ix, stonePos.m_iy);
}

void Player::StoneErase()
{
	MapDraw::ErasePoint(stone, stonePos.m_ix, stonePos.m_iy);
}


void Player::KeyInput()
{
	char ch;
	//키보드 입력값에 따라
	if (_kbhit())
	{
		ch = _getch();
	
		switch (ch)
		{
		case KEY_LEFT:
		case KEY_RIGHT:
		case KEY_UP:
		case KEY_DOWN:
		{
			Move(ch);
			break;
		}
		//바둑돌 놓는 기능 추가 예정
		case KEY_ENTER:
		{
			stoneVec.push_back(stonePos);
		}
		}
	}
}

void Player::Move(char input)
{
	switch (input)
	{
	case KEY_LEFT:
	{
		//x = 0 이상일때까지만 //나중에 수정할 예정
		if (stonePos.m_ix - 1 >= 0)
		{
			stonePos.m_ix--;
			break;
		}
	}
	case KEY_RIGHT:
	{
		//x = 20 이하 
		if (stonePos.m_ix + 1 < 20)
		{
			stonePos.m_ix++;
			break;
		}
	}
	case KEY_UP:
	{
		if (stonePos.m_iy - 1 >= 0)
		{
			stonePos.m_iy--;
			break;
		}
	}
	case KEY_DOWN:
	{
		if (stonePos.m_iy + 1 < 20)
		{
			stonePos.m_iy++;
			break;
		}
	}
	//바둑돌 놓는 기능 추가 예정
	case KEY_ENTER:
	{

	}
	}


	StoneErase();  //먼저 기존에 있던 바둑돌을 지운디
	//stonePos = nextPos; //바둑돌의 좌표를 nextPos로 업데이트
	MapDraw::testDraw(stoneVec, stone, 20, 20, stonePos.m_ix, stonePos.m_iy);
	//StoneDraw(); //업데이트된 좌표에 바둑돌을 그린다.
}
