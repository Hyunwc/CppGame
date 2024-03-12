#include "Player.h"

Player::Player() : stone("○"), isBlackTurn(true), playerName("Black"), map{ {CHECK_EMPTY} }
{
	turn = 1;
	b_CancelCount = 5;
	w_CancelCount = 5;
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
	//루프를 돌아 해당 좌표에 맞는 기호를 그림
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			switch (map[y][x])
			{
			case CHECK_BLACK: //흑
			{
				MapDraw::DrawPoint("○", x, y);
				break;
			}
			case CHECK_WHITE: //백
			{
				MapDraw::DrawPoint("●", x, y);
				break;
			}
			case CHECK_NOT: //무르기
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
		//StoneErase(prevPos);  //돌의 이전 좌표를 보낸다.
		switch (_getch())
		{
		case KEY_LEFT:
		{
			//x의 다음좌표가 0 이상일때만 (0까지만)
			if (curPos.m_ix - 1 >= 0)
				curPos.m_ix--;
			break;
		}
		case KEY_RIGHT:
		{
			//x의 다음좌표가 20 미만 즉 19
			if (curPos.m_ix + 1 < width)
				curPos.m_ix++;
			break;
		}
		case KEY_UP:
		{
			if (curPos.m_iy - 1 >= 0)
				curPos.m_iy--;
			break;
		}
		case KEY_DOWN:
		{
			if (curPos.m_iy + 1 < height)
				curPos.m_iy++;
			break;
		}
		//엔터 입력시
		case KEY_ENTER:
		{
			//턴증가
			turn++;
			for (int y = 0; y < height; y++)
			{
				for (int x = 0; x < width; x++)
				{
					if (map[y][x] == CHECK_NOT)
					{
						map[y][x] = CHECK_EMPTY;
						Position temp = { x, y };
						StoneErase(temp);
					}
				}
			}
			//CursorUpdate();
			//블랙턴이면서 공백인곳만
			if ((isBlackTurn && map[curPos.m_iy][curPos.m_ix] == CHECK_EMPTY) && !(map[curPos.m_iy][curPos.m_ix] == CHECK_NOT))
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
			else if(!(isBlackTurn && map[curPos.m_iy][curPos.m_ix] == CHECK_EMPTY) && !(map[curPos.m_iy][curPos.m_ix] == CHECK_NOT))
			{
				map[curPos.m_iy][curPos.m_ix] = CHECK_WHITE;
				whiteSavePos = curPos;
				playerName = "Black";
				isBlackTurn = true;
			}

			WinStone(); //승리체크
			CursorUpdate(); //마지막 커서로 위치 업데이트
			MenualUpdate(); //정보 최신화(어떤 플레이어의 턴, 턴 수, 무르기 수)
			break;
		}
		//무르기
		case KEY_CANCEL:
		{
			turn--;
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
		map[blackSavePos.m_iy][blackSavePos.m_ix] = CHECK_NOT;
	else
		map[whiteSavePos.m_iy][whiteSavePos.m_ix] = CHECK_NOT;

	CursorUpdate();
}

void Player::MenualUpdate()
{
	MapDraw::gotoxy(width * 0.8, height + 2);
	cout << "====조작키====" << endl;
	cout << "이동 : A, S, W, D  돌놓기 : ENTER" << endl;
	cout << "무르기 : N 종료 : ESC" << endl;
	cout << "Player Name : " << playerName << " 무르기 : 5" << endl;
	cout << "Turn : " << turn;
}

void Player::WinStone()
{
	int Count = 0;
	
	if (isBlackTurn)
	{
		Count = WinCheck(CHECK_BLACK);
		if (Count == 5)
		{
			MapDraw::gotoxy(width * 0.8, height - 15);
			cout << "블랙 승리";
		}
	}
	else
	{

	}
}

//기존에 int로 작성하였는데 로직 수정되면 bool로 바꿀 예정
int Player::WinCheck(int stone)
{
	int Count = 0;

	//가로 승리 조건 {0, 0} 부터탐색
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			
		}
	}
	
	return Count;
}


