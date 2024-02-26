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
	KEY_ENTER = 13,  
	KEY_CANCEL = 'n' //무르기
};

class Player
{
private:
	string stone; //바둑돌 모양
	Position stonePos; //바둑돌의 x, y 좌표
	Position savePos; //바둑돌의 좌표를 저장할 변수
public:
	Player();
	void SetPosition(const Size& _mapSize);
	void StoneDraw();
	void StoneErase();
	void KeyInput(); //키보드 입력에 따라 움직임, 말놓기, 무르기, 종료 수행
};