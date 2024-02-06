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
	GameManager(); //������
	void Menu(); //���Ӽ��ø޴� 
	void GameStart();
	void TextScore(); //���ھ� ����
	~GameManager();
};