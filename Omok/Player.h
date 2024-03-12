#pragma once
#include "Mecro.h"
#include "MapDraw.h"

enum KEY
{
	KEY_LEFT = 'a',
	KEY_RIGHT = 'd',
	KEY_UP = 'w',
	KEY_DOWN = 's',
	KEY_ESC = 27,  
	KEY_ENTER = 13,  //돌놓기
	KEY_CANCEL = 'n' //무르기
};

enum CHECK
{
	CHECK_EMPTY = 0, //공백
	CHECK_BLACK,
	CHECK_WHITE,
	CHECK_NOT //선택불가
};

class Player
{
private:
	int height;  //세로
	int width;   //가로
	int map[20][20];
	int b_CancelCount; //블랙의 무르기 남은 횟수
	int w_CancelCount; //화이트의 무르기 남은 횟수
	string stone; //바둑돌 모양
	Position curPos; //현재 x, y 좌표
	Position blackSavePos;
	Position whiteSavePos; //바둑돌의 좌표를 저장할 변수
	bool isBlackTurn; //블랙,화이트 턴 구분할 변수 true일시 블랙 턴
public:
	Player();
	void SetPosition(const Size& _mapSize);
	void StoneDraw();
	void StoneErase(Position prevPos);
	void KeyInput(); //키보드 입력에 따라 움직임, 말놓기, 무르기, 종료 수행
	void CursorUpdate();
	void Cancel(); //무르기 
	void MenualUpdate(); //메뉴얼 업데이트 : 이 곳에서 턴 증가와
	void WinStone(); //턴이 바뀔때마다 승리 체크하는 함수 호출하는 함수
	int WinCheck(int stone); //루프 돌면서 5개인지 체크하여 반환하는 함수

	string playerName;
	int turn;
	//void Move(char input);
};