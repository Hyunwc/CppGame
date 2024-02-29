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

class Player
{
private:
	string stone; //바둑돌 모양
	Position curPos; //현재 x, y 좌표
	Position blackSavePos;
	Position whiteSavePos; //바둑돌의 좌표를 저장할 변수
	vector<Position> BlackStoneVec; //흑돌의 좌표를 담을 컨테이너
	vector<Position> WhiteStoneVec; //백돌의 좌표를 담을 컨테이너
	bool isBlackTurn; //블랙,화이트 턴 구분할 변수 true일시 블랙 턴
	
public:
	Player();
	void SetPosition(const Size& _mapSize);
	void StoneDraw();
	void StoneErase(Position prevPos);
	void KeyInput(); //키보드 입력에 따라 움직임, 말놓기, 무르기, 종료 수행
	void CursorUpdate();
	void Cancel(); //무르기 
	bool WinCheck();

	string playerName;
	int turn;
	//void Move(char input);
};