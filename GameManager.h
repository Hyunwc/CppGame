#pragma once
#include "Mecro.h"
#include "MapDraw.h"
#include "Map.h"

class GameManager
{
private:
	Size m_mapSize;
	Map map;
	//int heartCount = 0; //하트 개수
	int score = 0;  //스코어
public:
	GameManager(); //생성자
	void SetPosition(Size _mapSize);
	void MenuDraw(); //게임선택메뉴 
	void GameStart();
	void TextScore(); //스코어 관리
	~GameManager();
};