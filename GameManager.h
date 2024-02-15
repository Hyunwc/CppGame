#pragma once
#include "Mecro.h"
#include "MapDraw.h"
#include "Map.h"
#include "Snake.h"


class GameManager
{
private:
	Size m_mapSize;
	Map map;
	Snake snake;
	//int heartCount = 0; //하트 개수
	int score;  //스코어
public:
	GameManager(); //생성자
	void SetPosition(Size _mapSize);
	void GameSetting();
	void MenuDraw(); //게임선택메뉴 
	void GameStart();
	void GamePlay();
	void GameOver();
	void TextScore(); //스코어 관리
	~GameManager();
};