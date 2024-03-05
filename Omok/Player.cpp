#include "Player.h"

Player::Player() : stone("○"), isBlackTurn(true), playerName("Black"), map{ {CHECK_EMPTY} }
{
	turn = 1;
}

void Player::SetPosition(const Size& _mapSize)
{
	//맵 중앙에 바둑돌을 그리기 위함
	curPos.m_ix = _mapSize.m_iWidth / 2;
	curPos.m_iy = _mapSize.m_iHeight / 2;
	//가로, 세로 _mapSize로 초기화
	height = _mapSize.m_iHeight;
	width = _mapSize.m_iWidth;
	blackSavePos = curPos;
	whiteSavePos = curPos;
}

void Player::StoneDraw()
{
	//컨테이너에 저장된 흑돌 Draw
	for (const auto& pos : BlackStoneVec)
		MapDraw::DrawPoint("○", pos.m_ix, pos.m_iy);
	//컨테이너에 저장된 백돌 Draw
	for (const auto& pos : WhiteStoneVec)
		MapDraw::DrawPoint("●", pos.m_ix, pos.m_iy);

	if (isBlackTurn)
		stone = "○";
	else
		stone = "●";

	MapDraw::DrawPoint(stone, curPos.m_ix, curPos.m_iy);
}

void Player::StoneErase(Position prevPos)
{
	//MapDraw::ErasePoint(stone, prevPos.m_ix, prevPos.m_iy);
	//전달받은 이전좌표에 조건에 맞는 기호를 그린다.
	MapDraw::gotoxy(prevPos.m_ix * 2, prevPos.m_iy);
	if (prevPos.m_ix == 0 && prevPos.m_iy == 0)
		cout << "┌";
	else if (prevPos.m_ix == width - 1 && prevPos.m_iy == 0)
		cout << "┐";
	else if (prevPos.m_ix == 0 && prevPos.m_iy == height - 1)
		cout << "└";
	else if (prevPos.m_ix == width - 1 && prevPos.m_iy == height - 1)
		cout << "┘";
	else if (prevPos.m_ix == 0)
		cout << "├";
	else if (prevPos.m_ix == width - 1)
		cout << "┤";
	else if (prevPos.m_iy == 0)
		cout << "┬";
	else if (prevPos.m_iy == height - 1)
		cout << "┴";
	else
		cout << "┼";
}


void Player::KeyInput()
{
	//돌의 이전 좌표 저장
	Position prevPos = curPos;
	//키보드 입력값에 따라
	if (_kbhit())
	{
		switch (_getch())
		{
		case KEY_LEFT:
		{
			//x = 0 이상일때까지만 //나중에 수정할 예정
			if (curPos.m_ix - 1 >= 0)
			{
				curPos.m_ix--;
				break;
			}
		}
		case KEY_RIGHT:
		{
			//x = 20 이하 
			if (curPos.m_ix + 1 < 20)
			{
				curPos.m_ix++;
				break;
			}
		}
		case KEY_UP:
		{
			if (curPos.m_iy - 1 >= 0)
			{
				curPos.m_iy--;
				break;
			}
		}
		case KEY_DOWN:
		{
			if (curPos.m_iy + 1 < 20)
			{
				curPos.m_iy++;
				break;
			}
		}
		//엔터 입력시
		case KEY_ENTER:
		{
			//턴증가
			turn++;
			//CursorUpdate();
			//블랙턴일때
			if (isBlackTurn)
			{
				//좌표를 흑돌벡터에 push 
				BlackStoneVec.push_back(curPos);
				//흑돌을 놓은 좌표에 Black을 대입
				map[curPos.m_iy][curPos.m_ix] = CHECK_BLACK;
				//그 좌표를 저장(턴이 돌아 왔을 때 이 좌표에서 시작하기 위함)
				blackSavePos = curPos;
				playerName = "White";
				isBlackTurn = false;
				//블랙에서 화이트턴으로 바뀌었으니 커서 업데이트 함수에서 화이트턴 조건을 타 
				//백돌의 마지막 좌표로 커서가 업데이트됨
			}
			else
			{
				//흑돌 기능과 반대 역할
				WhiteStoneVec.push_back(curPos);
				map[curPos.m_iy][curPos.m_ix] = CHECK_WHITE;
				whiteSavePos = curPos;
				playerName = "Black";
				isBlackTurn = true;
			}

			CursorUpdate();
			break;
		}
		//무르기
		case KEY_CANCEL:
		{
			//turn--;
			////cout << "무르기 호출";
			////무르기를 선택한게 블랙턴일 경우 턴 체인지
			//if (isBlackTurn)
			//{
			//	playerName = "White";
			//	isBlackTurn = false;
			//}
			//else
			//{
			//	playerName = "Black";
			//	isBlackTurn = true;
			//}
			////체인지 후에 무르기함수 호출
			//Cancel(); 
			//break;
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
		//좌표를 마지막에 흑돌 두었던 좌표로 업데이트
		curPos = blackSavePos;
	}
	else
	{
		curPos = whiteSavePos;
	}
	//업데이트된 좌표에 바둑돌 다시 그림
	StoneDraw();
}

//void Player::Cancel()
//{
//	//
//	if (isBlackTurn) {
//		//반복자에 흑돌 맨마지막 좌표 저장
//		//그 좌표 ※표시 여기에 못 놓게 하기 위함 (나중에 예외처리 만들 예정)
//		//맨마지막에 넣은 좌표 삭제
//		auto last = BlackStoneVec.end() - 1;
//		curPos.m_ix = last->m_ix;
//		curPos.m_iy = last->m_iy;
//		MapDraw::DrawPoint("※", last->m_ix, last->m_iy);
//
//	    BlackStoneVec.erase(BlackStoneVec.end() - 1);
//	}
//	else
//	{
//		auto last = WhiteStoneVec.end() - 1;
//		curPos.m_ix = last->m_ix;
//		curPos.m_iy = last->m_iy;
//		MapDraw::DrawPoint("※", last->m_ix, last->m_iy);
//		WhiteStoneVec.erase(WhiteStoneVec.end() - 1);
//		
//	}
//
//	//CursorUpdate();
//}

bool Player::WinCheck()
{
	int count = 0; 
	bool win = false;

	//{0, 0} 부터탐색
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			//해당좌표가 블랙일경우 
			if (map[y][x] == CHECK_BLACK)
				count++;
			else if (map[y][x] == CHECK_EMPTY)
				count = 0;

			if (count == 5)
				win = true;
		}
	}

	return win;
}
