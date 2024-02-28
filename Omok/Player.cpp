#include "Player.h"

Player::Player() : stone("○"), isBlackTurn(true), playerName("Black")
{
	turn = 0;
}

void Player::SetPosition(const Size& _mapSize)
{
	//맵 중앙에 바둑돌을 그리기 위함
	stonePos.m_ix = _mapSize.m_iWidth / 2;
	stonePos.m_iy = _mapSize.m_iHeight / 2;
	blackSavePos = stonePos;
	whiteSavePos = stonePos;
}

void Player::StoneDraw()
{
	//MapDraw::FieldDraw(20, 20); //지워진 맵을 다시 그리기 위함
	//MapDraw::DrawPoint(stone, stonePos.m_ix, stonePos.m_iy);
	for (const auto& pos : BlackStoneVec)
		MapDraw::DrawPoint("○", pos.m_ix, pos.m_iy);

	for (const auto& pos : WhiteStoneVec)
		MapDraw::DrawPoint("●", pos.m_ix, pos.m_iy);

	MapDraw::DrawPoint(stone, stonePos.m_ix, stonePos.m_iy);

	/*if(isBlackTurn)
		MapDraw::DrawPoint(stone, blackSavePos.m_ix, blackSavePos.m_iy);
	else
		MapDraw::DrawPoint(stone, whiteSavePos.m_ix, whiteSavePos.m_iy);*/
}

void Player::StoneErase(Position prevPos)
{
	//MapDraw::ErasePoint(stone, prevPos.m_ix, prevPos.m_iy);
	//전달받은 이전좌표에 조건에 맞는 기호를 그린다.
	MapDraw::gotoxy(prevPos.m_ix * 2, prevPos.m_iy);
	if (prevPos.m_ix == 0 && prevPos.m_iy == 0)
		cout << "┌";
	else if (prevPos.m_ix == 19 && prevPos.m_iy == 0)
		cout << "┐";
	else if (prevPos.m_ix == 0 && prevPos.m_iy == 19)
		cout << "└";
	else if (prevPos.m_ix == 19 && prevPos.m_iy == 19)
		cout << "┘";
	else if (prevPos.m_ix == 0)
		cout << "├";
	else if (prevPos.m_ix == 19)
		cout << "┤";
	else if (prevPos.m_iy == 0)
		cout << "┬";
	else if (prevPos.m_iy == 19)
		cout << "┴";
	else
		cout << "┼";
}


void Player::KeyInput()
{
	//돌의 이전 좌표 저장
	Position prevPos = stonePos;
	//키보드 입력값에 따라
	if (_kbhit())
	{
		switch (_getch())
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
			turn++;

			if (isBlackTurn)
			{
				//MapDraw::gotoxy(blackSavePos.m_ix, blackSavePos.m_iy);
				BlackStoneVec.push_back(stonePos);
				blackSavePos = stonePos;
				stone = "●";
				playerName = "White";
				isBlackTurn = false;
			}
			else
			{
				//MapDraw::gotoxy(whiteSavePos.m_ix, whiteSavePos.m_iy);
				WhiteStoneVec.push_back(stonePos);
				whiteSavePos = stonePos;
				stone = "○";
				playerName = "Black";
				isBlackTurn = true;
			}
			break;
		}
		}

		StoneErase(prevPos);  //돌의 이전 좌표를 보낸다.
		StoneDraw(); //업데이트된 좌표에 바둑돌을 그린다.
	}
}

void Player::CursorUpdate()
{
	//블랙턴이 되었을때 바로 커서 업데이트해버리자
	if (isBlackTurn)
	{
		MapDraw::gotoxy(blackSavePos.m_ix * 2, blackSavePos.m_iy);
	}
	else
	{
		MapDraw::gotoxy(whiteSavePos.m_ix * 2, whiteSavePos.m_iy);
	}
}
