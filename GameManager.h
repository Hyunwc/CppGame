#pragma once
#include "MEcro.h"
#include "MapDraw.h"
#define WIDTH 40
#define HEIGHT 30

class GameManager
{
private:
	MapDraw m_draw;
	int m_wallWidth;
	int m_wallHeight;
	int heartCount = 0;
	int score = 0;
public:
	GameManager(); //생성자
	void Menu(); //게임선택메뉴 
	void GameStart();
	void TextScore(); //스코어 관리
	~GameManager();
};