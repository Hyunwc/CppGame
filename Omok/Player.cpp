#include "Player.h"

Player::Player() : stone("○"), isBlackTurn(true), playerName("Black"), field{ {CHECK_EMPTY} }
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
			switch (field[y][x])
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


bool Player::KeyInput()
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
			//공백이면서 무르기가 아닌 곳만
			if (field[curPos.m_iy][curPos.m_ix] == CHECK_EMPTY && !(field[curPos.m_iy][curPos.m_ix] == CHECK_NOT))
			{
				//턴증가
				turn++;
				//체크낫인 좌표 다시 공백으로 바꾸고 오목판 다시 그리기
				for (int y = 0; y < height; y++)
				{
					for (int x = 0; x < width; x++)
					{
						if (field[y][x] == CHECK_NOT)
						{
							field[y][x] = CHECK_EMPTY;
							Position temp = { x, y };
							StoneErase(temp);
						}
					}
				}
				
				if (isBlackTurn)
				{
					//흑돌을 놓은 좌표에 Black을 대입
					field[curPos.m_iy][curPos.m_ix] = CHECK_BLACK;
					//그 좌표를 저장(턴이 돌아 왔을 때 이 좌표에서 시작하기 위함)
					blackSavePos = curPos;
					playerName = "White";
				}
				else
				{
					field[curPos.m_iy][curPos.m_ix] = CHECK_WHITE;
					whiteSavePos = curPos;
					playerName = "Black";
				}

				if(WinStone())
					return true; //승리체크 
				isBlackTurn = !isBlackTurn; //턴체인지	
			}
			
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
				b_CancelCount--;
				playerName = "White";
				isBlackTurn = false;
			}
			else
			{
				w_CancelCount--;
				playerName = "Black";
				isBlackTurn = true;
			}
			//체인지 후에 무르기함수 호출
			Cancel();
			MenualUpdate();
			break;
		}
		}

		StoneErase(prevPos);  //돌의 이전 좌표를 보낸다.
		StoneDraw(); //업데이트된 좌표에 바둑돌을 그린다.
	}

	return false;
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
		field[blackSavePos.m_iy][blackSavePos.m_ix] = CHECK_NOT;
	else
		field[whiteSavePos.m_iy][whiteSavePos.m_ix] = CHECK_NOT;

	CursorUpdate();
}

void Player::MenualUpdate()
{
	MapDraw::gotoxy(width * 0.6, height + 2);
	cout << "====조작키====" << endl;
	cout << "이동 : A, S, W, D  돌놓기 : ENTER" << endl;
	cout << "무르기 : N 종료 : ESC" << endl;
	cout << "Player Name : " << playerName;
	if(isBlackTurn)
		cout << " 무르기 : " << b_CancelCount << endl;
	else
		cout << " 무르기 : " << w_CancelCount << endl;
	cout << "Turn : " << turn;
}

bool Player::WinStone()
{
	int Count = 0;
	//블랙턴이면 블랙 아니면 화이트를 보냄
	Count = WinCheck(isBlackTurn ? CHECK_BLACK : CHECK_WHITE);

	if (Count == 5)
	{
		//블랙턴이면 블랙승리 아니면 화이트 승리
		MapDraw::gotoxy(width * 0.8, height / 4);
		cout << (isBlackTurn ? "블랙 승리" : "화이트 승리");
		return true;
	}

	return false;
}

void Player::Reset()
{
	//필드 다시 그리기
	MapDraw::FieldDraw(width, height);
	//배열 초기화
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			field[y][x] = CHECK_EMPTY;
		}
	}
	//현재위치, 마지막 저장위치, 턴 전부 초기 상태로
	curPos.m_ix = width / 2;
	curPos.m_iy = height / 2;
	blackSavePos = curPos;
	whiteSavePos = curPos;
	b_CancelCount = 5;
	w_CancelCount = 5;
	turn = 1;
	isBlackTurn = true;
	playerName = "Black";
}

//5목 체크하는 함수 매개변수 stoneColor는 흑인지 백인지 전달받는 변수
int Player::WinCheck(int stoneColor)
{
	int Count = 0;

	//가로 승리 조건 {0, 0} 부터탐색
	for (int y = 0; y < height; y++)
	{
		//각 행마다 카운트 초기화
		//이거 초기화가 안 이루어지면 y = 0 x = 17,18,19 , y = 1 x = 0,1 때 오목으로 이루어짐 
		Count = 0; 
		for (int x = 0; x < width; x++)
		{
			//연속되는 좌표가 블랙 스톤일 경우에만 증가 
			if (field[y][x] == stoneColor)
			{
				Count++;
				//5개 연속된지 체크
				if (Count == 5)
					return Count;
			}
			// 연속이 아니라면 0으로
			else
				Count = 0;
		}
	}
	//세로 방향 체크
	for (int x = 0; x < width; x++)
	{
		Count = 0; //각 열마다 카운트 초기화
		for (int y = 0; y < height; y++)
		{
			if (field[y][x] == stoneColor)
			{
				Count++;

				//5개 연속된지 체크
				if (Count == 5)
					return Count;
			}
			else
				Count = 0;
		}
	}

	//우측 하단으로 뻗는 대각선
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			Count = 0;
			for (int i = 0; i < 5; i++)
			{
				if (field[y + i][x + i] == stoneColor)
				{
					Count++;

					if (Count == 5)
						return Count;
				}
				else
					Count = 0;
			}
		}
	}
	//좌측 하단으로 뻗는 대각선
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			Count = 0;
			for (int i = 0; i < 5; i++)
			{
				if (field[y - i][x + i] == stoneColor)
				{
					Count++;

					if (Count == 5)
						return Count;
				}
				else
					Count = 0;
			}
		}
	}
	
	return Count;
}


