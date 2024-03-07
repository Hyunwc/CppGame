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
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			switch (map[y][x])
			{
			case CHECK_BLACK:
			{
				MapDraw::DrawPoint("○", x, y);
				break;
			}
			case CHECK_WHITE:
			{
				MapDraw::DrawPoint("●", x, y);
				break;
			}
			case CHECK_NOT:
			{
				MapDraw::DrawPoint("※", x, y);
				break;
			}
			default:
				break;
			}
		}
	}

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
			if (isBlackTurn && map[curPos.m_iy][curPos.m_ix] == CHECK_EMPTY)
			{
				//흑돌을 놓은 좌표에 Black을 대입
				map[curPos.m_iy][curPos.m_ix] = CHECK_BLACK;
				//그 좌표를 저장(턴이 돌아 왔을 때 이 좌표에서 시작하기 위함)
				blackSavePos = curPos;
				playerName = "White";
				isBlackTurn = false;
				//블랙에서 화이트턴으로 바뀌었으니 커서 업데이트 함수에서 화이트턴 조건을 타 
				//백돌의 마지막 좌표로 커서가 업데이트됨
			}
			else if(!isBlackTurn && map[curPos.m_iy][curPos.m_ix] == CHECK_EMPTY)
			{
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
			if (isBlackTurn)
			{
				playerName = "White";
				isBlackTurn = false;
			}
			else
			{
				playerName = "Black";
				isBlackTurn = true;
			}
			//체인지 후에 무르기함수 호출
			Cancel(); 
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

void Player::Cancel()
{
	
	if (isBlackTurn)
	{
		map[blackSavePos.m_iy][blackSavePos.m_ix] = CHECK_NOT;
	}
	else
	{
		map[whiteSavePos.m_iy][whiteSavePos.m_ix] = CHECK_NOT;
	}

	CursorUpdate();
}

int Player::WinCheck()
{
	int blackCount = 0;
	int whiteCount = 0;

	//가로 승리 조건 {0, 0} 부터탐색
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			//해당좌표가 블랙일경우 
			//map 0,0 탐색후 다음은 0,1 = 좌표상 1,0
			//블랙이면 계속해서 카운트가 증가한다.
			//공백 또는 백돌을 만나면 카운트는 초기화된다.
			switch (map[y][x])
			{
			case CHECK_BLACK:
			{
				blackCount++;
				whiteCount = 0;
				break;
			}
			case CHECK_WHITE:
			{
				whiteCount++;
				blackCount = 0;
				break;
			}
			case CHECK_EMPTY:
			{
				blackCount = 0;
				whiteCount = 0;
				break;
			}
			}
			if (blackCount == 5)
				return CHECK_BLACK;
			if (whiteCount == 5)
				return CHECK_WHITE;
		}
	}

	//세로 승리 조건 
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			//해당좌표가 블랙일경우 
			//map 0,0 탐색후 다음은 1, 0 = 좌표상 0,1
			switch (map[y][x])
			{
			case CHECK_BLACK:
			{
				blackCount++;
				whiteCount = 0;
				break;
			}
			case CHECK_WHITE:
			{
				whiteCount++;
				blackCount = 0;
				break;
			}
			case CHECK_EMPTY:
			{
				blackCount = 0;
				whiteCount = 0;
				break;
			}
			}
			if (blackCount == 5)
				return CHECK_BLACK;
			if (whiteCount == 5)
				return CHECK_WHITE;
		}
	}

	//오른쪽 대각선 승리 조건
	for (int y =  -1; y < height; y++)
	{
		for (int x = -1; x < width; x++)
		{
			//+1씩 하는 이유는 대각선이 아닌 바로 옆을 순회한다면 count가 0이 되기때문
			//y증가 시켜주는 이유 : x가 가로만큼 순회하기 때문에 y가 1증가 되기 전에 바로 옆을 탐색해버려서 count가 0이 되기떄문
			switch (map[y + 1][x + 1])
			{
			case CHECK_BLACK:
			{
				blackCount++;
				whiteCount = 0;
				y++;
				break;
			}
			case CHECK_WHITE:
			{
				whiteCount++;
				blackCount = 0;
				y++;
				break;
			}
			case CHECK_EMPTY:
			{
				blackCount = 0;
				whiteCount = 0;
				break;
			}
			}
			if (blackCount == 5)
				return CHECK_BLACK;
			if (whiteCount == 5)
				return CHECK_WHITE;
		}
	}

	//왼쪽 대각선 승리조건
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			//흑돌 만났을경우 y+1 x-=2 , x를 2빼주는 이유는 루프가 끝나면서 x가 1씩 증가되기 떄문
			//x를 -1하면 다시 원래대로 돌아오기 때문에 결과적으로 바로 밑에 돌을 체크하게됨
			switch (map[y][x])
			{
			case CHECK_BLACK:
			{
				blackCount++;
				whiteCount = 0;
				y++;
				x -= 2;
				break;
			}
			case CHECK_WHITE:
			{
				whiteCount++;
				blackCount = 0;
				y++;
				x -= 2;
				break;
			}
			case CHECK_EMPTY:
			{
				blackCount = 0;
				whiteCount = 0;
				break;
			}
			}
			if (blackCount == 5)
				return CHECK_BLACK;
			if (whiteCount == 5)
				return CHECK_WHITE;
		}
	}

	//count가 5일 경우 true를 반환
	return CHECK_EMPTY;
}
